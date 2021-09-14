#include<iostream>
using namespace std;
int findCandidate(int* a, int n){
	int max_rep_index = 0,count = 1;
	for(int i=1;i<n;i++){
		if(a[i] == a[max_rep_index])
			count++;
		else
			count--;

		if(count == 0){
			max_rep_index = i;
			count = 1;
		}
	}
	return a[max_rep_index];
}

bool isMajority(int* a,int n,int key){
	int count = 0;
	for(int i=0;i<n;i++) if(a[i] == key) count++;

	if(count > n/2)
		return true;
	return false;
}
int majority_element(int* a,int n){
	int key = findCandidate(a,n);
	if(isMajority(a,n,key)) return key;
	else return -1;
}

int main(){
	int a[] = {3,1,3,3,2};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"Input :";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	cout<<"Output :"<<majority_element(a,n)<<endl;
	return 0;
}
