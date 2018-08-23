#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

struct point
{
    float x,y;
};

int start_game()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    srand(time(0));

    SoundBuffer buffer;
    buffer.loadFromFile("res/load.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);

    Texture menu, apple_r, new_game, objective, obj;
    menu.loadFromFile("res/menu_bg.gif");
    apple_r.loadFromFile("res/appler.png");
    new_game.loadFromFile("res/new.png");
    objective.loadFromFile("res/obj.png");

    Sprite sMenu(menu), sAppler(apple_r), sNew(new_game), sObj(objective);

    sMenu.setPosition(0,0);
    sNew.setPosition(350,100);
    sObj.setPosition(350,250);

    point apple[20];
    int frm=0;

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

        frm++;
        if(frm==2) sound.play();

        if(Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto dot = Mouse::getPosition(frame);
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 100) && (dot.y <= 200))
            {
                return 1;
            }
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 250) && (dot.y <= 360))
            {
                return 2;
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
        frame.draw(sObj);
        frame.display();

    }
    frame.close();
    return 0;
}

int show_obj()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    frame.setFramerateLimit(10);
    Texture texture;
    texture.loadFromFile("res/objectives.gif");
    Sprite sprite(texture);
    sprite.setPosition(150,100);

    while(frame.isOpen())
    {
        Event e;
        while(frame.pollEvent(e))
        {
            if(e.type == Event::Closed)
                frame.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)) return 1;
        frame.clear();
        frame.draw(sprite);
        frame.display();
    }
    frame.close();
    return 0;
}

int Game_Over()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    frame.setFramerateLimit(10);
    SoundBuffer buffer;
    buffer.loadFromFile("res/over.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    Texture texture;
    texture.loadFromFile("res/over.png");
    Sprite sprite(texture);
    sprite.setPosition(0,0);

    int i=0;

    while(frame.isOpen())
    {
        Event e;
        while(frame.pollEvent(e))
        {
            if(e.type == Event::Closed)
                frame.close();
        }
        i++;
        if(i==1) sound.play();
        if(Keyboard::isKeyPressed(Keyboard::Escape)) return 1;
        frame.clear();
        frame.draw(sprite);
        frame.display();
    }
    frame.close();
    return 0;
}
