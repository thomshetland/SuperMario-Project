#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

class Goomba{
public:
    bool dead = false;
    Goomba(float x, float y){

        if (!texture_goomba.loadFromFile("Sprites/goomba.png")){
            std::cout << "Background didnt load\n";
        }
        if (!texture_dead_goomba.loadFromFile("Sprites/dead_goomba.png")){
            std::cout << "Background didnt load\n";
        }
        sprite_goomba.setTexture(texture_goomba);
        sprite_goomba.setPosition(sf::Vector2(x, y));
    }
    void moveLeft(){
        sprite_goomba.move(sf::Vector2f(2, 0));
    }
    void moveRight(){
        sprite_goomba.move(sf::Vector2f(-2, 0));
    }
    void hit_tube1(){
        sprite_goomba.move(-0.5f, 0.f);
    }
    void hit_tube2(){
        sprite_goomba.move(0.5f, 0.f);
    }

    sf::Sprite getSprite(){
        return sprite_goomba;
    }
    sf::FloatRect getCoordinates(){
        return sprite_goomba.getGlobalBounds();
    }
    float getx(){
        return sprite_goomba.getPosition().x;
    }
    sf::FloatRect getGlobalBounds(){
        return sprite_goomba.getGlobalBounds();
    }
    void dead_goomba(){
        sprite_goomba.setTexture(texture_dead_goomba);
        sprite_goomba.move(0.f, 0.f);
    }
private:
    sf::Sprite sprite_goomba;
    sf::Texture texture_goomba;
    sf::Texture texture_dead_goomba;
};