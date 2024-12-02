#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define double long double
#define int long long
#define db double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define endl "\n"


void code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
const int INF=1e18;
const int N=3e5+10;
const int MOD=1e9+7;
const int mod=998244353;

//vector<vector<char>>grid(N,vector<char>(N,'#'));
//vector<vector<bool>>vis(N,vector<bool>(N,false));
//vector<int>dx={1,-1,0,0};
//vector<int>dy={0,0,1,-1};


int32_t main()
{
    opt();
    //code();
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
       int n;
       cin>>n;
       string s;
       cin>>s;
       string str=s;
       sort(all(str));
       if(str==s)
       {
        cout<<0<<endl;
        continue;
       }
       string tmp="";
       tmp.pb(s[n-1]);
       string s1=s;
       s1[n-1]='*';
       for(int i=n-2;i>=0;i--)
       {
        if(tmp.back()<=s[i])
        {
            tmp.pb(s[i]);
            s1[i]='*';
        }
       }
       int j=0;
       for(int i=0;i<n;i++)
       {
        if(s1[i]=='*')
        {
            s1[i]=tmp[j++];
        }
       }
       int dp=0;
       char p=tmp[tmp.size()-1];
       for(int i=n-2;i>=0;i--)
       {
            if(s1[i]==p)dp++;
       }
       if(str==s1)
       {
        int tm;
        if(dp)tm=tmp.size()-dp;
        else tm=tmp.size();
        cout<<tm-1<<endl;
       }
       else cout<<-1<<endl;
       //cout<<tmp<<endl<<s1<<endl<<s<<endl;
    }
    return 0;
}
