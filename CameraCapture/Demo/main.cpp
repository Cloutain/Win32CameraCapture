#include "../CameraCapture/CameraCapture.h"
#include <stdlib.h>

int main()
{
	UINT cm_idx, cm_cnt;
	int width, height, frame_rate;

	// ��ӡ�����豸�б�
	cm_cnt = cm_print_driver_list();

	system("pause");
	// ����ʹ��0��
	cm_idx = 0;

	// �������豸
	cm_open(cm_idx);

	// ��������豸����
	cm_get_param(cm_idx, &width, &height, &frame_rate);
	printf("%d X %d @ %d fps\n", width, height, frame_rate);

	// �������豸��ȡһ��ͼƬ��������
	cm_grab_to_clipboard(cm_idx);

	// �������豸��ȡһ��ͼƬ��BMP�ļ�
	cm_grab_to_bmp(cm_idx, L"aaa.bmp");
	cm_grab_to_bmp(cm_idx, L"bbb.bmp");

	// ��ʼ¼����Ƶ
	cm_start_record(cm_idx, L"Cam.avi");
	printf("¼����Ƶ��ʼ�����س�ֹͣ¼�ơ�����\n");
	getchar();
	// ֹͣ¼����Ƶ
	cm_stop_record(cm_idx);
	printf("��Ƶ¼�ƽ���\n");


	// �ر������豸
	cm_close(cm_idx);

	system("pause");
	return 0;
}
