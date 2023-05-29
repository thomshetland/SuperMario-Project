#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <thread>
#include <array>
#include <vector>


class Brick{
public:
    int hit_value = 0;
    sf::Sprite brick;

    Brick(sf::Texture& texture, float x, float y){
        brick.setTexture(texture);
        brick.setPosition(x, y);
    }
};