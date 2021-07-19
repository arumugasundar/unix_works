/*
Question:

Given an array of n elements that contains elements from 0 to n-1,
with any of these numbers appearing any number of times.
Find these repeating numbers in O(n) and using only constant memory space.

Testcase:
Input : n = 7 and array[] = {1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6

Explanation: The numbers 1 , 3 and 6 appears more
than once in the array.

with Time: O(n) and Space: O(1)
*/

#include<iostream>
using namespace std;

/* display duplicate elements with count */
void print_duplicates_with_count(int* a,int n){
	for(int i=0;i<n;i++) a[a[i]%n] = a[a[i]%n]+n;

	for(int i=0;i<n;i++) if(a[i] >= n*2) cout<<i<<"("<<a[i]/n<<")"<<" ";
}

int main(){
	int n;
	cout<<"enter the number of elements in array";
	cin>>n;
	int a[n];
	cout<<sizeof(a)<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the element "<<i+1<<":";
		cin>>a[i];
	}

	cout<<"\nUnique Duplicate Elements are :";
	print_duplicates_with_count(a,n);
	return 0;
}
