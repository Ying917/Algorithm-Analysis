#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int MAX = 100;
int n;		//��¼����ĸ���
int* data;	//��¼��������Լ����һ���������
int** m;
int** s;	//��¼�ָ�λ��

// ���� r ����ӡ����
void printR() {
    for (int k = 1; k <= n; k++) {
		cout<<"r="<<k<<endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k){
					cout<<"m["<<i<<","<<j<<"]="<<m[i][j]<<endl;
                }
            }
        }
    }
    for (int k = 2; k <= n; k++) {
        cout << "r=" << k<<endl;
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k) {
                    cout<<"s["<<i<<","<<j<<"]="<<s[i][j]<<endl;
                }
            }
        }
    }
}

void matrixChain(int* data,int n) { 
	//�����㷨
    int i,j,k,t;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++) {
            s[i][j] = i;
        }
    }
    printR();
    for(int r = 2; r <= n; r++) {			//rΪ��ǰ�����ģ�����������⻮��
        for(i = 1; i <= (n-r+1); i++) {		//i����㲻�ϱ仯������r��
            j = i + r -1;					//��ͬ�յ�
            m[i][j] = m[i+1][j] + data[i-1]*data[i]*data[j];  //����ΪAi(Ai+1....Aj)
            s[i][j] = i;                                      //���Ԫ�� = ����
            for(k = i + 1; k <= j - 1; k++) {                 //��ͬ�Ļ���λ��
                t = m[i][k] + m[k+1][j] + data[i-1]*data[k]*data[j]; //ǰ���+�����+�������
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int recurMatrixChain(int* data,int i, int j){
	//�ݹ��㷨
    if (i == j) { // �ݹ鵽��С��Ԫ
        m[i][j] = 0;
        s[i][j] = i;
        return m[i][j];
    }
    m[i][j] = 1 << 30;  //�����
    s[i][j] = i;        //��i���ָ�
    for (int k=i; k<=j-1;k++) {
		// ��i��j-1��ʼ�ݹ飬����Сֵ��Ȼ�������������
        int q = recurMatrixChain(data, i, k) + recurMatrixChain(data, k+1, j) + data[i-1]*data[k]*data[j];
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}

void printProcess(int start, int end) {
	// ��ӡ�����������
    if(start == end)
        return;
    printProcess(start, s[start][end]);
    printProcess(s[start][end]+1, end);
	cout<<"(A"<<start<<"*A"<<end<<")";
    if(start != 1 || end !=n){
        printf("->");
    }
}

void printOrder(int start, int end){
	// ��ӡ�������
    if(start == end){
        cout << "A"<< end;
        return;
    }
	cout<<"(";
    printOrder(start, s[start][end]);
    printOrder(s[start][end]+1, end);
	cout<<")";
}

int main(){
	cin>>n;
    data = new int[n+1];
    m = new int*[n+1];
    s = new int*[n+1];
    for(int i = 0; i <= n; i++){
		cin>>data[i];
        m[i] = new int[n+1]();
        s[i] = new int[n+1]();
    }

    matrixChain(data, n);
    //recurMatrixChain(data, 1, n);
    printR();
	cout<<"�����������Ϊ��"<<m[1][n]<<endl;
	cout<<"�������Ϊ��";
	printOrder(1, n);
	getchar();
    return 0;
}