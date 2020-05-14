#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Animation.h"
#include "Collider.h"
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
    playerTexture.loadFromFile("graphics/image.png");
    platformTexture.loadFromFile("graphics/Ground&Stone/Ground/Ground0.png");
    Platform platform1 (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(1000.0f,0.0f));
    Platform platform2 (&platformTexture, sf::Vector2f(50.0f,50.0f), sf::Vector2f(350.0f,350.0f));
    Platform platform3 (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(200.0f,500.0f));
    Platform platform4 (&platformTexture, sf::Vector2f(50.0f,50.0f), sf::Vector2f(650.0f,250.0f));
    Platform platform5 (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(950.0f,150.0f));
    Platform platform6 (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(1150.0f,50.0f));
    Platform platform7 (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(1350.0f,-50.0f));
//    Platform platforms[3];
  //  int i = 0;
  //  while(i<3)
 //   {
  //      platforms[i]= Platform platform (&platformTexture, sf::Vector2f(128.0f,128.0f), sf::Vector2f(950.0f,150.0f));
 //   }
   // player.setTexture(&playerTexture);
    Player player(&playerTexture, sf::Vector2u(3,4),0.3f,300.0f,200.0f);
    float deltatime = 0.0f;
    sf::Clock clock;
    while (window.isOpen())
    {
        deltatime = clock.restart().asSeconds();
        sf::sleep(sf::milliseconds(9));
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                ResizeView(window,view);

        }

        player.update(deltatime);
        Collider playerCollision = player.GetCollider();
        sf::Vector2f direction;

        platform1.GetCollider().checkCollioson(playerCollision,direction,0.0f);
        if(platform2.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        if(platform3.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        if(platform4.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        if(platform5.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        if(platform6.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        if(platform7.GetCollider().checkCollioson(playerCollision,direction,1.0f))
        {
            player.onCollision(direction,deltatime);
        }
        player.onCollision(direction,deltatime);
        view.setCenter(player.GetPosition());

        //player.setTextureRect(animation.uvRect);

        window.clear(sf::Color(0,245,255));
        window.setView(view);
        player.draw(window);
        platform1.draw(window);
        platform2.draw(window);
        platform3.draw(window);
        platform4.draw(window);
        platform5.draw(window);
        platform6.draw(window);
        platform7.draw(window);
        window.display();
    }

    return 0;
}
