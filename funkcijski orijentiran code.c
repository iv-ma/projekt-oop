
#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;





void check_colision(int pongxy[], int player1xy[], int player2xy[], int* trigger, vector<string>& display)
{
    int broj = *trigger;


    if (pongxy[0] == 1)
    {
        if (pongxy[1] == player1xy[1] || pongxy[1] == player1xy[1]+1 || pongxy[1] == player1xy[1]-1)
        {
            *trigger = 4 + rand()%2;
            return;
        }
        else
        {
            display[pongxy[1]][pongxy[0]] = ' ';
                pongxy[0] = 6;
                pongxy[1] = 3;
                *trigger = rand()%6;
                player1xy[2]++;
        }
    }

    if (pongxy[0] == 12)
    {
        if (pongxy[1] == player2xy[1] || pongxy[1] == player2xy[1]+1 || pongxy[1] == player2xy[1]-1)
        {
            *trigger = 2 + rand()%2;
            return;
        }
        else
        {
            display[pongxy[1]][pongxy[0]] = ' ';
                pongxy[0] = 6;
                pongxy[1] = 3;
                *trigger = rand()%6;
                player2xy[2]++;
        }
    }

}

void pomak_igraca(int player1xy[], int player2xy[], vector<string>& display, char kbinput)
{
     if (kbinput == 's')
        {
            if (player1xy[1] < 5)
                player1xy[1]++;

        }
    else if (kbinput == 'w')
        {
            if (player1xy[1] > 1)
                player1xy[1]--;
        }
    else if (kbinput == 'l')
        {
            if (player2xy[1] < 5)
                player2xy[1]++;

        }
    else if (kbinput == 'o')
        {
            if (player2xy[1] > 1)
                player2xy[1]--;
        }


    for (unsigned i = 0 ; i < display.size() ; i++)
    {
        display[i][0]=' ';
        display[i][13]=' ';
    }

    display[player1xy[1]][player1xy[0]]='*';
    display[player1xy[1]-1][player1xy[0]]='*';
    display[player1xy[1]+1][player1xy[0]]='*';

    display[player2xy[1]][player2xy[0]]='*';
    display[player2xy[1]-1][player2xy[0]]='*';
    display[player2xy[1]+1][player2xy[0]]='*';


}


void pomak_lopte(int pongxy[],vector<string>& display, int* trigger)
{
    int broj = *trigger;


    display[pongxy[1]][pongxy[0]]=' ';
    switch (broj)
    {
        case 0:
            pongxy[0]--;
            break;
        case 1:
            pongxy[0]++;
            break;
        case 2:
            pongxy[0]--; pongxy[1]--;
            break;
        case 3:
            pongxy[0]--; pongxy[1]++;
            break;
        case 4:
            pongxy[0]++; pongxy[1]--;
            break;
        case 5:
            pongxy[0]++; pongxy[1]++;
            break;
        default:
            break;
    }



  if(pongxy[1] == 0)
  {
    if (broj == 2)
        *trigger = 3;
    else
        *trigger = 5;
  }

  if(pongxy[1] == 6)
  {
      if (broj == 3)
        *trigger = 2;
    else
        *trigger = 4;
  }

  display[pongxy[1]][pongxy[0]] = '0';

}

int main()
{
    srand (time(NULL));


    int player1xy[3] = {0,3,0};
    int player2xy[3] = {13,3,0};
    int pongxy[2] = {6,3};

    vector<string> display;
    string prvi = "              ";
    string drugi = "              ";
    string treci = "*            *";
    string cetvrti = "*            *";
    string peti = "*            *";
    string sesti = "              ";
    string sedmi = "              ";
    display.push_back(prvi);
    display.push_back(drugi);
    display.push_back(treci);
    display.push_back(cetvrti);
    display.push_back(peti);
    display.push_back(sesti);
    display.push_back(sedmi);

    string buffer;

    display[pongxy[1]][pongxy[0]]='0';

    int trigger;
    trigger = rand()%6;

    cout<<trigger<<"\n";
    pomak_lopte(pongxy, display, &trigger);


    while(1)
    {
        if (_kbhit())
        {
            char c = getch();
            pomak_igraca(player1xy,player2xy,display,c);
            pomak_lopte(pongxy, display, &trigger);
            cout<<trigger;
        }

        buffer.append("################");
        buffer.append("\n");

        for(unsigned i = 0 ;i < display.size() ; i++)
        {
            buffer.append("#");
            buffer.append(display[i]);
            buffer.append("#");
            buffer.append("\n");
        }
        buffer.append("################");
        pomak_lopte(pongxy,display, &trigger);

        if(pongxy[0] == 1 || pongxy[0] == 12)
        {check_colision(pongxy,player1xy,player2xy,&trigger,display);}

        cout<<"\n\n"<<buffer<<"\n\n";

        cout<<"Player 1 score "<<player1xy[2]<<endl;
        cout<<"Player 2 score "<<player2xy[2]<<endl;
        Sleep(400);
        system("cls");
        buffer.clear();

    }





    return 0;
}
