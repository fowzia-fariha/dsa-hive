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

//Topological Sorting using BFS=Kahn's Algorithm
//vis is not necessary

vector<vector<int>> getAdj(vector<vector<int>>&adj)
{

}

vector<int> bfs(queue<int>&q,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&inDegree)
{
    vector<int>res;
    while(!q.empty())
    {
        int cur=q.front();
        vis[cur]=true;
        res.pb(cur);
        q.pop();
        for(auto it:adj[cur])
        {
            inDegree[it]--;
            if(inDegree[it]==0 && !vis[it])
            {
                q.push(it);
            }
        }

    }
    return res;
}

vector<int> topologicalSort(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&inDegree)
{
    queue<int>q;
    for(int i=0;i<adj.size();i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
            vis[i]=true;
        }
    }
    vector<int>res=bfs(q,adj,vis,inDegree);
    return res;
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
       vector<int>inDegree(n,0);
       for(int i=0;i<n;i++)
       {
        for(auto it:adj[i])
        {
            inDegree[it]++;
        }
       }
       vector<bool>vis(n,false);
       vector<int>res=topologicalSort(adj,vis,inDegree);
    }
    return 0;
}