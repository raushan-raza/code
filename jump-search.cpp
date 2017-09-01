#include <iostream>
#include <math.h>
using namespace std;


void jump_search(int a[], int n, int data){
	int stepsize = sqrt(n);
	int i,j;
	for(i=0; i<n/stepsize; i++){
		if(a[i*stepsize] <= data && data <= a[(i+1)*stepsize]){
			for(j=(i+1)*stepsize; j>=i*stepsize; j--){
				if(a[j]==data)
					cout<<"data found\n";
				break;
			}
		}
		else if(i >= n/stepsize ){
				for(j=i*stepsize+1; j<n; j++){
					if(a[j]==data)
						cout<<"data found\n";
					break;
				}
		}
	}
}

int main(){
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int size = sizeof(a)/sizeof(int);
	int data;
	cin>>data;
	jump_search(a, size, data);
	//cout<<size<<endl;
}