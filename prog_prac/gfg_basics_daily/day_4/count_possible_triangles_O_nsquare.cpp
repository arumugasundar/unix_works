#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int count_possible_triangle(vector<int> a){
	int n = a.size();
	sort(a.begin(),a.end());
	int count = 0;
	for(int i=n-1;i>=1;i--){
		int l = 0, r = i-1;
		while(l<r){
			if(a[l]+a[r] > a[i]){
				count+=r-l;
				r--;
			}
			else
				l++;
		}
	}
	return count;
}
int main(){
	vector<int> a = {6,4,9,7,8};
	cout<<"Number of Possible Triangles :\n"<<count_possible_triangle(a);
	cout<<endl;
	return 0;
}
