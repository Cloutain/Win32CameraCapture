#include "CameraCapture.h"
#include "CaptureVideo.h"

CaptureVideo *capvid[MAX_CAMERA_INDEX];

#ifdef __cplusplus
extern "C" {
#endif

// ˵������ʼ����������
// ������idx���豸���
// ���أ���
void cm_init(UINT idx)
{
	capvid[idx] = new CaptureVideo();
}

// ˵����������������
// ������idx���豸���
// ���أ���
void cm_exit(UINT idx)
{
	if (capvid)
	{
		delete capvid[idx];
		capvid[idx] = 0;
	}
}

// ˵������ӡ���������б�
// ��������
// ���أ�������������
UINT cm_print_driver_list()
{
	// ö���豸
	return CaptureVideo::EnumAllDevices();
}

// ˵�����������豸
// ������idx���豸���
// ���أ�TRUE���򿪳ɹ���FALSE����ʧ��
BOOL cm_open(UINT idx)
{
	capvid[idx]->OpenDevice(idx);
	if (capvid[idx]->m_bConnected == TRUE)
	{
		// ��������ͷ
		capvid[idx]->StartCapture();
		return TRUE;
	}
	return FALSE;
}

// ˵�����ر������豸
// ������idx���豸���
// ���أ���
void cm_close(UINT idx)
{
	if (capvid[idx]->m_bConnected == TRUE)
	{	
		// �ر�����ͷ
		capvid[idx]->StopCapture();
	}
	// �ر��豸[0]
	capvid[idx]->CloseDevice();
}

// ˵�����������豸��ȡһ��ͼƬ��BMP�ļ�
// ������idx���豸��ţ�file���ļ�������a.bmp��
// ���أ�TRUE����ȡ�ɹ���FALSE����ȡʧ��
BOOL cm_grab_to_bmp(UINT idx, WCHAR *file)
{
	capvid[idx]->GrabOneFrame(file);
	return TRUE;
}

// ˵������ʼ¼����Ƶ
// ������idx���豸��ţ�file���ļ�������a.h264��
// ���أ�TRUE����ʼ¼�ƣ�FALSE��¼��ʧ��
BOOL cm_start_record(UINT idx, const char *file)
{
	capvid[idx]->StartGrabVideo(file);
	return 0;
}

// ˵����ֹͣ¼����Ƶ
// ������idx���豸���
// ���أ���
void cm_stop_record(UINT idx)
{
	capvid[idx]->StopGrabVideo();
}

// ˵������������豸����
// ������idx���豸��ţ�width��ͼ���ȣ�height��ͼ��߶�
// ���أ���
BOOL cm_get_param(UINT idx, int *width, int *height)
{
	if (capvid[idx]->m_bConnected == TRUE)
	{
		*width = (int)capvid[idx]->m_lWidth;
		*height = (int)capvid[idx]->m_lHeight;
	}
	return FALSE;
}

#ifdef __cplusplus
}
#endif
