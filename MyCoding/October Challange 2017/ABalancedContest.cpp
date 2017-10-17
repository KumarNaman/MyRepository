#include <bits/stdc++.h>
using namespace std;
int n,p;
vector<int> vec;
main()
{//fsa
  int t;
  cin>>t;

  while(t--)
  {
    bool flag=false;
    cin>>n>>p;
    int hc=0,cwc=0;
    for(int i=0;i<n;i++)
    {
      int arr;
      cin>>arr;
      if(arr<=p/10)
      {
        hc++;
      }
      if(arr>=p/2)
      cwc++;
    }
     if(hc==2&&cwc==1)
     flag=true;
     if(flag==false)
     cout<<"no\n";
     else
     cout<<"yes\n";
  }
}
