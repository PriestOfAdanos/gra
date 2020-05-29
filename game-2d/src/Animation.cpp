#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x=0;
    uvRect.width = texture->getSize().x/ float(imageCount.x);
    uvRect.height = texture->getSize().y/ float(imageCount.y);
}
void Animation::Update(int row, float deltaTime, bool faceRight)
{
   // std::cout<<"rr";
    currentImage.y = row;
    totalTime += deltaTime;
    if(totalTime>=switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x=0;
        }
    }

    //uvRect.left = currentImage.x * uvRect.width;
    //std::cout<<uvRect.left<<'\n';
    uvRect.top = currentImage.y * uvRect.height;

    if(faceRight)
    {
        uvRect.width = abs(uvRect.width);
        uvRect.left = currentImage.x * uvRect.width;


    } else {
        uvRect.left = (currentImage.x+1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);

    }
}
void Animation::UpdateItem(float deltaTime){
    currentImage.x=0;
    totalTime +=deltaTime;
       if(totalTime>=switchTime)
    {
        totalTime -= switchTime;
        currentImage.y++;
        if(currentImage.y >= imageCount.y)
        {
            currentImage.y=0;
        }
        uvRect.top = currentImage.y * uvRect.height;
        uvRect.left = currentImage.x * uvRect.width;
    }
}
void Animation::updateEnemy(int row,bool faceRight ,float deltatime){
     // std::cout<<"rr";
    currentImage.y = row;
    totalTime += deltatime;
    if(totalTime>=switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x=0;
        }
    }

    //uvRect.left = currentImage.x * uvRect.width;
    //std::cout<<uvRect.left<<'\n';
    uvRect.top = currentImage.y * uvRect.height;

    if(!faceRight)
    {
        uvRect.width = abs(uvRect.width);
        uvRect.left = currentImage.x * uvRect.width;


    } else {
        uvRect.left = (currentImage.x+1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);

    }
}
Animation::~Animation()
{
    //dtor
}
