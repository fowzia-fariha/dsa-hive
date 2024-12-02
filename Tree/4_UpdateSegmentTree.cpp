#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define opt()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define double long double
#define int long long
#define db double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lcm(a, b) (a * b) / (__gcd(a, b))
#define endl "\n"

void code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int INF = 1e18;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int mod = 998244353;

// vector<vector<char>>grid(N,vector<char>(N,'#'));
// vector<vector<bool>>vis(N,vector<bool>(N,false));
// vector<int>dx={1,-1,0,0};
// vector<int>dy={0,0,1,-1};

int a[N], segTree[4 * N];

void buildTree(int node, int st, int en)
{
    if (st == en)
    {
        segTree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    buildTree(2 * node, st, mid);
    buildTree(2 * node + 1, mid + 1, en);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return INT_MIN;
    if (l <= st && en <= r)
        return segTree[node];
    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}

void updateTree(int idx, int val, int node, int st, int en)
{
    if (st == en)
    {
        a[st] = val;
        segTree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        updateTree(idx, val, 2 * node, st, mid);
    }
    else
    {
        updateTree(idx, val, 2 * node + 1, mid + 1, en);
    }
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int32_t main()
{
    opt();
    int tt = 1;
    // cin>>tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        buildTree(1, 0, n - 1);
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int idx, val;
                cin >> idx >> val;
                updateTree(idx, val, 1, 0, n - 1);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << query(1, 0, n - 1, l, r) << endl;
            }
        }
    }
    return 0;
}
