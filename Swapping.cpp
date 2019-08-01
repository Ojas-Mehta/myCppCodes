// problem link: https://www.codechef.com/problems/SFRV
# include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
int main()
{   fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum+=ll(i+1)*arr[i];
        }
        ll a,b,c;
        a=0;
        b=arr[0]-arr[1];
        for(int i=2; i<n; i++){
            c = max(a, b);
            b = a + arr[i-1]-arr[i];
            a=c;
        }
        cout<<sum+max(a, b)<<'\n';


    }
    return 0;
}