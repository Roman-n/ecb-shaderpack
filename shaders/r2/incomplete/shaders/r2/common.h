#ifndef	COMMON_H
#define COMMON_H

//////////////////////////////////////////////////////////////////////////////////////////
// *** options

// #define USE_GAMMA_22
// #define USE_SPECULAR_RGB
// #define USE_SJITTER
// #define USE_SUNFILTER
//
// #define USE_MBLUR		//- HW-options defined
// #define USE_HWSMAP		//- HW-options defined
// #define USE_SHADER3		//- HW-options defined
// #define FP16_FILTER		//- HW-options defined
// #define FP16_BLEND		//- HW-options defined
//
// #define USE_PARALLAX		//- shader defined
// #define USE_TDETAIL		//- shader defined
// #define USE_LM_HEMI		//- shader defined
// #define USE_DISTORT		//- shader defined
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef SMAP_size
#define SMAP_size	2048
#endif
//////////////////////////////////////////////////////////////////////////////////////////
uniform float3x4	m_W;
uniform float3x4	m_V;
uniform float4x4 	m_P;
uniform float3x4	m_WV;
uniform float4x4 	m_VP;
uniform float4x4 	m_WVP;
uniform half4		fog_plane;
uniform half4		fog_params;		// x=near*(1/(far-near)), ?,?, w = -1/(far-near)
uniform half4		fog_color;
uniform half3		L_sun_color;
uniform half3		L_sun_dir_w;
uniform half3		L_sun_dir_e;
uniform half4		L_hemi_color;
uniform half4		L_ambient;
uniform half3		L_lmap_color;
uniform half4 		L_material;		// 0,0,0,mid

uniform half4		Ldynamic_color;		// dynamic light color (rgb1)	- spot/point
uniform half4		Ldynamic_pos;		// dynamic light pos+1/range(w) - spot/point
uniform half4		Ldynamic_dir;		// dynamic light direction 	- sun
uniform half4		parallax;

uniform half4		J_direct	[6];
uniform half4		J_spot		[6];

uniform float3 		eye_position;
uniform half3		eye_direction;
uniform half3		eye_normal;
uniform	half4 		dt_params;

half3 	unpack_normal	(half3 v)	{ return 2.f*v-1.f; 		}
half3 	unpack_bx2	(half3 v)	{ return 2.f*v-1.f; 		}
half3 	unpack_bx4	(half3 v)	{ return 4.f*v-2.f; 		}
half2 	unpack_tc_base	(half2 tc)	{ return tc;			} // [uncompressed]
half2 	unpack_tc_lmap	(half2 tc)	{ return tc*(1.f/32768.f);	} // [-1  .. +1 ]
half  	calc_fogging 	(half4 w_pos)	{ return dot(w_pos,fog_plane); 	}
half2 	calc_detail 	(half3 w_pos)	{ 
	float  	dtl	= distance(w_pos,eye_position)*dt_params.w;
		dtl	= min(dtl*dtl, 1);
	half  	dt_mul	= 1  - dtl;	// dt*  [1 ..  0 ]
	half  	dt_add	= .5 * dtl;	// dt+	[0 .. 0.5]
	return	half2	(dt_mul,dt_add);
}
float 	calc_cyclic 	(float x)				{
	float 	phase 	= 1/(2*3.141592653589f);
	float 	sqrt2	= 1.4142136f;
	float 	sqrt2m2	= 2.8284271f;
	float 	f 	= sqrt2m2*frac(x)-sqrt2;	// [-sqrt2 .. +sqrt2]
	return 	f*f - 1.f;				// [-1     .. +1]
}
float2 	calc_xz_wave 	(float2 dir2D, float frac)		{
	// Beizer
	float2  ctrl_A	= float2(0.f,		0.f	);
	float2 	ctrl_B	= float2(dir2D.x,	dir2D.y	);
	return  lerp	(ctrl_A, ctrl_B, frac);
}
float3 	calc_reflection	(float3 pos_w, float3 norm_w)
{
    return reflect(normalize(pos_w-eye_position), norm_w);
}
/*
float4	calc_spot 	(out float4 tc_lmap, out float2 tc_att, float4 w_pos, float3 w_norm)	{
	float4 	s_pos	= mul	(L_dynamic_xform, w_pos);
	tc_lmap		= s_pos.xyww;			// projected in ps/ttf
	tc_att 		= s_pos.z;			// z=distance * (1/range)
	float3 	L_dir_n = normalize	(w_pos - L_dynamic_pos.xyz);
	float 	L_scale	= dot(w_norm,-L_dir_n);
	return 	L_dynamic_color*L_scale*saturate(calc_fogging(w_pos));
}
float4	calc_point 	(out float2 tc_att0, out float2 tc_att1, float4 w_pos, float3 w_norm)	{
	float3 	L_dir_n = normalize	(w_pos - L_dynamic_pos.xyz);
	float 	L_scale	= dot		(w_norm,-L_dir_n);
	float3	L_tc 	= (w_pos - L_dynamic_pos.xyz) * L_dynamic_pos.w + .5f;	// tc coords
	tc_att0		= L_tc.xz;
	tc_att1		= L_tc.xy;
	return 	L_dynamic_color*L_scale*saturate(calc_fogging(w_pos));
}
*/
float3	calc_sun_r1		(float3 norm_w)	{ return L_sun_color*saturate(dot((norm_w),-L_sun_dir_w)); 		}
float3 	calc_model_hemi_r1 	(float3 norm_w)	{ return max(0,norm_w.y)*L_hemi_color; 					}
float3	calc_model_lq_lighting	(float3 norm_w) { return L_material.x*calc_model_hemi_r1(norm_w) + L_ambient + L_material.y*calc_sun_r1(norm_w); 	}

