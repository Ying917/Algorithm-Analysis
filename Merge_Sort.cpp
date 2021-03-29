#include<iostream>
using namespace std;
const int Max = 100;

void Merge_Sort(int A[],int left, int right){
	int mid, k, i, j;
	int temp[Max]; 
	mid = (left + right) / 2;
	k = left;
	i = left;	
	j = mid + 1;
	if (left == right) return;							 
	Merge_Sort(A,left, mid);
	Merge_Sort(A,mid + 1, right);
	while (i <= mid && j <= right) {
		if (A[i] > A[j]) 
			temp[k++] = A[j++]; 
		else 
			temp[k++] = A[i++];					 
	}
	while (i <= mid) 
		temp[k++] = A[i++];			 
	while (j <= right) 
		temp[k++] = A[j++];
	for (int i = left; i <= right; i++)
		A[i] = temp[i];							 
}
int main(){
	int A[Max];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	Merge_Sort(A,1, n);
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";	
	getchar();
	return 0;
}