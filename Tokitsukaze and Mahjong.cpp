//problems: Tokitsukaze and Mahjong
//Problem Link: https://codeforces.com/contest/1191/problem/B
# include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
int m[10], p[10], s[10];
int main()
{
	fast;
    string temp;
    for(int i=0;i<=2; i++){
        cin>>temp;
        if(temp[1]=='m')m[(int)(temp[0]-'0')]++;
        else if(temp[1]=='s')s[(int)(temp[0]-'0')]++;
        else if(temp[1]=='p')p[(int)(temp[0]-'0')]++;
 
    }
    int cnt, ans=-1;
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(m[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+1<=9 && m[i+1]>=1){
                cnt++;
                if(i+2<=9 && m[i+2]>=1){
                    cnt++;
 
                }
            }
        }
        if(cnt>ans)ans=cnt;
    }
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(m[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+2<=9 && m[i+2]>=1){
                cnt++;
            }
        }
        if(cnt>ans)ans=cnt;
    }
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(p[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+2<=9 && p[i+2]>=1){
                cnt++;
            }
        }
        if(cnt>ans)ans=cnt;
    }
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(s[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+2<=9 && s[i+2]>=1){
                cnt++;
            }
        }
        if(cnt>ans)ans=cnt;
    }
 
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(s[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+1<=9 && s[i+1]>=1){
                cnt++;
                if(i+2<=9 && s[i+2]>=1){
                    cnt++;
 
                }
            }
        }
        if(cnt>ans)ans=cnt;
    }
    for(int i=1; i<=9; i++){
            //cout<<m[i]<<endl;
            cnt=0;
        if(p[i]>=1){
            cnt++;
            //cout<<cnt;
            if(i+1<=9 && p[i+1]>=1){
                cnt++;
                if(i+2<=9 && p[i+2]>=1){
                    cnt++;
 
                }
            }
        }
        if(cnt>ans)ans=cnt;
    }
    cnt = 0;
     for(int i=1; i<=9; i++){
        cnt = s[i];
        if(cnt>ans)ans = cnt;
     }
     for(int i=1; i<=9; i++){
        cnt = p[i];
        if(cnt>ans)ans = cnt;
     }
     for(int i=1; i<=9; i++){
        cnt = m[i];
        if(cnt>ans)ans = cnt;
     }
    cout<<3-ans;
 
 
    return 0;
}
