#include <stdio.h>


////���n��쳲�������
//int Fib1(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return (Fib1(n - 1) + Fib1(n - 2));
//}
//
//int Fib2(int n) {
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2) {
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d %d", Fib1(n), Fib2(n));
//
//	return 0;
//}
//
//
////��n��k�η�
//int pow(int n, int k) {
//	if (k > 1)
//		return (n * pow(n, k - 1));
//	else
//		return n;
//}
//
//int main() {
//	int n = 0;
//	int k = 0;
//	scanf_s("%d %d", &n, &k);
//	printf("%d��%d�η���%d\n", n, k, pow(n, k));
//
//	return 0;
//}
//
//
////����һ������ÿλ֮��
//int DigitSum(int n) {
//	if (n / 10 != 0)
//		return ((n % 10) + DigitSum(n / 10));
//	else
//		return n;
//}
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d��ÿһλ֮����%d", n, DigitSum(n));
//
//	return 0;
//}
//
////��n�Ľ׳�
//int F1(int n) {
//	if (n != 0)
//		return (n * F1(n - 1));
//	else
//		return 1;
//}
//
//int F2(int n) {
//	int a = 1;
//	while (n>0)
//	{
//		a *= n;
//		n--;
//	}
//	return a;
//}
//
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d�Ľ׳���%d\n", n, F1(n));
//	printf("%d�Ľ׳���%d\n", n, F2(n));
//
//	return 0;
//}


void print(int n) {
	if (n / 10 != 0) {
		print(n / 10);
		printf("%d ", (n % 10));
	}
	else {
		printf("%d ", n);
	}
}

int main() {
	int n = 0;
	scanf_s("%d", &n);
	print(n);

	return 0;
}