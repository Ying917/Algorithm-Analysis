#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define maxsize 100     
  
typedef struct {  
	double weight;    //结点的权值
	int parent,left,right;//双亲指针及左右孩子Node
}Node;

typedef Node HuffmanTree[maxsize];

typedef struct {       
	//用于SelectMin函数中排序的结点类型
	int id;           //保存根结点在向量中的序号
	double weight;    //保存根结点的权值
}temp;

typedef struct {       //编码结点
	char ch;			//存储字符
	char bit[maxsize];	//存放编码位串
}CodeNode;
typedef CodeNode Code[maxsize];

void Init(HuffmanTree T,int m) {
	//初始化哈夫曼树
	for (int i = 0; i < m; i++) {
		T[i].left = -1;
		T[i].right = -1;
		T[i].parent = -1;
		T[i].weight = 0;
	}
}

void InputWeight(HuffmanTree T,int n) {
	for (int i = 0; i < n; i++) {
		double x;
		cin>>x;
		T[i].weight = x;
	}
}

bool cmp(temp a, temp b) {
	return a.weight < b.weight;
}

void SelectMin(HuffmanTree T, int k, int *p1, int *p2) {
	//在前k个结点中选择权值最小和次小的根结点，其序号分别为p1和p2
	temp x[maxsize];  
	int i, j;
	for (i = 0, j = 0; i <= k; i++){  
		//寻找最小和次小根节点的过程
		if (T[i].parent == -1){
			//若为根节点,则将该根节点的序号和权值赋值给x，
			x[j].id = i;      
			x[j].weight = T[i].weight;
			j++;
		}
	}
	sort(x, x + j, cmp);        //对x按照权值从小到大排序
	//排序后的x向量的第一和第二个位置中存储的id是所找的根节点的序号值
	*p1 = x[0].id;
	*p2 = x[1].id;
}

void CreateHuffmanTree(HuffmanTree T,int n) {
	//构造哈夫曼树，T[m-1]为其根结点
	int i, p1, p2;
	Init(T,2*n-1);  
	InputWeight(T,n);      
	for (i = n; i < 2*n-1; i++) {
		SelectMin(T, i - 1, &p1, &p2);
		//将根为T[p1]和T[p2]的两棵树作为左右子树合并为一棵新的树
		//新树的根是新结点T[i]
		T[p1].parent = T[p2].parent = i;//T[p1]和T[p2]的两棵树的根结点指向i
		T[i].left = p1;             //最小权的根结点是新结点的左孩子
		T[i].right = p2;             //次小权的根结点是新结点的右孩子
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void Encoding(HuffmanTree T, Code H,int n) {
	//求哈夫曼编码表H
	int c, p;
	char cd[maxsize];
	int start;
	cd[n] = '\0';
	getchar();
	for (int i = 0; i < n; i++) {
		//依次求叶子T[i]的编码
		H[i].ch = getchar();
		start = n;
		c = i;//从叶子T[i]开始上溯
		while((p = T[c].parent) >= 0){
			//直至上溯到T[c]是树根为止
			//若T[c]是T[p]的左孩子，则生成代码0；否则生成代码1
			if (T[p].left == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;
		}
		strcpy(H[i].bit, &cd[start]);//复制编码位串
	}
}


int main() {
	int n;
	HuffmanTree T;
	Code tem;
	cout<<"请输入叶子节点的个数：";
	cin>>n;
	cout<<"请依次输入"<<n<<"个叶子结点的权值(在原数值上乘0.01)：";
	CreateHuffmanTree(T,n);
	cout<<"请依次输入"<<n<<"个叶子结点所代表的字符(无需空格)：";
	Encoding(T, tem, n);
	cout<<"哈夫曼树如下（其中-1表示没有孩子节点）："<<endl;
	for(int i = 0; i < 2*n-1; i++) {
		cout<<"id: "<<left<<setw(3)<<i<<"    weight:"<<left<<setw(5)<<T[i].weight<<"    parent:"<<left<<setw(3)<<T[i].parent<<"    left child:"<<left<<setw(3)<<T[i].left<<"    right:"<<left<<setw(3)<<T[i].right<<endl;
	}
	printf("哈夫曼编码如下：\n");
	double avg_w = 0.0;
	for(int i = 0; i < n; i++) {
		cout<<"id:"<<i<<"    ch:"<<tem[i].ch<<"    code:"<<tem[i].bit<<endl;
		avg_w += strlen(tem[i].bit)*T[i].weight;
	}
	cout<<"平均码长为"<<avg_w;
	getchar();
	return 0;
}