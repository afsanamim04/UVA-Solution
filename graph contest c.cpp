#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>v[100000+5];
int vis[100000+5];

void DFS(int node)
{
    vis[node]=1;
    for(auto child: v[node])
    {
        if(vis[child]==0)
            DFS(child);
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int cnt=0;
    vector<int>p;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            cnt++;
            p.pb(i);
            DFS(i);

        }
    }
    sort(p.begin(),p.end());
    cout<<p.size()-1<<endl;
    for(int i=1; i<p.size(); ++i)
    {
        cout<<p[i]-1<<' '<<p[i]<<endl;
    }
}

