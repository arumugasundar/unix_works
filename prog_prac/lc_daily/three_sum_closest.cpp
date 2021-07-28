#include<iostream>
#include<math.h>
using namespace std;
int threeSumClosest(int a[],int n,int target){

	for(int i=0;i<n;i++){
		for(int j=i;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	int result = a[0] + a[1] + a[2];
	for(int i=0;i<n;i++){
		int left = i+1,right = n-1;
		while(left < right){
			int current_sum = a[i] + a[left] + a[right];

			if(current_sum > target)
				right--;
			if(current_sum < target)
				left++;

			if(abs(current_sum-target) < abs(result-target))
				result = current_sum;
		}
	}


	return result;
}
int main(){
	int arr[] = {-1,2,1,-4};
	int n = 4, target = 1;
	cout<<threeSumClosest(arr,n,target);
	return 0;
}
