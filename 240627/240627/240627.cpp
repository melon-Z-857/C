#include<stdio.h>
#include <malloc.h>

////��ϰʹ�ö�̬�ڴ���ص�4�������������Թ۲졣malloc��calloc��realloc��free
//int main() {
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	for (int i = 0; i < 10; i++) {
//		p1[i] = i;
//	}
//
//	int* p2 = (int*)calloc(10, 4);
//
//	p1 = (int*)realloc(p1, static_cast<size_t>(20) * 4);
//
//	free(p1);
//  p1=NULL;
//	free(p2);
//  p2=NULL;
//
//	return 0;
//}

////ʹ��malloc����ģ�⿪��һ��3*5�����Ͷ�ά���飬���ٺú�ʹ�ö�ά������±������ʽ�����ʿռ䡣
//int main() {
//	int(*arr)[5] = (int(*) [5])malloc(60);
//	if (arr != NULL) {
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 5; j++) {
//				arr[i][j] = j + i;
//			}
//		}
//	}
//	free(arr);
//  arr=NULL;
//
//	return 0;
//}

////ʹ���������֪ʶ��дһ�������жϵ�ǰ�����Ǵ�˻���С�ˣ������С�˷���1������Ǵ�˷���0.
//int test(int*p) {
//	if (*p == 0x11223300) {
//		return 1;
//	}
//	else if (*p == 0x00223344) {
//		return 0;
//	}
//}
//
//int main() {
//	union Un
//	{
//		char ch;
//		int n;
//	};
//	Un un = { 0 };
//	un.n = 0x11223344;
//	un.ch = 0x00;
//	printf("%d\n", test(&(un.n)));
//	return 0;
//}

