#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "MovingObject.h"
#include <string>
#include "Mine.h"
#include "map.h"
#include "level.h"

using namespace sf;

class EnemyTank :public MovingObject {
protected:
    int armor ;
    int countOfMine;
    std::string name;
    float shootTimer=0;
    int factorOfSpeed;
public:
    EnemyTank(std::string name, Level& lvl, float x, float y, float h, float w, Image& image, int armor, int factorOfSpeed) : MovingObject(x, y, h, w, image, dir) {
        obj = lvl.GetAllObjects();
        speed *= factorOfSpeed;
        armor = armor;
        dir = 1;
       
       

    }

    void  Desroyed() override {
        if (armor <= 0) {
            life = false;
            Image deathImage;
            deathImage.loadFromFile("Tanks/DestroyedTank.png");
            texture.loadFromImage(deathImage);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, 50, 75));
        }
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
        case 0:
            projY = y;
            break;
        case 1:
            projY = y;
            break;
        case 2:
            projY = y + h / 2;
            break;
        case 3:
            projY = y - h / 2;
            break;
        }
        return projY;
    }
    void interactionWithMapForEnemy()
    {

        for(int i=0; i<obj.size(); i++)

            {
            if (getRect().intersects(obj[i].rect))
            {
                if (obj[i].name == "solid" || obj[i].name == "wall")
                    if (bustY > 0) {
                        y = obj[i].rect.top - h;
                        if (x < (obj.size()/ 2))  sprite.setRotation(90); 
                        if (x > (obj.size()/ 2)) sprite.setRotation(270); 
                    }
                    if (bustY < 0) {
                        y = obj[i].rect.top + obj[i].rect.height;
                        sprite.scale(1, -1);
                    }
                    if (bustX > 0) {
                        x = obj[i].rect.left - w;
                        sprite.setRotation(180);
                    }
                    if (bustX < 0) {
                        x = obj[i].rect.left + obj[i].rect.width;
                        sprite.setRotation(180);

                    }

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
        interactionWithMapForEnemy();
        EnemyShoot();

        sprite.setPosition(x, y);
    }



    void EnemyShoot() {
        

        if (shootTimer > 1000) {
            isShoting = true;
            shootTimer - 1000;
            isShoting = false;
        }
    }
    

   
    int TakeDamage(int armor, int damage) override {
        return armor - damage;
    }

    int getArmor() const {
        return armor;
    }
    void TrapSet() {
        if (life = false)
            isPlanting = true;
    }



};



