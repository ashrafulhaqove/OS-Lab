#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,resourceNumber;
    //safe
    p=5;
    resourceNumber=3;
    int resources[resourceNumber]= {10,5,7};
    int allo[p][resourceNumber]= { {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    int maxim[p][resourceNumber]= { {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };


    int need[p][resourceNumber];
    cout<<"Need:"<<endl;
    int totalAlloc[resourceNumber]= {0,0,0};
    int available[resourceNumber]= {0,0,0}; // for each resources
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<resourceNumber ; j++)
        {
            need[i][j]=maxim[i][j]-allo[i][j];
            totalAlloc[j]+= allo[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Available:"<<endl;
    for(int i=0; i<resourceNumber; i++)
    {
        available[i]=resources[i]-totalAlloc[i];
        cout<<available[i]<<" ";
    }

    int cnt=0;
    bool done[p];
    queue<int> q;
    bool state=false;
    bool flag=false;
    while(cnt!=p)
    {
        state=false;
        for(int i=0; i<p; i++)
        {

            if(!done[i]&&(need[i][0]<=available[0]&&need[i][1]<=available[1]&&need[i][2]<=available[2]))
            {
                q.push(i);
                int val=q.back();
                done[i]=true;
                state=true;
                cnt++;
                for(int j=0; j<resourceNumber; j++)
                {
                    available[j]+=need[i][j];
                }

            }
            if(i==p-1&&state==false&&cnt!=p)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }

    if(!state&&cnt!=p)
        cout<<"\nSystem is not in safe state."<<endl;
    else
    {
        cout<<"\nSystem is in safe state."<<endl;
        cout<<"\nSafe sequence:";
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            cout<<"P"<<val<<" ";
        }

    }

}
