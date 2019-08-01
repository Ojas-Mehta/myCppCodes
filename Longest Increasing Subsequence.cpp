//problem link: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        
	    }
	    int temp;
	    int dp[n], ans=-1;
	    dp[0]=1;
	    for(int i=1; i<n; i++){
	        temp = 0;
	        for(int j=i-1; j>=0; j--){
	            if(arr[j]<arr[i]){
	                temp = max(temp, dp[j]);
	            }
	        }
	        dp[i] = temp+1;
	        ans = max(ans, dp[i]);
	    }
	    cout<<ans<<'\n';
	   // for(int i=0; i<n; i++)
	   // cout<<dp[i]<<' ';
	}
	return 0;
}