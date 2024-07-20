#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	//���ļ�
	FILE* p1 = fopen("data.txt", "r");
	if (p1 == NULL) {
		perror("fopen:");
		return 1;
	}
	FILE* p2 = fopen("data_copy.txt", "w");
	if (p2 == NULL) {
		perror("fopen:");
		return 1;
	}

	//��/д�ļ�
	int ch = 0;
	for (; (ch = fgetc(p1)) != EOF;) {
		fputc(ch, p2);
	}

	//�ر��ļ�
	fclose(p1);
	fclose(p2);
	p1 = NULL;
	p2 = NULL;

	return 0;
}