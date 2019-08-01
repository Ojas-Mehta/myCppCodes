//problem link: https://practice.geeksforgeeks.org/problems/edit-distance/0
//Recursive approach
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int edit(string s1, string s2, int r1, int r2){
    if(r1<0) return r2+1;
    else if(r2<0) return r1+1;
    if(s1[r1] == s2[r2]){
        return edit(s1,s2, r1-1, r2-1);
    }
    else if(dp[r1][r2]!=0)return dp[r1][r2];
    else{
        return dp[r1][r2] = min(edit(s1,s2, r1-1, r2-1)+1, min(edit(s1,s2, r1, r2-1)+1, edit(s1,s2, r1-1, r2)+1));
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    string s1,s2;
	    cin>>m>>n>>s1>>s2;
	    memset(dp, 0, 1001*1001*4);
	    cout<<edit(s1,s2, m-1, n-1)<<'\n';
	}
	return 0;
}


//Iterative approach: turns out to be faster
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    string s1,s2;
	    cin>>m>>n>>s1>>s2;
	    for(int i=0; i<=m; i++){
	        dp[i][0]=i;
	    }
	    for(int i=0; i<=n; i++){
	        dp[0][i]=i;
	    }
	    for(int i=1; i<=m; i++){
	        for(int j=1; j<=n; j++){
	            if(s1[i-1]==s2[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
	            }
	        }
	    }
	    cout<<dp[m][n]<<'\n';
	}
	return 0;
}