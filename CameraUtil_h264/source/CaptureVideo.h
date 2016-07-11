#ifndef __CAPTUREVIDEO_H__
#define __CAPTUREVIDEO_H__
#include "Common.h"
#include "GrabberCallback.h"

class CaptureVideo
{
public:
	CaptureVideo();
	~CaptureVideo();
	// ö��������Ƶ�豸
	HRESULT EnumAllDevices();
	// �򿪡��ر��豸
	HRESULT OpenDevice(int deviceID);
	void CloseDevice();
	// ������ֹͣ����
	HRESULT StartCapture();
	void StopCapture();
	// ����һ��ͼƬ
	void GrabOneFrame(const WCHAR *pFileName);
	// ������ֹͣ������Ƶ�ļ�
	void StartGrabVideo(const char *pFileName);
	void StopGrabVideo();
public:
	int m_nCaptureDeviceNumber;           //Device Count
	TCHAR m_pCapDeviceName[10][MAX_PATH]; //the Device name
	BOOL m_bConnected;
	LONG m_lWidth, m_lHeight;
private:
	HRESULT InitializeEnv();
	HRESULT BindFilter(int deviceID, IBaseFilter **pBaseFilter);
	void CloseInterface();
private:
	IGraphBuilder *m_pGraphBuilder;
	ICaptureGraphBuilder2 *m_pCaptureGB;
	IMediaControl *m_pMediaControl;
	IBaseFilter *m_pDevFilter;
	ISampleGrabber *m_pSampGrabber;  
	IMediaEventEx *m_pMediaEvent;
	IVideoWindow *m_pVideoWindow;
};

#endif  //__CAPTUREVIDEO_H__
