#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

struct {
    int seconds;
    int minutes;
    int hours;
}ceas;

void getTime()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // stores the local time of the computer.
    ceas.seconds = (timePtr->tm_sec);
    ceas.minutes = (timePtr->tm_min);
    ceas.hours = (timePtr->tm_hour);
}

int main()
{

    getTime();
    while (true)
    {
        system("cls");

        cout << "Timpul digital este:";
        // This output the message "The digital time is :"

        cout << "      " << ceas.hours << " : " << ceas.minutes << " : " << ceas.seconds << " " << endl;
        //increment sec min and hours
        ceas.seconds++;
        if (ceas.seconds >= 60)
        {
            ceas.seconds = 1;
            ceas.minutes++;
        }
        // This increases the minutes
        if (ceas.minutes >= 60)
        {
            ceas.minutes = 0;
            ceas.hours++;
        }
        // This increases the hours
        if (ceas.hours > 24)
        {
            ceas.hours= 00;
        }

        Sleep(1000); // opreste codul timp de 1000 ms(o secunda)
    }

    return 0;
}
