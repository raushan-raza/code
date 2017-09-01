#include <iostream>
#include <math.h>

using namespace std;

int prefixsum(int a[], int n){
	if(n==0)
		return a[0]; 
	else
		return a[n]+ prefixsum(a, n-1);
}
int sufixsum(int a[], int n){
	int size = sizeof(a);
	if(n == size-1)
		return a[n];
	else
		return a[n] + sufixsum(a, n+1);
}

int main(){
	int array[100000];
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		int min=0,i,index=0,sum[n];

		for(i=0; i<n; i++)
			cin>>array[i];
		
		for(i=0; i<n; i++){
			sum[i]=prefixsum(array, i) + sufixsum(array, i);
			cout<<sum[i]<<endl;
		}
		min = sum[0];

		for(i=1;i<n;i++){
			if(min > sum[i]){
				min=sum[i];
				index=i;
			}
		}
		cout<<index+1<<endl;
		t--;
	}
}