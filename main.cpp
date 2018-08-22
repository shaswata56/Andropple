#include "load.h"
#include "game.h"



int main()
{
    int x=start_game();
    if(x==1)
    {
        int y = play();
        if(y) main();
    }
    if(x==2)
    {
        int y = show_obj();
        if(y) main();
    }
    return 0;
}
