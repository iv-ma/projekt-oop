#include "pong.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void PongGame::postavi_display()
{
    display.clear();
    string temp;

    for (int i = 0 ; i < 15 ; i++)
    {
        for (int j = 0 ; j < 30 ; j++)
        {

            if (temp.size() == 30)
                break;


            temp+=' ';
        }
        display.push_back(temp);
    }
    temp.clear();

    x_display = display[0].size();
    y_display = display.size();

    igrac1.postavi_x(0);
    igrac1.postavi_y(y_display/2);
    igrac2.postavi_x(x_display-1);
    igrac2.postavi_y(y_display/2);

    int igrac1_x = igrac1.vrati_x();
    int igrac1_y = igrac1.vrati_y();
    int igrac2_x = igrac2.vrati_x();
    int igrac2_y = igrac2.vrati_y();

    display[igrac1_y][igrac1_x]='*';
    display[igrac1_y-1][igrac1_x]='*';
    display[igrac1_y+1][igrac1_x]='*';

    display[igrac2_y][igrac2_x]='*';
    display[igrac2_y-1][igrac2_x]='*';
    display[igrac2_y+1][igrac2_x]='*';

    int loptica_x = x_display/2;
    int loptica_y = y_display/2;

    loptica.postavi_lopticu(loptica_x,loptica_y);

    display[loptica_y][loptica_x] = '0';



}


void PongGame::pomak_igraca(char kbinput)
{
    int igrac1_x = igrac1.vrati_x();
    int igrac1_y = igrac1.vrati_y();
    int igrac2_x = igrac2.vrati_x();
    int igrac2_y = igrac2.vrati_y();


     if (kbinput == 's')
        {
            if (igrac1_y < y_display-1)
                igrac1.idi_dolje();

        }
    else if (kbinput == 'w')
        {
            if (igrac1_y  > 1)
                igrac1.idi_gore();
        }
    else if (kbinput == 'l')
        {
            if (igrac2_y < y_display-1)
                igrac2.idi_dolje();;

        }
    else if (kbinput == 'o')
        {
            if (igrac2_y  > 1)
                igrac2.idi_gore();
        }

}


void PongGame::pomak_lopte()
{
    int loptica_y = loptica.vrati_y();
    int loptica_x = loptica.vrati_x();

    display[loptica_y][loptica_x]=' ';
    switch (randbroj)
    {
        case 0:
            loptica.nazad();
            break;
        case 1:
            loptica.nazad_gore();
            break;
        case 2:
            loptica.nazad_dolje();
            break;
        case 3:
           loptica.naprijed();
            break;
        case 4:
            loptica.naprijed_gore();
            break;
        case 5:
            loptica.naprijed_dolje();
            break;
        default:
            break;
    }

    loptica_y = loptica.vrati_y();
    loptica_x = loptica.vrati_x();


    if(loptica_y  == 0)
    {
        if (randbroj == 1)
            randbroj = 2;
    else
        randbroj = 5;
    }

    if(loptica_y  == y_display-1)
    {
        if (randbroj == 2)
            randbroj = 1;
        else
            randbroj = 4;
    }


    display[loptica_y][loptica_x] = '0';
}



void PongGame::check_colision()
{
    int loptica_y = loptica.vrati_y();
    int loptica_x = loptica.vrati_x();
    int igrac1_x = igrac1.vrati_x();
    int igrac1_y = igrac1.vrati_y();
    int igrac2_x = igrac2.vrati_x();
    int igrac2_y = igrac2.vrati_y();

    if (loptica_x == 1)
    {
        if (loptica_y == igrac1_y|| loptica_y == igrac1_y+1 || loptica_y == igrac1_y-1)
        {
            randbroj = 3 + rand()%3;
            return;
        }
        else
        {
            igrac2.povecaj_score();
            postavi_display();
            return;
        }
    }

    else if (loptica_x == x_display-2)
    {
        if (loptica_y == igrac2_y  || loptica_y == igrac2_y+1  || loptica_y == igrac2_y-1 )
        {
            randbroj = rand()%3;
            return;
        }
        else
        {
            igrac1.povecaj_score();
            postavi_display();
            return;
        }
    }

}

void PongGame::refresh_display()
{

    for (unsigned i = 0 ; i < display.size() ; i++)
    {
        display[i][0]=' ';
        display[i][x_display-1]=' ';
    }

    int igrac1_x = igrac1.vrati_x();
    int igrac1_y = igrac1.vrati_y();
    int igrac2_x = igrac2.vrati_x();
    int igrac2_y = igrac2.vrati_y();

    display[igrac1_y][igrac1_x]='*';
    display[igrac1_y-1][igrac1_x]='*';
    display[igrac1_y+1][igrac1_x]='*';

    display[igrac2_y][igrac2_x]='*';
    display[igrac2_y-1][igrac2_x]='*';
    display[igrac2_y+1][igrac2_x]='*';


}

void PongGame::start_game()
{
    string buffer;

    while(1)
    {



        buffer.append(x_display+2, '#');
        buffer.append("\n");

        for(unsigned i = 0 ;i < display.size() ; i++)
        {
            buffer.append("#");
            buffer.append(display[i]);
            buffer.append("#");
            buffer.append("\n");
        }
        buffer.append(x_display+2, '#');

       if(loptica.vrati_x() == 1 || loptica.vrati_x() == x_display-2)
                {check_colision();}
        pomak_lopte();


        if (_kbhit())
        {
            char c = getch();
            pomak_igraca(c);
            pomak_lopte();
            if(loptica.vrati_x() == 1 || loptica.vrati_x() == x_display-1)
                {check_colision();}
            refresh_display();
        }


        cout<<"\n\n"<<buffer<<"\n\n";

        cout<<"Player 1 score "<<igrac1.vrati_score()<<endl;
        cout<<"Player 2 score "<<igrac2.vrati_score()<<endl;
        Sleep(200);
        system("cls");
        buffer.clear();


    }

}
