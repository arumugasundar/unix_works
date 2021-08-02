#include<iostream>
#include<vector>
using namespace std;
vector<int> maximum_sub_array(vector<int> a){
	vector<int> result;
	int n = a.size();
	int i = 0, maxm = 0, count = 0, start = 0, end = -1;
	int fstart = -1, fend = -1;
	long long int sum = 0, maxsum = 0;

	while(i<n){
		if(a[i] >= 0){
			sum+=a[i];
			count++;
			end++;
		}

		if(sum > maxsum){
			maxsum = sum;
			fstart = start;
			fend = end;
		}
		else if(sum == maxsum && count > maxm){
			maxm = count;
			fstart = start;
			fend = end;
		}

		if(a[i]<0){
			count=0;
			start=i+1;
			end=i;
			sum=0;
		}
		i++;
	}

	if(fstart!=-1 && fend!=-1)
		for(int i=fstart;i<=fend;i++)
			result.push_back(a[i]);
	return result;
}

int main(){
	vector<int> a = {1,2,5,-7,2,3};
	int n = a.size();

	cout<<"array elements are :";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	vector<int> result = maximum_sub_array(a);
	n = result.size();

	cout<<"The maximum sub array elements are :";
	for(int i=0;i<n;i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}
