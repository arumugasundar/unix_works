#include<chrono>
#include<iostream>
#include<omp.h>
#include<stdlib.h>
using namespace std;
using namespace std::chrono;
int main(){
	int a[] = {1,2,3,4,5};
	int sum = 0;

	auto start = high_resolution_clock::now();
	omp_set_num_threads(4);
	#pragma omp parallel for shared(sum)
        for (int i = 0; i < 5; i++) {
		cout<<omp_get_thread_num()<<" "<<i<<endl;
               // #pragma omp critical
                sum = sum + a[i];
        }
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop-start);
	cout<<"Time Taken by function :"<<duration.count()<<" microseconds"<<endl;
	cout<<sum<<endl;
	return 0;
}
