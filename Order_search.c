#include<stdio.h>
#define MANNUM 100
int Order_search(int T[], int n, int x) {
	int i;
	for (i = 0; i < n; i++){
		if (T[i] == x) {
			return i;
		}
	}
	return -1;
}

int main(){
	int T[MANNUM];
	int i, n, x, result;
	printf("����������T��Ԫ�ظ�����");
	scanf("%d",&n);
	printf("����������T��Ԫ��ֵ��");
	for(i = 0;i < n;i++){
		scanf("%d", &T[i]);
	}
	printf("��������Ҫ���ҵ�ֵ��");
	scanf("%d",&x);
	result = Order_search(T, n, x);
	printf("���ҽ��Ϊ��%d", result);
	return 0;
}
