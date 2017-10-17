#include <bits/stdc++.h>
using namespace std;
list<int> *edge;
int n;
void result(int testNode)
{
  bool visited[100005]=false;
  int level[100005]={0};
  int src=1;
  level[1]=src;
  visited[1]=true;
  list<int> queue;
  queue.push_back(1);
  while(!queue.empty())
  {
    int s=queue.front();
    queue.pop_back();
    visited[s]=true;
    list<int>::iterator i;
    for(i=edge[s].begin();i!=edge[s].end();++i)
    {
      if(!visited[*i])
      {
        level[*i]=++src;
        visited[*i]=true;
        queue.push_back(*i);
      }
    }
  }
  cout<<level[testNode];
}
//my improvements
main()
{
  cin>>n;
  edge=new list<int>[100005];
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a;
    cin>>b;
    edge[a].push_back(b);
  }
  int testNode;
  cin>>testNode;
  result(testNode);

}
