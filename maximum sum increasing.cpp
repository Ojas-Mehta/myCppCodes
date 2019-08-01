// Problem link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/?track=sp-dynamic-programming&batchId=152
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n+1], dp[n+1]={}, j;
	    for(int i=0; i<n; i++){
	        cin>>arr[i+1];
	    }
	    arr[0]=0;
	    int ans=-1;
	    for(int i=1; i<=n; i++){
	        for(j=i-1; j>=0; j--){
	           if(arr[i]>arr[j]){
	               dp[i] = max(dp[i], dp[j]+arr[i]);
	           }
	        }
	        
	        ans = max(ans, dp[i]);
	        //cout<<dp[i]<<"k";
	    }
	   // cout<<endl;
	    cout<<ans<<'\n';
	    
	}
	return 0;
}