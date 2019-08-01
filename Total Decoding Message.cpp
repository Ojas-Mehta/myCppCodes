// problem link: https://practice.geeksforgeeks.org/problems/total-decoding-messages/0/?track=sp-dynamic-programming
//

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n+1];
	    int dp[n+1]={};
	    char c;
	    for(int i=1; i<=n; i++){
	     cin>>c;
	     arr[i] = c-'0';  
	    }
	    if(arr[1]>=1 && arr[1]<=26)dp[1]++;
	    if(arr[2]>=1 && arr[2]<=26)dp[2]++;
	    if(arr[1]*10+arr[2]>=1 && arr[1]*10+arr[2]<=26)dp[2]++;
	    for(int i=3; i<=n; i++){
	        if(arr[i]>=1 && arr[i]<=26){
	            dp[i]=dp[i-1];
	        }
	        if(arr[i-1]!=0 && arr[i-1]*10+arr[i]>=1 && arr[i-1]*10+arr[i]<=26){
	            dp[i]+=dp[i-2];
	        }
	    }
	    int flag=0;
	    for(int i=2; i<=n; i++){
	        if(arr[i]==0 && (arr[i-1]<1 || arr[i-1]>2)){
	            flag=1;
	            break;
	        }
	    }
	    if(arr[1]==0)flag=1;
	    if(flag)cout<<0<<'\n';
	    else
	    cout<<dp[n]<<'\n';
	}
	return 0;
}