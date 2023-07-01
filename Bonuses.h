#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "map.h"
#include <string>


class Bonus : public StaticObject {
private:
    float teleportTimer;
    std::string name;
    float time;
public:
    Bonus(float x, float y, float h, float,Level &lvl, Image& image, std::string name) : StaticObject(x, y, h, w, image, armor, name, damage) {
        teleportTimer += time;
        armor = 0;
        obj = lvl.GetAllObjects();
     
    }
    void Teleport(float teleportX, float teleportY, float time) {

        if (teleportTimer > 30000) {
            teleportTimer = 0;
            x = teleportX;
            y = teleportY;
        }

    }

    void SetTeleport(float time) override {
        if (teleportTimer > 30000) {
            teleportTimer = 0;
            srand((0));
            float tx;
            float ty;
            tx = 50 + rand() % (1250 - 50);
            ty = 50 + rand() % (1500 - 50);
            x = tx;
            y = ty;

        }
    }

    void Desroyed() override {
        life = false;

    }
    int TakeDamage(int armor, int damage) override {
        SetTeleport(time);
        return armor - damage;

    }



};



