#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <thread>
#include <array>
#include <vector>
#include <SFML/Window/Joystick.hpp>

class Castle{
public:
    Castle(float x, float y){

        if (!texture_castle.loadFromFile("Sprites/castle.png")){
            std::cout << "Background didnt load\n";
        }
        sprite_castle.setTexture(texture_castle);
        sprite_castle.setPosition(sf::Vector2(x, y));
    }
    void moveLeft(){
        sprite_castle.move(sf::Vector2f(2, 0));
    }
    void moveRight(){
        sprite_castle.move(sf::Vector2f(-2, 0));
    }
    sf::Sprite getSprite(){
        return sprite_castle;
    }
private:
    sf::Sprite sprite_castle;
    sf::Texture texture_castle;
};