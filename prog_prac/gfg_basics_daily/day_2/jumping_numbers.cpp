#include<iostream>
#include<math.h>
using namespace std;
bool isJumpingNumber(int n){
	int prev = n%10;
	bool f = true;
	while(n){
		n /= 10;
		int temp = n%10;
		if(n!=0 && abs(prev-n%10)!=1){
			f = false;
			break;
		}
		prev = temp;
	}
	return f;
}
int main(){
	int num = 0, diff = 0;
	bool f = true;
	cout<<"\nEnter a Number:";
	cin>>num;
	while(num){
		if(isJumpingNumber(num)){
			cout<<num;
			return 0;
		}
		num--;
	}
	return 0;
}
