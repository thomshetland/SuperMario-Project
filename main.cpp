#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <thread>
#include <array>
#include <vector>
#include <SFML/Window/Joystick.hpp>

// including programming files:
#include "SuperMario.cpp"
#include "bakgrunn.cpp"
#include "global.hpp"
#include "ground.cpp"
#include "entities.cpp"
#include "goomba.cpp"
#include "bricks.cpp"
#include "castle.cpp"
#include "pole.cpp"
#include "coin.cpp"

int main() {
    std::vector<sf::Sprite*> vector_sprites;
    sf::Clock goomba_time;

    // create the window, lage et objekt av klassen RenderWindow
    sf::RenderWindow window(sf::VideoMode(560, 320), "my window");

    // set fps, enable vsync
    window.setVerticalSyncEnabled(true);

    // texture and sprite mario
    sf::Texture texture_mario{text_mario()};
    sf::Texture texture_mario2{text_mario2()};
    sf::Texture texture_mario3{text_mario3()};
    sf::Texture texture_mario_jumping{text_mario_jumping()};
    sf::Texture texture_big_mario{text_big_mario()};
    sf::Texture texture_big_mario_jumping{text_big_mario_jumping()};

    sf::Sprite sprite_mario(texture_mario);
    sf::FloatRect rectmario = sprite_mario.getGlobalBounds();
    sprite_mario.setPosition(sf::Vector2f(15, 100));

    // texture and sprite background
    sf::Texture texture_bakgrunn{text_bakgrunn()};
    sf::Sprite sprite_background1(texture_bakgrunn);
    vector_sprites.push_back(&sprite_background1);

    // texture and sprite ground
    sf::Texture texture_ground{text_ground()};
    sf::Sprite sprite_ground(texture_ground);
    sprite_ground.setPosition(sf::Vector2f(0, 256));
    vector_sprites.push_back(&sprite_ground);

    sf::Texture texture_ground2{text_end_ground()};
    sf::Sprite sprite_ground2(texture_ground2);
    sprite_ground2.setPosition(sf::Vector2f(200, 256));
    vector_sprites.push_back(&sprite_ground2);

    sf::Sprite sprite_ground3(texture_ground2);
    sprite_ground3.setPosition(sf::Vector2f(568, 256));
    vector_sprites.push_back(&sprite_ground3);

    sf::Sprite sprite_ground4(texture_ground2);
    sprite_ground4.setPosition(sf::Vector2f (936, 256));
    vector_sprites.push_back(&sprite_ground4);

    Castle castle(1000, 192);

    sf::Texture texture_block{text_block()};
    sf::Sprite sprite_block(texture_block);
    sprite_block.setPosition(sf::Vector2f(952, 240));
    vector_sprites.push_back(&sprite_block);

    Pole pole(950, 80);

    sf::Texture texture_flag{text_flag()};
    sf::Sprite sprite_flag(texture_flag);
    sprite_flag.setPosition(sf::Vector2f(940, 90));
    vector_sprites.push_back(&sprite_flag);

    // first brick set
    sf::Texture texture_broken_brick{text_broken_brick()};
    sf::Texture texture_brick{text_brick()};
    sf::Sprite sprite_brick1(texture_brick);
    sf::Sprite sprite_brick2(texture_brick);
    sf::Sprite sprite_brick3(texture_brick);
    sf::Sprite sprite_brick4(texture_brick);
    sf::FloatRect rectbrick1 = sprite_brick1.getGlobalBounds();
    sf::FloatRect rectbrick2 = sprite_brick2.getGlobalBounds();
    sf::FloatRect rectbrick3 = sprite_brick3.getGlobalBounds();
    sf::FloatRect rectbrick4 = sprite_brick4.getGlobalBounds();
    vector_sprites.push_back(&sprite_brick1);
    vector_sprites.push_back(&sprite_brick2);
    vector_sprites.push_back(&sprite_brick3);
    vector_sprites.push_back(&sprite_brick4);
    sprite_brick1.setPosition(sf::Vector2f(48, 208));
    sprite_brick2.setPosition(sf::Vector2f(64, 208));
    sprite_brick3.setPosition(sf::Vector2f(80, 208));
    sprite_brick4.setPosition(sf::Vector2f(96, 208));


    // second brick set
    //sprite_brick5.setPosition(sf::Vector2f (568, 208));
    sf::Texture texture_4_blocks{text_4_block()};
    sf::Sprite sprite_4_blocks(texture_4_blocks);
    sf::Sprite sprite_4_block2(texture_4_blocks);
    sprite_4_blocks.setPosition(sf::Vector2f (568, 208));
    sprite_4_block2.setPosition(sf::Vector2f (650, 208));
    vector_sprites.push_back(&sprite_4_blocks);
    vector_sprites.push_back(&sprite_4_block2);

    sf::Texture texture_5_blocks{text_5_block()};
    sf::Sprite sprite_5_blocks(texture_5_blocks);
    sprite_5_blocks.setPosition(sf::Vector2f (600, 160));
    vector_sprites.push_back(&sprite_5_blocks);
    // third brick set
    //sprite_brick9.setPosition(sf::Vector2f(648, 208));

    // fourth brick set
    //sprite_brick13.setPosition(sf::Vector2f(600, 160));


    sf::Texture texture_tube{text_tube()};
    sf::Sprite sprite_tube1(texture_tube);
    sf::Sprite sprite_tube2(texture_tube);
    sprite_tube1.setPosition(sf::Vector2f(304, 224));
    sprite_tube2.setPosition(sf::Vector2f(432, 224));
    vector_sprites.push_back(&sprite_tube1);
    vector_sprites.push_back(&sprite_tube2);

    // Entities
    Coin coin1(48, 192);
    Coin coin2(64, 192);
    Coin coin3(80, 192);
    Coin coin4(96, 192);
    Coin coin5(436, 214);
    Coin coin6(600, 148);
    Coin coin7(664, 148);

    sf::Texture texture_mushroom{text_mushroom()};
    sf::Sprite sprite_mushroom(texture_mushroom);
    sprite_mushroom.setPosition(sf::Vector2f(247, 192));
    vector_sprites.push_back(&sprite_mushroom);

    sf::Texture texture_lucky_block{text_lucky_block()};
    sf::Sprite sprite_lucky_block(texture_lucky_block);
    sprite_lucky_block.setPosition(sf::Vector2f(247, 192));
    vector_sprites.push_back(&sprite_lucky_block);

    Goomba goomba(350, 240);

    sf::Texture texture_6_block {text_6_block()};
    sf::Sprite sprite_6_blocks_stairs(texture_6_block);
    sprite_6_blocks_stairs.setPosition(sf::Vector2f(824, 240));
    vector_sprites.push_back(&sprite_6_blocks_stairs);

    sf::Texture texture_5_block_stairs{text_5_block()};
    sf::Sprite sprite_5_blocks_stairs (texture_5_block_stairs);
    sprite_5_blocks_stairs.setPosition(sf::Vector2f (840, 224));
    vector_sprites.push_back(&sprite_5_blocks_stairs);

    sf::Texture texture_4_block_stairs{text_4_block()};
    sf::Sprite sprite_4_blocks_stairs(texture_4_block_stairs);
    sprite_4_blocks_stairs.setPosition(sf::Vector2f(856, 208));
    vector_sprites.push_back(&sprite_4_blocks_stairs);

    sf::Texture texture_3_block_stairs{text_3_block()};
    sf::Sprite sprite_3_blocks_stairs(texture_3_block_stairs);
    sprite_3_blocks_stairs.setPosition(sf::Vector2f(872, 192));
    vector_sprites.push_back(&sprite_3_blocks_stairs);

    sf::Texture texture_2_block_stairs{text_2_block()};
    sf::Sprite sprite_2_blocks_stairs(texture_2_block_stairs);
    sprite_2_blocks_stairs.setPosition(sf::Vector2f (888, 176));
    vector_sprites.push_back(&sprite_2_blocks_stairs);

    sf::Sprite sprite_1_blocks_stairs(texture_block);
    sprite_1_blocks_stairs.setPosition(sf::Vector2f(904, 160));
    vector_sprites.push_back(&sprite_1_blocks_stairs);





    // COIN COUNTER
    sf::Texture texture_0coin{text_0coin()};
    sf::Sprite sprite_0coin(texture_0coin);
    sprite_0coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_1coin{text_1coin()};
    sf::Sprite sprite_1coin(texture_1coin);
    sprite_1coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_2coin{text_2coin()};
    sf::Sprite sprite_2coin(texture_2coin);
    sprite_2coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_3coin{text_3coin()};
    sf::Sprite sprite_3coin(texture_3coin);
    sprite_3coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_4coin{text_4coin()};
    sf::Sprite sprite_4coin(texture_4coin);
    sprite_4coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_5coin{text_5coin()};
    sf::Sprite sprite_5coin(texture_5coin);
    sprite_5coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_6coin{text_6coin()};
    sf::Sprite sprite_6coin(texture_6coin);
    sprite_6coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_7coin{text_7coin()};
    sf::Sprite sprite_7coin(texture_7coin);
    sprite_7coin.setPosition(sf::Vector2f(270, 25));

    sf::Texture texture_lava{text_lava()};
    sf::Sprite sprite_lava (texture_lava);
    sprite_lava.setPosition(sf::Vector2f(160, 300));
    vector_sprites.push_back(&sprite_lava);

    sf::Music music1;
    sf::Music music2;
    sf::Music music3;
    sf::Music music4;
    if (!music1.openFromFile("music/music1.ogg"))
    {
        return -1;
    }
    music1.setVolume(100);
    if (!music2.openFromFile("music/music2.ogg"))
    {
        return -1;
    }
    music2.setVolume(100);

    if (!music3.openFromFile("music/music3.ogg"))
    {
        return -1;
    }
    music3.setVolume(100);

    if (!music4.openFromFile("music/end_song.ogg"))
    {
        return -1;
    }
    music4.setVolume(100);

    music1.play();

    sf::SoundBuffer jumpbuffer;
    if (!jumpbuffer.loadFromFile("music/jump_sound.ogg"))
    {
        return -1;
    }
    sf::Sound jumpsound;
    jumpsound.setBuffer(jumpbuffer);


    sf::SoundBuffer coinbuffer;
    if (!coinbuffer.loadFromFile("music/coin_pickup.ogg"))
    {
        return -1;
    }
    sf::Sound coinsound;
    coinsound.setBuffer(coinbuffer);

    sf::SoundBuffer levelupbuffer;
    if (!levelupbuffer.loadFromFile("music/levelup.ogg"))
    {
        return -1;
    }
    sf::Sound levelupsound;
    levelupsound.setBuffer(levelupbuffer);

    sf::SoundBuffer deadbuffer;
    if (!deadbuffer.loadFromFile("music/dying.ogg"))
    {
        return -1;
    }
    sf::Sound deadsound;
    deadsound.setBuffer(deadbuffer);

    sf::SoundBuffer luckybuffer;
    if (!luckybuffer.loadFromFile("music/lucky_sound.ogg"))
    {
        return -1;
    }
    sf::Sound luckysound;
    luckysound.setBuffer(luckybuffer);

    sf::Texture dead_text{text_dead_text()};
    sf::Sprite sprite_dead_text (dead_text);
    sprite_dead_text.setPosition(sf::Vector2f(0, 0));

    sf::Texture won_text{text_won_text()};
    sf::Sprite sprite_won_text(won_text);
    sprite_won_text.setPosition(sf::Vector2f(0, 0));

    float time = 0.f; // initialize time to 0

    sf::FloatRect marioRect = sprite_mario.getGlobalBounds();
    sf::FloatRect tube1Rect = sprite_tube1.getGlobalBounds();
    sf::FloatRect tube2Rect = sprite_tube2.getGlobalBounds();

    if (!sf::Joystick::isConnected(0)){
        std::cout << "Joystick not connected\n";
    }

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen()) {

        // clear the window
        window.clear();

        // check if the first song has finished playing
        if (music1.getStatus() == sf::SoundSource::Stopped && !mario_dead) {
            // stop the current song and play the next one
            music1.stop();
            music2.play();
        }

        // check if the second song has finished playing
        if (music2.getStatus() == sf::SoundSource::Stopped && !mario_dead) {
            // stop the current song and play the next one
            music2.stop();
            music3.play();
        }

        // check if the third song has finished playing
        if (music3.getStatus() == sf::SoundSource::Stopped && !mario_dead) {
            // stop the current song and play the first one again
            music3.stop();
            music1.play();
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float xpos = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        // draw something
        // enables mario to move left, right and down. Also checks if he collides with other sprites.
        if (sf::Event::KeyPressed) {
            if ((1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || xpos > 50)&& !mario_dead && !finish) {
                if (animationtime.getElapsedTime().asMilliseconds() > 200) {
                    // alternate between the two mario sprites
                    if (!marioismoving) {
                        if (mario_is_big == false)
                            sprite_mario.setTexture(texture_mario2);
                    } else {
                        if (mario_is_big == false)
                            sprite_mario.setTexture(texture_mario3);
                    }
                    marioismoving = !marioismoving;
                    animationtime.restart();
                }

                if (sprite_mario.getPosition().x > 50 && sprite_background1.getPosition().x > -560) {
                    if ((mario_intersects(sprite_mario, sprite_tube1) && sprite_tube1.getPosition().x == 66) || ((mario_intersects(sprite_mario, sprite_tube2) && sprite_tube2.getPosition().x == 66))){

                    }
                    else {
                        for (auto& sprite : vector_sprites)
                            (*sprite).move(sf::Vector2f(-2,0));
                        entity_movement -= 2;
                        castle.moveRight();
                        pole.moveRight();
                        goomba.moveRight();
                    }

                } else
                    if ((mario_intersects(sprite_mario, sprite_6_blocks_stairs) && sprite_mario.getPosition().x == 249) || (mario_intersects(sprite_mario, sprite_5_blocks_stairs) && sprite_mario.getPosition().x == 265) || (mario_intersects(sprite_mario, sprite_4_blocks_stairs) && sprite_mario.getPosition().x == 281) || (mario_intersects(sprite_mario, sprite_3_blocks_stairs) && sprite_mario.getPosition().x == 297) || (mario_intersects(sprite_mario, sprite_2_blocks_stairs) && sprite_mario.getPosition().x == 313) || (mario_intersects(sprite_mario, sprite_1_blocks_stairs) && sprite_mario.getPosition().x == 329)){

                    }
                    else
                    sprite_mario.move(sf::Vector2f(2, 0));
            } else if ((1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || xpos < -50) && !mario_dead && !finish) {
                marioismoving = true;
                if (sprite_background1.getPosition().x < 0 && sprite_mario.getPosition().x < 50) {
                    if ((mario_intersects(sprite_mario, sprite_tube1) && sprite_tube1.getPosition().x == 28) ||
                            (mario_intersects(sprite_mario, sprite_tube2) && sprite_tube2.getPosition().x == 28)){

                    }
                    else {
                        for (auto& sprite : vector_sprites)
                            (*sprite).move(sf::Vector2f(2,0));
                        entity_movement += 2;
                        castle.moveLeft();
                        pole.moveLeft();
                        goomba.moveLeft();
                    }
                } else {
                    sprite_mario.move(sf::Vector2f(-2, 0));

                }
            }
            if ((1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 1)) && !finish) {
                if (mario_is_jumping == false && mario_velocity == 0.f) {
                    jumpsound.play();
                    mario_is_jumping = true;
                    mario_velocity = -9.f;
                }
            }

        }
        else {
            marioismoving = false;
            sprite_mario.setTexture(texture_mario);
        }

        if (sprite_mario.getGlobalBounds().intersects(pole.getCoordinates())){
            music4.play();
            finish = true;
            music1.stop();
            music2.stop();
            music3.stop();
        }
        if (finish){
            if (sprite_mario.getPosition().y < sprite_flag.getPosition().y){
                mario_velocity = 1.f;
                sprite_mario.move(0, mario_velocity);
            }

            if (sprite_mario.getPosition().y == sprite_flag.getPosition().y && !touchedblock){
                sprite_mario.setTexture(texture_mario);
                mario_velocity = 1.f;
                flagvelocity = 1.f;
                sprite_mario.move(0, mario_velocity);
                sprite_flag.move(0, flagvelocity);
            }
            else if (!touchedblock){
                sprite_mario.setTextureRect(sf::IntRect(0, 0, 16, 16));
                sprite_mario.setPosition(sf::Vector2f(pole.getx(), sprite_mario.getPosition().y));
                sprite_mario.setTexture(texture_mario);
                sprite_mario.setPosition(sprite_mario.getPosition().x, round(sprite_mario.getPosition().y));
                flagvelocity = 1.f;
                sprite_flag.move(0, flagvelocity);
            }
            if (sprite_flag.getPosition().y == sprite_block.getPosition().y){
                touchedblock = true;
                flagvelocity = 0.f;
                mario_velocity = 0.f;
            }
        }

    else {
            // update coin position with sine wave
            coin1.animation(48.f, 183.f, entity_movement, time);
            coin2.animation(64.f, 183.f, entity_movement, time);
            coin3.animation(80.f, 183.f, entity_movement, time);
            coin4.animation(96.f, 183.f, entity_movement, time);
            coin5.animation(438.f, 198.f, entity_movement, time);
            coin6.animation(600.f, 138.f, entity_movement, time);
            coin7.animation(664.f, 138.f, entity_movement, time);
            time += 0.03f; // increment time by a small amount each frame

            bool brick1_is_1_or_2 = false;
            bool brick2_is_1_or_2 = false;
            bool brick3_is_1_or_2 = false;
            bool brick4_is_1_or_2 = false;


            if (mario_is_jumping == true) {
                if (mario_is_big)
                    sprite_mario.setTexture(texture_big_mario_jumping);
                else
                    sprite_mario.setTexture(texture_mario_jumping);
                mario_velocity += 0.5f;
                sprite_mario.move(sf::Vector2f(0, mario_velocity));


                if (mario_intersects(sprite_mario, sprite_ground) ||
                    mario_intersects(sprite_mario, sprite_ground2) || mario_intersects(sprite_mario, sprite_ground3) ||
                    mario_intersects(sprite_mario, sprite_ground4))
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_6_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_5_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_4_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_3_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_2_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;
                if (mario_intersects(sprite_mario, sprite_1_blocks_stairs) && mario_velocity > 0)
                    mario_is_jumping = false;

                if (mario_intersects(sprite_mario, sprite_lucky_block)){
                    if (mario_velocity < 0){
                        mario_is_jumping = false;
                        mario_velocity = 0.5f;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_lucky_block.getPosition().y + 20);
                        if (lucky_block_used == false){
                            lucky_block_used = true;
                            sprite_lucky_block.setTexture(texture_block);
                            sprite_mushroom.move(sf::Vector2f (0, -16));
                            luckysound.play();
                        }
                    }
                    else{
                        mario_is_jumping = false;
                    }
                }

                if (mario_intersects(sprite_mario, sprite_4_blocks) ||
                    mario_intersects(sprite_mario, sprite_4_block2)) {
                    if (mario_velocity < 0) {
                        mario_is_jumping = false;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_4_blocks.getPosition().y + 20.f);
                    } else
                        mario_is_jumping = false;
                }

                if (mario_intersects(sprite_mario, sprite_5_blocks)) {
                    if (mario_velocity < 0) {
                        mario_is_jumping = false;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_5_blocks.getPosition().y + 20.f);
                    } else
                        mario_is_jumping = false;
                }

                if (mario_intersects(sprite_mario, sprite_brick1)) {
                    if (brick1_value == 1 || brick1_value == 2)
                        brick1_is_1_or_2 = true;
                    if (mario_velocity < 0 &&
                        sprite_mario.getGlobalBounds().intersects(sprite_brick1.getGlobalBounds()) &&
                        brick1_is_1_or_2) {
                        mario_is_jumping = false;
                        brick1_value = brick1_value + 1;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_brick1.getPosition().y + 20.f);
                    } else if (mario_velocity > 0 &&
                               sprite_mario.getGlobalBounds().intersects(sprite_brick1.getGlobalBounds()) &&
                               brick1_is_1_or_2) {
                        if (mario_is_big) {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick1.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 32));
                        } else {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick1.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                }
                if (mario_intersects(sprite_mario, sprite_brick2)) {
                    if (brick2_value == 1 || brick2_value == 2)
                        brick2_is_1_or_2 = true;
                    if (mario_velocity < 0 &&
                        sprite_mario.getGlobalBounds().intersects(sprite_brick2.getGlobalBounds()) &&
                        brick2_is_1_or_2) {
                        mario_is_jumping = false;
                        brick2_value = brick2_value + 1;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_brick2.getPosition().y + 20.f);
                    } else if (mario_velocity > 0 &&
                               sprite_mario.getGlobalBounds().intersects(sprite_brick2.getGlobalBounds()) &&
                               brick2_is_1_or_2) {
                        if (mario_is_big) {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick2.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 32));
                        } else {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick2.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                }

                if (mario_intersects(sprite_mario, sprite_brick3)) {
                    if (brick3_value == 1 || brick3_value == 2)
                        brick3_is_1_or_2 = true;
                    if (mario_velocity < 0 &&
                        sprite_mario.getGlobalBounds().intersects(sprite_brick3.getGlobalBounds()) &&
                        brick3_is_1_or_2) {
                        mario_is_jumping = false;
                        brick3_value = brick3_value + 1;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_brick3.getPosition().y + 20.f);
                    } else if (mario_velocity > 0 &&
                               sprite_mario.getGlobalBounds().intersects(sprite_brick3.getGlobalBounds()) &&
                               brick3_is_1_or_2) {
                        if (mario_is_big) {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick3.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 32));
                        } else {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick3.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                }

                if (mario_intersects(sprite_mario, sprite_brick4)) {
                    if (brick4_value == 1 || brick4_value == 2)
                        brick4_is_1_or_2 = true;
                    if (mario_velocity < 0 &&
                        sprite_mario.getGlobalBounds().intersects(sprite_brick4.getGlobalBounds()) &&
                        brick4_is_1_or_2 == true) {
                        brick4_value = brick4_value + 1;
                        mario_velocity = 0.5;
                        sprite_mario.setPosition(sprite_mario.getPosition().x, sprite_brick4.getPosition().y + 17.f);
                        mario_is_jumping = false;
                    } else if (mario_velocity > 0 &&
                               sprite_mario.getGlobalBounds().intersects(sprite_brick4.getGlobalBounds()) &&
                               brick4_is_1_or_2 == true) {
                        if (mario_is_big) {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick4.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 32));
                        } else {
                            mario_is_jumping = false;
                            float bricktop = sprite_brick4.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                }

                if (mario_intersects(sprite_mario, sprite_tube1) || mario_intersects(sprite_mario, sprite_tube2)) {
                    mario_is_jumping = false;
                }
            } else {
                mario_velocity += gravity;
                sprite_mario.move(0, mario_velocity);
            }

            if (mario_is_jumping == false) {
                if (!marioismoving)
                    if (mario_is_big)
                        sprite_mario.setTexture(texture_big_mario);
                    else
                        sprite_mario.setTexture(texture_mario);
                // Check if Mario intersects with ground
                if (sprite_mario.getGlobalBounds().intersects(sprite_ground.getGlobalBounds())) {
                    if (mario_is_big == true) {
                        float grasstop = sprite_ground.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, grasstop - 32));
                    } else {// Adjust Mario's position to stand on the grass
                        float grasstop = sprite_ground.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, grasstop - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                }
                    // Check if Mario intersects with the grass sprite
                else if (sprite_ground2.getGlobalBounds().intersects(sprite_mario.getGlobalBounds())) {
                    if (mario_is_big) {
                        float groundtop2 = sprite_ground2.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float groundtop2 = sprite_ground2.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                }
                    // Check if Mario intersects with the grass sprite
                else if (sprite_ground3.getGlobalBounds().intersects(sprite_mario.getGlobalBounds())) {
                    if (mario_is_big) {
                        float groundtop3 = sprite_ground3.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop3 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float groundtop3 = sprite_ground3.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop3 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                }
                    // Check if Mario intersects with the grass sprite
                else if (sprite_ground4.getGlobalBounds().intersects(sprite_mario.getGlobalBounds())) {
                    if (mario_is_big) {
                        float groundtop4 = sprite_ground4.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop4 - 32));
                    } else {// Adjust Mario's position to stand on the grass
                        float groundtop4 = sprite_ground4.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop4 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_tube1)) {
                    if (sprite_mario.getPosition().y < 231) {
                        if (mario_is_big) {
                            float tube1top = sprite_tube1.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, tube1top - 32));
                        } else {
                            float tube1top = sprite_tube1.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, tube1top - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_tube2)) {
                    if (sprite_mario.getPosition().y < 231) {
                        if (mario_is_big) {
                            float tube2top = sprite_tube2.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, tube2top - 32));
                        } else {
                            float tube2top = sprite_tube2.getPosition().y;
                            sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, tube2top - 16));
                        }
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_brick1)) {
                    if (brick1_value == 1 || brick1_value == 2)
                        brick1_is_1_or_2 = true;
                    if (brick1_is_1_or_2) {
                        float bricktop = sprite_brick1.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_brick2)) {
                    if (brick2_value == 1 || brick2_value == 2)
                        brick2_is_1_or_2 = true;
                    if (brick2_is_1_or_2) {
                        float bricktop = sprite_brick2.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_brick3)) {
                    if (brick3_value == 1 || brick3_value == 2)
                        brick3_is_1_or_2 = true;
                    if (brick3_is_1_or_2) {
                        float bricktop = sprite_brick3.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_brick4)) {
                    if (brick4_value == 1 || brick4_value == 2)
                        brick4_is_1_or_2 = true;
                    if (brick4_is_1_or_2) {
                        float bricktop = sprite_brick4.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, bricktop - 16));
                        mario_velocity = 0.0f; // Stop Mario from falling through the grass
                    }
                } else if (mario_intersects(sprite_mario, sprite_4_blocks) ||
                           mario_intersects(sprite_mario, sprite_4_block2)) {
                    if (mario_is_big) {
                        float blocktop3 = sprite_4_blocks.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, blocktop3 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float blocktop3 = sprite_4_blocks.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, blocktop3 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_5_blocks)) {
                    if (mario_is_big) {
                        float blocktop3 = sprite_5_blocks.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, blocktop3 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float blocktop3 = sprite_5_blocks.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, blocktop3 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_6_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop1 = sprite_6_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop1 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop1 = sprite_6_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop1 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_5_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop2 = sprite_5_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop2 = sprite_5_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_4_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop2 = sprite_4_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop2 = sprite_4_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_3_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop2 = sprite_3_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop2 = sprite_3_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_2_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop2 = sprite_2_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop2 = sprite_2_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                } else if (mario_intersects(sprite_mario, sprite_1_blocks_stairs)) {
                    if (mario_is_big) {
                        float stairtop2 = sprite_1_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float stairtop2 = sprite_1_blocks_stairs.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, stairtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                }
                else if (mario_intersects(sprite_mario, sprite_lucky_block)) {
                    if (mario_is_big) {
                        float groundtop2 = sprite_lucky_block.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop2 - 32));
                    } else {
                        // Adjust Mario's position to stand on the grass
                        float groundtop2 = sprite_lucky_block.getPosition().y;
                        sprite_mario.setPosition(sf::Vector2f(sprite_mario.getPosition().x, groundtop2 - 16));
                    }
                    mario_velocity = 0.0f; // Stop Mario from falling through the grass
                }
                if (mario_intersects(sprite_mario, sprite_mushroom)) {
                    if (mushroom_taken == false) {
                        sprite_mario.setPosition(
                                sf::Vector2f(sprite_mario.getPosition().x, sprite_mario.getPosition().y - 32));
                        sprite_mario.setTextureRect(sf::IntRect(0, 0, 16, 32));
                        sprite_mario.setTexture(texture_big_mario);
                        levelupsound.play();
                    }
                    mario_is_big = true;
                    mushroom_taken = true;
                }
                // hold mario within the screen
                if (sprite_mario.getPosition().x < 0) {
                    sprite_mario.setPosition(sf::Vector2f(0, sprite_mario.getPosition().y));
                } else if (sprite_mario.getPosition().x > 1020 - sprite_mario.getGlobalBounds().width) {
                    sprite_mario.setPosition(
                            sf::Vector2f(1020 - sprite_mario.getGlobalBounds().width, sprite_mario.getPosition().y));
                }
            }
        }
    if (sprite_mario.getGlobalBounds().intersects(goomba.getGlobalBounds())){
        if (sprite_mario.getPosition().y < 224 && !goomba.dead && mario_is_big){
            goomba.dead = true;
            goomba.dead_goomba();
            jumpsound.play();
            mario_is_jumping = true;
            mario_velocity = -9.f;
        }
        else if (sprite_mario.getPosition().y < 235 && !goomba.dead && !mario_is_big){
            goomba.dead = true;
            goomba.dead_goomba();
            jumpsound.play();
            mario_is_jumping = true;
            mario_velocity = -9.f;
        }
        else if (!goomba.dead && goomba_time.getElapsedTime().asSeconds() > 2.f){
            if (mario_is_big){
                sprite_mario.setTexture(texture_mario);
                sprite_mario.setTextureRect(sf::IntRect(0, 0, 16, 16));
                mario_is_big = false;
                sprite_mario.setPosition(sf::Vector2f (sprite_mario.getPosition().x, sprite_mario.getPosition().y+15.f));
                goomba_time.restart();
        }
            else{
                mario_dead = true;
            }
        }
    }

        if (sprite_mario.getPosition().y >= 300)
            mario_dead = true;

        if (!goomba.dead) {
            if (goomba.getGlobalBounds().intersects(sprite_tube1.getGlobalBounds()))
                goomba_left_right = false;

            else if (goomba.getGlobalBounds().intersects(sprite_tube2.getGlobalBounds()))
                goomba_left_right = true;


            if (goomba_left_right == true)
                goomba.hit_tube1();
            else
                goomba.hit_tube2();
        }

        window.draw(sprite_lava);

        window.draw(sprite_background1);
        window.draw(sprite_lava);
        window.draw(sprite_ground);
        window.draw(sprite_ground2);
        window.draw(sprite_ground3);
        window.draw(sprite_ground4);

        if (brick1_value == 1) {
            sprite_brick1.setTexture(texture_brick);
            window.draw(sprite_brick1);
        }
        else if (brick1_value == 2) {
            sprite_brick1.setTexture(texture_broken_brick);
            window.draw(sprite_brick1);
        }
        if (brick2_value == 1) {
            sprite_brick2.setTexture(texture_brick);
            window.draw(sprite_brick2);
        }
        else if (brick2_value == 2) {
            sprite_brick2.setTexture(texture_broken_brick);
            window.draw(sprite_brick2);
        }
        if (brick3_value == 1) {
            sprite_brick3.setTexture(texture_brick);
            window.draw(sprite_brick3);
        }
        else if (brick3_value == 2) {
            sprite_brick3.setTexture(texture_broken_brick);
            window.draw(sprite_brick3);
        }
        if (brick4_value == 1) {
            sprite_brick4.setTexture(texture_brick);
            window.draw(sprite_brick4);
        }
        else if (brick4_value == 2) {
            sprite_brick4.setTexture(texture_broken_brick);
            window.draw(sprite_brick4);
        }

        window.draw(sprite_4_blocks);
        window.draw(sprite_4_block2);
        window.draw(sprite_5_blocks);

        window.draw(castle.getSprite());
        window.draw(sprite_block);
        window.draw(pole.getSprite());
        window.draw(sprite_flag);

        if (mushroom_taken == false)
            window.draw(sprite_mushroom);

        window.draw(sprite_lucky_block);

        window.draw(sprite_tube1);
        window.draw(sprite_tube2);


        window.draw(sprite_1_blocks_stairs);
        window.draw(sprite_2_blocks_stairs);
        window.draw(sprite_3_blocks_stairs);
        window.draw(sprite_4_blocks_stairs);
        window.draw(sprite_5_blocks_stairs);
        window.draw(sprite_6_blocks_stairs);

        window.draw(goomba.getSprite());

        if (coin1.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin1.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin1.checkcollected();
                coinsound.play();
            }
        }
        if (coin2.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin2.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin2.checkcollected();
                coinsound.play();
            }
        }
        if (coin3.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin3.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin3.checkcollected();
                coinsound.play();
            }
        }
        if (coin4.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin4.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin4.checkcollected();
                coinsound.play();
            }
        }
        if (coin5.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin5.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin5.checkcollected();
                coinsound.play();
            }
        }
        if (coin6.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin6.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin6.checkcollected();
                coinsound.play();
            }
        }
        if (coin7.collected == false) {
            if (sprite_mario.getGlobalBounds().intersects(coin7.getCoordinates())) {
                coin_counter = coin_counter + 1;
                coin7.checkcollected();
                coinsound.play();
            }
        }


        if (coin1.collected == false)
            window.draw(coin1.getsprite());
        if (coin2.collected == false)
            window.draw(coin2.getsprite());
        if (coin3.collected == false)
            window.draw(coin3.getsprite());
        if (coin4.collected == false)
            window.draw(coin4.getsprite());
        if (coin5.collected == false)
            window.draw(coin5.getsprite());
        if (coin6.collected == false)
            window.draw(coin6.getsprite());
        if (coin7.collected == false)
            window.draw(coin7.getsprite());

        if (coin_counter == 0)
            window.draw(sprite_0coin);
        else if (coin_counter == 1)
            window.draw(sprite_1coin);
        else if (coin_counter == 2)
            window.draw(sprite_2coin);
        else if (coin_counter == 3)
            window.draw(sprite_3coin);
        else if (coin_counter == 4)
            window.draw(sprite_4coin);
        else if (coin_counter == 5) {
            window.draw(sprite_5coin);
        } else if (coin_counter == 6) {
            window.draw(sprite_6coin);
        } else if (coin_counter == 7) {
            window.draw(sprite_7coin);
        }

        if (!mario_dead)
            window.draw(sprite_mario);
        else {
            window.draw(sprite_dead_text);
        }

        if (mario_dead && !mario_dead_sound){
            deadsound.play();
            music1.stop();
            music2.stop();
            music3.stop();
            mario_dead_sound = true;
        }
        if (finish)
            window.draw(sprite_won_text);

        std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;


        // buffer swap.
        window.display();

        clock.restart();
    }

    return 0;
}
