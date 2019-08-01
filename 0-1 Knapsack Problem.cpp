Problem link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
//recursive
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int check(int W, int ind, int *v, int *w){
    if(ind==-1||W<=0) return 0;
    if(dp[ind][W]!=0) return dp[ind][W];
    if(W>=w[ind])
    return dp[ind][W] = max(check(W, ind-1, v, w), check(W-w[ind], ind-1, v, w)+v[ind]);
    else return dp[ind][W] = (check(W, ind-1, v, w));
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, W;
	    cin>>n>>W;
	    int v[n], w[n];
	    memset(dp, 0, 1001*1001*4);
	    for(int i=0; i<n; i++)cin>>v[i];
	    for(int i=0; i<n; i++)cin>>w[i];
	    //cout<<1<<endl;
	    cout<<check(W, n-1, v,w)<<'\n';
	}
	return 0;
}

//iterative

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, W;
	    cin>>n>>W;
	    int v[n], w[n];
	    memset(dp, 0, 1001*1001*4);
	    for(int i=0; i<n; i++)cin>>v[i];
	    for(int i=0; i<n; i++)cin>>w[i];
	    for(int i=w[0]; i<=W; i++)
	        dp[0][i]=v[0];
	    for(int i=1; i<n; i++){
	        for(int j=1; j<=W; j++){
	            if(j-w[i]>=0){
	               dp[i][j] = max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);   
	            }
	            else{
	               dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    cout<<dp[n-1][W]<<'\n';
	}
	return 0;
}