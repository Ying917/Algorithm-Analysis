#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void LCS(string& x,string& y,string& lcs){
	int c[100][100];
	for (int i = x.length() - 1; i >= 0; i--){  
		for (int j = y.length() - 1; j >= 0; j--){  
			if (x[i] == y[j])  
				c[i][j] = c[i + 1][j + 1] + 1;
			else  
				c[i][j] = max(c[i + 1][j], c[i][j + 1]);
		}
	}
	int i =0,j = 0;
	while (i< x.length()&&j<y.length()){
		if (x[i]==y[j]){
			lcs += x[i];
			i++;
			j++;
		}
		else if (c[i+1][j] >= c[i][j+1])
			i++;
		else 
			j++;
	}
}

int main() {
	string str1,str2,lcs;
	cout<<"请输入两个字符串：";
	cin>>str1>>str2;
	LCS(str1,str2,lcs);
	cout<<"最长公共子序列为："<<lcs<<endl;
}