//////////////////////////////////////////////////////////////////////////////////////////
struct 	v_static        {
	float4 	P	: POSITION;	// (float,float,float,1)
	float4	Nh	: NORMAL;	// (nx,ny,nz,hemi occlusion)
	float3 	T 	: TANGENT;	// tangent
	float3 	B 	: BINORMAL;	// binormal
	float2 	tc	: TEXCOORD0;	// (u,v)
	float2	lmh	: TEXCOORD1;	// (lmu,lmv)
};
struct 	v_tree          {
	float4 	P	: POSITION;	// (float,float,float,1)
	float4	Nh	: NORMAL;	// (nx,ny,nz)
	float3 	T 	: TANGENT;	// tangent
	float3 	B 	: BINORMAL;	// binormal
	float4 	tc	: TEXCOORD0;	// (u,v,frac,???)
};
struct 	v_model         {
	float4 	P	: POSITION;	// (float,float,float,1)
	float3	N	: NORMAL;	// (nx,ny,nz)
	float3	T	: TANGENT;	// (nx,ny,nz)
	float3	B	: BINORMAL;	// (nx,ny,nz)
	float2	tc	: TEXCOORD0;	// (u,v)
};
struct	v_detail        {
	float4 	pos	: POSITION;	// (float,float,float,1)
	int4 	misc	: TEXCOORD0;	// (u(Q),v(Q),frac,matrix-id)
};

#ifdef	USE_HWSMAP
struct 	v_shadow_direct_aref
{
	float4 	hpos:	POSITION;	// Clip-space position 	(for rasterization)
	float2 	tc0:	TEXCOORD1;	// Diffuse map for aref
};
struct 	v_shadow_direct
{
	float4 	hpos:	POSITION;	// Clip-space position 	(for rasterization)
};
#else
struct 	v_shadow_direct_aref
{
	float4 	hpos:	POSITION;	// Clip-space position 	(for rasterization)
	float 	depth: 	TEXCOORD0;	// Depth
	float2 	tc0:	TEXCOORD1;	// Diffuse map for aref
};
struct 	v_shadow_direct
{
	float4 	hpos:	POSITION;	// Clip-space position 	(for rasterization)
	float 	depth: 	TEXCOORD0;	// Depth
};
#endif

