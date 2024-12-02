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

//To find Minimum wighted spanning tree(MST)
//TC->O(ElogE)


vector<vector<pair<int,int>>> getAdj(vector<vector<pair<int,int>>>&adj)
{
     adj = {{{ 3,2}, {5,7}}};
     return adj;
}

int Prims(vector<vector<pair<int,int>>>&adj)
{
    int sm=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<bool>inMst(adj.size(),false);
    while(!pq.empty())
    {
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        if(inMst[node])continue;
        inMst[node]=true;
        sm+=wt;
        for(auto it:adj[node])
        {
            int next=it.first;
            int nextWt=it.second;
            pq.push({nextWt,next});
        }
    }
    return sm;
}

int32_t main()
{
    opt();
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
       vector<vector<pair<int,int>>>adj;
       getAdj(adj);
       int n=adj.size();
       int src=0;
       int sm=Prims(adj);
    }
    return 0;
}
