#include <stdio.h>
#include <stdbool.h>

////ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
////�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
//void multiplication_table(int a)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= a; i++) {
//		for (j = 1; j <= a; j++) {
//			if(j<=i)
//				printf("%d*%d=%d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	multiplication_table(9);
//	return 0;
//}
//
//
//bool is_leap_year(int year) {
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		return true;
//	else
//		return false;
//}
//int main() {
//	int year = 0;
//	scanf_s("%d", &year);
//	if (is_leap_year(year))
//		printf("%d������", year);
//	else
//		printf("%d��������", year);
//	return 0;
//}
//
//
////ʵ��һ������is_prime���ж�һ�����ǲ���������
////��������ʵ�ֵ�is_prime��������ӡ100��200֮���������
//bool is_prime(int a) {
//	int i = 0;
//	int tag = 0;
//	for (i = 2; i < a; i++) {
//		if (a % i == 0) {
//			tag = 1;
//			break;
//		}
//	}
//	if (tag == 1)
//		return false;
//	else
//		return true;
//}
//int main() {
//	int i = 0;
//	for (i = 100; i <= 200; i++) {
//		if (is_prime(i))
//			printf("%d ", i);
//	}
//	return 0;
//}


//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
void init(int arr[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
	}
}

void print(int arr[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[]) {
	int i = 0;
	int temp = 0;
	for (i = 0; i < 5; i++) {
		arr[i] = temp;
		arr[i] = arr[9 - i];
		arr[9 - i] = temp;
	}
}
int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	print(arr);
	reverse(arr);
	print(arr);
	init(arr);
	print(arr);

	return 0;
}