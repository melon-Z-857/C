#include"Heap.h"

void test01() {
	Heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 2);
	HeapPush(&hp, 4);
	HeapPush(&hp, 1);
	HeapPush(&hp, 3);
	HeapPush(&hp, 0);

	HeapPop(&hp);
}

void test02() {
	int a[] = { 3,65,77,12,2,43,98,55 };

	//a[]�Ž����ȴ����һ�����ڵ�(n-1)/2��λ�õ����ڵ��λ�����µ�����С�ѣ���ʱ���ڵ������С������
	// Ȼ��Ѹ��ڵ�����һ���ڵ㽻��λ�ã�αɾ�����һ���ڵ㣬�����µ�����С���ҳ���С����...
	HeapSort(a, sizeof(a) / sizeof(a[0]));
}

void CreateNDate()
{
	// ������
	int n = 20;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 100;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void test03() {
	CreateNDate();
	printf("��������Ҫ����ֵ�������ĸ���k:\n");
	int k;
	scanf_s("%d", &k);
	PrintTopK(k);
}

int main() {
	//test01();

	test02();

	//test03();

	return 0;
}