#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> sorted_sub_seq(vector<int> a){
	int n = a.size();
	vector<int> result;
	int small = INT_MAX;
	int large = INT_MAX;
	int i;
	for(i=0;i<n;i++){
		if(a[i] <= small) small = a[i];
		else if(a[i] <= large) large = a[i];
		else break;
	}
	if(i==n) return result;

	for(int j=0;j<i+1;j++)
		if(a[j] < large){
			small = a[j];
			break;
		}
	result.push_back(small);
	result.push_back(large);
	result.push_back(a[i]);
	return result;
}
int main(){
	vector<int> a = {1,2,1,1,3};
	vector<int> result = sorted_sub_seq(a);
	for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
	return 0;
}
