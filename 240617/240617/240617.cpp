#include<stdio.h>
#include<string.h>

////ʵ��һ�����������������ַ����е�k���ַ�
////����
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
//void LeftTurn(char * ch, int n,int len) {
//	while (n > 0) {
//		char tmp1 = *ch;
//		int len1 = len;
//		char* p1 = ch;
//		char* p2 = ch + 1;
//		while (len - 1 > 0) {
//			char tmp2 = 0;
//			tmp2 = *p1;
//			*p1 = *p2;
//			*p2 = tmp2;
//			p1++;
//			p2++;
//			len--;
//		}
//		len = len1;
//		*(ch + len1 - 1) = tmp1;
//		n--;
//	}
//}
//
//int main() {
//	char ch[] = { "abcdefghijk" };
//	int n = 0;
//	int len = 0;
//	len = strlen(ch);
//	printf("��������Ҫ�����ĸ���\n");
//	scanf_s("%d", &n);
//	LeftTurn(ch,n,len);
//	printf("����������Ϊ%s\n", ch);
//
//	return 0;
//}

////ģ��ʵ�ֿ⺯��strlen
//size_t my_strlen(char* p) {
//	int count = 0;
//	while (*p) {
//		count++;
//		p++;
//	}
//	return count;
//}
//
//int main() {
//	char ch[] = { "abcde" };
//	printf("%zd\n", my_strlen(ch));
//	return 0;
//}

////��������ʹ����ȫ����λ��ż��ǰ�档
//void sort(int* p1) {
//	int arr2[9] = { 0 };
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 9; i++) { 
//		if ((*(p1 + i)) % 2 == 0) {
//			count++;
//			arr2[9 - count] = *(p1 + i);
//		}
//		else {
//			arr2[i-count] = *(p1 + i);
//		}
//	}
//	int j = 0;
//	for (j = 0; j < 9; j++) {
//		*(p1 + j) = arr2[j];
//	}
//}
//
//int main() {
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	sort(arr1);
//	int i = 0;
//	for (i = 0; i < 9; i++) {
//		printf("%d ", arr1[i]);
//	}
//
//	return 0;
//}