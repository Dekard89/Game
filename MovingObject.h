#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "IDestroyed.h"
#include"level.h"
#include<vector>


using namespace sf;


class MovingObject :ITakeDamage, IDesrtroyed {
public:
    std::vector<Object>obj;
    float bustX;
    float bustY;
    int dir;
    float speed = 0;
    int factorOfSpeed;
    float x;
    float y;
    float h;
    float w;
    bool life;
    std::string name;
    Image image;
    Texture texture;
    Sprite sprite;

    bool isShoting;
    bool isPlanting;

    MovingObject(float x, float y, float h, float w, Image& image, int factorOfSpeed) {
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(h / 2, w / 2);
        sprite.setTextureRect(IntRect(0, 0, w, h));
        life = true;
        dir = 0;
    }
    const std::string& getName() const {
        return name;
    }

    bool isLife() const {
        return life;
    }

    virtual void Update(float time) {
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
        speed = 0;
        sprite.setPosition(x, y);


    };
    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }
    FloatRect getRect() {
        return FloatRect(x, y, w, h);
    }

    int getDir() const {
        return dir;
    }

    const Sprite& getSprite() const {
        return sprite;
    }
    virtual void Desroyed() override {};
    virtual  int TakeDamage(int armor, int damage) override {
        return armor - damage;
    }


};


