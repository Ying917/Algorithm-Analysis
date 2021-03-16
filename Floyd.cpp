#include<stdio.h>
#define V 4  //顶点数为4
#define Inf 10000  //表示两顶点间不存在边
int main(){
	int D[V][V] = {{0,2,6,4},{Inf,0,3,Inf},{7,Inf,0,1},{5,Inf,12,0}};  //输入最初的距离矩阵，表示图中各个节点之间的路径
	int path[V][V];  //表示图中后继节点矩阵
	int i, j, k, count;
	
	for(i= 0;i < V;++i){ 
		//遍历各顶点，对path进行初始化
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
	
	//不断加入顶点，更新矩阵
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

	printf("顶点之间的最短距离矩阵为：\n");
	for(i = 0;i < V;++i) {
		for(j = 0;j < V;++j) {
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}
	getchar();
}