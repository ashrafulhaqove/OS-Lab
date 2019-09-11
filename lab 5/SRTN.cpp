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

bool comparison(struct process a, struct process b)
{

    return a.AT < b.AT;

}

//SRTN : Shortest remaining time next


int main()
{

    int numberOfProcesses,timeQuantum, timer = 0;
    cout << "number of process : " ;
    cin >> numberOfProcesses;
    //cout  << "time Quantum : ";
    //cin >> timeQuantum;

    struct process p;


    vector <struct process> pv ; // processes that are complete

    //queue <struct process> pq ;

    cout << "process AT BT" << endl ;



    for(int i = 0 ; i < numberOfProcesses ; i++)
    {
        //cin >> p[i].id >> p[i].BT  ;
        //cin >> p1.push_back() >> p[i].BT  ;

        cin >> p.id >> p.AT >> p.BT ;
        p.remainingBT = p.BT;
        //pq.push(p);
        pv.push_back(p);

    }

    // if arrival time is not given serially
    ///sort(pq.front() , pq.back()  , comparison);

    //queue can not be sorted


    cout << endl ;


    int shortestProcess = 0;
    vector <struct process> completed;

    while(!(completed.size() >= numberOfProcesses) )
    {
        for(int i = 0 ; i < numberOfProcesses ; i++)
        {
            p = pv[i];

            if(pv[i].AT <= timer  ||  pv[i].remainingBT > 0) continue;

            if( pv[i].remainingBT < pv[shortestProcess].remainingBT   )
            {

                shortestProcess = i;
            }
        }
        // found the shortest in the second

        timer ++ ;
        pv[shortestProcess].remainingBT --;

        if(pv[shortestProcess].remainingBT == 0)
        {
            pv[shortestProcess].TT = timer - pv[shortestProcess].AT ; // arrival time = 0
            pv[shortestProcess].WT = pv[shortestProcess].TT - pv[shortestProcess].BT;
            completed.push_back(pv[shortestProcess]);

        }


    }

    for(int i = 0 ; i < numberOfProcesses ; i++)
    {
        //cin >> p[i].id >> p[i].BT  ;
        //cin >> p1.push_back() >> p[i].BT  ;
        p = completed[i];
        cout <<"p" <<  p.id << " waiting: " << p.WT <<  " turnaround :" << p.TT   << endl ;

    }


    return 0 ;
}
