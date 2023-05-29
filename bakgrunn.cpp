#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>


sf::Texture text_bakgrunn(){
    sf::Texture texture_bakgrunn;
    if (!texture_bakgrunn.loadFromFile("Bakgrunn/background_double.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_bakgrunn;
}


sf::Texture text_block(){
    sf::Texture texture_block;
    if (!texture_block.loadFromFile("Sprites/block.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_block;
}
sf::Texture text_2_block(){
    sf::Texture texture_2_block;
    if (!texture_2_block.loadFromFile("Sprites/2_blocks.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_2_block;
}
sf::Texture text_3_block(){
    sf::Texture texture_3_block;
    if (!texture_3_block.loadFromFile("Sprites/3_blocks.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_3_block;
}


sf::Texture text_4_block(){
    sf::Texture texture_4_block;
    if (!texture_4_block.loadFromFile("Sprites/4_blocks.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_4_block;
}

sf::Texture text_5_block(){
    sf::Texture texture_5_block;
    if (!texture_5_block.loadFromFile("Sprites/5_blocks.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_5_block;
}
sf::Texture text_6_block(){
    sf::Texture texture_6_block;
    if (!texture_6_block.loadFromFile("Sprites/6_blocks.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_6_block;
}

sf::Texture text_flag(){
    sf::Texture texture_flag;
    if (!texture_flag.loadFromFile("Sprites/flag.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_flag;
}

sf::Texture text_coins(){
    sf::Texture texture_coin;
    if (!texture_coin.loadFromFile("Sprites/coin.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_coin;
}

sf::Texture text_mushroom(){
    sf::Texture texture_mushroom;
    if (!texture_mushroom.loadFromFile("Sprites/mushroom.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_mushroom;
}

sf::Texture text_lucky_block(){
    sf::Texture texture_lucky_block;
    if (texture_lucky_block.loadFromFile("Sprites/bonus_block.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_lucky_block;
}


sf::Texture text_goomba(){
    sf::Texture texture_goomba;
    if (!texture_goomba.loadFromFile("Sprites/goomba.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_goomba;
}

sf::Texture text_0coin(){
    sf::Texture texture_0coin;
    if (!texture_0coin.loadFromFile("Sprites/0_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_0coin;
}

sf::Texture text_1coin(){
    sf::Texture texture_1coin;
    if (!texture_1coin.loadFromFile("Sprites/1_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_1coin;
}
sf::Texture text_2coin(){
    sf::Texture texture_2coin;
    if (!texture_2coin.loadFromFile("Sprites/2_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_2coin;
}
sf::Texture text_3coin(){
    sf::Texture texture_3coin;
    if (!texture_3coin.loadFromFile("Sprites/3_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_3coin;
}

sf::Texture text_4coin(){
    sf::Texture texture_4coin;
    if (!texture_4coin.loadFromFile("Sprites/4_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_4coin;
}
sf::Texture text_5coin(){
    sf::Texture texture_5coin;
    if (!texture_5coin.loadFromFile("Sprites/5_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_5coin;
}
sf::Texture text_6coin(){
    sf::Texture texture_6coin;
    if (!texture_6coin.loadFromFile("Sprites/6_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_6coin;
}
sf::Texture text_7coin(){
    sf::Texture texture_7coin;
    if (!texture_7coin.loadFromFile("Sprites/7_coins.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_7coin;
}


sf::Texture text_lava(){
    sf::Texture texture_lava;
    if (!texture_lava.loadFromFile("bakgrunn/lava.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_lava;
}
sf::Texture text_dead_text(){
    sf::Texture texture_dead_text;
    if (!texture_dead_text.loadFromFile("Sprites/dead_text.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_dead_text;
}
sf::Texture text_won_text(){
    sf::Texture texture_won_text;
    if (!texture_won_text.loadFromFile("Sprites/won_text.png")){
        std::cout << "Background didnt load\n";
    }
    return texture_won_text;
}
