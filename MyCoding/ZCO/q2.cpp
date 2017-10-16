#include <bits/stdc++.h>
using namespace std;
main()
{
  int n,h;
  cin>>n>>h;
  vector<int> numberOfBoxes;
  for(int i=0;i<n;i++)
    {
      int boxes;
      cin>>boxes;
      numberOfBoxes.push_back(boxes);
    }
      int command=1;
      int pos=0;
      cin>>command;
      while(command)
      {

          if(command==1&&pos!=0)
          {
            pos--;
          }
          else if(command==2&&pos!=n-1)
          {
            pos++;
          }
          else if(command==3&&numberOfBoxes[pos]>=0)
          {
            numberOfBoxes[pos]--;
          }
          else if(command==4 && numberOfBoxes[pos]<h)
          {
            numberOfBoxes[pos]++;
          }
          cin>>command;
      }
      for(std::vector<int>::iterator i=numberOfBoxes.begin();i!=numberOfBoxes.end();i++)
      {
        cout<<*i<<" ";
      }
}
