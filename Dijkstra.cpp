#include<stdio.h>
#define V 8
#define Inf 10000
int main(){
	int G[V][V] = {{0,1,Inf,Inf,Inf,Inf,Inf,Inf},{Inf,0,Inf,2,Inf,Inf,Inf,Inf},{2,Inf,0,Inf,Inf,Inf,Inf,Inf},{Inf,Inf,1,0,Inf,8,Inf,Inf},
					{Inf,Inf,Inf,2,0,Inf,2,Inf},{Inf,Inf,Inf,Inf,2,0,Inf,Inf},{Inf,Inf,Inf,Inf,Inf,3,0,3},{Inf,Inf,Inf,Inf,Inf,2,Inf,0}};
	int dis[V];//记录顶点a到各顶点的最小距离
	int S[V];//p标记访问过的节点
	int i, j;
	int min,temp;
	for(i = 0;i < V;++i){
		//初始化记录顶点已被访问的数组和dis数组
		S[i] = 0;
		dis[i] = G[0][i];
	}
	S[0] = 1;

	for(i = 1;i < V;i++){
		min = Inf;
		for(j = 0;j < V;j++){
			if (!S[j] && dis[j] < min){ 
			//寻找距离顶点a最近的，且未被访问过的顶点
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
		//输出从顶点a到其他顶点的最短距离
		printf("%d-->", dis[i]);
	}
	printf("%d\n", dis[V-1]);
	printf("故顶点a到顶点h的最短距离为：%d\n",dis[V-1]);
	getchar();
	return 0;
}