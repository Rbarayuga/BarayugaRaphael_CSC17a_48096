/* 
 * File:   Player.h
 * Author: Raphael M.B. Barayuga
 * 
 * Created on December 8, 2016, 12:13 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Entity.h"
using namespace std;
class Player: public Entity {
public:
     Player(string name): Entity(name){
        this->sword  = (rand() % 15 + 1);
        this->magic  = (rand() % 20 + 1);
        this->dagger =( rand() % 15 + 1)*2 ;
        this->exp = 0;
    }
  
    virtual ~Player();
    void SetLevel(int level);
    int GetLevel() const;
    void SetDagger(int dagger);
    int GetDagger() const;
    void SetMagic(int magic);
    int GetMagic() const;
    void SetSword(int sword);
    int GetSword() const;
    void SetJclass(string jclass);
    string GetJclass() const;
    void SetExp(int exp);
    int GetExp() const;
    void SetHealth(int health);
    int GetHealth() const;
    void SetName(string name);
    string GetName() const;
private:
    string jclass; //Player job class
    string name; //Name of player's character
    int health; //Health of the player
    int sword; //Weapon class
    int magic; //Weapon class
    int dagger; //Weapon class 
    int exp;     //Experience of player
    int level; //Level of character
    
};

#endif /* PLAYER_H */

