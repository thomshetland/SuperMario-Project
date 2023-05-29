#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <thread>
#include <array>
#include <vector>
#include <SFML/Window/Joystick.hpp>

class Pole{
public:
    Pole(float x, float y){

        if (!texture_pole.loadFromFile("Sprites/pole.png")){
            std::cout << "Background didnt load\n";
        }
        sprite_pole.setTexture(texture_pole);
        sprite_pole.setPosition(sf::Vector2(x, y));
    }
    void moveLeft(){
        sprite_pole.move(sf::Vector2f(2, 0));
    }
    void moveRight(){
        sprite_pole.move(sf::Vector2f(-2, 0));
    }
    sf::Sprite getSprite(){
        return sprite_pole;
    }
    sf::FloatRect getCoordinates(){
        return sprite_pole.getGlobalBounds();
    }
    float getx(){
        return sprite_pole.getPosition().x;
    }
private:
    sf::Sprite sprite_pole;
    sf::Texture texture_pole;
};