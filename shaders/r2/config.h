/*
    ECB-shaderpack configuration file
    ______________________________________
*/

#ifndef CONFIG_H
#define CONFIG_H

// Motion Blur and Bump
#define USE_MBLUR                                   // �������� �������� ��� ��������
#define ECB_MBUMP                                   // ���������������� ����

// Bloom
#define ECB_BLOOM_DIV 0.69h                         // �� ����� �������� �������� ���������� ������
#define ECB_BLOOM_SKYDIV 0.95h                      // �� ����� �������� �������� ���������� ������ (����)
#define ECB_BLOOM_BRIGHTNESS 0.5f                   // ������� �����
#define ECB_SPECULAR 0.61f                          // ������� ������
//#define ECB_LCOMPRESS                             // bloom 2218

#define ECB_DOF                                     // Depth of Field
    #define ECB_DOF_MINDIST 0.5f                    // ����������� ���������� ��� �������
    #define ECB_DOF_MAXDIST 600.f                   // ������������ ���������� ��� �������
    #define ECB_DOF_MAXCOF 4.f                      // ������������ ������ �������� ��������� ��������
    #define ECB_DOF_MAXCOF_NEAR 4.f                 // ������������ ������ �������� ������� ��������
    #define ECB_DOF_MAXNEAR float(0.7)              // ���������� �� �������� ������ DoF � ����������� ���������
    #define ECB_DOF_MINNEAR float(0.0)              // ���������� �� ��������� �������� ������ DoF � ������������ ���������

#define ECB_DDOF                                    // Dynamic Depth of Field
    #define ECB_DDOF_MINDIST_ADD float(0.7)         // ���������� ������ ��������
    #define ECB_DDOF_MAXDIST_FACTOR float(4.0)      // ���������� �������� �������� ��������� �������� ��� ������� �� �������
    #define ECB_DDOF_MINDIST float(0.0)             // ����������� ���������� ���������� �������
    #define ECB_DDOF_MAXDIST float(10.0)            // ������������ ���������� ���������� �������

#define ECB_SSAO                                  // Screen Space Ambient Occlusion
    #define ECB_SSAO_QUALITY 2                      // 2 - low, 3 - high, 4 - slow as hell
    #define ECB_SSAO_FADE_DIST 12.f                 // ������ ������� ���������� � �����
    #define ECB_SSAO_FADE_COEF .15f                 // ���� ����������

#define ECB_LTRAILS                                 // Condensation Light Trail
    #define ECB_LTRAIL_VELOCITY 12.5f               // ����� ������ � ����������� �� ��������
    #define ECB_LTRAIL_FACTOR 1.5f                  // ������� ������
    #define ECB_LTRAIL_CLAMP                        // ������������ ����� ������
    #define ECB_LTRAIL_CLAMP_VALUE half(0.0175)     // �������� ����������� �����
    #define ECB_LTRAIL_USE_THRESHOLD                // ������� ������ ��� ���������� ��������
    #define ECB_LTRAIL_THRESHOLD 100.f              // �������� �������� ��� ��������� ������

// Fog
#define ECB_FOG_COLOR 0.25                          // ��������� ������� ������ (fog_color)
#define ECB_FOG_DIST 0.9                            // ��������� ���������� ������ (fog_distance)

// Sun
//#define ECB_SHADER_RESTORE_SUN                    // ������������ ��������� ������
#define ECB_SUN_SAT 0.9h                            // ������������ ������

// Shadow
#define ECB_SHADOW_KERNEL .9f                       // ������ ��������� �������-��������� � �����
#define ECB_SHADOW_STEPS 2                          // ���������� ������� �������� ���� �� ������� � ������ (integer)
//#define ECB_SHADOW_LENGTH 3.0f                    // ����� �����

// Lightmaps
#define ECB_R2A_LMAP_FACTOR .2f + .8f               // ������� ��������� �� R2a
#define ECB_SB 0.66f                                // ������� �����
#define ECB_H*lerp(ECB_SB, 1.f, h*2)                // ������� �������� ������� ������� ���������
#define ECB_H2*lerp(ECB_SB, 1.f, h)                 // ������� �������� ������� ������� ���������
#define ECB_H3*lerp(ECB_SB, 1.f, h*3)               // ������� �������� ������� ������� ��������� (�������� � ������)
#define ECB_S1 0.045                                // base_aref_bump, base_aref_flat, base_flat, impl_bump
#define ECB_S2 0.045                                // base_bump
#define ECB_S3 0.045                                // impl_flat

// Setting local light
#define ECB_LL_DIST 1.2f                            // ��������� ��������� ���� � �������
#define ECB_LL_BRIGHTNESS 0.7f                      // ������� ��������� ���� � �������

// Setting brightness and color
#define ECB_EMISSIVE_MUL 1.1f                       // ������� ���������� ������������
#define ECB_DIFFUSE_AMBIENT_SAT 1.0f                // ��������� ���������� ��������
#define ECB_ANTI_OVERBRIGHT 0.85h                   // ������������ ��������� ��������
#define ECB_BRIGHTNESS 2.5f                         // ������� �������� � �����
#define ECB_SUN_FAR 1.0f                            // ������� �������� ������ ���������� ���������
#define ECB_TERRAIN_SAT 1.0f                        // ��������� �������
#define ECB_AUTOSAT_FACTOR 21.25f                   // ���������� ��������� �������� ��� �������� ������������
#define ECB_PARTICLE_FACTOR *.75f                   // ������� ���������

#endif
