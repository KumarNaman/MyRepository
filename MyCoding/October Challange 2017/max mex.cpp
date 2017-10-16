#include <bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
      int num;
      cin>>num;
      arr.push_back(num);
    }
    int result=-1;
    sort(arr.begin(),arr.end());
    vector<int>::iterator it ;
    it=unique(arr.begin(),arr.end());
    arr.resize(distance(arr.begin(),it));
    for(vector<int>::iterator it=arr.begin();it!=arr.end();++it)
    cout<<" "<<*it;
    cout<<*(arr.end()-1);
    int p=0;
    for(int i=0;i<*(arr.end()-1);i++)
    {
      if(k==0&&arr[p]!=i)
      {
        result=i;
        break;
      }

      if(arr[p]!=i)
      {

          k--;
          
      }
      else  p++;

    }
    if(result==-1)
    result=*(arr.end()-1)+k+1;
    cout<<result<<"\n";
  }
}
