#include <stdio.h>


//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣�
//���������a��ƿ�Ӹ�����ÿ�γ���2��������������ˮ���������1,��ô�������ƿ�Ӹ���������������1��ֻ��ƿ�Ӹ�������2��������
//int MostDrink(int a) {
//	int i = 0;
//	int sum = a;
//	while (a>=2) {
//		if (a % 2 == 1) {
//			a = a / 2;
//			sum += a;
//			a += 1;
//		}
//		else {
//			a = a / 2;
//			sum += a;
//		}
//	}
//	return sum;
//}
//int main() {
//	int a = 0;
//	printf("��������ˮ��Ǯ��\n");
//	scanf_s("%d", &a);
//	printf("%dԪǮ�����Ժ�%dƿ��ˮ\n", a, MostDrink(a));
//	return 0;
//}
//
// 
// 
// 
//
//int main() {
//	printf("      *      \n");
//	printf("     ***     \n");
//	printf("    *****    \n");
//	printf("   *******   \n");
//	printf("  *********  \n");
//	printf(" *********** \n");
//	printf("*************\n");
//	printf(" *********** \n");
//	printf("  *********  \n");
//	printf("   *******   \n");
//	printf("    *****    \n");
//	printf("     ***     \n");
//	printf("      *      \n");
//
//}
//
// 
// 
// 
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�������*/
//int Number_Of_Daffodils(int i) {
//	int j = i;
//	int count1 = 1;
//	int sum = 0;
//	while (j)//ͳ��λ��
//	{
//		if (j / 10 != 0) {
//			count1++;
//		}
//		j = j / 10;
//	}
//	j = i;
//	int count2 = count1;
//	while (j)
//	{
//		count1 = count2;
//		int a = 0;
//		a = j % 10;
//		int b = a;
//		j = j / 10;
//		while (count1-1)
//		{
//			a = b * a;
//			count1--;
//		}
//		sum += a;
//	}
//	if (sum == i)
//		return 1;
//	else
//		return 0;
// }
//int main() {
//	int i = 0;
//	for (i = 0; i <= 100000; i++) {
//		if (Number_Of_Daffodils(i))
//			printf("%d ", i);
//	}
//	return 0;
//}
//
// 
//// ��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//// ���磺2 + 22 + 222 + 2222 + 22222
////��
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//
//
//	scanf_s("%d%d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}
////�ҵĴ���
//int main() {
//	int j = 0;
//	int a = 0;
//	scanf_s("%d", &a);
//	int sum = a;
//	for (j = 1; j <= 5; j++) {
//		int b = a;
//		int i = 0;
//		for (i = 1; i <= j; i++) {
//			b = a * 10;
//			sum += b;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}