#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;
void Menu(RenderWindow& window, int& menuNum) {
    Texture menuElemen1;
    menuElemen1.loadFromFile("menu/menu el1.png");
    Texture menuElemen2;
    menuElemen2.loadFromFile("menu/menu el2.png");
    Texture menuElemen3;
    menuElemen3.loadFromFile("menu/menu el3.png");
    Texture menuElemen4;
    menuElemen4.loadFromFile("menu/menu el4.png");
    

    Sprite spriteEl1(menuElemen1);
    Sprite spriteEl2(menuElemen2);
    Sprite spriteEl3(menuElemen3);
    Sprite spriteEl4(menuElemen4);
    

    bool isMenu = true;

    menuNum = 0;
    spriteEl1.setPosition(100, 90);
    spriteEl2.setPosition(100, 150);
    spriteEl3.setPosition(100, 210);
    spriteEl4.setPosition(100, 270);
   
    while (isMenu) {
        spriteEl1.setColor(Color::White);
        spriteEl2.setColor(Color::White);
        spriteEl3.setColor(Color::White);
        spriteEl4.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(197, 196, 191));
        if (Keyboard::isKeyPressed(Keyboard::Num1)) {
            spriteEl1.setColor(Color::Red);
            menuNum = 1;
            isMenu = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num2)) {
            spriteEl2.setColor(Color::Red);
            menuNum = 2;
            isMenu = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num3)) {
            spriteEl3.setColor(Color::Red);
            menuNum = 3;
            isMenu = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num4)) {
            spriteEl4.setColor(Color::Red);
            menuNum = 4;
            isMenu = false;
        }




        window.draw(spriteEl1);
        window.draw(spriteEl2);
        window.draw(spriteEl3);
        window.draw(spriteEl4);
        

        window.display();
    }


}



