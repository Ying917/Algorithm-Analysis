#include<iostream>
using namespace std;
#define maxsize 100
int V[maxsize][maxsize];
int x[maxsize];

int max(int x, int y){
	return (x > y)?x:y;
}

int packet0_1(int n, int w[], int v[],int B){
	int i, j;
	for ( i = 0; i <=n; i++){
		V[i][0] = 0;
	}

	for ( j = 0; j <=B; j++){
		V[0][j] = 0;
	}

	for (i = 1; i <= n; i++){
		for ( j = 1; j <= B; j++)
		{
			if (j<w[i-1]){
				V[i][j] = V[i - 1][j];
			}
			else{
				V[i][j] = max(V[i - 1][j], V[i-1][j-w[i-1]]+v[i-1]);
			}
		}
	}

	for (j = B,i = n; i > 0; i--){
		if (V[i][j] > V[i-1][j]){
			x[i-1] = 1;
			j = j - w[i-1];
		}
		else{
			x[i-1] = 0;
		}
	}
	return V[n][B];
}

int main(){
	int w[maxsize];		//物品重量
	int v[maxsize];		//物品价值
	int n;		//物品数量
	int B;		//背包容量
	cout<<"请输入物品的数量n 和 背包的容量B：";
	cin>>n>>B;
	cout<<"请依次输入物品的重量和价值："<<endl;
	for(int i = 0;i < n;i++){
		cin>>w[i]>>v[i];
	}
	cout << "背包的最大价值为:" << packet0_1(n, w, v, B) << endl;
	cout << "装入背包的物品是:";
	for (int i = 0; i < n; i++){
		if (x[i]==1){
			cout << "物品" << i + 1<<"   ";
		}
	}
	printf("\n");
	cout << endl;
	return 0;
}