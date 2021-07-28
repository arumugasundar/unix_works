#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int m){
	    int f = 0;
	    if(m<2) return false;

	    for(int j=2;j<=sqrt(m);j++)
	        if(m%j == 0){
	            f = 1;
	            break;
		}
	return f == 0;
}

long long int prime_sum(int n){
	long long sum = 0;
	for(int i=1;i<=n;i++) if(isPrime(i) && (cout<<i<<" ")) sum += i;
   	return sum;
}

int main(){
	int n = 15;
	long long int result = prime_sum(n);
	cout<<"\nPrime Sum :"<<result<<endl;
	return 0;
}
