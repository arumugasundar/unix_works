#include<iostream>
using namespace std;
bool isPrime(int n){
	int f = 0;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			f = 1;
			break;
		}
	}
	return f == 0;
}
long long int greatestPrimeFactor(long long int n){
	long max = -1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			long factor_1 = i, factor_2 = n/i;
			if(isPrime(factor_1) && factor_1>max) max = factor_1;
			else if(isPrime(factor_2) && factor_2>max) max = factor_2;
		}
	}
	return max;
}
int main(){
	cout<<greatestPrimeFactor(24)<<endl;
	return 0;
}
