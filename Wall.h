#pragma once

#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include <string>
#include "Projectile.h"

using namespace sf;

class Wall : public StaticObject {
private:



public:
    Wall(float  x, float y, float h, float w, Image& image, int armor, const std::string& name,Level &lvl)
        : StaticObject(x, y, h, w, image, armor, name, damage) {
        obj = lvl.GetAllObjects();

    }

    int TakeDamage(int armor, int damage) override {
        if (armor > 0)
            sprite.setTextureRect(IntRect(50 * (3 - armor), 0, 50, 50));
        if (armor <= 0)
            life = false;
        return armor - damage;

    }
    void Desroyed() override {
        if (armor < 0)
            life = false;
    }

};




