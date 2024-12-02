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

//DSU


vector<vector<int>> getAdj(vector<vector<int>>&adj)
{
     adj = {{{1, 3,2}, {2,5,7}}};
     return adj;
}

void dfsFill(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        dfsFill(it,adj,vis,st);
    }
    st.push(node);
}

void dfsTraversal(int node,vector<vector<int>>&revAdj,vector<bool>&vis)
{
    vis[node]=true;
    for(auto it:revAdj[node])
    {
        if(!vis[it])
        {
            dfsTraversal(it,revAdj,vis);
        }
    }
}

int kosaraju(vector<vector<int>>&adj)
{
    //Step-1:
    stack<int>st;
    vector<bool>vis(adj.size(),false);
    for(int i=0;i<adj.size();i++)
    {
        if(!vis[i])
        {
            dfsFill(i,adj,vis,st);
        }
    }
    //Step-2:
    vector<vector<int>>revAdj(adj.size());
    for(int i=0;i<adj.size();i++)
    {
        for(auto it:adj[i])
        {
            revAdj[it].push_back(i);
        }
    }
    //Step-3:
    int scc=0;
    vis=vector<bool>(adj.size(),false);
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            dfsTraversal(node,revAdj,vis);
            scc++;
        }
    }
}

int32_t main()
{
    opt();
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
       vector<vector<int>>adj;
       getAdj(adj);
       int n=adj.size();
       int src=0;
       int scc=kosaraju(adj);
    }
    return 0;
}
