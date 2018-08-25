#include "load.h"
#include "game.h"

int main()
{
    int z=0;
    int x=start_game();
    if(x==1)
    {
        int y = play();
        if(y>0) z=Game_Over(y);
        else main();
        if(z) main();
    }
    if(x==2)
    {
        int y = show_obj();
        if(y) main();
    }
    if(x==3)
    {
        int y = highscore();
        if(y) main();
    }
    if(x==4)
    {
        int y = About();
        if(y) main();
    }
    return 0;
}
