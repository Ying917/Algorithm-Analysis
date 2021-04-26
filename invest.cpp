#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main() {
	int m, n,	//m万元  n个项目
		f[MAX][MAX],		//存储初始收益
		dp[MAX][MAX] = {0},	//记录局部最大收益
		invest[MAX][MAX];	//用于记录投资方案
	
	cout<<"请输入投资金额（万元）和项目个数：";
	cin>>m>>n;
	cout<<"请分别输入投资金额为0-"<<m<<"万元时"<<n<<"个项目各自的收益金额："<<endl;
	for(int i = 0; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin>>f[j][i];
		}
	}

	//动态规划
	for (int k = 1; k <= n; k++) 
		for (int x = 1; x <= m; x++)
			for (int i = 0; i <= x; i++)
				if (dp[k - 1][x - i] + f[k][i] >= dp[k][x]) {
					dp[k][x] = dp[k - 1][x - i] + f[k][i];
					invest[k][x] = i;
				}

	//输出局部最大收益及其对应的投资金额（如文档中计算结果表格）
	for (int x = 1; x <= m; x++) {
		for (int k = 1; k <= n; k++)
			cout << dp[k][x] << " "<<invest[k][x]<<" ";
		cout << endl;
	}

	cout <<"最大收益为："<< dp[n][m] << endl;
	cout << "分配方案为："<<endl;
	int sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "分配给第" << i << "个项目" << invest[i][sum] << "万元"<<endl;
		sum -= invest[i][sum];
	}
}