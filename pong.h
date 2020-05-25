#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#ifndef PONG.H
#define PONG.H

using namespace std;

class Ball
{
private:
    int ball_x;
    int ball_y;

public:
    void postavi_lopticu(int unos_x,int unos_y){ball_x = unos_x; ball_y = unos_y;};
    int vrati_x(){return ball_x;};
    int vrati_y(){return ball_y;};
    void nazad_dolje(){ball_x--;ball_y++;};
    void nazad_gore(){ball_x--;ball_y--;};
    void nazad(){ball_x--;};
    void naprijed_gore(){ball_x++;ball_y--;};
    void naprijed_dolje(){ball_x++;ball_y++;};
    void naprijed(){ball_x++;};
};

class Player
{
private:
    int x,y;
    int score = 0;
public:
    void povecaj_score(){score++;};
    void postavi_x(int unos){x = unos;};
    void postavi_y(int unos){y = unos;};
    void idi_dolje(){y++;};
    void idi_gore(){y--;};
    int vrati_x(){return x;};
    int vrati_y(){return y;};
    int vrati_score(){return score;};
};



class PongGame
{
private:
    Player igrac1;
    Player igrac2;
    vector<string> display;
    int x_display;
    int y_display;
    Ball loptica;
    int randbroj = rand()%6;


public:
    void postavi_display();
    void start_game();
    void pomak_igraca(char);
    void pomak_lopte();
    void check_colision();
    void refresh_display();
};








#endif // PONG


