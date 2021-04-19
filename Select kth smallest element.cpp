#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Select(vector<int> S,int n,int k) {
	vector<int> temp, M, S1, S2;
	temp = S;

	//�Ѽ���S���ֳ����5��һ�飬��n/5�飨����ȡ����
	for(int i = 0; i < n; i += 5){
		int len = min(5, n - i);
		sort(temp.begin() + i, temp.begin() + i + len);		//��ÿ��Ԫ�ؽ�����������
		M.push_back(temp[i + (len - 1) / 2]);	//��ÿ��Ԫ�ص���λ���ŵ�����M��
	}

	sort(M.begin(), M.end());	//�Դ����λ���ļ���M��������
	int length = M.size();
	int mid_m = M[(length - 1) /  2];	//�����λ������λ��m*����mid_m

	//������S���ֳ�ABCD��������S1=S1��C,S2=S2��B������A������D�е�Ԫ����m*���бȽϣ���С�ķ���S1���ϴ�ķ���S2
	for(int i = 0; i < n; i += 5){
		//�����鲻��5������ֱ�ӱ����Ƚϴ�С
		if(n - i < 5){
			for(int j = i; j < n; j++){
				if(temp[j] > mid_m)
					S2.push_back(temp[j]);
				else if(temp[j]<mid_m)
					S1.push_back(temp[j]);
			}
			break;
		}

		//�������Ϊ5�����Ҹ�����λ��С��m*ʱ
		if(temp[i + 2] < mid_m){	
			for(int j = i; j <=i+2; j++)
				//��������λ��С��m*����λ����λ��ǰ��Ԫ��Ҳһ��С��m*
				S1.push_back(temp[j]);
			for(int j = i + 3; j < i+5; j++){
				//��λ����λ�����Ԫ����m*�Ĵ�С��ϵ��һ��
				if (temp[j] > mid_m)
					S2.push_back(temp[j]);
				else S1.push_back(temp[j]);
			}
		}

		//�������Ϊ5�����Ҹ�����λ������m*ʱ
		else if(temp[i + 2] > mid_m){
			for(int j = i; j <= i+2; j++){
				//��������λ����Ȼ����m*����λ����λ��ǰ��Ԫ����m*�Ĵ�С��ϵ��һ��
				if (temp[j] > mid_m)
					S2.push_back(temp[j]);
				else S1.push_back(temp[j]);
			}
			for(int j = i + 3; j < i+5; j++)
				//��λ����λ�����Ԫ��һ������m*
				S2.push_back(temp[j]);
		}

		//�������Ϊ5�����Ҹ�����λ������m*ʱ��m*������S1��S2��ֱ�Ӷ���
		else{
			for(int j = i; j < i+2; j++)
				//��������λ������m*����λ����λ��ǰ��Ԫ��һ��С��m*
				S1.push_back(temp[j]);
			for (int j = i + 3; j <i+5; j++)
				//λ����λ�����Ԫ��һ������m*
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
	vector<int>s;		//����S
	cout<<"��ֱ�����Ԫ�صĸ���n �� ��Ҫ���ҵ�kСԪ�ص�kֵ�� ";
	cin>>n>>k;
	for(i = 0; i < n; i++){
		cin>>a;
		s.push_back(a);
	}
	cout <<"��"<<k<<"С����Ϊ��";
	Select(s, n, k);
}