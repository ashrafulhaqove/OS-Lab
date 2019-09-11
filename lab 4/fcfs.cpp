#include<bits/stdc++.h>

using namespace std ;


struct process
{
    int pId ;
    int BT;
    int AT;

};


bool comparisonFcfs(process a , process b)
{
    return(a.AT < b.AT);

}

bool comparisonSjf(process a , process b)
{
    return(a.BT < b.BT);

}


int main ()
{
    int n = 0 , a ;
    cout << "how many processes ? "  ;
    cin >> n ;

    int waitingTime[n] ;
    int totalWaitingTime;
    int turnArdTime [n];
    int TotalturnArdTime;

    struct process p[n];


    for(int i = 0 ; i < n ; i ++){

            cin >> p[i].pId ;
            cin >> p[i].BT ;
    }
    waitingTime[0] = 0 ;

    for(int i = 1 ; i < n ; i ++){

        waitingTime[i] = p[i-1].BT + waitingTime[i-1] ;
        totalWaitingTime = waitingTime[i] ;

    }
    int avgwt = totalWaitingTime / n ;

    for(int i = 0 ; i < n ; i ++){
        turnArdTime[i] = waitingTime[i] +  p[i].BT ;
        TotalturnArdTime += turnArdTime[i];

    }

    int avgtt = TotalturnArdTime / n ;

    for(int i = 0 ; i < n ; i ++){
     cout << waitingTime[i] << "   " << turnArdTime[i] <<endl ;
    }

    cout << "average waiting time : " << avgwt << endl ;
    cout << "average turn around time : " << avgtt << endl ;




    return 0 ;
}



