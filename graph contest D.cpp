#include<bits/stdc++.h>
#define pb push_back
#define nl endl
#define ll long long int
#define mx INT_MAX
#define mn INT_MIN
using namespace std;
vector<ll>v[100000+100];
bool vis[100000+100];
int dis[100000+100], par[100000+100];

void BFS(int node)
{
    queue<ll>q;
    q.push(node);
    vis[node]=1;
    dis[node]=1;
    par[node]=-1;

    while(!q.empty())
    {
        ll cur= q.front();
        q.pop();
        for(auto child: v[cur])
        {
            if(vis[child]==0)
            {
                dis[child]=dis[cur]+1;
                vis[child]=1;
                par[child]=cur;
                q.push(child);
            }
        }
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    BFS(1);
    if(!vis[n]) cout<<"IMPOSSIBLE"<<nl;
    else
    {
        cout<<dis[n]<<nl;
        ll i=n;
        vector<ll>v1;
       // v1.pb(n);
        while(i!=-1)
        {
            v1.pb(i);
            i=par[i];
        }
        sort(v1.begin(),v1.end());
        for(auto it: v1)
        {
            cout<<it<<' ';
        }
        cout<<nl;
    }

}
