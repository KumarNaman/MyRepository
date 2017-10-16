#include <bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int cnta=0,cntb=0;
    for (int i = 0; i < s.length(); i++) {
      if(s[i]=='a')
        cnta++;
      else
      cntb++;
    }
    std::vector<char> ch;
    int cntx=0,cnty=0;

    while(cnta>0||cntb>0)
    {
      if(cnta>=cntb)
      {
        if(cntx<x)
         {
           ch.push_back('a');
           cntx++;
           cnty=0;
           cnta--;
         }
         else
         {
           if(cntb!=0)
           {
             ch.push_back('b');
             cnty++;
             cntb--;
             cntx=0;
           }
          else
           {
            ch.push_back('*');
            ch.push_back('a');
            cntx=1;
            cnta--;
          }

         }
      }
      else
      {
          if(cnty<y){
           ch.push_back('b');
           cnty++;
           cntx=0;
           cntb--;
         }
         else
         {
           if(cnta!=0){
           ch.push_back('a');
            cnta--;
            cntx++;
            cnty=0;
            }
            else
            {
              ch.push_back('*');
              ch.push_back('b');
              cnty=1;
              cntb--;
            }
         }
      }
    }
    ch.push_back('\0');
    string ans(ch.begin(),ch.end());
    cout<<ans<<"\n";
  }
}
