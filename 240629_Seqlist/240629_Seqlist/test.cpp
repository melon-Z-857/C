#include"Seqlist.h"

//SL sl;
//
//void test01() {
//	SLInit(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPushBack(&sl, 5);
//	SLPrint(&sl);
//	SLPushFront(&sl, 0);
//	SLPrint(&sl);
//	SLPopBack(&sl);
//	SLPrint(&sl);
//	SLPopFront(&sl);
//	SLPrint(&sl);
//	SLInsert(&sl, 0, 0);
//	SLPrint(&sl);
//	SLInsert(&sl, 5, 5);
//	SLPrint(&sl);
//	SLErase(&sl, 0);
//	SLPrint(&sl);
//	SLErase(&sl, 4);
//	SLPrint(&sl);
//	SLErase(&sl, 1);
//	SLPrint(&sl);
//	int a = SLFind(&sl, 3);
//	printf("%d\n", SLFind(&sl, 3));
//	SLDestroy(&sl);
//
//}

contact con;
void menu() {
	printf("****************************************\n");
	printf("***************ͨѶ¼*******************\n");
	printf("******1.�����ϵ��  2.ɾ����ϵ��********\n");
	printf("******3.������ϵ��  4.�޸���ϵ��********\n");
	printf("******5.չʾ��ϵ��  0.�˳�ͨѶ¼********\n");
	printf("****************************************\n");
}
void test02() {
	int input = 0;
	InitContact(&con);
	do
	{
		menu();
		printf("��������Ҫ���еĲ���\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			printf("���˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input != 0);
	DestroyContact(&con);
}

int main() {
	//test01();
	test02();
	return 0;
}