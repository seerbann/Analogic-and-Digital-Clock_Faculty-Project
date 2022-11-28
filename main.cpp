#include <iostream>
#include <graphics.h>
#include <ctime>
using namespace std;

struct
{
    int secunde;
    int minute;
    int ore;
} ceas;

void iaTimpulLocal()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // ia timpul local al calculatorului
    ceas.secunde = (timePtr->tm_sec);
    ceas.minute = (timePtr->tm_min);
    ceas.ore = (timePtr->tm_hour);
}

void scrieTimpul()
{
    while (true)
    {
        cleardevice(); //sterge consola
        //stilizare
        setcolor(9);
        settextstyle(3, HORIZ_DIR,7 );
        outstreamxy(50,50);

        bgiout << "      " << ceas.ore << " : " << ceas.minute << " : " << ceas.secunde << " " << endl; ;
        outstreamxy(150, 150);
        //incrementeaza sec min si ore
        ceas.secunde++;
        if (ceas.secunde >= 60)
        {
            ceas.secunde = 1;
            ceas.minute++;
        }
        if (ceas.minute >= 60)
        {
            ceas.minute = 0;
            ceas.ore++;
        }
        if (ceas.ore > 24)
        {
            ceas.ore= 00;
        }
        delay(1000); // opreste codul timp de 1000 ms(o secunda)
    }
}
int main()
{
    initwindow(800,600);

    iaTimpulLocal();
    scrieTimpul();

    getch();
    closegraph();
    return 0;
    return 0;
}
