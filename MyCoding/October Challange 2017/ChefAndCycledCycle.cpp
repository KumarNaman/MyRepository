#include <bits/stdc++.h>
using namespace std;
class Cycles
{

  public:
    int v1,v2;
    int w;

    int numberOfNodes;
    int wt[100005];
    int cycleSum;
    int destination;
    int start;
    int cycleId;
    int otherCycleSum;
};
int toStartNodeSum(int c1,int v1,Cycles cycle[])
{
  c1--;
  v1--;
  int sum=0;
  int flag=0;
  cout<<"%"<<cycle[c1].start<<"%\n";
  if(flag==0)
  {
    for(int i=v1;;(i==(cycle[c1].numberOfNodes-1))?i=0:i++)
    {

      if(i==cycle[c1].start)
        {break;
          cout<<"p";
        }
      sum+=cycle[c1].wt[i];
      if(i==cycle[c1].destination)
      {
        flag=1;
        break;
      }
    }
  }
  if(flag==1)
  {
    for(int i=v1;i!=cycle[c1].start;(i==0)?(i=cycle[c1].numberOfNodes-1):i--)
    {
      sum+=cycle[c1].wt[(i-1==-1)?(cycle[c1].numberOfNodes-1):i-1];
    }
  }
  return sum;
}
int toEndNodeSum(int c1,int v1,Cycles cycle[])
{
  c1--;
  v1--;
  int sum=0;
  int flag=0;
  if(flag==0)
  {
    for(int i=v1;;(i==(cycle[c1].numberOfNodes-1))?i=0:i++)
    {
      if(i==cycle[c1].destination)
        break;
      sum+=cycle[c1].wt[i];
      if(i==cycle[c1].start)
      {
        flag=1;
        break;
      }
    }
  }
  if(flag==1)
  {
    for(int i=v1;i!=cycle[c1].destination;(i==0)?(i=cycle[c1].numberOfNodes-1):i--)
    {
      sum+=cycle[c1].wt[(i-1==-1)?(cycle[c1].numberOfNodes-1):i-1];
    }
  }
  return sum;
}
int toSumStartToEndNode(int c,Cycles cycle[])
{
  c--;
  int sum=0;
  for(int i=cycle[c].start;i!=cycle[c].destination;(i==(cycle[c].numberOfNodes-1))?i=0:i++)
  {
    sum+=cycle[c].wt[i];
  }
  return sum;
}
int toSumEndToStartNode(int c,Cycles cycle[])
{
  c--;
  int sum=0;
  for(int i=cycle[c].destination;i!=cycle[c].start;(i==cycle[c].numberOfNodes-1)?i=0:i++)
  {
    sum+=cycle[c].wt[i];
  }
  return sum;
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {

 int n,q;
    cin>>n>>q;
    cout<<"dsa";
      int node[100005];
    Cycles cycle[n+10];

    for(int i=0;i<n;i++)
    {

      cycle[i].cycleId=i;
      int nde;
     cin>>nde;
     cycle[i].numberOfNodes=nde;


     for(int j=0;j<nde;j++)
     {
       int wt;
       cin>>wt;
    cycle[i].wt[j]=wt;
       cycle[i].cycleSum+=cycle[i].wt[j];
cout<<cycle[i].cycleSum;
     }
    }

    for(int i=0;i<n;i++)
    {
       cout<<"fsa";
    int v1,v2,w;
      cin>>v1>>v2>>w;
      cycle[i].v1=v1-1;
      cycle[i%n+1].v2=v2-1;
      cycle[i].w=w;
      cycle[i].destination=v2-1;
      cycle[i%n+1].start=v1-1;

    }
    for(int i=0;i<n;i++)
    {
      cycle[i].otherCycleSum=min(toSumStartToEndNode(i,cycle),cycle[i].cycleSum-toSumStartToEndNode(i,cycle));
    }

    while(q--)
    {

      int v1,v2,c1,c2;
      cin>>v1>>v2>>c1>>c2;

   int sumToStartNode=toStartNodeSum(c1,v1,cycle);
       int sumToEndNode=toEndNodeSum(c1,v1,cycle);
    int sumStartToEndNodeSource=cycle[c1].cycleSum-sumToStartNode-sumToEndNode;
      int c=c1;
      int sumRoadFive=sumStartToEndNodeSource+sumToEndNode;
      int sumRoadSix=sumStartToEndNodeSource+sumToStartNode;
      int sumRoadOne=sumToStartNode+cycle[c].w;
      int sumRoadTwo=sumToEndNode+cycle[(c-1==0)?n-1:c-1].w;
      int posRoadOne=cycle[c].destination;
      int posRoadTwo=cycle[c].start;

      //case 1
      while(cycle[c].cycleId!=cycle[c2].cycleId)
      {
         sumRoadOne+=cycle[c].otherCycleSum;
         sumRoadOne+=cycle[c].w;
         posRoadOne=cycle[c].destination;
          c=c%n+1;
      }

      c=c1;
      //case 2
      while(cycle[c].cycleId!=cycle[c2].cycleId)
      {
        sumRoadTwo+=min(toSumEndToStartNode(c,cycle),cycle[c].cycleSum-toSumEndToStartNode(c,cycle));
        sumRoadTwo+=cycle[c].w;
        posRoadTwo=cycle[c].start;
        c=(c-1==0)?n-1:c-1;
      }
      sumRoadFive+=sumRoadOne-sumToStartNode;
      sumRoadSix+=sumRoadOne-sumToEndNode;
      int sumRoadThree;
      int sumRoadFour;

      int sumStartToEndNodeDest=cycle[c2].cycleSum-toStartNodeSum(c2,v2,cycle)-toEndNodeSum(c2,v2,cycle);
      if(posRoadOne==cycle[c2].start)
      {
        sumRoadThree=sumStartToEndNodeDest+toEndNodeSum(c2,v2,cycle)+sumRoadOne;
        sumRoadOne+=toStartNodeSum(c2,v2,cycle);
        sumRoadFive+=sumStartToEndNodeDest+toEndNodeSum(c2,v2,cycle);
      }
      else
      {
      
        sumRoadThree=sumStartToEndNodeDest+toStartNodeSum(c2,v2,cycle)+sumRoadOne;
        sumRoadOne+=toEndNodeSum(c2,v2,cycle);
        sumRoadFive+=sumStartToEndNodeDest+toStartNodeSum(c2,v2,cycle);
      }
      if(posRoadTwo==cycle[c2].destination)
      {
        sumRoadFour=sumStartToEndNodeDest+toStartNodeSum(c2,v2,cycle)+sumRoadTwo;
        sumRoadTwo+=toEndNodeSum(c2,v2,cycle);
        sumRoadSix+=sumStartToEndNodeDest+toStartNodeSum(c2,v2,cycle);
      }
      else
      {
        sumRoadSix+=sumStartToEndNodeDest+toEndNodeSum(c2,v2,cycle);
        sumRoadFour=sumStartToEndNodeDest+toStartNodeSum(c2,v2,cycle)+sumRoadTwo;
        sumRoadTwo+=toStartNodeSum(c2,v2,cycle);
      }
      cout<<"R1-"<<sumRoadOne<<"\n";
      cout<<"R2-"<<sumRoadTwo<<"\n";
      cout<<"R3-"<<sumRoadThree<<"\n";
      cout<<"R4-"<<sumRoadFour<<"\n";
      cout<<"R5-"<<sumRoadFive<<"\n";
      cout<<"R6-"<<sumRoadSix<<"\n";

       cout<<min(min(min(sumRoadOne,sumRoadFive),min(sumRoadTwo,sumRoadSix)),min(sumRoadThree,sumRoadFour))<<"\n";

    }

  }
  cout<<"Yessss";
}
