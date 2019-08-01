//problem link: https://practice.geeksforgeeks.org/problems/find-optimum-operation/0
#include <iostream>
using namespace std;
int dp[10004];
int main() {
	//code
	int t;
	cin>>t;
	dp[1]=1;
	for(int i=2; i<=10000; i++){
	    if(i%2==0)
	    dp[i]=min(dp[i/2],dp[i-1])+1;
	    else
	    dp[i]=dp[i-1]+1;
	}
	while(t--){
	    int n;
	    cin>>n;
	    cout<<dp[n]<<'\n';
	}
	return 0;
}