#include<iostream>
using namespace std;
int comp(const void* a, const void* b){
	return *(int*)a > *(int*)b;
}
int count_possible_triangle(int* a,int n){
	int count = 0;
	qsort(a,n,sizeof(a[0]),comp);
	for(int i=0;i<n;i++){
		int k = i+2;
		for(int j=i+1;j<n;j++){
			while(k<n && a[i]+a[j] > a[k]) k++;
			if(k > j) count+= k-j-1;
		}
	}
	return count;
}
int main(){
	int n = 5;
	int arr[] = {6,4,9,7,8};
	cout<<"\nNumber of Possible Triangles :\n"<<count_possible_triangle(arr,n);
	cout<<endl;
	return 0;
}
