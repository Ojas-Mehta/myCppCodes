//problem link:https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int dp[n+1];
        fill(dp, dp+n+1, INT_MAX);
        
        if(arr[0]==0){
            cout<<"-1\n";
        }
        else{
            dp[0] = 1;
            int temp, ind, upto, flag=1, ans=0;
            for(int i=0; i<n; i++){
                upto = arr[i];
                temp = 0;
                ind = i;
                if(i>=n-1){
                    dp[n]=dp[i];
                    break;
                }
                if(i+arr[i]>=n-1){
                    dp[n]=dp[i];
                    break;
                }
                for(int j=1; j<=upto; j++){
                    if(i+j<n-1 && arr[i+j]==0)continue;
                    if(i+j>=n-1){
                        dp[n]=dp[i];
                        ans=1;
                        break;
                    }
                    if(i+j<n-1 && arr[i+j]+j>temp){
                        temp = arr[i+j]+j;
                        ind = i+j;
                    }
                    
                }
                if(ans)break;
                if(ind==i){
                    flag=0;
                    break;
                }
                if(ind>=n-1){
                    dp[ind] = dp[i];
                    break;
                }
                dp[ind] = dp[i]+1;
                i=ind-1;
            }
            if(!flag){
                cout<<-1<<'\n';
            }
            else{
                cout<<dp[n]<<'\n';
            }
        
        }
    }
	return 0;
}.cpp