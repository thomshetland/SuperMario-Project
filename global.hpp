#pragma once

const float gravity = 5.f;

float entity_movement = 0;

bool goomba_left_right = true;

bool mario_dead = false;
bool mario_dead_sound = false;

bool mario_is_jumping = false;
float mario_velocity = 0.f;

int coin_counter = 0;
bool coin1_collected = false;
bool coin2_collected = false;
bool coin3_collected = false;
bool coin4_collected = false;
bool coin5_collected = false;
bool coin6_collected = false;
bool coin7_collected = false;

const int ground_array_size = 3;

sf::Clock animationtime;
bool marioismoving = false;

int brick1_value = 1;
int brick2_value = 1;
int brick3_value = 1;
int brick4_value = 1;

bool bool_gravity = true;

bool mario_is_big = false;
bool mushroom_taken = false;

bool finish = false;
bool touchedblock = false;
float flagvelocity = 0;

bool lucky_block_used = false;


