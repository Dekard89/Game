#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Wall.h"
#include "Projectile.h"
#include <list>
#include "Menu.h"
#include "StaticObject.h"
#include "Bonuses.h"
#include "map.h"
#include "level.h"
#include<vector>
#include "EnemyTank.h"

using namespace sf;

void JoinEnemy(std::list<Tank>& list, Tank& tank, int& counter) {
    if (counter > 0) {
        list.push_back(tank);
        counter--;
    }

}





int main() {
    sf::RenderWindow window(sf::VideoMode(1376, 768), "My First Game");
    int menuNum;
    Menu(window,menuNum);
    view.reset(FloatRect(0, 0, 1276, 668));
    Level lvl;
    lvl.LoadFromFile("Source/mapfinal.tmx");
    Clock clock1;

    std::vector<Object>objects;
    Image wallImage;
    wallImage.loadFromFile("Source/walls.png");
    Image mediumTankImage;
    mediumTankImage.loadFromFile("Tanks/mediumTank.png");
    mediumTankImage.createMaskFromColor(Color(55, 62, 72));
    Image hardTankImage;
    hardTankImage.loadFromFile("Tanks/hardTank.png");
    hardTankImage.createMaskFromColor(Color(55, 62, 72));
    Image semiHardTank;
    semiHardTank.loadFromFile("Tanks/semihardTank.png");
    semiHardTank.createMaskFromColor(Color(55, 62, 72));
    Image lightTankImage;
    lightTankImage.loadFromFile("Tanks/lightTank.png");
    lightTankImage.createMaskFromColor(Color(55, 62, 72));
    Image ammoImage;
    ammoImage.loadFromFile("Source/ammo.png");
    Image armorImage;
    armorImage.loadFromFile("Source/bonuses.png");
    Image superImage;
    superImage.loadFromFile("Source/super.png");
    Image projImage;
    projImage.loadFromFile("Source/Projectile.png");
    Image mineImage;
    mineImage.loadFromFile("Source/Mine.png");
    
    Object player = lvl.GetObject("player");
    Object enemyH = lvl.GetObject("enemy1");
    Object enemyS = lvl.GetObject("enemy2");
    Object enemyM = lvl.GetObject("enemy3");
    Object enemyL = lvl.GetObject("enemy4");
    Object ammo = lvl.GetObject("ammo");
    Object armor = lvl.GetObject("armor");
    Object super = lvl.GetObject("super");
    Object wallObj = lvl.GetObject("wall");

    std::vector<StaticObject*>staticObjects;
    
    for (auto item : objects) {
        if (item.name == "wall");
        Wall* wall=new Wall(wallObj.rect.left, wallObj.rect.top, 50, 50, wallImage, 3, "wall", lvl);
        staticObjects.push_back(wall);
        
    }
    Bonus* ammobonus=new Bonus(ammo.rect.left, ammo.rect.top,50,50, lvl, ammoImage, "ammo");
    staticObjects.push_back(ammobonus);
    Bonus* armorbonus=new Bonus(armor.rect.left, armor.rect.top, 50, 50, lvl, armorImage, "armor");
    staticObjects.push_back(armorbonus);
    Bonus* superbonus=new Bonus(super.rect.left, super.rect.top, 50, 50, lvl, superImage, "super");
    staticObjects.push_back(superbonus);

    std::vector<MovingObject*>movingObjects;
    
    
    if (menuNum = 1) {
       Tank* playerTank=new Tank("player", lvl, player.rect.left, player.rect.top, 75, 50, hardTankImage, 4, 20, 3, 1);
       movingObjects.push_back(playerTank);
    }
   if (menuNum = 2) {
        Tank* playerTank=new Tank("player", lvl, player.rect.left, player.rect.top, 75, 50, semiHardTank, 3, 20, 3, 2);
        movingObjects.push_back(playerTank);
   }
   if (menuNum = 3) {
       Tank* playerTank=new Tank("player", lvl, player.rect.left, player.rect.top, 75, 50, mediumTankImage, 2, 20, 4, 3);
       movingObjects.push_back(playerTank);
    }
    if (menuNum = 4) {
       Tank* playerTank=new Tank("player", lvl, player.rect.left, player.rect.top, 75, 50, lightTankImage, 1, 20, 5, 4);
       movingObjects.push_back(playerTank);
    }
    EnemyTank* enemyHardTank=new EnemyTank("enemyH", lvl, enemyH.rect.left, enemyH.rect.top, 75, 50, hardTankImage, 4, 1);
    movingObjects.push_back(enemyHardTank);
    EnemyTank* enemySemiHardTank=new EnemyTank("enemyS", lvl, enemyS.rect.left, enemyS.rect.top, 75, 50,semiHardTank, 3, 2);
    movingObjects.push_back(enemySemiHardTank);
    EnemyTank* enemyMediumTank=new EnemyTank("enemyM", lvl, enemyM.rect.left, enemyM.rect.top, 75, 50, mediumTankImage, 2, 2);
    movingObjects.push_back(enemyMediumTank);
    EnemyTank* enemyLightTank=new EnemyTank("enemyL", lvl, enemyL.rect.left, enemyL.rect.top, 75, 50, lightTankImage, 1, 4); 

    std::vector<MovingObject*>::iterator movIt;
    std::vector<StaticObject*>::iterator statIt;
    statIt = staticObjects.begin();
    movIt = movingObjects.begin();

    
    

    while (window.isOpen())
    {
        float time = clock1.getElapsedTime().asMicroseconds();
        clock1.restart();
        time = time / 800;
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        for (statIt = staticObjects.begin();statIt!=staticObjects.end();statIt++)
            window.draw((*statIt)->getSprite());
        for (movIt = movingObjects.begin();movIt != movingObjects.end();movIt++);
           (* movIt)->Update(time);
         for (movIt = movingObjects.begin();movIt != movingObjects.end();movIt++);
            window.draw((*movIt)->getSprite());
       
        //for (auto item1 : movingObjects)
          //  item1->Update(time);
       // for (auto item1 : movingObjects)
         //   window.draw(item1->getSprite());



       



        window.clear();
        lvl.Draw(window);
        ControlMap(time);
        window.setView(view);

        



        window.display();
    }
    return 0;
}
