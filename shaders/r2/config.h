#ifndef	CONFIG_H
#define CONFIG_H

// �� ������� ��� �������� ���������� �������� "ECB" ��� ���������. 
// ������ ��� �������� ������� � ������ ������ ����������� ���� �� ����������� 
// ����, ��� ��� ���������� � ���������� ������������ �������� ����������� �� ����� �����.

// ������� �������� ���� ������� �������� ���������������� ��������� ������� ������ � �������
#define ECB_FOG_COLOR 0.25 // ��������� ������� ������ (fog_color)
#define ECB_FOG_DIST 0.9 // ��������� ���������� ������ (fog_distance)

// shadows
#define	ECB_SHADOW_KERNEL	.9f // ������ ��������� �������-��������� � �����
#define ECB_SHADOW_STEPS 2 // integer; ���������� ������� �������� ���� �� ������� � ������. 

#define ECB_H *lerp( 0.5f, 1.f, h * 2 ) //  ��� ������� �������� ������� ������� ���������.
#define ECB_H3 *lerp( 0.4f, 1.f, h * 3 ) //  ��� ������� �������� ������� ������� ���������. (�������� � ������)
#define ECB_H2 *lerp( 0.4f, 1.f, h ) //  ��� ������� �������� ������� ������� ���������.

#define ECB_S1 0.045 // base_aref_bump, base_aref_flat, base_flat, impl_bump // 0.05
#define ECB_S2 0.045 // base_bump // 0.02
#define ECB_S3 0.045 // impl_flat // 0.04

#define ECB_SUN_SAT 0.9h // ������������ ������

#define ECB_EMISSIVE_MUL 1.5f // ������� ���������� ������������: ��� ������ ��� ���� ������ � ����� ������� � ��.

#define ECB_BLOOM_DIV 0.69h // �� ����� �������� �������� ���������� ������.
#define ECB_BLOOM_SKYDIV 0.95h // �� ����� �������� �������� ���������� ������ (����)
#define ECB_BLOOM_BRIGHTNESS 0.5f // ������� �����
#define ECB_SPECULAR 0.61f // ������� ������
#define ECB_DIFFUSE_AMBIENT_SAT 1.0f // ��������� ���������� ��������
//#define ECB_SHADOW_LENGTH 3.0f // ��������� ����� � n ��� (����������������� ����)
#define ECB_ANTI_OVERBRIGHT 0.85h // ����������, �� ������� �������� ���������� ���� ��������. ��� ���� ����� �������� �� ���������� ������ ��� ��������� ���������.
#define ECB_BRIGHTNESS 2.5f // ������� �������� � ����� 1.6
#define ECB_SUN_FAR 1.0f // ��� ����������� ������� ����� ������� ������� ���������� ����� � ����������. ���������� ������� �������� ������
#define ECB_R2A_LMAP_FACTOR .2f+.8f

//#define USE_MBLUR

// DoF
#define USE_DOF

#define MINDIST 	0.5f
#define MAXDIST 	600.f
#define MAXCOF		1.f
#define MAXCOF_NEAR	15.f
#define MAXNEAR float(0.5)					// Distance at which Near Field DOF starts. Default is 0.7. Larger values will blur your weapon more, and not only its near part.
#define MINNEAR float(0.0)					// Distance at which Near Field DOF stops. Default is 0.0

// DDoF
#define ECB_USE_DDOF

#define DDOF_MINDIST_ADD float(0.5)			// Added to view distance, at this distance begins blurring
#define DDOF_MAXDIST_FACTOR float(1.0)		// Mindist times factor = maxdist
#define DDOF_MINDIST float(0.0)				// Minimum distance DDOF starts.
#define DDOF_MAXDIST float(10.0)			// Distance at which DOF stops rendering. Beyond this view distance, only minor DDOF

//#define ECB_SSAO
#define SSAO_QUALITY 2 	//2 - low quality; 3 - high quality
#define FADE_DIST 4.f
#define FADE_COEF .2f

#define USE_ECB_LTRAILS // ��������������� �������� ����
#define ECB_LTRAIL_VELOCITY 12.5f // ����� ������ � ����������� �� ��������
#define ECB_LTRAIL_FACTOR 1.5f // ������� ������
#define USE_TCLAMP // ������������ ����� ������
#define TRAIL_CLAMP	half(0.0175) // �������� ����������� �����
#define USE_LTRAIL_THRESHOLD // ������� ������ ��� ���������� ��������
#define LTRAIL_THRESHOLD 100.f // ��� ������� ��������, ��� ������� �������� �������� ����� ������ ��� ��������� ������

//#define USE_SHADER_RESTORESUN

#define ECB_TERRAIN_SAT 0.8f

//#define USE_LCOMPRESS # ���� ��� 2218

#define ECB_LL_DIST 1.2f
#define ECB_LL_BRIGHTNESS 1.0f

#define ECB_AUTOSAT_FACTOR 21.25f

#define ECB_PARTICLE_FACTOR *.75f

#define ECB_MBUMP

#endif
