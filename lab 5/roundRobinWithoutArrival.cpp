#include<bits/stdc++.h>
using namespace std ;

struct process
{
    int id;
    int AT;
    int BT;
    int remainingBT;
    int WT;
    int TT;

};


int main()
{

    int numberOfProcesses,timeQuantum, timer = 0;
    cout << "number of process : " ;
    cin >> numberOfProcesses;
    cout  << "time Quantum : ";
    cin >> timeQuantum;

    struct process p;


    vector <struct process> pv ; // processes that are complete

    queue <struct process> pq ;

    cout << "process BT" << endl ;



    for(int i = 0 ; i < numberOfProcesses ; i++)
    {
        //cin >> p[i].id >> p[i].BT  ;
        //cin >> p1.push_back() >> p[i].BT  ;

        cin >> p.id >> p.BT ;
        p.remainingBT = p.BT;
        pq.push(p);

    }


    cout << endl ;
    while(!pq.empty())
    {
        p = pq.front();
        pq.pop();

        cout  << p.id <<" " <<   p.remainingBT << endl;

        if(p.remainingBT > timeQuantum)
        {
            timer += timeQuantum;
            p.remainingBT = p.remainingBT - timeQuantum;
            pq.push(p);

        }
        else
        {
            // the process is over
            timer += p.remainingBT;
            p.remainingBT = 0;
            p.TT = timer - 0 ; // arrival time = 0
            p.WT = p.TT - p.BT;
            pv.push_back(p);

        }
    }



    for(int i = 0 ; i < numberOfProcesses ; i++)
    {
        //cin >> p[i].id >> p[i].BT  ;
        //cin >> p1.push_back() >> p[i].BT  ;
        p = pv[i];
        cout <<"p" <<  p.id << " waiting: " << p.WT <<  " turnaround :" << p.TT   << endl ;

    }






    return 0 ;
}
