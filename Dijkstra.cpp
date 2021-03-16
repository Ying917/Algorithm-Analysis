#include<stdio.h>
#define V 8
#define Inf 10000
int main(){
	int G[V][V] = {{0,1,Inf,Inf,Inf,Inf,Inf,Inf},{Inf,0,Inf,2,Inf,Inf,Inf,Inf},{2,Inf,0,Inf,Inf,Inf,Inf,Inf},{Inf,Inf,1,0,Inf,8,Inf,Inf},
					{Inf,Inf,Inf,2,0,Inf,2,Inf},{Inf,Inf,Inf,Inf,2,0,Inf,Inf},{Inf,Inf,Inf,Inf,Inf,3,0,3},{Inf,Inf,Inf,Inf,Inf,2,Inf,0}};
	int dis[V];//��¼����a�����������С����
	int S[V];//p��Ƿ��ʹ��Ľڵ�
	int i, j;
	int min,temp;
	for(i = 0;i < V;++i){
		//��ʼ����¼�����ѱ����ʵ������dis����
		S[i] = 0;
		dis[i] = G[0][i];
	}
	S[0] = 1;

	for(i = 1;i < V;i++){
		min = Inf;
		for(j = 0;j < V;j++){
			if (!S[j] && dis[j] < min){ 
			//Ѱ�Ҿ��붥��a����ģ���δ�����ʹ��Ķ���
				min = dis[j];
				temp = j;
			}
		}
		S[temp] = 1;
		for(j = 0;j < V;j++){
			if(G[temp][j] < Inf) {
				if(G[temp][j] + dis[temp] < dis[j]){
					dis[j] = G[temp][j] + dis[temp];
				}
			}
		}
	}

	for (i = 0; i < V-1; i++){
		//����Ӷ���a�������������̾���
		printf("%d-->", dis[i]);
	}
	printf("%d\n", dis[V-1]);
	printf("�ʶ���a������h����̾���Ϊ��%d\n",dis[V-1]);
	getchar();
	return 0;
}