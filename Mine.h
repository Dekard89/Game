#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Tank.h"
#include <string>

using namespace sf;


class Mine : public StaticObject {
private:
    float damage = 1;
public:
    Mine(float x, float y,float h, float w, Image image, std::string name) : StaticObject(x, y, h, w, image, armor, name, damage) {
        sprite.setTextureRect(IntRect(0, 0, w, h));
        

    }
    void Desroyed() override {
        life = false;
        sprite.setTextureRect(IntRect(0, 50, w, h));
    }

    float getDamage() const {
        return damage;
    }


};




