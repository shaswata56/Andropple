#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
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
    buffer.loadFromFile("res/load.buf");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);

    Texture menu, apple_r, new_game, objective, high, about;
    menu.loadFromFile("res/menu_bg.imz");
    apple_r.loadFromFile("res/appler.imz");
    new_game.loadFromFile("res/new.imz");
    objective.loadFromFile("res/obj.imz");
    high.loadFromFile("res/high.imz");
    about.loadFromFile("res/abt.imz");

    Sprite sMenu(menu), sAppler(apple_r), sNew(new_game), sObj(objective), sHigh(high), sAbt(about);

    sMenu.setPosition(0,0);
    sNew.setPosition(350,50);
    sObj.setPosition(350,200);
    sHigh.setPosition(350,350);
    sAbt.setPosition(350,500);

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
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 50) && (dot.y <= 170))
            {
                return 1;
            }
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 200) && (dot.y <= 320))
            {
                return 2;
            }
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 350) && (dot.y <= 470))
            {
                return 3;
            }
            if((dot.x >= 350) && (dot.x <= 760) && (dot.y >= 500) && (dot.y <= 620))
            {
                return 4;
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
        frame.draw(sHigh);
        frame.draw(sAbt);
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
    texture.loadFromFile("res/objectives.imz");
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

using namespace std;

int Game_Over(int x)
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    frame.setFramerateLimit(10);

    Text text;
    Font font;
    font.loadFromFile("res/tscope.fnt");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);

    int score_int=0;
    FILE *fp;
    fp = fopen("res/score.sv","r");
    if(fp == NULL)
    {
        fp=fopen("res/score.sv","w");
    }
    fscanf(fp,"%d",&score_int);
    fclose(fp);

    if(score_int > x)
    {
            string line="Your score is ";
            line.append(to_string(x));
            text.setString(line);
            text.setPosition(340,100);
    }
    else
    {
        fp = fopen("res/score.sv","w");
        string line="Your new Highscore is ";
        line.append(to_string(x));
        text.setString(line);
        text.setPosition(250,100);
        fprintf(fp,"%d",x);
        fclose(fp);
    }

    SoundBuffer buffer;
    buffer.loadFromFile("res/over.buf");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    Texture texture;
    texture.loadFromFile("res/over.imz");
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
        frame.draw(text);
        frame.display();
    }
    frame.close();
    return 0;
}

int highscore()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    frame.setFramerateLimit(10);
    Texture texture;
    texture.loadFromFile("res/hsbg.imz");
    Sprite sprite(texture);
    sprite.setPosition(0,0);

    Text text;
    Font font;
    font.loadFromFile("res/tscope.fnt");
    text.setFont(font);
    text.setCharacterSize(72);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);

    string line;
    int a;
    FILE *fp;
    fp= fopen("res/score.sv","r");
    if(fp == NULL)
    {
        fp=fopen("res/score.sv","w");
        a=-1;
    }
    else{
        fscanf(fp,"%d",&a);
        fclose(fp);
    }
    if(a>0)
    {
        line="YOUR HIGHSCORE IS ";
        line.append(to_string(a));
        text.setString(line);
        text.setPosition(250,200);
    }
    else{
        line="YOU HAVE NO SAVED SCORE YET";
        text.setString(line);
        text.setPosition(100,200);
    }
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
        frame.draw(text);
        frame.display();
    }
    frame.close();
    return 0;
}

int About()
{
    RenderWindow frame(VideoMode(1100,720),"Andropple!");
    frame.setFramerateLimit(10);
    Texture texture;
    texture.loadFromFile("res/about.imz");
    Sprite sprite(texture);
    sprite.setPosition(0,0);

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
