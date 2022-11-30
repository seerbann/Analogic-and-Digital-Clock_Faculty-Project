#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

#define MAX 20
#define FUNDAL CYAN
struct punct
{
    int x, y;
};

struct dreptunghi
{
    punct SS, DJ;
};

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

       // cleardevice(); //sterge consola
        //stilizare
       // setcolor(9);
       // settextstyle(3, HORIZ_DIR,7 );
        //outstreamxy(50,50);

        bgiout << "      " << ceas.ore << " : " << ceas.minute << " : " << ceas.secunde << " " << endl; ;
        outstreamxy(getmaxx()/2-75, getmaxy()/2);
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

bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;

}

struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};

buton B[6];
int nrButoane=5;
void deseneazaMeniul()
{
    setcolor(WHITE);
    rectangle(0,150,getmaxx(),getmaxy());
   // setcolor(LIGHTBLUE);
  //  setfillstyle(SOLID_FILL,LIGHTCYAN);
    int i;
    for (i=1; i<=nrButoane; i++)
    {
        B[i].D.SS.x=100*i;
        B[i].D.DJ.x=100*(i+1)-10;
        B[i].D.SS.y=50;
        B[i].D.DJ.y=80;
        switch(i)
        {
        case 1:
            strcpy(B[i].text,"Setari");
            break;
        case 2:
            strcpy(B[i].text,"Joc");
            break;
        case 3:
            strcpy(B[i].text,"Coma. 3");
            break;
        case 4:
            strcpy(B[i].text,"Alta");
            break;
        case 5:
            strcpy(B[i].text,"IESIRE");
            break;
        }
        rectangle(B[i].D.SS.x, B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
        bar(B[i].D.SS.x, B[i].D.SS.y+30, B[i].D.DJ.x, B[i].D.SS.y);
      //  setbkcolor(LIGHTCYAN);
        outtextxy(B[i].D.SS.x+25,B[i].D.SS.y+10,B[i].text);
    }
}

int butonAles()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane; i++)
            if (apartine(p,B[i].D))
                return i;
    }
    return 0;
}

int main()
{
    initwindow(800,600);
    iaTimpulLocal();
    int comanda, butonul_apasat;
    do
    {   scrieTimpul();
        deseneazaMeniul();
        butonul_apasat=butonAles();
        if (butonul_apasat!=0)
            {

                comanda=butonul_apasat;
                if(comanda==1)
                    cleardevice();
                if(comanda==2)
                    ceas.ore=ceas.ore+2;
                cout<<"Comanda "<<comanda<<endl;
            }

    }
    while (comanda!=5);

    closegraph();
    return 0;
}
