//problem link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    string a, b;
	    cin>>m>>n>>a>>b;
	    int dp[m][n]={}, ans=-1;
	    //memset(dp, 0, n*m*4);
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(a[i]==b[j]){
	                dp[i][j] = (i==0||j==0?1:dp[i-1][j-1]+1);
	                
	            }
	            else{
	                
	                dp[i][j] = max((i==0?0:dp[i-1][j]), (j==0?0:dp[i][j-1]));
	            }
	            ans = max(ans, dp[i][j]);
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}