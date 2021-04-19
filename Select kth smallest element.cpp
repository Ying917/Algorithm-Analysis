#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Select(vector<int> S,int n,int k) {
	vector<int> temp, M, S1, S2;
	temp = S;

	//把集合S划分成最多5个一组，共n/5组（向上取整）
	for(int i = 0; i < n; i += 5){
		int len = min(5, n - i);
		sort(temp.begin() + i, temp.begin() + i + len);		//对每组元素进行升序排序
		M.push_back(temp[i + (len - 1) / 2]);	//将每组元素的中位数放到集合M中
	}

	sort(M.begin(), M.end());	//对存放中位数的集合M升序排序
	int length = M.size();
	int mid_m = M[(length - 1) /  2];	//求出中位数的中位数m*，即mid_m

	//将集合S划分成ABCD四区域，且S1=S1∪C,S2=S2∪B，区域A和区域D中的元素与m*进行比较，较小的放入S1，较大的放入S2
	for(int i = 0; i < n; i += 5){
		//若该组不足5个，则直接遍历比较大小
		if(n - i < 5){
			for(int j = i; j < n; j++){
				if(temp[j] > mid_m)
					S2.push_back(temp[j]);
				else if(temp[j]<mid_m)
					S1.push_back(temp[j]);
			}
			break;
		}

		//该组个数为5个，且该组中位数小于m*时
		if(temp[i + 2] < mid_m){	
			for(int j = i; j <=i+2; j++)
				//该组内中位数小于m*，则位于中位数前的元素也一定小于m*
				S1.push_back(temp[j]);
			for(int j = i + 3; j < i+5; j++){
				//但位于中位数后的元素与m*的大小关系不一定
				if (temp[j] > mid_m)
					S2.push_back(temp[j]);
				else S1.push_back(temp[j]);
			}
		}

		//该组个数为5个，且该组中位数大于m*时
		else if(temp[i + 2] > mid_m){
			for(int j = i; j <= i+2; j++){
				//该组内中位数虽然大于m*，但位于中位数前的元素与m*的大小关系不一定
				if (temp[j] > mid_m)
					S2.push_back(temp[j]);
				else S1.push_back(temp[j]);
			}
			for(int j = i + 3; j < i+5; j++)
				//但位于中位数后的元素一定大于m*
				S2.push_back(temp[j]);
		}

		//该组个数为5个，且该组中位数大于m*时，m*不存入S1或S2，直接丢弃
		else{
			for(int j = i; j < i+2; j++)
				//该组内中位数等于m*，则位于中位数前的元素一定小于m*
				S1.push_back(temp[j]);
			for (int j = i + 3; j <i+5; j++)
				//位于中位数后的元素一定大于m*
				S2.push_back(temp[j]);
		}
	}

	int length1 = S1.size(), length2 = S2.size();
	if(k == length1+1){
		cout << mid_m << endl;
		return;
	}
	else if (k <= length1){
		Select(S1, length1, k);
	}
	else{
		Select(S2, length2, k - length1 - 1);
	}
}

int main(){
	int n, k, i, a;
	vector<int>s;		//集合S
	cout<<"请分别输入元素的个数n 和 需要查找第k小元素的k值： ";
	cin>>n>>k;
	for(i = 0; i < n; i++){
		cin>>a;
		s.push_back(a);
	}
	cout <<"第"<<k<<"小的数为：";
	Select(s, n, k);
}