#include<bits/stdc++.h>
using namespace std;

void printCalender(int year);
string getMonth( int monthNum );
string getWeekName( int weekNum );
int firstDayOfYear( int year );

int main(){
    int year = 2023;
    // printCalender(year);


    cout << firstDayOfYear( year ) << endl;
    return 0;
}

void printCalender(int year){
    for( int i=0; i<12; i++ ){
        printf( "---------- %s -----------\n", getMonth(i).c_str() );
        printf("Sun Mon Tues Wed Thurs Fri Sat \n\n");
        
    }
}

string getMonth( int monthNum ){
    string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septemberr", "October", "November", "December" };
    return monthName[monthNum];
}

int firstDayOfYear( int year ){
    int x1, x2, x3;
    x1 = year / 4;
    x2 = year / 100;
    x3 = year / 400;
    return (year + x1 - x2 + x3 ) % 7;
}