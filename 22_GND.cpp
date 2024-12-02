#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N=1e5+9;
int a[35];
int grundy[N];
 int n,m;

int calcSg(int x)
{
    if(x<a[0] || x==0)return 0;
    if(grundy[x]!=-1)return grundy[x];
    bool vis[35];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<m;i++)
    {
        if(x>=a[i])
        {
            vis[calcSg(x-a[i])]=true;
        }
    }
    int m=0;
    while(vis[m])m++;
    return grundy[x]=m;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(grundy,-1,sizeof(grundy));

        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        sort(a,a+m);
        int xs=0;
        for(int i=0;i<n;i++)
        {
            int piles;
            cin>>piles;
            xs^=calcSg(piles);
        }
        if(xs)cout<<"Ada"<<endl;
        else cout<<"Vinit"<<endl;
    }
    return 0;

}
