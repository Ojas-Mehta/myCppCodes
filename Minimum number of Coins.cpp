//problem link: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
#include <bits/stdc++.h>
using namespace std;
int coin[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int dp[1000002], dcoin[1000002];
int main() {
	//code
	int temp;
	for(int i=1; i<=1000000; i++){
	    temp = INT_MAX;
	    for(int j=0; j<10; j++)
	    if(i-coin[j]>=0){
	        if(temp>dp[i-coin[j]]){
	            dcoin[i] = coin[j];
	            temp = dp[i-coin[j]];
	        }
	    }
	    dp[i]=temp+1;
	}
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(dp[n]);
	    int i=0;
	    while(n>0){
	        v[i++] = dcoin[n];
	        n = n-dcoin[n];
	    }
	    while(i-->0){
	        cout<<v[i]<<" ";
	    }
	    cout<<'\n';
	}
	return 0;
}