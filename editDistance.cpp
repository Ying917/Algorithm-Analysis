#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define maxSize 100		//源串和目标串的长度都小于2000
#define min(x,y) ((x)>(y)? (y) :(x))	//定义取最小值函数min
int dis[maxSize][maxSize];	//用于记录操作数的矩阵

using namespace std;
int editDistance(string& s,string& t){
	int s_len = s.length();		//记录源串的字符长度
    int t_len = t.length();		//记录目标串的字符长度
    int i = 0, j = 0;

    for(i = 1;i <= s_len;i++){
		//初始化边界
        dis[i][0] = i;
	}
    for(j = 1;j <= t_len;j++){
		//初始化边界
        dis[0][j] = j;
	}
    for(i = 1;i <= s_len;i++){
        for(j = 1;j <= t_len;j++){
		//计算操作次数
            if(s[i-1] == t[j-1]){
			//若源串当前位置的字符与目标串当前位置的字符相同，则操作数不变
                dis[i][j] = dis[i-1][j-1];
            }
            else{
			//以下情况分别为源串当前位置的字符不再目标串内；源串当前位置的字符在目标串的t[1,...,t_len-1]中；源串当前位置的字符与目标串当前位置的字符对应，但不同	
                dis[i][j] = min(min(dis[i-1][j]+1,dis[i][j-1]+1),dis[i-1][j-1]+1);
            }
        }
    }
    return dis[s_len][t_len];
}

int main(){
    string s,t;
	cout<<"请输入源串：";
	cin>>s;
	cout<<"请输入目标串：";
	cin>>t;
	cout<<"\n当源串为"<<s<<"，目标串为"<<t<<"时，最小操作数为"<<editDistance(s,t)<<endl;
	getchar();
    return 0;
}
