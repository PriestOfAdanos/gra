#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>

class Animation
{
    public:
        sf::IntRect uvRect;
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        void Update(int row, float deltaTime, bool faceRight);
        virtual ~Animation();

    protected:

    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        bool faceRight;
        float totalTime;
        float switchTime;
};

#endif // ANIMATION_H
