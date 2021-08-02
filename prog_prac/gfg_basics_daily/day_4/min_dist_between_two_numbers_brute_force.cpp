#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int min_dist(vector<int> a,int x, int y){
	int n = a.size();
	int minimum_dist = INT_MAX;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((a[i] == x && a[j] == y)||(a[j] == x && a[i] == y)){
				if(j-i < minimum_dist)
					minimum_dist = j-i;
			}
		}
	}
	if(minimum_dist == INT_MAX) return -1;
	return minimum_dist;
}

int main(){
	vector<int> a = {3, 5, 4, 2, 6, 2, 0, 0, 5, 4, 8, 3};
	int x = 6, y = 3;
	cout<<min_dist(a,x,y)<<endl;
	return 0;
}
