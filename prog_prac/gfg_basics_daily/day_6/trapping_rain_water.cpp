#include<iostream>
#include<algorithm>
using namespace std;
int maxWater(int a[],int n){
	int left = 0;
	int right = n-1;

	int l_max = 0;
	int r_max = 0;

	int result = 0;
	while(left <= right){
		if(r_max <= l_max){
			result += max(0,r_max-a[right]);
			r_max = max(r_max,a[right]);
			right -= 1;
		}else{
			result += max(0,l_max-a[left]);
			l_max = max(l_max,a[left]);
			left += 1;
		}
	}
	return result;
}
int main(){
	int arr[] = {3,0,0,2,0,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maxWater(arr,n)<<endl;
	return 0;
}
