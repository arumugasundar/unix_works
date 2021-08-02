#include<iostream>
using namespace std;
int count_possible_triangle(int* a,int n){
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				cout<<a[i]<<" "<<a[j]<<" "<<a[k];
				if(a[i]+a[j] > a[k] &&
					a[j]+a[k] > a[i] &&
						a[k]+a[i] > a[j]){
					cout<<" - Possible";
					count++;
				}
				cout<<endl;
			}
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
