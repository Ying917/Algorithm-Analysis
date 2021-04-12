#include<iostream>
#include<math.h>
#include<algorithm> 
using namespace std;

#define MAX 99999  //定义无穷大
#define NUM 10000

int PointSet[NUM];// 保存排序的索引

struct point{
	double x, y;
}p[NUM];
 
int cmpx(const point& a, const point& b){  
	//按照x轴升序排序
	return a.x < b.x;
}
 
int cmpy(int &a, int &b){   
	//按照y轴升序排序
	return p[a].y < p[b].y;
}
 
inline double min(double a, double b){   
	//返回两个值中较小的值
	return a < b ? a : b;
}

inline double dist(const point& a, const point& b){
	//计算两点之间的距离
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double closePair(int low, int high){
	//求最近的点对
	int i, j, k = 0, c = 0;
	int mid = 0;
	double dist_min = 0;
	if(low == high)   
		return MAX;
	if(low + 1 == high){
		//即n=2，返回两点之间的距离
		return dist(p[low], p[high]);
	}
	if(low + 2 == high){
		//即n=3，通过两两比较，返回两点之间的距离
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
	mid = (low + high) / 2;  //求中间位置
	dist_min = min(closePair(low, mid), closePair(mid+1, high));  //递归求出两边最小距离
	for(i = low;i <= high;i++){
		//统计并记录哪些点位于两虚线内
		if (p[mid].x - dist_min <= p[i].x && p[i].x <= p[mid].x + dist_min)
			PointSet[c++] = i;
	}
	sort(PointSet, PointSet + c, cmpy);//按照y轴升序排序
	for(i = 0; i < c; i++){
		//比较s1中虚线内的点和s2中虚线内的点的距离是否存在有小于两侧最小对的
		k = i + 7 > c ? c : i + 7;  
		//由“在矩形中满足条件的点的总数不超过7个”得
		for (j = i + 1; j < k; j++){
			if(p[PointSet[j]].y - p[PointSet[i]].y > dist_min){  
				//如果位于中位线两侧的点的距离大于dist_min则跳出第一个循环
				break;
			}
			else{
				//如果有两个点小于两侧的最近对，则选出最小的点
				dist_min = min(dist(p[PointSet[i]], p[PointSet[j]]), dist_min);   
			}
		}
	}
	return dist_min;
}
 
int main(){
	int i,n;
	double dist_min;
	cout<<"请输入点的个数："<<endl;
	cin >> n;
	cout<<"请分别输入点的坐标："<<endl;
	for(i = 0;i < n;i++){
		cout<<"p"<<i<<":";
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p + n,cmpx); //按照x轴升序排序
	dist_min = closePair(0, n-1);
	cout<<"最近的距离是："<<dist_min<<endl;
	getchar();
	return 0;
}