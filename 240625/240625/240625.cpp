#include<stdio.h>

int main() {
	int a = 1;
	char* p = (char*)&a;
	if (*p == 0x00)
		printf("��˴洢");
	else if(*p==0x01)
		printf("С�˴洢");

	return 0;
}