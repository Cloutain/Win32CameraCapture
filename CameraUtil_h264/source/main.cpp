#include "CaptureVideo.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	CaptureVideo capvid;

	// ö���豸
	HRESULT r = capvid.EnumAllDevices();
	for (int i = 0; i < capvid.m_nCaptureDeviceNumber; i++)
	{
		wprintf(L"[%d] %s\n", i, capvid.m_pCapDeviceName[i]);
	}
	// ���豸[0]
	capvid.OpenDevice(0);
	if (capvid.m_bConnected == TRUE)
	{
		// ��������ͷ
		capvid.StartCapture();
		// ����һ��ͼƬ
		Sleep(500);
		capvid.GrabOneFrame(L"aaa.bmp");
		// ������Ƶ�ļ�
		capvid.StartGrabVideo("vvv.h264");
		Sleep(10000);
		capvid.StopGrabVideo();
		// �ر�����ͷ
		capvid.StopCapture();
	}
	// �ر��豸[0]
	capvid.CloseDevice();

	system("pause");
	return 0;
}
