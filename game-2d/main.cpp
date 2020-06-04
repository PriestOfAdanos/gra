#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Collecatable.h"
#include "Animation.h"
#include "Collider.h"
#include "Enemy.h"
#include "Box.h"
#include "Tekst.h"

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
    sf::Texture boxTexture;
    sf::SoundBuffer BufferCoin;
    sf::Font font;
    if (!font.loadFromFile("Fonts/Boxy-Bold.ttf"))
    {
        std::cout<<"error during font loading";
    } else {
        std::cout<<"good";
    }
    Tekst tekst(&font,"chuj",48,sf::Color::Black, sf::Vector2f(50.0f,50.0f));
    BufferCoin.loadFromFile("Audio/Coin.wav");
    sf::Sound CoinSound;
    CoinSound.setBuffer(BufferCoin);
    enemyTexture.loadFromFile("graphics/dragon-2.png");
    playerTexture.loadFromFile("graphics/wilber_from_gimp.png");
    coinTexture.loadFromFile("graphics/coins.png");
    boxTexture.loadFromFile("graphics/box.png");
    platformTexture.loadFromFile("graphics/Ground&Stone/Ground/Ground0.png");
    std::vector<Collecatable> Coins;
    Coins.push_back(Collecatable(&coinTexture, sf::Vector2u(1,4),0.3f,sf::Vector2f(30.0f,30.0f),sf::Vector2f(264.0f+0*70.0f,435.0f)));
    Coins.push_back(Collecatable(&coinTexture, sf::Vector2u(1,4),0.3f,sf::Vector2f(30.0f,30.0f),sf::Vector2f(264.0f+1*70.0f,435.0f)));
    Coins.push_back(Collecatable(&coinTexture, sf::Vector2u(1,4),0.3f,sf::Vector2f(30.0f,30.0f),sf::Vector2f(264.0f+2*70.0f,435.0f)));

    Box box(&boxTexture, sf::Vector2f(60.0f,60.0f), sf::Vector2f(264.0f,400.0f));
    std::vector<Platform> platforms;
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(200.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(264.0f,500.0f)));


    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+1*64.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+2*64.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+3*64.0f,500.0f)));

    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+8*64.0f,500.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(520.0f+9*64.0f,500.0f)));


    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+4*64.0f,280.0f)));

    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+5*64.0f,775.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+6*64.0f,775.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+7*64.0f,775.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+8*64.0f,775.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+9*64.0f,775.0f)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(64.0f,64.0f), sf::Vector2f(900.0f+10*64.0f,775.0f)));

    Enemy dragon(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f);
    Player player(&playerTexture, sf::Vector2u(3,9),0.3f,300.0f,200.0f,0,1);
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
        dragon.update(deltatime);
        box.update(deltatime);
        tekst.updateText(player.lives,player.score,player.GetPosition());
        Collider playerCollision = player.GetCollider();
        Collider boxColision = box.GetCollider();
        sf::Vector2f directionBox;
        sf::Vector2f directionPlayer;
        if(box.GetCollider().checkCollioson(playerCollision,directionPlayer,0.5f))
                player.onCollision(directionPlayer,deltatime);

        for(Platform& platform : platforms)
        {
            if(platform.GetCollider().checkCollioson(playerCollision,directionPlayer,1.0f))
                player.onCollision(directionPlayer,deltatime);
            if(platform.GetCollider().checkCollioson(boxColision,directionBox,1.0f))
                box.onCollision(directionBox,deltatime);
        }
        for(Collecatable& coin: Coins)
        {
            coin.update(deltatime);
            if(coin.GetCollider().checkCollioson(playerCollision,directionPlayer,0))
            {
                CoinSound.play();
                player.onCollisionWithCoin();
                coin.removeElement();
            }
        }

        box.onCollision(directionBox,deltatime);
        player.onCollision(directionPlayer,deltatime);
        view.setCenter(player.GetPosition());

        //player.setTextureRect(animation.uvRect);

        window.clear(sf::Color(0,245,255));
        window.setView(view);
        player.draw(window);
        box.draw(window);
        dragon.draw(window);
        tekst.draw(window);
        if(dragon.GetCollider().checkCollioson(playerCollision,directionPlayer,1.0f))
        {
            player.onCollisionWithEnemy();
        }

        for(Platform& platform : platforms)
        {
            platform.draw(window);
        }
        for(Collecatable& coin : Coins)
        {
            coin.draw(window);
        }
        if(player.lives<1)
        {
            Tekst gameOver(&font,"Game\nOver",96,sf::Color::Black, sf::Vector2f(50.0f,100.0f));
            gameOver.draw(window);
        }
        window.display();
    }

    return 0;
}
