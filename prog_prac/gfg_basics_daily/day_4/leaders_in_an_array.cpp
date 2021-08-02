#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Time complexity for
1)vector_name.push_back() is O(1).
2)vector_name.insert(vector_name.begin(),val) is O(M+N), where N is the number of elements inserted and M is the number of the elements moved .
3)Reverse is O(n).
So that reversing is mandatory to reduce time complexity.

vector<int> leaders_in_array(vector<int> a){
	vector<int> result;
	int max = a[a.size()-1];
	result.insert(result.begin(),max);
	for(int i=a.size()-2;i>=0;i--){
		if(a[i] >= max){
			max = a[i];
			result.insert(result.begin(),max);
		}
	}
	return result;
}
*/

vector<int> leaders_in_array(vector<int> a){
        vector<int> result;
        int max = a[a.size()-1];
        result.push_back(max);
        for(int i=a.size()-2;i>=0;i--){
                if(a[i] >= max){
                        max = a[i];
                        result.push_back(max);
                }
        }
	reverse(result.begin(),result.end());
        return result;
}
int main(){
	vector<int> input = {16,17,4,3,5,2};
	vector<int> result = leaders_in_array(input);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}
