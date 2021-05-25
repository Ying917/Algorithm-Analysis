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
	double weight;    //����Ȩֵ
	int parent,left,right;//˫��ָ�뼰���Һ���Node
}Node;

typedef Node HuffmanTree[maxsize];

typedef struct {       
	//����SelectMin����������Ľ������
	int id;           //���������������е����
	double weight;    //���������Ȩֵ
}temp;

typedef struct {       //������
	char ch;			//�洢�ַ�
	char bit[maxsize];	//��ű���λ��
}CodeNode;
typedef CodeNode Code[maxsize];

void Init(HuffmanTree T,int m) {
	//��ʼ����������
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
	//��ǰk�������ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2
	temp x[maxsize];  
	int i, j;
	for (i = 0, j = 0; i <= k; i++){  
		//Ѱ����С�ʹ�С���ڵ�Ĺ���
		if (T[i].parent == -1){
			//��Ϊ���ڵ�,�򽫸ø��ڵ����ź�Ȩֵ��ֵ��x��
			x[j].id = i;      
			x[j].weight = T[i].weight;
			j++;
		}
	}
	sort(x, x + j, cmp);        //��x����Ȩֵ��С��������
	//������x�����ĵ�һ�͵ڶ���λ���д洢��id�����ҵĸ��ڵ�����ֵ
	*p1 = x[0].id;
	*p2 = x[1].id;
}

void CreateHuffmanTree(HuffmanTree T,int n) {
	//�������������T[m-1]Ϊ������
	int i, p1, p2;
	Init(T,2*n-1);  
	InputWeight(T,n);      
	for (i = n; i < 2*n-1; i++) {
		SelectMin(T, i - 1, &p1, &p2);
		//����ΪT[p1]��T[p2]����������Ϊ���������ϲ�Ϊһ���µ���
		//�����ĸ����½��T[i]
		T[p1].parent = T[p2].parent = i;//T[p1]��T[p2]���������ĸ����ָ��i
		T[i].left = p1;             //��СȨ�ĸ�������½�������
		T[i].right = p2;             //��СȨ�ĸ�������½����Һ���
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void Encoding(HuffmanTree T, Code H,int n) {
	//������������H
	int c, p;
	char cd[maxsize];
	int start;
	cd[n] = '\0';
	getchar();
	for (int i = 0; i < n; i++) {
		//������Ҷ��T[i]�ı���
		H[i].ch = getchar();
		start = n;
		c = i;//��Ҷ��T[i]��ʼ����
		while((p = T[c].parent) >= 0){
			//ֱ�����ݵ�T[c]������Ϊֹ
			//��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
			if (T[p].left == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;
		}
		strcpy(H[i].bit, &cd[start]);//���Ʊ���λ��
	}
}


int main() {
	int n;
	HuffmanTree T;
	Code tem;
	cout<<"������Ҷ�ӽڵ�ĸ�����";
	cin>>n;
	cout<<"����������"<<n<<"��Ҷ�ӽ���Ȩֵ(��ԭ��ֵ�ϳ�0.01)��";
	CreateHuffmanTree(T,n);
	cout<<"����������"<<n<<"��Ҷ�ӽ����������ַ�(����ո�)��";
	Encoding(T, tem, n);
	cout<<"�����������£�����-1��ʾû�к��ӽڵ㣩��"<<endl;
	for(int i = 0; i < 2*n-1; i++) {
		cout<<"id: "<<left<<setw(3)<<i<<"    weight:"<<left<<setw(5)<<T[i].weight<<"    parent:"<<left<<setw(3)<<T[i].parent<<"    left child:"<<left<<setw(3)<<T[i].left<<"    right:"<<left<<setw(3)<<T[i].right<<endl;
	}
	printf("�������������£�\n");
	double avg_w = 0.0;
	for(int i = 0; i < n; i++) {
		cout<<"id:"<<i<<"    ch:"<<tem[i].ch<<"    code:"<<tem[i].bit<<endl;
		avg_w += strlen(tem[i].bit)*T[i].weight;
	}
	cout<<"ƽ���볤Ϊ"<<avg_w;
	getchar();
	return 0;
}