#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("写下你要找的数字");
	scanf("%d", &k);
	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
		{
			printf("找到了，下标为 %d\n", mid);
			break;
		}
	}if (left > right)
		printf("该数字不存在\n");
	return 0;
}
