#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#define PI 3.1415

using namespace std;

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

struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};

bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;

}

buton B[6];
int nrButoane=5;
void deseneazaMeniul()
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,LIGHTRED);
    int i;
    for (i=1; i<=nrButoane; i++)
    {
        B[i].D.SS.x=100*i;
        B[i].D.DJ.x=100*(i+1)-5;
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
            strcpy(B[i].text,"Digital");
            break;
        case 4:
            strcpy(B[i].text,"Analogic");
            break;
        case 5:
            strcpy(B[i].text,"IESIRE");
            break;
        }
        rectangle(B[i].D.SS.x, B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
        bar(B[i].D.SS.x, B[i].D.SS.y+30, B[i].D.DJ.x, B[i].D.SS.y);
        setbkcolor(LIGHTRED);
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


void afisCasutaIesire()
{
    rectangle(10,10,40,30);
    outtextxy(18,12,"<-");
}

bool apartineCasutaIesire(punct P)
{
    return 10<=P.x && P.x<=40 && 10<=P.y && P.y<=30;
}

int intoarcereMeniuPrincipal()
{
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        if (apartineCasutaIesire(p))
            return 1;
    }
    return 0;
}


void scrieTimpulDigital()
{
    int k=1;
    while (k)
    {
        setbkcolor(BLACK);
        cleardevice(); //sterge consola
        setcolor(WHITE);
        afisCasutaIesire();
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
        if(intoarcereMeniuPrincipal()!=0)
        {
            k=0;
            cout<<"[INFO]Intoarcere la meniu."<<endl;
        }

    }
}


void afiseazaCeasAnalogic()
{
    int k=1;
    while(k)
    {
        setbkcolor(BLACK);
        cleardevice();
        afisCasutaIesire();
        setcolor(WHITE);
        circle(350,350,200);
        circle(350,350,5);
        outtextxy(350+180*sin(PI/6)-5, 350-180*cos(PI/6), "1");
        outtextxy(350+180*sin(2*PI/6)-5, 350-180*cos(2*PI/6), "2");
        outtextxy(350+180*sin(3*PI/6)-5, 350-180*cos(3*PI/6), "3");
        outtextxy(350+180*sin(4*PI/6)-5, 350-180*cos(4*PI/6), "4");
        outtextxy(350+180*sin(5*PI/6)-5, 350-180*cos(5*PI/6), "5");
        outtextxy(350+180*sin(6*PI/6)-5, 350-180*cos(6*PI/6), "6");
        outtextxy(350+180*sin(7*PI/6)-5, 350-180*cos(7*PI/6), "7");
        outtextxy(350+180*sin(8*PI/6)-5, 350-180*cos(8*PI/6), "8");
        outtextxy(350+180*sin(9*PI/6)-5, 350-180*cos(9*PI/6), "9");
        outtextxy(350+180*sin(10*PI/6)-5, 350-180*cos(10*PI/6), "10");
        outtextxy(350+180*sin(11*PI/6)-5, 350-180*cos(11*PI/6), "11");
        outtextxy(350+180*sin(12*PI/6)-5, 350-180*cos(12*PI/6), "12");

        iaTimpulLocal();

        //linia pentru ora

        setcolor(RED);
        line(350,350,350+150*sin(ceas.ore*PI/6),350-150*cos(ceas.ore*PI/6));

        //linia pentru minute

        setcolor(GREEN);
        line(350,350,350+190*sin(ceas.minute*PI/30),350-190*cos(ceas.minute*PI/30));

        //linia pentru secunde

        setcolor(WHITE);
        line(350,350,350+150*sin(ceas.secunde*PI/30),350-150*cos(ceas.secunde*PI/30));
        delay(1000);
        if(intoarcereMeniuPrincipal()!=0)
        {
            k=0;
            cout<<"[INFO]Intoarcere la meniu."<<endl;
        }
    }
}

int main()
{
    const int paginaMeniului=0;
    const int paginaCeasDigital=1;
    const int paginaCeasAnalogic=2;
    int comanda, butonul_apasat;
    initwindow(900,600);
    deseneazaMeniul();
    setactivepage(paginaMeniului);

    do
    {
        butonul_apasat=butonAles();
        if (butonul_apasat!=0)
        {
            comanda=butonul_apasat;
            cout<<"[INFO]Comanda "<<comanda<<endl;
            if(comanda==3)
            {
                cout<<"[INFO]Afisare ceas digital."<<endl;
                setactivepage(paginaCeasDigital);
                setvisualpage(paginaCeasDigital);
                iaTimpulLocal();
                scrieTimpulDigital();
                setvisualpage(paginaMeniului);
            }
            if(comanda==4)
            {
                cout<<"[INFO]Afisare ceas analogic."<<endl;
                setactivepage(paginaCeasAnalogic);
                setvisualpage(paginaCeasAnalogic);
                afiseazaCeasAnalogic();
                setvisualpage(paginaMeniului);
            }
            if(comanda==5)
                cout<<"[INFO]IESIRE.";
        }
    }
    while (comanda!=5);
    closegraph();
    return 0;
}
