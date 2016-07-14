#include "../source/CameraCapture.h"

#include <stdio.h>

void run(UINT cm_idx)
{
	int width, height;
	// ��ʼ����������
	cm_init(cm_idx);
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
	cm_exit(cm_idx);
}

int main()
{
	UINT cm_idx, cm_cnt;

	// ��ӡ�����豸�б�
	cm_cnt = cm_print_driver_list();
	run(0);
	run(1);

	system("pause");
	return 0;
}
