#include<iostream>
#include<vector>
using namespace std;
void print_wave_array(vector<int> a){
	int n = a.size();
	for(int i=0;i<n-1;i+=2){
		int t = a[i];
		a[i] = a[i+1];
		a[i+1] = t;
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	vector<int> a = {1,2,3,4,5};
	print_wave_array(a);
	return 0;
}
