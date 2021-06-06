#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define maxSize 100		//Դ����Ŀ�괮�ĳ��ȶ�С��2000
#define min(x,y) ((x)>(y)? (y) :(x))	//����ȡ��Сֵ����min
int dis[maxSize][maxSize];	//���ڼ�¼�������ľ���

using namespace std;
int editDistance(string& s,string& t){
	int s_len = s.length();		//��¼Դ�����ַ�����
    int t_len = t.length();		//��¼Ŀ�괮���ַ�����
    int i = 0, j = 0;

    for(i = 1;i <= s_len;i++){
		//��ʼ���߽�
        dis[i][0] = i;
	}
    for(j = 1;j <= t_len;j++){
		//��ʼ���߽�
        dis[0][j] = j;
	}
    for(i = 1;i <= s_len;i++){
        for(j = 1;j <= t_len;j++){
		//�����������
            if(s[i-1] == t[j-1]){
			//��Դ����ǰλ�õ��ַ���Ŀ�괮��ǰλ�õ��ַ���ͬ�������������
                dis[i][j] = dis[i-1][j-1];
            }
            else{
			//��������ֱ�ΪԴ����ǰλ�õ��ַ�����Ŀ�괮�ڣ�Դ����ǰλ�õ��ַ���Ŀ�괮��t[1,...,t_len-1]�У�Դ����ǰλ�õ��ַ���Ŀ�괮��ǰλ�õ��ַ���Ӧ������ͬ	
                dis[i][j] = min(min(dis[i-1][j]+1,dis[i][j-1]+1),dis[i-1][j-1]+1);
            }
        }
    }
    return dis[s_len][t_len];
}

int main(){
    string s,t;
	cout<<"������Դ����";
	cin>>s;
	cout<<"������Ŀ�괮��";
	cin>>t;
	cout<<"\n��Դ��Ϊ"<<s<<"��Ŀ�괮Ϊ"<<t<<"ʱ����С������Ϊ"<<editDistance(s,t)<<endl;
	getchar();
    return 0;
}
