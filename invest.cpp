#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main() {
	int m, n,	//m��Ԫ  n����Ŀ
		f[MAX][MAX],		//�洢��ʼ����
		dp[MAX][MAX] = {0},	//��¼�ֲ��������
		invest[MAX][MAX];	//���ڼ�¼Ͷ�ʷ���
	
	cout<<"������Ͷ�ʽ���Ԫ������Ŀ������";
	cin>>m>>n;
	cout<<"��ֱ�����Ͷ�ʽ��Ϊ0-"<<m<<"��Ԫʱ"<<n<<"����Ŀ���Ե������"<<endl;
	for(int i = 0; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin>>f[j][i];
		}
	}

	//��̬�滮
	for (int k = 1; k <= n; k++) 
		for (int x = 1; x <= m; x++)
			for (int i = 0; i <= x; i++)
				if (dp[k - 1][x - i] + f[k][i] >= dp[k][x]) {
					dp[k][x] = dp[k - 1][x - i] + f[k][i];
					invest[k][x] = i;
				}

	//����ֲ�������漰���Ӧ��Ͷ�ʽ����ĵ��м��������
	for (int x = 1; x <= m; x++) {
		for (int k = 1; k <= n; k++)
			cout << dp[k][x] << " "<<invest[k][x]<<" ";
		cout << endl;
	}

	cout <<"�������Ϊ��"<< dp[n][m] << endl;
	cout << "���䷽��Ϊ��"<<endl;
	int sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "�������" << i << "����Ŀ" << invest[i][sum] << "��Ԫ"<<endl;
		sum -= invest[i][sum];
	}
}