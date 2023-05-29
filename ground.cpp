#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture text_ground(){
    sf::Texture texture_ground;
    if (!texture_ground.loadFromFile("Sprites/ground1.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_ground;
}

sf::Texture text_end_ground(){
    sf::Texture texture_endground;
    if (!texture_endground.loadFromFile("Sprites/endground.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_endground;
}
sf::Texture text_brick() {
    sf::Texture texture_brick1;
    if (!texture_brick1.loadFromFile("Sprites/brick.png")) {
        std::cout << "Background didnt load\n";
    }
    return texture_brick1;
}

sf::Texture text_broken_brick(){
    sf::Texture texture_broken_brick;
    if (!texture_broken_brick.loadFromFile("Sprites/broken_brick.png")) {
        std::cout << "Background didnt load\n";
    }
    return texture_broken_brick;
}

sf::Texture text_stairs() {
    sf::Texture texture_strairs;
    if (!texture_strairs.loadFromFile("Sprites/stairs.png")) {
        std::cout << "Background didnt load\n";
    }
    return texture_strairs;
}
sf::Texture text_tube(){
    sf::Texture texture_tube;
    if (!texture_tube.loadFromFile("Sprites/tube.png")) {
        std::cout << "Background didnt load\n";
    }
    return texture_tube;
}

bool mario_intersects(sf::Sprite mario, sf::Sprite ground){
    if (mario.getGlobalBounds().intersects(ground.getGlobalBounds())) {
        if (mario.getPosition().y < ground.getPosition().y)
            return true;
    }
    else {
        return false;
    }
}
