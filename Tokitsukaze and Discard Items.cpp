//Problem: Tokitsukaze and Discard Items
//Problem Link: https://codeforces.com/contest/1191/problem/C
# include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
int main()
{
	fast;
    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[m];
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    ll point=0, cur=0, ans=0,lp=0;
    cur+= ceil((arr[point]-cur)/(long double)k)*k;
    for(;point<m;){
        lp=point;
        do{ lp=point;
            while(point<m && arr[point]<=cur){
            point++;
            }
            if(point-lp>0)
            ans++;
            cur+=point-lp;
        }while(point-lp>0);
        cur+= ceil((arr[point]-cur)/(long double)k)*k;
    }
    cout<<ans;
    return 0;
}