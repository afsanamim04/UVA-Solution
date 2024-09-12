#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  int n;
    while(cin>>n && n!=0)
    {
        int cnt=1;
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)
          {
              while(n%i==0)
              {
                  n/=i;
              }
              cnt++;
          }
      }
      cout<<cnt<<endl;
    }
}
