#include <iostream>
using namespace std;
#define maxSize 100
int color[maxSize];
int scheme_num = 0;		//统计着色方案的数量
bool ok(int k,int c[][maxSize]){//判断顶点k的着色是否发生冲突
	int i;
	for(i=1;i<k;i++){
		if(c[k][i]==1 && color[i]==color[k])
			return false;
	}
	return true;
}
  
void graphColor(int n,int m,int c[][maxSize]){
	int i,k;
	for(i=1;i<=n;i++){
		color[i]=0;
	}
	k=1;
	while(k>=1){
		color[k]=color[k]+1;
		while(color[k]<=m)
		if(ok(k,c))
			break;
		else 
			color[k]=color[k]+1;//搜索下一个颜色
		if(color[k]<=m && k==n){
			scheme_num++;
			for(i=1;i<=n;i++) {
				cout<<color[i]<<"  ";
			}
			cout<<endl;
		}
		else if(color[k]<=m && k<n)
			k=k+1;//处理下一个顶点
		else{
			color[k]=0;
			k=k-1;//回溯
		}
	}
}
int main(){
    int i,n,m,edge_num,v1,v2;
	int c[maxSize][maxSize];	//存储n个顶点的无向图的数组
	cout<<"请输入顶点的个数：";
	cin>>n;
	cout<<"请输入颜色的个数：";
	cin>>m;
	cout<<"请输入边的个数：";
	cin>>edge_num;
	cout<<"请依次输入各边的两个顶点："<<endl;
	for(i = 0;i < edge_num;i++){
		cin>>v1>>v2;
		c[v1][v2] = 1;
		c[v2][v1] = 1;
	}
	cout<<"该组顶点的着色方案为(按1-"<<n<<"排序)"<<endl;
    graphColor(n,m,c);
	if(scheme_num == 0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"当顶点个数为"<<n<<"，颜色个数为"<<m<<"时，共有"<<scheme_num<<"个着色方案";
	}
	return 0;
}