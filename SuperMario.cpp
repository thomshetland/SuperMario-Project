#include <iostream>
#include <SFML/Graphics.hpp>

sf::Texture text_mario(){
    sf::Texture texture_mario;
    if (!texture_mario.loadFromFile("Sprites/mario_idle.png")) {
        // error loading texture
    }
    return texture_mario;
}
sf::Texture text_mario2(){
    sf::Texture texture_mario2;
    if (!texture_mario2.loadFromFile("Sprites/mario_walking.png")) {
        // error loading texture
    }
    return texture_mario2;
}
sf::Texture text_mario3(){
    sf::Texture texture_mario3;
    if (!texture_mario3.loadFromFile("Sprites/mario_walking2.png")) {
        // error loading texture
    }
    return texture_mario3;
}

sf::Texture text_mario_jumping(){
    sf::Texture texture_mario_jumping;
    if (!texture_mario_jumping.loadFromFile("Sprites/mario_jumping.png")) {
        // error loading texture
    }
    return texture_mario_jumping;
}

sf::Texture text_big_mario(){
    sf::Texture texture_big_mario;
    if (!texture_big_mario.loadFromFile("Sprites/big_mario_idle.png")) {
        // error loading texture
    }
    return texture_big_mario;
}
sf::Texture text_big_mario_jumping(){
    sf::Texture texture_big_mario_jumping;
    if (!texture_big_mario_jumping.loadFromFile("Sprites/big_mario_jumping.png")) {
        // error loading texture
    }
    return texture_big_mario_jumping;
}
