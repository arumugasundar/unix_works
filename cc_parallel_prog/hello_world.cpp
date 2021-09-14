#include<omp.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[]){
	int nthreads, tid;

	// Begin of parallel region
	#pragma omp parallel private(nthreads,tid)
	{
		tid = omp_get_thread_num();
		cout<<"Hello World - thread "<<tid<<endl;
		if(tid == 0){
			nthreads = omp_get_num_threads();
			cout<<"Number of threads : "<<nthreads<<endl;
		}
	}
	return 0;
}
