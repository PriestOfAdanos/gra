#ifndef COLLIDER_H
#define COLLIDER_H
#include<SFML\Graphics.hpp>

class Collider
{
    public:
        Collider(sf:: RectangleShape& body);
        virtual ~Collider();
        bool checkCollioson(Collider& other,sf::Vector2f& direction, float push);
        void Move(float dx, float dy){body.move(dx,dy);}
        sf::Vector2f GetPosition() {return body.getPosition();}
        sf::Vector2f GetHalfSize() {return body.getSize()/2.0f;}

    protected:

    private:
        sf::RectangleShape& body;
};

#endif // COLLIDER_H
