
/* 
 * File:   Entity.h
 * Author: Raphael M.B. Barayuga
 * 
 * Created on December 8, 2016, 12:13 PM
 */

#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <cstdlib>
using namespace std;
class Entity {
public:
    Entity(string name) :
        name(name) {
    }
    virtual ~Entity();
    void SetExp(int exp);
    int GetExp() const;
    void SetDmg(int dmg);
    int GetDmg() const;
    void SetHp(int hp);
    int GetHp() const;
    void SetName(string name);
    string GetName() const;
    
protected:
    string name;
    int hp; 
    int dmg; 
    int exp;

};

#endif /* ENTITY_H */

