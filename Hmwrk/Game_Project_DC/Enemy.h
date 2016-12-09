/* 
 * File:   Enemy.h
 * Author: rcc
 *
 * Created on December 8, 2016, 1:56 PM
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"


class Enemy: public Entity {
public:
    Enemy(string name, int Hp , int Dmg, int Exp):Entity(name){
        this->rathp=10;
    }
    virtual ~Enemy();

    
private:

    int rathp; //rat health
    int ratdmg; //rat damage
    int ratexp; //rat experience gained

    int cychp; //cyclops health
    int cycdmg; //cyclops damage
    int cycexp; //cyclops experience gained

    int skelhp; //skeleton health
    int skeldmg; //skeleton damage
    int skelexp; //skeleton experience gained

    int draghp; //dragon health
    int dragdmg; //dragon damage
    int dragexp; //dragon experience gained

    int vamphp; //vampire health
    int vampdmg; //vampire damage
    int vampexp; //vampire experience gained

    int ghoulhp; //ghoul health
    int ghouldmg; //ghoul damage
    int ghoulexp; //ghoul experience

    int armagehp; //archmage health
    int armagedmg; //archmage damage
    int armageexp; //archmage experience gained

    int thiefhp; //thief health
    int thiefdmg; //thief damage
    int thiefexp; //thief experience  

    int guardhp; //guard health
    int guarddmg; //guard damage
    int guardexp; //guard experience

    int armorhp; //guard health
    int armordmg; //guard damage
    int armorexp; //guard experience

};

#endif /* ENEMY_H */

