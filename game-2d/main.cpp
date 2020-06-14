#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <memory>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Collecatable.h"
#include "Animation.h"
#include "Collider.h"
#include "Enemy.h"
#include "Box.h"
#include "Tekst.h"

int incrementDragon = 0;

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
    sf::Texture rockTexture;
    if (!rockTexture.loadFromFile("graphics/Rock.png"))
    {
        std::cout<<"error during font loading";
    }
    sf::Font font;
    if (!font.loadFromFile("Fonts/Boxy-Bold.ttf"))
    {
        std::cout<<"error during font loading";
    }
    BufferCoin.loadFromFile("Audio/Coin.wav");
    sf::Sound CoinSound;
    CoinSound.setBuffer(BufferCoin);
    enemyTexture.loadFromFile("graphics/dragon-2.png");
    playerTexture.loadFromFile("graphics/wilber_from_gimp.png");
    coinTexture.loadFromFile("graphics/coins.png");
    boxTexture.loadFromFile("graphics/box.png");
    platformTexture.loadFromFile("graphics/Ground&Stone/Ground/Ground0.png");
    float totalScore;
    std::vector<Platform*> platforms;
    std::vector<Collecatable*> Coins;
    std::vector<Enemy*> dragons;

        Box box(&boxTexture, sf::Vector2f(60.0f,60.0f), sf::Vector2f(210.0f,520.0f));
        platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(136.0f, 550.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(200.0f, 550.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(264.0f, 550.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(328.0f, 550.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(520.0f + 1 * 64.0f, 390.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(520.0f + 2 * 64.0f, 390.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(520.0f + 3 * 64.0f, 390.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(520.0f + 4 * 64.0f, 390.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(900.0f + 1 * 64.0f, 700.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(900.0f + 2 * 64.0f, 700.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(900.0f + 3 * 64.0f, 700.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(900.0f + 4 * 64.0f, 700.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f + 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f + 2 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f + 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f + 4 * 64.0f)));


		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1000.0f, 10.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f - 2 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f - 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f, 280.0f)));
		///
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1300.0f + 1 * 64.0f, 700.0f - 1 * 64.0f )));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1300.0f + 1 * 64.0f, 700.0f - 2 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1300.0f + 2 * 64.0f, 700.0f - 2 * 64.0f )));
        Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1300.0f + 2 * 64.0f, 700.0f - 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1300.0f + 3 * 64.0f, 700.0f - 3 * 64.0f )));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1300.0f + 3 * 64.0f, 700.0f - 4 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1300.0f + 4 * 64.0f, 700.0f - 4 * 64.0f )));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1300.0f + 4 * 64.0f, 700.0f - 5 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 1 * 64.0f, 280.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 2 * 64.0f, 280.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 3 * 64.0f, 280.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 4 * 64.0f, 280.0f)));


        dragons.push_back(new Enemy(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(1220.0f + 4 * 64.0f, 233.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1600.0f + 1 * 64.0f, 280.0f+ 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1600.0f + 2 * 64.0f, 280.0f+ 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1600.0f + 3 * 64.0f, 280.0f+ 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1600.0f + 4 * 64.0f, 280.0f+ 1 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f + 1 * 64.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f + 2 * 64.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f + 3 * 64.0f, 280.0f - 1 * 64.0f)));
		//platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1000.0f + 4 * 64.0f, 280.0f - 1 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 1 * 64.0f, 280.0f - 4 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 2 * 64.0f, 280.0f - 4 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 3 * 64.0f, 280.0f - 4 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1200.0f + 4 * 64.0f, 280.0f - 4 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1500.0f + 1 * 64.0f, 280.0f - 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1500.0f + 2 * 64.0f, 280.0f - 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1500.0f + 3 * 64.0f, 280.0f - 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1500.0f + 4 * 64.0f, 280.0f - 3 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1900.0f + 3 * 64.0f, 80.0f  )));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 1 * 64.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 2 * 64.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 3 * 64.0f, 280.0f - 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 4 * 64.0f, 280.0f - 1 * 64.0f)));
               dragons.push_back(new Enemy(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(2300.0f + 4 * 64.0f, 280.0f - 2 * 55.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 10 * 64.0f, 280.0f - 1 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 15 * 64.0f, 280.0f - 1 * 64.0f)));

		 //

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f)));



		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f+21 * 64.0f, 280.0f + 1 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 2 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 3 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 4 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 5 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 6 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 7 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 21 * 64.0f, 280.0f + 8 * 64.0f)));


		////

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 22 * 64.0f, 280.0f + 8 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 23 * 64.0f, 280.0f + 12 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 22 * 64.0f, 280.0f + 16 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 24 * 64.0f, 280.0f + 20 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 28 * 64.0f, 280.0f + 24 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 32 * 64.0f, 280.0f + 23 * 64.0f)));


		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2300.0f + 32 * 64.0f, 280.0f + 22 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 24 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 25 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 26 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 27 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 28 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2260.0f + 38 * 64.0f, 280.0f + 29 * 64.0f)));



		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 24 * 64.0f)));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 25 * 64.0f)));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 26 * 64.0f)));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 27 * 64.0f)));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 28 * 64.0f)));
		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2280.0f + 39 * 64.0f, 280.0f + 29 * 64.0f)));




		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 24 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 25 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 26 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 27 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 28 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f + 29 * 64.0f)));



		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 38 * 64.0f, 280.0f+ 33 * 64.0f))); // tu dać ptwroa
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 39 * 64.0f, 280.0f+ 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 40 * 64.0f, 280.0f+ 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 41 * 64.0f, 280.0f+ 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 42 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 43 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 44 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 45 * 64.0f, 280.0f + 33 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 45 * 64.0f, 280.0f + 32 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 46 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 47 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 48 * 64.0f, 280.0f + 33 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 48 * 64.0f, 280.0f + 32 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 48 * 64.0f, 280.0f + 31 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 48 * 64.0f, 280.0f + 30 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 49 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 47 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 46 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 45 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 44 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 43 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 42 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 41 * 64.0f, 280.0f + 33 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 32 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 31 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 30 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 29 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 28 * 64.0f)));
	//	platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 27 * 64.0f)));



		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 57 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 58 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 59 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 50 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 51 * 64.0f, 280.0f + 33 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 51 * 64.0f, 280.0f + 32 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 52 * 64.0f, 280.0f + 33 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 53 * 64.0f, 280.0f + 33 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 63 * 64.0f, 280.0f + 31 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 66 * 64.0f, 300.0f + 29 * 64.0f)));//

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 63 * 64.0f, 320.0f + 27 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 62 * 64.0f, 280.0f + 26 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 66 * 64.0f, 280.0f + 25 * 64.0f)));

        Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2300.0f + 66 * 64.0f, 280.0f + 24 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 69 * 64.0f, 280.0f + 24 * 64.0f)));

        Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2300.0f + 69 * 64.0f, 280.0f + 23 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 72 * 64.0f, 280.0f + 25 * 64.0f)));

		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2300.0f + 72 * 64.0f, 280.0f+ 24 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 75 * 64.0f, 280.0f + 24 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 78 * 64.0f, 280.0f + 23 * 64.0f)));

		Coins.push_back(new Collecatable(&coinTexture, sf::Vector2u(1, 4), 0.3f, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(2300.0f + 78 * 64.0f, 280.0f+ 22 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 81 * 64.0f, 280.0f + 21 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 83 * 64.0f, 300.0f + 19 * 64.0f)));

		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 80 * 64.0f, 280.0f + 18 * 64.0f)));


		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 78 * 64.0f, 280.0f + 18 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 77 * 64.0f, 280.0f + 18 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 76 * 64.0f, 280.0f + 18 * 64.0f)));
		platforms.push_back(new Platform(&platformTexture, sf::Vector2f(64.0f, 64.0f), sf::Vector2f(2300.0f + 75 * 64.0f, 280.0f + 18 * 64.0f)));


   // Enemy dragon(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(1540.0f,720.0f));
   // std::unique_ptr<Enemy*> dragons;

    dragons.push_back(new Enemy(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(1480.0f,-25.0f)));
    dragons.push_back(new Enemy(&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(1150.0f,650.0f)));
   // dragons.push_back&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(1540.0f,720.0f);
   // dragons.push_back(Enemy (&enemyTexture, sf::Vector2u(3,2),0.3f,300.0f, sf::Vector2f(700.0f,320.0f)));
    Tekst tekst(&font,"",48,sf::Color::Black, sf::Vector2f(50.0f,50.0f));
    Tekst gameOver(&font,"Game\nOver",96,sf::Color::Black, sf::Vector2f(50.0f,100.0f));
    Tekst win(&font,"You\nWon!",36,sf::Color::Black, sf::Vector2f(7149.0f,1000.0f));
    Player player(&playerTexture, sf::Vector2u(3,9),0.3f,300.0f,200.0f,0,3);
    std::vector<Rock> rocks;
    rocks.push_back(Rock(&coinTexture, sf::Vector2f(-200.0f,-300.0f),600.0f,0.3f,0));

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
            if(event.type == (sf::Event::KeyPressed)){
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
              {
                player.amountOfRocks++;
                //rocks.push_back(Rock(nullptr, sf::Vector2f(0.0f,0.0f),600.0f,0.3f));
                rocks.push_back(Rock(&rockTexture,player.GetPosition(), 600.0f, 0.3f,player.faceRight));
                rocks[player.amountOfRocks].dispatchTheRock(deltatime); //to-do
               }
            }
        }
        player.update(deltatime);
         for(Enemy* dragon : dragons)
        {
            dragon->update(deltatime);
        }
        box.update(deltatime);
        tekst.updateText(player.lives,player.score,player.GetPosition());
        Collider playerCollision = player.GetCollider();
        Collider boxColision = box.GetCollider();

        sf::Vector2f directionBox;
        sf::Vector2f directionBoxForAmmunition;
        sf::Vector2f directionPlayer;

        if(box.GetCollider().checkCollioson(playerCollision,directionPlayer,0.5f))
                player.onCollision(directionPlayer,deltatime);

        for(Platform* platform : platforms)
        {

            for(Rock& rock : rocks)
            {
                sf::Vector2f directionRock;
                Collider rockCollision = rock.GetCollider();
                if(platform->GetCollider().checkCollioson(rockCollision,directionRock,1.0f))
                {
                    rock.onCollisionWithPlatforms();
                } else {
                    rock.dispatchTheRock(deltatime);
                }
            }
            if(platform->GetCollider().checkCollioson(playerCollision,directionPlayer,1.0f))
                player.onCollision(directionPlayer,deltatime);
            if(platform->GetCollider().checkCollioson(boxColision,directionBox,1.0f))
                box.onCollision(directionBox,deltatime);
        }

             for(Rock& rock : rocks)
            {
            rock.dispatchTheRock(deltatime);
            if(rock.GetCollider().checkCollioson(boxColision,directionBoxForAmmunition,0))
            {
                rock.onCollisionWithPlatforms();
            } else {
                rock.dispatchTheRock(deltatime);
            }
        }
        for(Collecatable* coin: Coins)
        {
            coin->update(deltatime);
            if(coin->GetCollider().checkCollioson(playerCollision,directionPlayer,0))
            {
                CoinSound.play();
                player.onCollisionWithCoin();
                coin->removeElement();
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


        for(Enemy* dragon : dragons)
        {
            for(Rock& rock : rocks)
            {
                sf::Vector2f directionRock;
                Collider rockCollision = rock.GetCollider();
                if(dragon->GetCollider().checkCollioson(rockCollision,directionRock,1.0f))
                {
                    dragon->killDragon();
                    rock.onCollisionWithEnemy();
                    player.deadDragons++;
                } else {
                    rock.dispatchTheRock(deltatime);
                }
            }
           if(dragon->GetCollider().checkCollioson(playerCollision,directionPlayer,1.0f))
           {
               player.onCollisionWithEnemy();
           }
        }
        for(Enemy* dragon : dragons)
        {

            dragon->draw(window);
        }
        for(Platform* platform : platforms)
        {
            platform->draw(window);
        }
        for(Collecatable* coin : Coins)
        {
            coin->draw(window);
        }
        for(Rock& rock : rocks)
        {
            rock.draw(window);
        }
        if(player.lives<1)
        {
            std::cout<<"Game Over!";
            break;
        }
       if(player.GetPosition().x > 7145.0f && player.GetPosition().y < 1350.0f)
        {
            totalScore = player.score;
            totalScore += (10/player.amountOfRocks);
            totalScore += (sqrt(player.deadDragons));
            totalScore += player.lives*3;
            std::string text = "You Won\nSlaughtered Dragons:"+std::to_string(player.deadDragons)+"\nCollected coins: "+ std::to_string(player.score) +"\nThrown rocks: "+ std::to_string(player.amountOfRocks)+"\ntotal score: "+std::to_string(totalScore);
            win.text.setString(text);
            win.draw(window);
        }
        tekst.draw(window);
        window.display();
    }

    return 0;
}
