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




int rootN;
struct Q{
    int idx;
    int l;
    int r;
};

Q query[N];

bool cmp(Q q1,Q q2)
{
    if(q1.l/rootN==q2.l/rootN)
    {
        return q1.r/rootN>q2.r/rootN;
    }
    return q1.l/rootN<q2.l/rootN;
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
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];
       rootN=sqrtl(n);
       int q;
       cin>>q;
       for(int i=0;i<q;i++)
       {
        int l,r;
        cin>>l>>r;
        query[i].l=l;
        query[i].r=r;
        query[i].idx=i;
       }
       sort(query,query+n,cmp);
       vector<int>ans(q);
       int currL=0,currR=-1,l,r;
       int currAns=0;
       for(int i=0;i<q;i++)
       {
        l=query[i].l;
        r=query[i].r;
        l--,r--;
        while(currR<r)
        {
            currR++;
            currAns+=a[currR];
        }
        while(currL>l)
        {
            currL--;
            currAns+=a[currL];
        }
        while(currR>r)
        {
            currAns-=a[currR];
            currR--;
        }
        while(currL<l)
        {
            currAns-=a[currL];
            currL++;
        }
        ans[query[i].idx]=currAns;
       }
       for(int i=0;i<n;i++)cout<<ans[i]<<" ";
       cout<<endl;
    }
    return 0;
}
