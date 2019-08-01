//problem link: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0/?track=sp-dynamic-programming&batchId=152


#include <iostream>
using namespace std;
int mod = 1e9+7;
int dp[100009];
int main() {
	int t;
	cin>>t;
	dp[1] = 1;
	dp[2]=2;
	for(int i=3; i<=100000; i++)dp[i] = (dp[i-1]+dp[i-2])%mod;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<dp[n]<<'\n';
	}
	return 0;
}