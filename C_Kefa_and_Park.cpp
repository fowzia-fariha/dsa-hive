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
const int N=3e2+10;
const int MOD=1e9+7;
const int mod=998244353;

//vector<vector<char>>grid(N,vector<char>(N,'#'));
//vector<vector<bool>>vis(N,vector<bool>(N,false));
//vector<int>dx={1,-1,0,0};
//vector<int>dy={0,0,1,-1};

vector<pair<int,int>>adj[N];
vector<bool>vis(N,false);
int res=0;

int dfs(int node)
{
    int res=0;
    vis[node]=true;
    for(auto it:adj[node])
    {
         if(!vis[it.fi])
         {
            res=max(res,dfs(it.fi)+it.se);
         }
    }
    return res;
}

int32_t main()
{
    opt();
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
       int n;
       cin>>n;
       //adj.resize(n);
       for(int i=0;i<n-1;i++)
       {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
       }
       cout<<dfs(0)<<endl;
    }
    return 0;
}
