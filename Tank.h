#pragma once

#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "MovingObject.h"
#include <string>
#include "Mine.h"
#include "map.h"


class Tank : public MovingObject {
protected:
    int armor ;
    int ammo;
    int countOfMine;
    std::string name;
    Projectile* projectile;
   


public:


    Tank(std::string name, Level& lvl, float x, float y, float h, float w, Image& image, int armor, int ammo,int countOfmine,int factorOfSpeed) : MovingObject(x, y, h, w, image, dir) {
        obj = lvl.GetAllObjects();
        speed *= factorOfSpeed;
        armor = armor;
        ammo = ammo;
        countOfMine = countOfmine;
        dir = 0;
        

    }

    void Desroyed() override {
        if (armor <= 0) {
            life = false;
            Image deathImage;
            deathImage.loadFromFile("Tanks/DestroyedTank.png");
            texture.loadFromImage(deathImage);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, 50, 75));


        }
    }



    void MoveUp() {
        dir = 1;
        speed = 0.1;
        sprite.setRotation(0);
    }
    void MoveDown() {
        dir = 0;
        speed = 0.1;
        sprite.setRotation(180);
    }
    void MoveLeft() {
        dir = 3;
        speed = 0.1;
        sprite.setRotation(270);
    }
    void MoveRight() {
        dir = 2;
        speed = 0.1;
        sprite.setRotation(90);
    }
    void Shoot(float x, float y) {

       // projectile = new Projectile();
        ammo--;
        isShoting = false;
       // return projectile;
    }
    void TrapSet(float x, float y) {
       // Mine mine(GetMineX(), GetMineY());
        isPlanting = false;
        countOfMine--;
        //return mine;

    }


    float GetProjX() {
        float projX;
        switch (dir) {
        case 0:projX = x + h / 2;
            break;
        case 1:projX = x - h / 2;
            break;
        case 2:projX = x;
            break;
        case 3:projX = x;
            break;

        }
        return projX;
    }
    float GetProjY() {
        float projY;
        switch (dir) {
        case 0:projY = y;
            break;
        case 1:projY = y;
            break;
        case 2:projY = y + h / 2;
            break;
        case 3:projY = y - h / 2;
            break;

        }
        return projY;
    }
    float GetMineX() {
        float mineX;
        switch (dir) {
        case 0:mineX = x - h / 2;
            break;
        case 1:mineX = x + h / 2;
            break;
        case 2:mineX = x;
            break;
        case 3:mineX = x;
            break;

        }
        return mineX;
    }
    float GetMineY() {
        float mineY;
        switch (dir) {
        case 0:
            mineY = y;
            break;
        case 1:
            mineY = y;
            break;
        case 2:
            mineY = y - h / 2;
            break;
        case 3:
            mineY = y + h / 2;
            break;

        }
        return mineY;
    }

    void Control() {
        if (name == "Player") {
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                MoveUp();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                MoveDown();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                MoveRight();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                MoveLeft();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                isShoting = true;
                Shoot(x, y);
            }
            if (Keyboard::isKeyPressed(Keyboard::E)) {
                isPlanting = true;
                TrapSet(x, y);

            }


        }
    }
    void interactionWithMap()
    {

        for (int i = 0; i < obj.size(); i++)
            if (getRect().intersects(obj[i].rect))
            {
                if (obj[i].name == "solid"||obj[i].name=="wall")
                {
                    if (bustX > 0) { y = obj[i].rect.top - h;  }
                    if (bustX < 0) { y = obj[i].rect.top + obj[i].rect.height; }
                    if (bustY > 0) { x = obj[i].rect.left - w; }
                    if (bustY < 0) { x = obj[i].rect.left + obj[i].rect.width; }
                }
                if (obj[i].name == "armor")
                    armor += 1;
                if (obj[i].name == "ammo")
                    ammo += 20;
                if (obj[i].name == "super") {
                    armor += 1;
                    countOfMine += 2;
                    ammo += 20;
                }
            }
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
        interactionWithMap();
        speed = 0;
        Control();
        sprite.setPosition(x, y);
    }


    int TakeDamage(int armor, int damage) override {
        return armor - damage;
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        Tank::armor = armor;
    }

    void setAmmo(int ammo) {
        Tank::ammo = ammo;
    }

    void setCountOfMine(int countOfMine) {
        Tank::countOfMine = countOfMine;
    }

    int getAmmo() const {
        return ammo;
    }

    int getCountOfMine() const {
        return countOfMine;
    }


};

