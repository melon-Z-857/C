#include<stdio.h>
#include<string.h>
#define n 3

////��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
////Ҫ��ʱ�临�Ӷ�С��O(N);
//int Find(int arr[n][n], int N, int A) {
//	int flag = 0;
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		if (A < arr[i][i])
//			break;
//		else if (A == arr[i][i])
//			flag = 1;
//	}
//	if (flag == 0) {
//		int j = 0;
//		for (j = 0; j < i; j++) {
//			int k = 0;
//			for (k = i; k < n; k++) {
//				if (A == arr[j][k]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//	}
//	if (flag == 0) {
//		int j = 0;
//		for (j = i; j < N; j++) {
//			int k = 0;
//			for (k = 0; k < i; k++) {
//				if (A == arr[j][k]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//	}
//	if (flag == 1)
//		return 1;
//	else
//		return 0;
//}
//int main() {
//	int arr[n][n] = { {1,2,3},{2,3,5},{3,5,6} };
//	int a = 0;
//	scanf_s("%d", &a);
//	Find(arr, n, a);
//	printf("%d\n", Find(arr, n, a));
//
//	return 0;
//}

////�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
////����Ϊ4�����ɷ��Ĺ���:
////A˵�������ҡ�
////B˵����C��
////C˵����D��
////D˵��C�ں�˵
////��֪3����˵���滰��1����˵���Ǽٻ���
////�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//int test(int arr[4][4], int sz) {
//	int flag = 0;//��һ��������
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		int arr1[4] = { 1,1,1,1 };//������������1���������ɣ�һ��ʼ�������ɣ����ݳ�����Ϊ0����ʾһ���������֣����ֻ��1��1��3��0
//		int j = 0;
//		for (j = 0; j < sz; j++) {
//			if (j != i) {
//				int k = 0;
//				for (k = 0; k < sz; k++) {
//					if (arr[j][k] == 0) {
//						arr1[k] = 0;
//					}
//				}
//			}
//		}
//		int count = 0;//���ָ���
//		int l = 0;
//		for (l = 0; l < sz; l++) {
//			if (arr1[l] == 1) {
//				flag = l;
//			}
//			count += arr1[l];
//		}
//		if (count == 1) {
//			return flag;
//		}
//	}
//}
//int main() {
//	int arr[4][4] = { {0,1,1,1},{0,0,1,0},{0,0,0,1},{1,1,1,0} };//4��һά����ֱ����ABCD4���˵ĳ�����0����һ���������֣�1��ʾ������
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	test(arr, sz);
//	printf("%d\n", test(arr, sz));
//
//	return 0;
//}

////ת�Ʊ�ͻص�����
//void menu() {
//	printf("-------------------------\n");
//	printf("-------1.Add 2.Sub-------\n");
//	printf("-------3.Mul 4.Div-------\n");
//	printf("-------0.Exit------------\n");
//	printf("---------��ѡ��----------\n");
//	printf("-------------------------\n");
//}
//
//int Add(int x, int y) {
//	return (x + y);
//}
//int Sub(int x, int y) {
//	return (x - y);
//}
//int Mul(int x, int y) {
//	return (x * y);
//}
//int Div(int x, int y) {
//	return (x / y);
//}
//int(*pf[5])(int, int) = { 0,Add,Sub,Mul,Div};
//void Calc(int(*pf)(int, int)) {
//	int x = 0;
//	int y = 0;
//	printf("����������������\n");
//	scanf_s("%d %d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//
//int main() {
//	int input = 0;
//	do {
//		menu();
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	}while(input);
//
//	return 0;
//}

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
//���磺
//�������Ԫ���ǣ�1��2��3��4��5��1��2��3��4��6
//ֻ��5��6ֻ����1�Σ�Ҫ�ҳ�5��6.
void Find(int arr[],int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		int flag1 = 0;
		int flag2 = 0;
		int j = 0;
		for (j = 0; j < sz; j++) {
			if (j != i) {
				flag2 = 1;
				if (arr[i] == arr[j]) {
					flag1 = 1;
				}
			}
		}
 		if (flag1 == 0 && flag2 ==1) {
			printf("%d ",arr[i]);
		}
	}
}

int main() {
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find(arr,sz);

	return 0;
}