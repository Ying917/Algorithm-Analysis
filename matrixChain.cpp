#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int MAX = 100;
int n;		//记录矩阵的个数
int* data;	//记录矩阵的行以及最后一个矩阵的列
int** m;
int** s;	//记录分割位置

// 按照 r 来打印数据
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
	//迭代算法
    int i,j,k,t;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++) {
            s[i][j] = i;
        }
    }
    printR();
    for(int r = 2; r <= n; r++) {			//r为当前问题规模，进行子问题划分
        for(i = 1; i <= (n-r+1); i++) {		//i的起点不断变化，各种r长
            j = i + r -1;					//不同终点
            m[i][j] = m[i+1][j] + data[i-1]*data[i]*data[j];  //划分为Ai(Ai+1....Aj)
            s[i][j] = i;                                      //标记元素 = 坐标
            for(k = i + 1; k <= j - 1; k++) {                 //不同的划分位置
                t = m[i][k] + m[k+1][j] + data[i-1]*data[k]*data[j]; //前面的+后面的+相乘数据
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int recurMatrixChain(int* data,int i, int j){
	//递归算法
    if (i == j) { // 递归到最小单元
        m[i][j] = 0;
        s[i][j] = i;
        return m[i][j];
    }
    m[i][j] = 1 << 30;  //无穷大
    s[i][j] = i;        //在i处分割
    for (int k=i; k<=j-1;k++) {
		// 从i到j-1开始递归，求最小值，然后加上整体数据
        int q = recurMatrixChain(data, i, k) + recurMatrixChain(data, k+1, j) + data[i-1]*data[k]*data[j];
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}

void printProcess(int start, int end) {
	// 打印过程运算过程
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
	// 打印结果序列
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
	cout<<"计算次数至少为："<<m[1][n]<<endl;
	cout<<"计算次序为：";
	printOrder(1, n);
	getchar();
    return 0;
}