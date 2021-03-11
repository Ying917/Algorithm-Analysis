#include<iostream>
using namespace std;
#define MAXNUM 200  
#define MAXCOST 1000000;

int graph[MAXNUM][MAXNUM];

void prim(int graph[MAXNUM][MAXNUM], int n){
	//prim算法构造最小生成树
	int lowcost[MAXNUM];
	int mst[MAXNUM];
	int i, j, min, minnum, sum;
	sum = 0;
	for(i = 2;i <= n;i++){
		lowcost[i] = graph[1][i];	//lowcost中存放顶点1可达点的路径长度 
		mst[i] = 1 ;	//初始化，将1作为起始点 
	}
	mst[1] = 0;
	for(i = 2;i <= n;i++){
		min = MAXCOST;
		minnum = 0;
		for(j = 2;j <= n;j++){
			if(lowcost[j] < min && lowcost[j] != 0){
				min = lowcost[j];	//找出权值最短的路径长度 
				minnum = j;		//找出最小的num 
			}
		}
		cout << "<" << mst[minnum] << "," << minnum << "> = " << min << endl;
		sum += min;		//求最小权值之和 
		lowcost[minnum] = 0;	//重置最短路径的值为0 
		for(j = 2;j <= n;j++){
			if(graph[minnum][j] < lowcost[j]){ 
				//对这一点直达的顶点进行路径更新 
				lowcost[j] = graph[minnum][j];
				mst[j] = minnum;
			}
		}
	}
	cout << "最小权值之和为：" << sum << endl;
}
int main()
{
	int i, j, k, V, E;
	int weight;
	cout<<"请输入顶点与边的数量："<<endl;
    cin >> V >> E;

	for(i = 1;i <= V;i++){
		//初始化图 
		for(j = 1;j <= V;j++){
			graph[i][j] = MAXCOST;
		}
	}
	cout<<"请输入各边的起始点、终点、权重："<<endl;
	for(k = 0;k < E;k++){
		cin >> i >> j >> weight;
		graph[i][j] = weight;
		graph[j][i] = weight;
	}
	prim(graph, V);
	return 0;
}