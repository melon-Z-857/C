#include <stdio.h>

//// arr �ǲ��ҵ�����
////left ��������±�
////right ��������±�
////key Ҫ���ҵ�����
//int bin_search(int arr[10], int left, int right, int key)
//{
//	int flag = 0;
//	int tag = 0;
//	while (left <= right)
//	{
//		flag = (left + right) / 2;
//		if (arr[flag] < key)
//			left = flag + 1;
//		else if (arr[flag] > key)
//			right = flag - 1;
//		else
//		{
//			tag = 1;
//			break;
//		}
//	}
//	if (tag == 1)
//		return flag;
//	else
//		return -1;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int bin_search(int arr[10], int left, int right, int key);
//	printf("%d", bin_search(arr, 0, 9, 11));
//	return 0;
//}
