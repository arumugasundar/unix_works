#include<iostream>
#include<math.h>
#include<list>
#include<queue>
#include<climits>
#include<iterator>
using namespace std;
void bfs(long n,int i,list<int> *result){
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		i = q.front();
		q.pop();
		if(i <= n){
			result->push_back(i);
			int lastDigit = i%10;
			if(lastDigit == 0)
				q.push((i*10)+(lastDigit + 1));
			else if(lastDigit == 9)
				q.push((i*10) + (lastDigit - 1));
			else{
				q.push((i*10) + (lastDigit - 1));
				q.push((i*10)+(lastDigit + 1));
			}
		}
	}
}

long largestJumpingNumber(int n){
	if(n <= 10)
		return n;
	list<int> result;
	for(int i=1;i<10 && i<=n;i++)
		bfs(n,i,&result);
	int max = INT_MIN;
	list<int> :: iterator it;
	for(it = result.begin();it!=result.end();it++){
		if(*it > max) max = *it;
		cout<<*it<<" ";
	}
	cout<<endl;
	return max;
}

int main(){
	int num;
	cout<<"\nEnter a Number:";
	cin>>num;
	long result = largestJumpingNumber(num);
	cout<<"Largest Jumping Number :"<<result<<endl;
	return 0;
}
