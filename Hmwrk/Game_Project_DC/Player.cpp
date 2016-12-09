/* 
 * File:   Player.cpp
 * Author: Raphael M.B. Barayuga
 * 
 * Created on December 8, 2016, 12:13 PM
 */

#include "Player.h"


Player::~Player() {
}

void Player::SetLevel(int level) {
    this->level = level;
}

int Player::GetLevel() const {
    return level;
}

void Player::SetDagger(int dagger) {
    this->dagger = dagger;
}

int Player::GetDagger() const {
    return dagger;
}

void Player::SetMagic(int magic) {
    this->magic = magic;
}

int Player::GetMagic() const {
    return magic;
}

void Player::SetSword(int sword) {
    this->sword = sword;
}

int Player::GetSword() const {
    return sword;
}

void Player::SetJclass(string jclass) {
    this->jclass = jclass;
}

string Player::GetJclass() const {
    return jclass;
}

void Player::SetExp(int exp) {
    this->exp = exp;
}

int Player::GetExp() const {
    return exp;
}

void Player::SetHealth(int health) {
    this->health = health;
}

int Player::GetHealth() const {
    return health;
}

void Player::SetName(string name) {
    this->name = name;
}

string Player::GetName() const {
    return name;
}


