#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Tank.h"
#include <string>
#include"level.h"



using namespace sf;

class Projectile : public MovingObject {
private:
    int damage = 1;
    int factorOfSpeed = 10;
public:
    float getDamage() const {
        return damage;
    }

    Projectile(float x, float y, int dir,std::string name,Image image,float w, float h, Level &lvl) : MovingObject(x, y, h, w, image, dir), damage(damage) {
    
        sprite.setTextureRect(IntRect(0, 0, w, h));
        this->x = x;
        this->y = y;


    }

    void Desroyed() override {
        life = false;
    }



    void Shoted(float time) {
        speed *= factorOfSpeed;
        float currentFrame;
        currentFrame += 0.005 * time;
        image.loadFromFile("Source/shoot.png");
        image.createMaskFromColor(Color(70, 73, 114));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 50));
        if (currentFrame > 2)
            return;
    }
    void Update(float time) override {
        switch (dir) {
        case 0:
            bustX = 0;
            bustY = speed;
            break;
        case 1:
            bustX = 0;
            bustY = -speed;
            break;
        case 2:
            bustX = speed;
            bustY = 0;
            break;
        case 3:
            bustX = -speed;
            bustY = 0;
            break;
        }
        x += bustX * time;
        y += bustY * time;
        if (x <= 0) x = 1;
        if (y <= 0) y = 1;
        sprite.setPosition(x, y);
        interactionWithMap();

     
    }
    void interactionWithMap()
    {

        for (int i = 0; i < obj.size(); i++)
            if (getRect().intersects(obj[i].rect))
            {
                if (obj[i].name == "solid" || obj[i].name == "wall")
                {
                    Desroyed();
                   
                }
            }
    }




};




