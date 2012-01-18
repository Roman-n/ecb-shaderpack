/*---------------------------------------#
|  Library of shader variables ECB Team  |
#---------------------------------------*/

#ifndef	CONFIG_H
#define CONFIG_H

// Motion Blur
//#define USE_MBLUR

// Bloom
#define ECB_BLOOM_DIV 0.69h          // �� ����� �������� �������� ���������� ������
#define ECB_BLOOM_SKYDIV 0.95h       // �� ����� �������� �������� ���������� ������ (����)
#define ECB_BLOOM_BRIGHTNESS 0.33f   // ������� �����
#define ECB_SPECULAR 0.61f           // ������� ������
//#define USE_LCOMPRESS                   // bloom 2218

// Depth of Field
#define USE_DOF
#define NEAR 0.2h                    // 
#define MINDIST 0.4h                 // ����������� ����������, ����������� ��������
#define MAXDIST 600.h                // ������������ ����������, ������������ ��������
#define MAXCOF 5.h                   // ���� ������������ ��������
#define MAXCOF_NEAR	100.h            // 
#define EPSDEPTH 0.0001h             // 

// Screen Space Ambient Occlusion
#define ECB_SSAO
#define SSAO_QUALITY 2               // 2 - low, 3 - high
#define FADE_DIST 4.f                // ������ ������� ���������� � �����
#define FADE_COEF 0.2f               // ���� ����������

// Condensation Light Trail
#define USE_ECB_LTRAILS
#define ECB_LTRAIL_VELOCITY 12.5f    // ����� ������ � ����������� �� ��������
#define ECB_LTRAIL_FACTOR 1.75f      // ������� ������
#define USE_TCLAMP                   // ������������ ����� ������
#define TRAIL_CLAMP	half(0.0175)     // �������� ����������� �����
#define LTRAIL_THRESHOLD 100.f       // �������� �������� ��� ��������� ������
//#define USE_LTRAIL_THRESHOLD            // ������� ������ ��� ���������� ��������

// Fog
#define ECB_FOG_COLOR 0.25           // ��������� ������� ������ (fog_color)
#define ECB_FOG_DIST 0.9             // ��������� ���������� ������ (fog_distance)

// Shader Sun
#define ECB_SUN_SAT 0.9h             // ������������ ������
#define USE_OGSM_RESTORESUN          // ������������ ��������� ������ (�������� ����� ����������)

// Shadow
#define	ECB_SHADOW_KERNEL 0.9f       // ������ ��������� �������-��������� � �����
#define ECB_SHADOW_STEPS 2           // ���������� ������� �������� ���� �� ������� � ������ (integer)
//#define ECB_SHADOW_LENGTH 3.0f          // ������� ����

// Lightmaps
#define ECB_H *lerp(0.5f, 1.f, h*2)  // ��� ������� �������� ������� ������� ���������
#define ECB_H3 *lerp(0.4f, 1.f, h*3) // ��� ������� �������� ������� ������� ��������� (�������� � ������)
#define ECB_H2 *lerp(0.4f, 1.f, h)   // ��� ������� �������� ������� ������� ���������
#define ECB_R2A_LMAP_FACTOR .2f+.8f  // ������� ��������� �� R2a
#define ECB_S1 0.045                 // base_aref_bump, base_aref_flat, base_flat, impl_bump
#define ECB_S2 0.045                 // base_bump
#define ECB_S3 0.045                 // impl_flat

// Setting local light
#define ECB_LL_DIST 1.2f             // ��������� ��������� ���� � �������
#define ECB_LL_BRIGHTNESS 2.0f       // ������� ��������� ���� � �������

// Setting brightness and color
#define ECB_EMISSIVE_MUL 1.5f        // ������� ���������� ������������
#define ECB_DIFFUSE_AMBIENT_SAT 1.0f // ��������� ���������� ��������
#define ECB_ANTI_OVERBRIGHT 0.85h    // ������������ ���� ��������
#define ECB_BRIGHTNESS 2.5f          // ������� �������� � �����
#define ECB_SUN_FAR 1.0f             // ������� �������� ������ ���������� ���������
#define ECB_TERRAIN_SAT 0.8f         // ��������� �������
#define ECB_AUTOSAT_FACTOR 21.25f    // ���������� ��������� �������� ��� �������� ������������

uniform sampler 	s_smap;		  // 2D/cube shadowmap (������ � COMMON � ������� ������!)

#endif
