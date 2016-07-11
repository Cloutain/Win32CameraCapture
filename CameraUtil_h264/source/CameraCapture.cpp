#include "CameraCapture.h"
#include "CaptureVideo.h"

CaptureVideo *capvid;

#ifdef __cplusplus
extern "C" {
#endif

// ˵������ʼ����������
// ��������
// ���أ���
void cm_init()
{
	capvid = new CaptureVideo();
}

// ˵����������������
// ��������
// ���أ���
void cm_exit()
{
	if (capvid)
	{
		capvid = new CaptureVideo();
		capvid = 0;
	}
}

// ˵������ӡ���������б�
// ��������
// ���أ�������������
UINT cm_print_driver_list()
{
	// ö���豸
	int i;
	HRESULT r = capvid->EnumAllDevices();
	for (i = 0; i < capvid->m_nCaptureDeviceNumber; i++)
	{
		wprintf(L"[%d] %s\n", i, capvid->m_pCapDeviceName[i]);
	}
	return UINT(i);
}

// ˵�����������豸
// �������豸���
// ���أ�TRUE���򿪳ɹ���FALSE����ʧ��
BOOL cm_open(UINT idx)
{
	capvid->OpenDevice(idx);
	if (capvid->m_bConnected == TRUE)
	{
		// ��������ͷ
		capvid->StartCapture();
		return TRUE;
	}
	return FALSE;
}

// ˵�����ر������豸
// ������idx���豸���
// ���أ���
void cm_close(UINT idx)
{
	if (capvid->m_bConnected == TRUE)
	{	
		// �ر�����ͷ
		capvid->StopCapture();
	}
	// �ر��豸[0]
	capvid->CloseDevice();
}

// ˵�����������豸��ȡһ��ͼƬ��BMP�ļ�
// ������idx���豸��ţ�file���ļ�������a.bmp��
// ���أ�TRUE����ȡ�ɹ���FALSE����ȡʧ��
BOOL cm_grab_to_bmp(UINT idx, WCHAR *file)
{
	capvid->GrabOneFrame(file);
	return TRUE;
}

// ˵������ʼ¼����Ƶ
// ������idx���豸��ţ�file���ļ�������a.h264��
// ���أ�TRUE����ʼ¼�ƣ�FALSE��¼��ʧ��
BOOL cm_start_record(UINT idx, const char *file)
{
	capvid->StartGrabVideo(file);
	return 0;
}

// ˵����ֹͣ¼����Ƶ
// ������idx���豸���
// ���أ���
void cm_stop_record(UINT idx)
{
	capvid->StopGrabVideo();
}

// ˵������������豸����
// ������idx���豸��ţ�width��ͼ���ȣ�height��ͼ��߶�
// ���أ���
BOOL cm_get_param(UINT idx, int *width, int *height)
{
	if (capvid->m_bConnected == TRUE)
	{
		*width = (int)capvid->m_lWidth;
		*height = (int)capvid->m_lHeight;
	}
	return FALSE;
}

#ifdef __cplusplus
}
#endif
