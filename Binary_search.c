#include<stdio.h>
#define MANNUM 100
int Binary_search(int T[], int n, int x) {
	int left, right, mid;
	left = 0;
	right = n - 1;
	while (left <= right){
		mid = (left + right) / 2;
		if(T[mid] == x) {
			return mid;
		}
		else{
			if(T[mid] > x) {
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
	}
	return -1;
}

int main(){
	int T[MANNUM];
	int i, n, x, result;
	printf("请输入序列T的元素个数：");
	scanf("%d",&n);
	printf("请输入序列T的元素值：");
	for(i = 0;i < n;i++){
		scanf("%d", &T[i]);
	}
	printf("请输入需要查找的值：");
	scanf("%d",&x);
	result = Binary_search(T, n, x);
	printf("查找结果为：%d", result);
	return 0;
}
