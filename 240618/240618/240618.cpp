#include<stdio.h>
#include<string.h>


////дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
////arr��һ������һά���顣
//void print(int(*p), int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		printf("%d ", *(p + i));
//	}
//}
//
//int main() {
//	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//
//	return 0;
//}

////ʵ��һ�������������ð������
//void Sort(int* p, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++) {
//			if (*(p + j) > *(p + j + 1)) {
//				int tmp = 0;
//				tmp = *(p + j);
//				*(p + j) = *(p + j + 1);
//				*(p + j + 1) = tmp;
//			}
//		}
//	}
//}
//
//int main() {
//	int arr[9] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
////���磺����s1 =AABCD��s2 = BCDAA������1
////����s1=abcd��s2=ACBD������0
//int F(char* p1, char* p2) {
//	size_t len = strlen(p1);
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < len; i++) {
//		int count = 0;
//		int j = 0;
//		for (j = 0; j < len; j++) {
//			if (strcmp((p1 + j), (p2 + j)) == 0) {
//				count++;
//			}
//		}
//		if (count == len) {
//			flag = 1;
//			break;
//		}
//		int k = 0;
//		if (i < len - 1) {
//			char tmp = *(p1);
//			for (k = 0; k < len - 1; k++) {
//				*(p1 + k) = *(p1 + k + 1);
//			}
//			*(p1 + k) = tmp;
//		}
//	}
//	return flag;
//}
//
//int main() {
//	char ch1[] = { "AABCD" };
//	char ch2[] = { "DAABC" };
//	F(ch1, ch2);
//	printf("%d", F(ch1, ch2));
//	return 0;
//}

void test(int(*p)[4], int sz) {

}

int main() {
	//0��ʾһ���������֣�1��ʾ������
	int arr[4][4] = { {0,1,1,1},{0,0,1,0},{0,0,0,1},{1,1,10} };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	test(arr,sz);

	return 0;
}