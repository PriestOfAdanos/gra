#ifndef ENEMY_H
#define ENEMY_H
#include "Animation.h"
#include "Collider.h"


class Enemy
{
    public:
        Enemy(sf::Texture* texture, sf::Vector2u imageCount,  float switchTime, float speed, sf::Vector2f position);
        void draw(sf::RenderWindow &Window);
        Collider GetCollider(){return Collider(body);}
        Animation animation;
        void killDragon();
        void update(float);


        virtual ~Enemy();

    protected:

    private:
        float totalDistance;
        bool leftDirectionForward;
        sf::RectangleShape body;
        sf::Vector2f velocity;
        bool faceRight;
        float speed;
        int row;

};

#endif // ENEMY_H
