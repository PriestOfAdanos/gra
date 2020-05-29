#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Collecatable.h"
#include "Animation.h"
#include "Collider.h"
#include "Enemy.h"

static const float VIEW_WIDTH = 1280.0f;
static const float  VIEW_HEIGHT  = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x/float(window.getSize().y));
    float aspectRatio1 = float(window.getSize().y/float(window.getSize().x));
    view.setSize(VIEW_HEIGHT*aspectRatio, VIEW_WIDTH*aspectRatio1);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!",sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
   // sf::RectangleShape player(sf::Vector2f(100.0f,150.0f));
    //player.setPosition(206.0f,206.0f);
    sf::Texture playerTexture;
    sf::Texture platformTexture;
    sf::Texture coinTexture;
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("graphics/dragon.png");
    playerTexture.loadFromFile("graphics/tux_from_linux.png");
    coinTexture.loadFromFile("graphics/coins.png");
    platformTexture.loadFromFile("graphics/Ground&Stone/Ground/Ground0.png");
    Collecatable bottle(&coinTexture, sf::Vector2u(1,4),0.3f,sf::Vector2f(30.0f,30.0f),sf::Vector2f(264.0f,435.0f));

    std::vector<Platform> platforms;
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(200.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(264.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(328.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(392.0f,500.0f)));

    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+1*64.0f,390.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+2*64.0f,390.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+3*64.0f,390.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+4*64.0f,390.0f)));




//    Platform platforms[3];
  //  int i = 0;
  //  while(i<3)
 //   {
  //      platforms[i]= Platform platform (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(950.0f,150.0f));
 //   }
   // player.setTexture(&playerTexture);
    Enemy dragon(&enemyTexture, sf::Vector2u(3,4),0.3f,300.0f);
    Player player(&playerTexture, sf::Vector2u(3,9),0.3f,300.0f,200.0f);
    float deltatime = 0.0f;
    sf::Clock clock;
    while (window.isOpen())
    {
        deltatime = clock.restart().asSeconds();
        sf::sleep(sf::milliseconds(11));
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                ResizeView(window,view);

        }

        player.update(deltatime);
        bottle.update(deltatime);
        dragon.update(deltatime);
        Collider playerCollision = player.GetCollider();
        sf::Vector2f direction;
        for(Platform& platform : platforms)
        {
            if(platform.GetCollider().checkCollioson(playerCollision,direction,1.0f))
                player.onCollision(direction,deltatime);
        }

        player.onCollision(direction,deltatime);
        view.setCenter(player.GetPosition());

        //player.setTextureRect(animation.uvRect);

        window.clear(sf::Color(0,245,255));
        window.setView(view);
        player.draw(window);
        bottle.draw(window);
        dragon.draw(window);
        if(dragon.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollisionWithEnemy();
        }
        if(bottle.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollisionWithCoin();
            bottle.removeElement();
        }
        for(Platform& platform : platforms)
        {
            platform.draw(window);
        }
        window.display();
    }

    return 0;
}