//////////////////////////////////////////////////////////////////////////////////////////
struct 	p_bumped        {
	float4 	hpos	: POSITION;
	float2 	tcdh	: TEXCOORD0;	// Texture coordinates
	float4	position: TEXCOORD1;	// position + hemi
	half3 	M1	: TEXCOORD2;	// nmap 2 eye - 1
	half3 	M2	: TEXCOORD3;	// nmap 2 eye - 2
	half3 	M3	: TEXCOORD4;	// nmap 2 eye - 3
#ifdef	USE_PARALLAX
	half3 	eye	: TEXCOORD5;	// vector to point in tangent space
  #ifdef USE_TDETAIL
	float2	tcdbump	: TEXCOORD6;	// d-bump
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD7;	// lm-hemi
    #endif
  #else
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD6;	// lm-hemi
    #endif
  #endif	
#else
  #ifdef USE_TDETAIL
	float2	tcdbump	: TEXCOORD5;	// d-bump
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD6;	// lm-hemi
    #endif
  #else
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD5;	// lm-hemi
    #endif
  #endif
#endif
};
//////////////////////////////////////////////////////////////////////////////////////////
struct 	p_flat          {
	float4 	hpos	: POSITION;
	float2	tcdh	: TEXCOORD0;	// Texture coordinates + depth(Z) + hemi(W)
	float4	position: TEXCOORD1;	// position + hemi
	half3	N	: TEXCOORD2;	// Eye-space normal	(for lighting)
  #ifdef USE_TDETAIL
	float2	tcdbump	: TEXCOORD3;	// d-bump
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD4;	// lm-hemi
    #endif
  #else
    #ifdef USE_LM_HEMI
	float2 	lmh	: TEXCOORD3;	// lm-hemi
    #endif
  #endif	
};
//////////////////////////////////////////////////////////////////////////////////////////
struct 	f_deffer	{
	half4	position: COLOR0;	// px,py,pz, m-id
	half4	Ne	: COLOR1;	// nx,ny,nz, hemi
	half4	C	: COLOR2;	// r, g, b,  gloss
};
//////////////////////////////////////////////////////////////////////////////////////////
struct 	p_screen        {
	float4 	hpos	: POSITION;
  	float2 	tc0	: TEXCOORD0;	// Texture coordinates 	(for sampling maps)
};
//////////////////////////////////////////////////////////////////////////////////////////
// Geometry phase / deferring		//
uniform sampler2D 	s_base;		//
uniform sampler2D	s_bump;		//
uniform sampler2D	s_bumpX;	//
uniform sampler2D	s_detail;	//
uniform sampler2D	s_bumpD;	//
uniform sampler2D 	s_hemi;		//
//////////////////////////////////////////////////////////////////////////////////////////
// Lighting/shadowing phase		//
uniform sampler2D 	s_depth;	//
uniform sampler2D 	s_position;	//
uniform sampler2D 	s_normal;	//
uniform sampler 	s_smap;		// 2D/cube shadowmap
uniform sampler 	s_lmap;		// 2D/cube projector lightmap
uniform sampler3D 	s_material;	//
uniform sampler1D 	s_attenuate;	//
//////////////////////////////////////////////////////////////////////////////////////////
// Combine phase			// 
uniform sampler2D 	s_diffuse;	// rgb.a = diffuse.gloss
uniform sampler2D 	s_accumulator;	// rgb.a = diffuse.specular
uniform sampler2D 	s_generic;	// 
uniform sampler2D 	s_bloom;	//
uniform sampler 	s_image;	// used in various post-processing 
uniform sampler2D 	s_tonemap;	// actually MidleGray / exp(Lw + eps)
//////////////////////////////////////////////////////////////////////////////////////////
// Defines				// 
#define def_gloss	half(8.f /255.f)
#define def_aref 	half(128.f/255.f)
#define def_dbumph	half(0.333f)
#define def_virtualh	half(.05f)	// 5cm
#define def_distort	half(0.05f)	// we get -0.5 .. 0.5 range, this is -512 .. 512 for 1024, so scale it
#define def_lum_hrange	half(0.55h)	// hight luminance range

//////////////////////////////////////////////////////////////////////////////////////////
#define	LUMINANCE_VECTOR 		half3(0.3f, 0.48f, 0.22f)
void	tonemap		(out half4 low, out half4 high, half3 rgb, half scale)
{
	rgb 	= 	rgb*scale;
#ifdef 	USE_GAMMA_22
	low	= 	half4(sqrt(rgb.xyz),	0);
#else
	low 	= 	half4(rgb,	  	0);
#endif
	high	= 	half4(rgb-def_lum_hrange, dot( min(rgb,def_lum_hrange), LUMINANCE_VECTOR ) );
}
half4 	combine_bloom	(half3	low, half3 high)		{
	return	half4(low+high,1.h);
}

float3	v_hemi 		(float3 n)		{	return L_hemi_color*(.5f + .5f*n.y); 			}
float3	v_hemi_wrap	(float3 n, float w)	{	return L_hemi_color*(w + (1-w)*n.y); 			}
float3 	v_sun 		(float3 n)		{	return L_sun_color*dot(n,-L_sun_dir_w);			}
float3 	v_sun_wrap	(float3 n, float w)	{	return L_sun_color*(w+(1-w)*dot(n,-L_sun_dir_w));	}
half3	p_hemi		(float2 tc) 	{
	half3	t_lmh 	= tex2D		(s_hemi, tc);
	return  dot	(t_lmh,1.h/3.h);
}

#define FXPS technique _render{pass _code{PixelShader=compile ps_3_0 main();}}
#define FXVS technique _render{pass _code{VertexShader=compile vs_3_0 main();}}

#endif
