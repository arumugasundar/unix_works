#include<iostream>
#include<math.h>
using namespace std;
class PrimeSum{
	private:
		long long int *dp;
		int n;
	public:
		PrimeSum(int n){
			dp = new long long int[n];
			this->n = n;
		}

		void findSumUsingSieve(){

			/*
			creating temporary array of size n+1
			set the non prime numbers to 1
			and others are 0 by default
			*/

			int arr[n+1]={0};
			arr[0] = 1;
			arr[1] = 1;

			for(int i=2;i<=sqrt(n);i++)
				if(arr[i] == 0)
					for(int j=i*i;j<=n;j+=i)
						arr[j] = 1;

			cout<<"Seive Array :";
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;

			/*
			iterate from 1 to n
			identify the prime number with the condition arr[i] == 0
			calculate the sum of prime numbers and store it in dp
			with the reference of index
			*/

			long long int runningPrimeSum = 0;
			cout<<"Prime Numbers:";
			for(int i=1;i<=n;i++){
				if(arr[i] == 0 && (cout<<i<<" "))
					runningPrimeSum += i;
				dp[i] = runningPrimeSum;
			}
		}

		long long int printSum(){
			return dp[n];
			/*
			also used to print sum of prime numbers in a given range 
			--> return dp[n]-dp[5-1] to display sum of prime numbers
			between 5 to n inclusive.
			*/
		}
};
int main(){
	PrimeSum p(15);
	p.findSumUsingSieve();
	cout<<"\nPrime Sum :"<<p.printSum()<<endl;
}
