#pragma once
#include "Projectile.h"
#include "Tank.h"

class IDesrtroyed {
public:
    virtual void Desroyed() = 0;

};

class ITakeDamage {
public:
    virtual int TakeDamage(int armor, int damage) {
        return armor - damage;

    }
};


