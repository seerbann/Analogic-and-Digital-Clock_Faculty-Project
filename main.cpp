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
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
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
            strcpy(B[i].text,"DIGITAL");
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
        setbkcolor(LIGHTCYAN);
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

void iaTimpulLocal()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // ia timpul local al calculatorului
    ceas.secunde = (timePtr->tm_sec);
    ceas.minute = (timePtr->tm_min);
    ceas.ore = (timePtr->tm_hour);
}

void afisMeniuDigital()
{
    rectangle(10,10,40,30);
    outtextxy(18,12,"<-");
}

bool apartineDigital(punct P)
{
    return 10<=P.x && P.x<=40 && 10<=P.y && P.y<=30;
}

int iesireMeniuDigital()
{
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        if (apartineDigital(p))
            return 1;
    }
    return 0;
}

void scrieTimpul()
{
    int k=1;
    while (k)
    {
        setbkcolor(1);
        cleardevice(); //sterge consola
        //stilizare
        // setcolor(9);
        //settextstyle(3, HORIZ_DIR,7 );
        //outstreamxy(50,50);
        afisMeniuDigital();
        bgiout << "      " << ceas.ore << " : " << ceas.minute << " : " << ceas.secunde << " " << endl; ;
        outstreamxy(370, 270);
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
        if(iesireMeniuDigital()!=0)
            k=0;
    }
}

int main()
{
    const int paginaMeniului=0;
    const int paginaCeasDigital=1;

    initwindow(900,600);
    deseneazaMeniul();
    setactivepage(paginaMeniului);

    int comanda, butonul_apasat;
    do
    {
        butonul_apasat=butonAles();
        if (butonul_apasat!=0)
        {
            comanda=butonul_apasat;
            cout<<"Comanda "<<comanda<<endl;

            if(comanda==3)
            {
                setactivepage(paginaCeasDigital);
                setvisualpage(paginaCeasDigital);
                iaTimpulLocal();
                scrieTimpul();
                setvisualpage(paginaMeniului);
            }
        }
    }
    while (comanda!=5);
    // getch();
    closegraph();
    return 0;
}
