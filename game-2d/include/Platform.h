#ifndef PLATFORM_H
#define PLATFORM_H
#include "Collider.h"
#include <SFML\Graphics.hpp>

class Platform
{
    public:

        Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
        Collider GetCollider(){return Collider(block);}
        void draw(sf::RenderWindow& window);
        virtual ~Platform();

    protected:
        sf::RectangleShape block;
    private:

};

#endif // PLATFORM_H
