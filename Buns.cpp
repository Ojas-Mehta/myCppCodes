//problems: sBuns
//Problem Link: https://codeforces.com/contest/106/problem/C
# include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
	fast;
    int n,m;
    cin>>n>>m;
    int a[m+1],c[m+1],d[m+1], dp[n+1][m+1],temp1, temp2;
    memset(dp, 0, n*m*4+4*n+4*m+4);
    cin>>c[0]>>d[0];
    a[0]=INT_MAX;
    for(int i=1; i<=m; i++){
        cin>>temp1>>temp2>>c[i]>>d[i];
        a[i]=temp1/temp2;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = (i/c[0])*d[0];
    }
    for(int j=1; j<=m; j++){
    for(int i=1; i<=n; i++){
 
                temp1 = min(a[j],(i/c[j])*d[j]);
                temp2=max(dp[i-1][j],dp[i][j-1]);
                for(int k=0; k<=temp1;k++){
                    if(i-k*c[j]>=0)
                    temp2 = max(temp2, k*d[j]+dp[(i-k*c[j])][j-1]);
                    else break;
                }
                dp[i][j] = temp2;
        }
    }
cout<<dp[n][m];
 
    return 0;
}