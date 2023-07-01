#pragma once
#include <SFML/Graphics.hpp>

View view;

View getPlayerCoordinateForView(float x, float y) {
    return view;
}
View ControlMap(float time) {
    if (Keyboard::isKeyPressed(Keyboard::Up))
        view.move(0, -0.1 * time);
    if (Keyboard::isKeyPressed(Keyboard::Down))
        view.move(0, 0.1 * time);
    if (Keyboard::isKeyPressed(Keyboard::Left))
        view.move(-0.1 * time, 0);
    if (Keyboard::isKeyPressed(Keyboard::Right))
        view.move(0.1 * time, 0);

    return view;
}


