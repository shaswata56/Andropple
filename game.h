#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

struct pt
{
    float x,y;
};

struct score
{
    long long s;
};


int play()
{
    RenderWindow app(VideoMode(1100,720),"Andropple!");
    srand(time(0));

    Texture game, apple_red, new_game, android, top, tile;
    game.loadFromFile("res/game_bg.png");
    apple_red.loadFromFile("res/appler.png");
    android.loadFromFile("res/android.png");
    top.loadFromFile("res/game_top.png");
    tile.loadFromFile("res/tile.gif");

    Sprite sGame(game), sAppler(apple_red), sAndroid(android), sTop(top), st1(tile),st2(tile),st3(tile),st4(tile),st5(tile),st6(tile),st7(tile),st8(tile),st9(tile),st10(tile),st11(tile);

    pt apple[20];
    int life=5;
    score scr;
    scr.s=0;



    Text text;
    Font font;
    font.loadFromFile("res/tscope.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setColor(Color::Black);
    text.setStyle(Text::Bold);

    sGame.setPosition(0,0);
    st1.setPosition(0,620);
    st2.setPosition(100,620);
    st3.setPosition(200,620);
    st4.setPosition(300,620);
    st5.setPosition(400,620);
    st6.setPosition(500,620);
    st7.setPosition(600,620);
    st8.setPosition(700,620);
    st9.setPosition(800,620);
    st10.setPosition(900,620);
    st11.setPosition(1000,620);



    for(int i=0;i<5;i++)
    {
        apple[i].x=rand()%1000;
        apple[i].y=rand()%720;
    }

    int x=105,y=492,t1=1,t2=1,t3=1,t4=1,t5=1,t6=1,t7=1,t8=1,t9=1,t10=1,t11=1;
    float dy=0;

    while(app.isOpen())
    {
        Event e;
        while(app.pollEvent(e))
        {
            if(e.type == Event::Closed)
                app.close();
        }

    if(x>0 && x<=100)
    {
        if(t2 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(x>15 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>100 && x<=200)
    {
        if(t3 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t1 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>115 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>200 && x<=300)
    {
        if(t4 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t2 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>215 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>300 && x<=400)
    {
        if(t5 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t3 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>315 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>400 && x<=500)
    {
        if(t6 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t4 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>415 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>500 && x<=600)
    {
        if(t7 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t5 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>515 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>600 && x<=700)
    {
        if(t8 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t6 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>615 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>700 && x<=800)
    {
        if(t9 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t7 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>715 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>800 && x<=900)
    {
        if(t10 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t8 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>815 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>900 && x<=1000)
    {
        if(t11 && Keyboard::isKeyPressed(Keyboard::Right)) x+=10;
        if(t9 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>915 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }
    if(x>1000 && x<=1100)
    {
        if(t10 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
        if(x>1015 && Keyboard::isKeyPressed(Keyboard::Left)) x-=10;
    }

    dy=2;

    for (int i=0;i<3;i++)
    {
        apple[i].y = apple[i].y + dy;
        if (apple[i].y>720)
        {
        life--;
            apple[i].y=0;
            apple[i].x=rand()%1050;
        }
    }

    app.clear();
    app.setFramerateLimit(60);
    app.draw(sGame);
    app.draw(sTop);

    for(int i=0;i<3;i++)
    {
        sAppler.setOrigin(32.5,32.5);
        sAppler.setPosition(apple[i].x, apple[i].y);
        sAppler.setScale(0.13,0.13);
        app.draw(sAppler);

        if(sAppler.getGlobalBounds().intersects(sAndroid.getGlobalBounds()))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            scr.s++;
        }
        else if(sAppler.getGlobalBounds().intersects(st1.getGlobalBounds()) && (t1))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t1=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st2.getGlobalBounds()) && (t2))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t2=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st3.getGlobalBounds()) && (t3))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t3=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st4.getGlobalBounds()) && (t4))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t4=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st5.getGlobalBounds()) && (t5))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t5=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st6.getGlobalBounds()) && (t6))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t6=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st7.getGlobalBounds()) && (t7))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t7=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st8.getGlobalBounds()) && (t8))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t8=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st9.getGlobalBounds()) && (t9))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t9=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st10.getGlobalBounds()) && (t10))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t10=0;
            life--;
        }
        else if(sAppler.getGlobalBounds().intersects(st11.getGlobalBounds()) && (t11))
        {
            apple[i].y=0;
            apple[i].x=rand()%1050;
            t11=0;
            life--;
        }
    }

    string point = " Points:", score_str = to_string(scr.s), lyf="\n Life:", lyf_str = to_string(life);
    point.append(score_str);
    lyf.append(lyf_str);
    point.append(lyf);
    text.setString(point);

    sAndroid.setPosition(x,y);
    sAndroid.setScale(.5,.5);
    st1.setScale(2,2);
    st2.setScale(2,2);
    st3.setScale(2,2);
    st4.setScale(2,2);
    st5.setScale(2,2);
    st6.setScale(2,2);
    st7.setScale(2,2);
    st8.setScale(2,2);
    st9.setScale(2,2);
    st10.setScale(2,2);
    st11.setScale(2,2);

    if(t1) app.draw(st1);
    if(t2) app.draw(st2);
    if(t3) app.draw(st3);
    if(t4) app.draw(st4);
    if(t5) app.draw(st5);
    if(t6) app.draw(st6);
    if(t7) app.draw(st7);
    if(t8) app.draw(st8);
    if(t9) app.draw(st9);
    if(t10) app.draw(st10);
    if(t11) app.draw(st11);

    app.draw(sAndroid);
    app.draw(text);
    app.display();

    if(life < 0) return 1;
    }
    app.close();
    return 0;
}
