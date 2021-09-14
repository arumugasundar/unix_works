#include<chrono>
#include<iostream>
using namespace std;
using namespace std::chrono;
int main(){
	int a[] = {1,2,3,4,5};
	int sum = 0;

	auto start = high_resolution_clock::now();
	for(int i=0;i<5;i++) sum += a[i];
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop-start);
	cout<<"Time Taken by function :"<<duration.count()<<" microseconds"<<endl;
	cout<<sum<<endl;
	return 0;
}
