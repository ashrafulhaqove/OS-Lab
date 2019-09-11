#include<bits/stdc++.h>

using namespace std ;


struct process
{
    int pId ;
    int BT;
    int AT;

};

bool comparison( struct process a , struct process b){
    return (a.AT < b.AT);

}


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
            cin >> p[i].AT;
            cin >> p[i].BT ;
    }
    for(int i = 0 ; i < n ; i ++){

            cout << p[i].pId << " " ;
            cout << p[i].AT << " " ;
            cout << p[i].BT << endl;
    }


    sort( p ,  p+n , comparison) ;

    for(int i = 0 ; i < n ; i ++){

            cout << p[i].pId << " " ;
            cout << p[i].AT << " " ;
            cout << p[i].BT << endl;
    }



    waitingTime[0] = 0 ;

    for(int i = 1 ; i < n ; i ++){

        waitingTime[i] = p[i-1].BT + waitingTime[i-1] - p[i].AT ;

    }

    for(int i = 0 ; i < n ; i ++){
        turnArdTime[i] = waitingTime[i] +  p[i].BT ;

    }


    for(int i = 0 ; i < n ; i ++){
     cout << waitingTime[i] << "   " << turnArdTime[i] <<endl ;
    }

    return 0 ;
}




