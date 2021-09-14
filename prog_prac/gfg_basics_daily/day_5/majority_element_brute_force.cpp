#include<iostream>
using namespace std;
int majority_element(int* a,int n){
	int max_index = 0, max_count = 0;
	for(int i=0;i<n;i++){
		int count = 0;
		for(int j=0;j<n;j++){
			if(a[i] == a[j]){
				count++;
			}
		}

		if(count>max_count){
			max_index = i;
			max_count = count;
		}
	}

	if(max_count > n/2) return a[max_index];
	else return -1;
}
int main(){
	int a[] = {3,1,3,3,2};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<majority_element(a,n);
	return 0;
}
