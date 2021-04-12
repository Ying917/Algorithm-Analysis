#include<iostream>
#include<math.h>
#include<algorithm> 
using namespace std;

#define MAX 99999  //���������
#define NUM 10000

int PointSet[NUM];// �������������

struct point{
	double x, y;
}p[NUM];
 
int cmpx(const point& a, const point& b){  
	//����x����������
	return a.x < b.x;
}
 
int cmpy(int &a, int &b){   
	//����y����������
	return p[a].y < p[b].y;
}
 
inline double min(double a, double b){   
	//��������ֵ�н�С��ֵ
	return a < b ? a : b;
}

inline double dist(const point& a, const point& b){
	//��������֮��ľ���
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double closePair(int low, int high){
	//������ĵ��
	int i, j, k = 0, c = 0;
	int mid = 0;
	double dist_min = 0;
	if(low == high)   
		return MAX;
	if(low + 1 == high){
		//��n=2����������֮��ľ���
		return dist(p[low], p[high]);
	}
	if(low + 2 == high){
		//��n=3��ͨ�������Ƚϣ���������֮��ľ���
		dist_min = dist(p[low],p[low + 1]);
		for(i = low;i < high;i++){
			for(j = i + 1;j <= high;j++){
				if(dist(p[i],p[j]) < dist_min){
					dist_min = dist(p[i],p[j]);
				}
			}
		}
		return dist_min;
	}
	mid = (low + high) / 2;  //���м�λ��
	dist_min = min(closePair(low, mid), closePair(mid+1, high));  //�ݹ����������С����
	for(i = low;i <= high;i++){
		//ͳ�Ʋ���¼��Щ��λ����������
		if (p[mid].x - dist_min <= p[i].x && p[i].x <= p[mid].x + dist_min)
			PointSet[c++] = i;
	}
	sort(PointSet, PointSet + c, cmpy);//����y����������
	for(i = 0; i < c; i++){
		//�Ƚ�s1�������ڵĵ��s2�������ڵĵ�ľ����Ƿ������С��������С�Ե�
		k = i + 7 > c ? c : i + 7;  
		//�ɡ��ھ��������������ĵ������������7������
		for (j = i + 1; j < k; j++){
			if(p[PointSet[j]].y - p[PointSet[i]].y > dist_min){  
				//���λ����λ������ĵ�ľ������dist_min��������һ��ѭ��
				break;
			}
			else{
				//�����������С�����������ԣ���ѡ����С�ĵ�
				dist_min = min(dist(p[PointSet[i]], p[PointSet[j]]), dist_min);   
			}
		}
	}
	return dist_min;
}
 
int main(){
	int i,n;
	double dist_min;
	cout<<"�������ĸ�����"<<endl;
	cin >> n;
	cout<<"��ֱ����������꣺"<<endl;
	for(i = 0;i < n;i++){
		cout<<"p"<<i<<":";
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p + n,cmpx); //����x����������
	dist_min = closePair(0, n-1);
	cout<<"����ľ����ǣ�"<<dist_min<<endl;
	getchar();
	return 0;
}