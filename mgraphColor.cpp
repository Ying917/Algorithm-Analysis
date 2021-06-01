#include <iostream>
using namespace std;
#define maxSize 100
int color[maxSize];
int scheme_num = 0;		//ͳ����ɫ����������
bool ok(int k,int c[][maxSize]){//�ж϶���k����ɫ�Ƿ�����ͻ
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
			color[k]=color[k]+1;//������һ����ɫ
		if(color[k]<=m && k==n){
			scheme_num++;
			for(i=1;i<=n;i++) {
				cout<<color[i]<<"  ";
			}
			cout<<endl;
		}
		else if(color[k]<=m && k<n)
			k=k+1;//������һ������
		else{
			color[k]=0;
			k=k-1;//����
		}
	}
}
int main(){
    int i,n,m,edge_num,v1,v2;
	int c[maxSize][maxSize];	//�洢n�����������ͼ������
	cout<<"�����붥��ĸ�����";
	cin>>n;
	cout<<"��������ɫ�ĸ�����";
	cin>>m;
	cout<<"������ߵĸ�����";
	cin>>edge_num;
	cout<<"������������ߵ��������㣺"<<endl;
	for(i = 0;i < edge_num;i++){
		cin>>v1>>v2;
		c[v1][v2] = 1;
		c[v2][v1] = 1;
	}
	cout<<"���鶥�����ɫ����Ϊ(��1-"<<n<<"����)"<<endl;
    graphColor(n,m,c);
	if(scheme_num == 0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"���������Ϊ"<<n<<"����ɫ����Ϊ"<<m<<"ʱ������"<<scheme_num<<"����ɫ����";
	}
	return 0;
}