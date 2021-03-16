#include<stdio.h>
#define V 4  //������Ϊ4
#define Inf 10000  //��ʾ������䲻���ڱ�
int main(){
	int D[V][V] = {{0,2,6,4},{Inf,0,3,Inf},{7,Inf,0,1},{5,Inf,12,0}};  //��������ľ�����󣬱�ʾͼ�и����ڵ�֮���·��
	int path[V][V];  //��ʾͼ�к�̽ڵ����
	int i, j, k, count;
	
	for(i= 0;i < V;++i){ 
		//���������㣬��path���г�ʼ��
		count = 0;
		for(j = 0;j < V;++j){
			if(i != j){
				path[i][j] = count;
			}
			else{
				path[i][j] = -1;
			}
			++count;
		}
	}
	
	//���ϼ��붥�㣬���¾���
	for(k = 0;k < V;++k){
		for(i = 0;i < V;++i){
			for(j = 0;j < V;++j){
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}

	printf("����֮�����̾������Ϊ��\n");
	for(i = 0;i < V;++i) {
		for(j = 0;j < V;++j) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}
	getchar();
}