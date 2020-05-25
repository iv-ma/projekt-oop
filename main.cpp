#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "pong.h"

using namespace std;

int main()
{
    srand (time(NULL));

    PongGame instance;

    instance.postavi_display();
    instance.start_game();
}
