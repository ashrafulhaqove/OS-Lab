#include<stdio.h>
#include<vector>
#include <iostream>
#define white 1
#define gray 2
#define black 3
int node,edge,mynodes[10];

using namespace std;
vector <int> v1[10];
 void dfsvisit(int x)
 {
     mynodes[x]=gray;
     for(int i=0;i<v1[x].size();i++)
     {
         int c=v1[x][i];
         if(mynodes[c]== gray && c != x)
            cout << "cycle";
         if(mynodes[c]==white)
            dfsvisit(c);

     }
      mynodes[x]=black;
      printf("%d ",x);
 }
void dfs()
{
    for(int i=0;i<node;i++)
        mynodes[i]=white;


         for(int i=0;i<node;i++)
         {
              if( mynodes[i]==white)
         {
             dfsvisit(i);
         }
         }


}
int main()
{
    int n1,n2;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        v1[n2].push_back(n1);
        v1[n1].push_back(n2);

    }
    dfs();

}
