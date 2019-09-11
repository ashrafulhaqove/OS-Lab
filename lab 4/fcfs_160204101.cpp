#include<bits/stdc++.h>

using namespace std ;


struct process
{
    int pId ;
    int BT;

};


int main ()
{
    int n = 0 ;
    cout << "how many processes ? "  ;
    cin >> n ;

    int waitingTime[n] ;

    int turnArdTime [n];

    struct process p[n];


    for(int i = 0 ; i < n ; i ++){

            cin >> p[i].pId ;
            cin >> p[i].BT ;
    }


    waitingTime[0] = 0 ;

    for(int i = 1 ; i < n ; i ++){

        waitingTime[i] = p[i-1].BT + waitingTime[i-1] ;

    }

    for(int i = 0 ; i < n ; i ++){
        turnArdTime[i] = waitingTime[i] +  p[i].BT ;

    }


    for(int i = 0 ; i < n ; i ++){
     cout << waitingTime[i] << "   " << turnArdTime[i] <<endl ;
    }

    return 0 ;
}




