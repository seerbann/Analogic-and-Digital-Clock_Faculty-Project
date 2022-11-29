#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>

#define PI 3.1415

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

int main()
{
    initwindow(500,500,"CEAS ANALOGIC");

    iaTimpulLocal();

    while(1)
    {

        cleardevice();
        setcolor(WHITE);
        circle(250,250,200);
        circle(250,250,5);
        outtextxy(250+180*sin(PI/6)-5, 250-180*cos(PI/6), "1");
        outtextxy(250+180*sin(2*PI/6)-5, 250-180*cos(2*PI/6), "2");
        outtextxy(250+180*sin(3*PI/6)-5, 250-180*cos(3*PI/6), "3");
        outtextxy(250+180*sin(4*PI/6)-5, 250-180*cos(4*PI/6), "4");
        outtextxy(250+180*sin(5*PI/6)-5, 250-180*cos(5*PI/6), "5");
        outtextxy(250+180*sin(6*PI/6)-5, 250-180*cos(6*PI/6), "6");
        outtextxy(250+180*sin(7*PI/6)-5, 250-180*cos(7*PI/6), "7");
        outtextxy(250+180*sin(8*PI/6)-5, 250-180*cos(8*PI/6), "8");
        outtextxy(250+180*sin(9*PI/6)-5, 250-180*cos(9*PI/6), "9");
        outtextxy(250+180*sin(10*PI/6)-5, 250-180*cos(10*PI/6), "10");
        outtextxy(250+180*sin(11*PI/6)-5, 250-180*cos(11*PI/6), "11");
        outtextxy(250+180*sin(12*PI/6)-5, 250-180*cos(12*PI/6), "12");

        iaTimpulLocal();

        //linia pentru ora

        setcolor(RED);
        line(250,250,250+150*sin(ceas.ore*PI/6),250-150*cos(ceas.ore*PI/6));

        //linia pentru minute

        setcolor(GREEN);
        line(250,250,250+190*sin(ceas.minute*PI/30),250-190*cos(ceas.minute*PI/30));

        //linia pentru secunde

        setcolor(WHITE);
        line(250,250,250+150*sin(ceas.secunde*PI/30),250-150*cos(ceas.secunde*PI/30));
        delay(1000);
    }
    getch();
    closegraph();
    return 0;
}
