#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];

void merge(int mid, int l, int r){
	 int leftsize = mid-l+1;
	 int L[leftsize+1];
	 int rightsize = r - mid;
	 int R[rightsize+1];
	 for (int i = 0; i < leftsize; ++i)
	 {
	 	L[i]=a[i+l];
	 }
	 for (int i = 0; i < rightsize; ++i)
	 {
	 	R[i]=a[i+mid+1];
	 }

	 L[leftsize] = R[rightsize] = INT_MAX;
	 int lefti = 0;
	 int righti = 0;
	 for (int i = l; i < r; ++i)
	 {
	 	if (L[lefti]<=R[righti])
	 	{
	 		a[i]=L[lefti];  
	 		lefti++;
	 	}else{
	 		a[i]=R[rightsize];
	 		righti++;
	 	}
	 }
}
void mergesort(int l, int r){
	if (l==r){
		return;
	}
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);
	merge(l, r, mid);
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	mergesort(0, n-1);

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}