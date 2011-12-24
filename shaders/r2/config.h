#ifndef	CONFIG_H
#define CONFIG_H

// �� ������� ��� �������� ���������� �������� "ECB" ��� ���������. 
// ������ ��� �������� ������� � ������ ������ ����������� ���� �� ����������� 
// ����, ��� ��� ���������� � ���������� ������������ �������� ����������� �� ����� �����.

// ������� �������� ���� ������� �������� ���������������� ��������� ������� ������ � �������
#define ECB_FOG_COLOR 0.35 // ��������� ������� ������ (fog_color)
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
#define ECB_BLOOM_SKYDIV 0.92h // �� ����� �������� �������� ���������� ������ (����)
#define ECB_BLOOM_BRIGHTNESS 0.5f // ������� �����
#define ECB_SPECULAR 0.61f // ������� ������
#define ECB_DIFFUSE_AMBIENT_SAT 1.0f // ��������� ���������� ��������
//#define ECB_SHADOW_LENGTH 3.0f // ��������� ����� � n ��� (����������������� ����)
#define ECB_USE_ECB_BLOOM // ������������ "��� �����" ����
#define ECB_ANTI_OVERBRIGHT 0.85h // ����������, �� ������� �������� ���������� ���� ��������. ��� ���� ����� �������� �� ���������� ������ ��� ��������� ���������.
#define ECB_BRIGHTNESS 2.5f // ������� �������� � ����� 1.6
#define ECB_SUN_FAR 1.0f // ��� ����������� ������� ����� ������� ������� ���������� ����� � ����������. ���������� ������� �������� ������
#define ECB_R2A_LMAP_FACTOR .2f+.8f

//#define USE_MBLUR

// DoF
//#define USE_DOF
#define NEAR 		0.2h
#define MINDIST 	0.4h
#define MAXDIST 	600.h
#define MAXCOF		5.h
#define MAXCOF_NEAR	100.h
#define EPSDEPTH	0.0001h

//#define ECB_SSAO
#define SSAO_QUALITY 2 	//2 - low quality; 3 - high quality
#define FADE_DIST 4.f
#define FADE_COEF .2f

#define USE_ECB_LTRAILS // ��������������� �������� ����
#define ECB_LTRAIL_VELOCITY 20.f
#define ECB_LTRAIL_FACTOR 1.0f

//#define USE_ECBOPTS // ������������� �����������
uniform sampler 	s_smap;		// 2D/cube shadowmap

#define USE_OGSM_RESTORESUN

#define ECB_TERRAIN_SAT 0.8f

//#define USE_LCOMPRESS # ���� ��� 2218

#define ECB_LL_DIST 1.4f
#define ECB_LL_BRIGHTNESS 2.0f

#define ECB_AUTOSAT_FACTOR 18.75f

#endif
