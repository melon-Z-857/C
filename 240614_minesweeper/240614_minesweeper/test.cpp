#include "game.h"

//�˵�
void menu() {
	printf("----------ɨ����Ϸ-----------\n");
	printf("--------����1��ʼ��Ϸ--------\n");
	printf("----------����0�˳�----------\n");
	printf("-----------------------------\n");

}

//��Ϸ
void game()
{
	//��������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//����
	FindMine(mine, show, ROW, COL);
}

void test() {
	int a = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0: 
			printf("���˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (a);
}

int main() {
	test();
	return 0;
}