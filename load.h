#include <SFML/Graphics.hpp>
using namespace sf;

struct point
{
    float x,y;
};

int start_game()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    srand(time(0));

    Texture menu, apple_r, new_game;
    menu.loadFromFile("res/menu_bg.gif");
    apple_r.loadFromFile("res/appler.png");
    new_game.loadFromFile("res/new.png");

    Sprite sMenu(menu), sAppler(apple_r), sNew(new_game);

    sMenu.setPosition(0,0);
    sNew.setPosition(350,100);

    point apple[20];

    for(int i=0;i<20;i++)
    {
        apple[i].x=rand()%1100;
        apple[i].y=rand()%720;
    }

    while(frame.isOpen())
    {
        Event e;
        while(frame.pollEvent(e))
        {
            if(e.type == Event::Closed)
                frame.close();
        }

        if(Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto dot = Mouse::getPosition(frame);
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 100) && (dot.y <= 200))
            {
                sNew.setColor(Color::Red);
                return 1;
            }
        }

        for (int i=0;i<20;i++)
        {
            apple[i].y = apple[i].y + 3;
            if (apple[i].y>720)
            {
                apple[i].y=0;
                apple[i].x=rand()%1100;
            }
        }

        frame.clear();
        frame.setFramerateLimit(30);
        frame.draw(sMenu);
        for(int i=0;i<20;i++)
        {
            sAppler.setPosition(apple[i].x, apple[i].y);
            sAppler.setScale(0.05,0.05);
            frame.draw(sAppler);
        }
        frame.draw(sNew);
        frame.display();

    }
    frame.close();
    return 0;
    }
