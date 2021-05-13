#include<stdio.h>
#define MAXSIZE 100
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int result(int s,int n,int w[],int v[]){
    int i,j;
    int ans[MAXSIZE][MAXSIZE];
    //��ʼ����һ����Ʒ
    for(j=0;j<=s;j++) ans[1][j]=w[1]<=j?v[1]:0;
    for(i=2;i<=n;i++)
    {
        int jmin=w[i]<s?w[i]:s;
        //��Ʒ�����������������
        for(j=0;j<jmin;j++) ans[i][j]=ans[i-1][j];
        //��Ʒ����С�����������
        for(j=w[i];j<=s;j++){
        	ans[i][j]=max(ans[i-1][j],ans[i-1][j-w[i]]+v[i]);
        }
    }
    return ans[n][s];
}
int main(){
    int i,r;
    int b;
    int n;
    printf("�����뱳������������Ʒ��������\n");
    scanf("%d %d",&b,&n);
    int w[MAXSIZE];
    int v[MAXSIZE];
    printf("��������Ʒ�������ͼ�ֵ��\n");
    for(i=1;i<=n;i++){
		scanf("%d %d",&w[i],&v[i]);
	}
    r=result(b,n,w,v);
    printf("Maximum value��%d\n",r);
    return 0;
}
