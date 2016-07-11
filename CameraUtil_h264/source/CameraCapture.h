#ifndef _CAMERACAPTURE_H_
#define _CAMERACAPTURE_H_
#include <windows.h>

#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CAMERA_INDEX 10

// ˵������ʼ����������
// ��������
// ���أ���
DLLEXPORT void cm_init();

// ˵����������������
// ��������
// ���أ���
DLLEXPORT void cm_exit();

// ˵������ӡ���������б�
// ��������
// ���أ�������������
DLLEXPORT UINT cm_print_driver_list();

// ˵�����������豸
// �������豸���
// ���أ�TRUE���򿪳ɹ���FALSE����ʧ��
DLLEXPORT BOOL cm_open(UINT idx);

// ˵�����ر������豸
// ������idx���豸���
// ���أ���
DLLEXPORT void cm_close(UINT idx);

// ˵�����������豸��ȡһ��ͼƬ��BMP�ļ�
// ������idx���豸��ţ�file���ļ�������a.bmp��
// ���أ�TRUE����ȡ�ɹ���FALSE����ȡʧ��
DLLEXPORT BOOL cm_grab_to_bmp(UINT idx, WCHAR *file);

// ˵�����������豸��ȡһ��ͼƬ��������
// ������idx���豸���
// ���أ�TRUE����ȡ�ɹ���FALSE����ȡʧ��
DLLEXPORT BOOL cm_grab_to_clipboard(UINT idx);

// ˵������ʼ¼����Ƶ
// ������idx���豸��ţ�file���ļ�������a.h264��
// ���أ�TRUE����ʼ¼�ƣ�FALSE��¼��ʧ��
DLLEXPORT BOOL cm_start_record(UINT idx, const char *file);

// ˵����ֹͣ¼����Ƶ
// ������idx���豸���
// ���أ���
DLLEXPORT void cm_stop_record(UINT idx);

// ˵������������豸����
// ������idx���豸��ţ�width��ͼ���ȣ�height��ͼ��߶�
// ���أ���
DLLEXPORT BOOL cm_get_param(UINT idx, int *width, int *height);

#ifdef __cplusplus
}
#endif

#endif
