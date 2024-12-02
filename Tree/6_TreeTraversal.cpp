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

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node *newNode(int val)
{
    Node *tmp=new Node();
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

Node *insert(Node *root,int val)
{
    if(root==NULL)return newNode(val);
    else if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}

void preOrder(struct Node* root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root)
{
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node* root)
{
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int32_t main()
{
    opt();
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        struct Node* root=NULL;
        root=insert(root,1);
        root=insert(root,4);
        root=insert(root,7);
        root=insert(root,2);
        root=insert(root,3);
        root=insert(root,5);
        root=insert(root,6);
        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
    }
    return 0;
}
