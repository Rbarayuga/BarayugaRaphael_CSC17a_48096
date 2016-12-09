/* 
 * File:   Entity.cpp
 * Author: Raphael M.B. Barayuga
 * 
 * Created on December 8, 2016, 12:13 PM
 */

#include "Entity.h"


Entity::~Entity() {
}

void Entity::SetExp(int exp) {
    this->exp = exp;
}

int Entity::GetExp() const {
    return exp;
}

void Entity::SetDmg(int dmg) {
    this->dmg = dmg;
}

int Entity::GetDmg() const {
    return dmg;
}

void Entity::SetHp(int hp) {
    this->hp = hp;
}

int Entity::GetHp() const {
    return hp;
}

void Entity::SetName(string name) {
    this->name = name;
}

string Entity::GetName() const {
    return name;
}

