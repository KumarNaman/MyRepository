#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
     vector<long long> v;
    for(int i=0;i<n;i++)
    {
      int c;
      cin>>c;
      v.push_back(c);
    }
    sort(v.begin(),v.end());
    int customerCount=n;
    long long ans=0;
    long long max=-1;
    for(int i=0;i<n;i++)
    {
      if(v[i]==v[i-1]&&i>0)
        {
          customerCount--;
          continue;
        }
        ans=v[i]*customerCount;
        if(ans>max)
        {
          max=ans;
        }
        customerCount--;
    }
    cout<<max;
}
