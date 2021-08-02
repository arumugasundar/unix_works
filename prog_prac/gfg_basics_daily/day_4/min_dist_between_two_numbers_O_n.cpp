#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int min_dist(vector<int> a,int x, int y){
	int n = a.size();
	int p=-1, minimum_dist = INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]==x || a[i]==y){
			if(p != -1 && a[i] != a[p])
				minimum_dist = min(minimum_dist, i-p);
			p = i;
		}
	}
	if(minimum_dist == INT_MAX) return -1;
	return minimum_dist;
}

int main(){
	vector<int> a = {3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
	int x = 6, y = 3;
	cout<<min_dist(a,x,y)<<endl;
	return 0;
}
