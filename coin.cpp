#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <thread>
#include <array>
#include <vector>
#include <SFML/Window/Joystick.hpp>

class Coin{
public:
    bool collected = false;
    Coin (float x, float y){
        if (!texture_coin.loadFromFile("Sprites/coin.png")){
            std::cout << "Background didnt load\n";
        }
        sprite_coin.setTexture(texture_coin);
        sprite_coin.setPosition(sf::Vector2(x, y));
    }

    sf::Sprite getsprite(){
        return sprite_coin;
    }
    sf::FloatRect getCoordinates(){
        return sprite_coin.getGlobalBounds();
    }
    void animation(float x, float y, float entity_movement, float time){
        // update coin position with sine wave
        float yOffset = 5.f * std::sin(time * 3.14f); // 50.f is the amplitude of the wave
        sprite_coin.setPosition(x + entity_movement, y + yOffset); // update y position with yOffset
    }
    void checkcollected(){
        collected = true;
    }
    bool coin_collected(){
        return collected;
    }

private:
    sf::Sprite sprite_coin;
    sf::Texture texture_coin;
};
