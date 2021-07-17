/*

Problem Statement:
You are given an array arr which consists of only zeros and ones,
divide the array into three non-empty parts such that
all of these parts represent the same binary value.

Test Case:
 Input: arr = [1,0,1,0,1]
 Output: [0,3]

*/

#include<iostream>
using namespace std;
int* three_equal_parts(int* arr,int n){

	int num_of_ones = 0;
	for(int i=0;i<n;i++) num_of_ones += arr[i];

	if(num_of_ones == 0)
		return new int[2]{0,2};
	if(num_of_ones%3!=0)
		return new int[2]{-1,1};

	int ones_count = 0;
	int num_of_ones_in_each_part = num_of_ones/3;

	int first_partition_first_index = -1;
	int second_partition_first_index = -1;
	int third_partition_first_index = -1;

	for(int i=0;i<n;i++){
		if(arr[i]==1){
			ones_count++;
			if(ones_count == 1)
                                first_partition_first_index = i;
			else if(ones_count == num_of_ones_in_each_part+1)
				second_partition_first_index = i;
			else if(ones_count ==2*num_of_ones_in_each_part+1)
				third_partition_first_index = i;
		}
	}

	while(third_partition_first_index < n){
		if(arr[first_partition_first_index] == arr[second_partition_first_index] && arr[first_partition_first_index] == arr[third_partition_first_index]){
			first_partition_first_index++;
			second_partition_first_index++;
			third_partition_first_index++;
		}
		else
			return new int[2]{-1,1};
	}
	return new int[2]{first_partition_first_index-1,second_partition_first_index};
}

int main(){
	int n;
	cout<<"Enter the n value:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the value:";
		cin>>arr[i];
	}
	int* res = three_equal_parts(arr,n);

	cout<<endl<<"Output: "<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
	return 0;
}
