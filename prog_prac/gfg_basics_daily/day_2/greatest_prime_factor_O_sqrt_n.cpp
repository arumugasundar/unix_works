#include<iostream>
using namespace std;
long long greatestPrimeFactor(long long n){
	long long maxPrime = -1;

	while(n%2 == 0){
		maxPrime = 2;
		n >>= 1; /* equivalent to n/=2 */
	}

	while(n%3 == 0){
		maxPrime = 3;
		n /= 3;
	}

	for(int i=5;i*i<=n;i+=6){
		while(n%i == 0){
			maxPrime = i;
			n /= i;
		}

		while(n%(i+2) == 0){
			maxPrime = i+2;
			n /= i+2;
		}
	}

	if(n>4)
		maxPrime = n;
	return maxPrime;
}
int main(){
	cout<<greatestPrimeFactor(24)<<endl;
	return 0;
}
