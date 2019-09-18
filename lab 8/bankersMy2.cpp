#include<bits/stdc++.h>
using namespace std;


int main()
{
    int processNum,resourceNumber;
    //safe
    processNum = 5;
    resourceNumber = 3;
    int resources[resourceNumber] = {10,5,7};
    int allocation[processNum][resourceNumber] =
    {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    int maxim[processNum][resourceNumber]=
    {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };


    int need[processNum][resourceNumber];
    cout<<"Need:"<<endl;
    int totalAlloc[resourceNumber] = {0,0,0};
    int available[resourceNumber]; // for each resources



    for(int i = 0 ; i < processNum ; i ++)
    {
        for(int j = 0 ; j < resourceNumber ; j ++)
        {
            need[i][j]= maxim[i][j]- allocation[i][j];
            totalAlloc[j] += allocation[i][j];

            cout << need[i][j] << " ";
        }
        cout << endl ;
    }

    cout << "Total: " << endl;

    for(int i = 0 ; i < resourceNumber ; i ++)
    {

        cout << totalAlloc[i] << " ";
    }
    cout << endl ;


    cout << "Available: " << endl;

    for(int i = 0 ; i < resourceNumber ; i ++)
    {
        available[i] = resources[i] - totalAlloc[i];
        cout << available[i] << " ";
    }
    cout << endl ;


    vector<int>completed ;

    int processTrack[processNum] = {0,0,0,0,0};

    while(completed.size() < processNum)
    {

        for(int i = 0 ; i < processNum ; i ++)
        {
            if(processTrack[i] == 1)continue;

            bool state = true ;
            for(int j = 0 ; j < resourceNumber ; j ++)
            {
                cout <<"P :" << i << endl;
                if(available[j]< need[i][j])
                {
                    state = false;
                }
            }
            if(state == true)
            {
                processTrack[i] = 1 ;
                completed.push_back(i);
                cout <<"P :" << i <<"completed" << endl;
                for(int j = 0 ; j < resourceNumber ; j ++)
                {
                    available[j] += allocation[i][j];

                }
            }
        }
    }

    cout << "safe Sequence: " ;
    for(int j = 0 ; j < completed.size() ; j ++)
    {
        cout << "p:" << completed[j] << " ";

    }
    cout << endl ;





}
