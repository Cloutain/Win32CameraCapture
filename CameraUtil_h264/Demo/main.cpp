#include "../source/CameraCapture.h"

#include <stdio.h>

int main()
{
	UINT cm_idx, cm_cnt;
	int width, height;

	// ��ʼ����������
	cm_init();

	// ��ӡ�����豸�б�
	cm_cnt = cm_print_driver_list();
	// ����ʹ��0��
	cm_idx = 0;

	// �������豸
	cm_open(cm_idx);

	// ��������豸����
	cm_get_param(cm_idx, &width, &height);
	printf("%d X %d\n", width, height);

	// �������豸��ȡһ��ͼƬ��BMP�ļ�
	Sleep(500);
	cm_grab_to_bmp(cm_idx, L"aaa.bmp");
	Sleep(500);
	cm_grab_to_bmp(cm_idx, L"bbb.bmp");
	
	// ��ʼ¼����Ƶ
	cm_start_record(cm_idx, "Cam.h264");
	printf("¼����Ƶ��ʼ�����س�ֹͣ¼�ơ�����\n");
	getchar();
	// ֹͣ¼����Ƶ
	cm_stop_record(cm_idx);
	printf("��Ƶ¼�ƽ���\n");

	// �ر������豸
	cm_close(cm_idx);

	// ������������
	cm_exit();

	system("pause");
	return 0;
}
