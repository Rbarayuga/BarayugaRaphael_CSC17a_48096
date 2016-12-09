
/* 
 * File:   main.cpp
 * Author: Raphael M.B Barayuga
 * Purpose: Project Game
 * Created on December 8, 2016 11:30 am
 */

//System Libraries
#include <cstdlib>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

//User Libraries

#include "Game.h"
#include "Player.h"
#include "Utilities.h"
#include "Enemy.h"
//Execution

int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));
    Utilities::intro();

    string inputStr;
    cout << "What is your name?" << endl;
    getline(cin, inputStr);
    Player *player = new Player(inputStr);
    player->SetName(inputStr);
    cout << "Nice to meet you: " << player->GetName() << endl;

    //Input class choice
    cout << "What is your job choice?" << endl;
    cin >> inputStr;

    player->SetJclass(inputStr);

    if (player->GetJclass() == "Fighter" ||
            player->GetJclass() == "fighter") {
        Potion pot;
        player->SetHealth(50);
        Enemy rat("rat", 10, rand() % 2 + 1, 5);
        Enemy cyclops("cyclops", 35, rand() % 15 + 1, 20);
        Enemy dragon("dragon", 45, rand() % 12 + 1, 50);
        Enemy skeleton("skeleton", 35, rand() % 10 + 1, 20);
        
        pot.hpot = 10;
        fstream myfile("PlayerStat.txt", ios::out | ios::binary);
        //Fighter Story
        cout << "You chose Fighter \nGet ready!" << endl;
        cout << "Tutorial on how to play!\n\n" << endl;
        cout << "Your sword does 1-15 damage" << endl;
        cout << "You have 50 starting health" << endl;
        cout << "Potions will heal you for 10 health" << endl;
        cout << "The monster will always hit you" << endl;
        cout << "You can choose whether to attack or drink a potion" << endl;
        cout << "You will fight a rat first to learn how to play" << endl;
        cout << "Type attack to swing or potion to gain health" << endl;

        // Loop Combat till death
        do {
            string turn;
            //Variables of damage loop
            rat.SetHp(50);
            rat.SetDmg(rand() % 2 + 1);
            rat.SetExp(5);
            player->SetSword(rand() % 15 + 1);
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            // Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You swung for: " << player->GetSword() << endl;
                rat.SetHp(rat.GetHp() - player->GetSword());
                cout << rat.GetName() << " has: " << rat.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (rat.GetHp() <= 0) {
                cout << "Good job! You killed the rat continue on" << endl;
                player->SetExp(player->GetExp() + rat.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() > 0 && rat.GetHp() > 0);

        cout << "Now that you know how to play, lets get going!\n" << endl;
        //Story


        cout << player->GetName() << " an adventurer for hire,\n" << player->GetName()
                << " is talked with clearing out a monsters' den a few miles away\n"
                << "from the village of Fukkatton." << endl;
        cout << player->GetName() << " enters the den and hears the sound of screaming\n"
                << player->GetName() << " rushes in, sword drawn and sees a"
                << cyclops.GetName() << ".\n"
                << "You have engaged in combat!" << endl;

        //Cyclops fight loop

        do {
            string turn;
            //Variables for damage loop
            cyclops.SetDmg(rand() % 15 + 1);
            cyclops.SetHp(35);
            cyclops.SetExp(20);
            player->SetSword(rand() % 15 + 1);

            cout << "Choose your action! Attack | Potion " << endl;

            cin>>turn;

            if (turn == "attack" || turn == "Attack") {
                cout << "You swung for: " << player->GetSword() << endl;
                cyclops.SetHp(cyclops.GetHp() - player->GetSword());
                cout << cyclops.GetName() << " has: " << cyclops.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - cyclops.GetDmg());
                cout << cyclops.GetName() << " attacked for: " << cyclops.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - cyclops.GetDmg());
                cout << cyclops.GetName() << " attacked for: " << cyclops.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (cyclops.GetHp() <= 0) {
                cout << "Good job! You killed the " << cyclops.GetName() << " continue on" << endl;
                player->SetExp(player->GetExp() + cyclops.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }
            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() >= 0 && cyclops.GetHp() > 0);

        cout << "After slaying the cyclops " << player->GetName()
                << " comes across a handful of imprisoned villagers\n"
                << player->GetName() << " frees the villagers before continuing further\n"
                << player->GetName() << " finds a " << skeleton.GetName() << ", with weapon drawn\n"
                << "You have engaged in combat!" << endl;
        //Skeleton Fight

        do {
            string turn;
            //Variables for damage loop

            player->SetSword(rand() % 15 + 1);
            cout << "Choose your action! Attack | Potion " << endl;

            cin>>turn;

            if (turn == "attack" || turn == "Attack") {
                cout << "You swung for: " << player->GetSword() << endl;
                skeleton.SetHp(skeleton.GetHp() - player->GetSword());
                cout << skeleton.GetName() << " has: " << skeleton.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - skeleton.GetDmg());
                cout << skeleton.GetName() << " attacked for: " << skeleton.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - skeleton.GetDmg());
                cout << skeleton.GetName() << " attacked for: " << skeleton.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (skeleton.GetHp() <= 0) {
                cout << "Good job! You killed the skeleton continue on" << endl;
                player->SetExp(player->GetExp() + skeleton.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }
            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() >= 0 && skeleton.GetHp() >= 0);

        cout << "On the way out of the den " << player->GetName() << " encounters a dragon!\n"
                << "Begin combat!" << endl;


        //Boss Dragon Fight
        do {
            string turn;
            //Variables for damage loop
            player->SetSword(rand() % 15 + 1);
            dragon.SetHp(45);
            dragon.SetDmg(rand() % 12 + 1);
            dragon.SetExp(50);

            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;
            if (turn == "attack" || turn == "Attack") {
                cout << "You swung for: " << player->GetSword() << endl;
                dragon.SetHp(dragon.GetHp() - player->GetSword());
                cout << dragon.GetName() << " has: " << dragon.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - dragon.GetDmg());
                cout << dragon.GetName() << " attacked for: " << dragon.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - dragon.GetDmg());
                cout << dragon.GetName() << " attacked for: " << dragon.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (dragon.GetHp() <= 0) {
                cout << "Good job! You killed the " << dragon.GetName() << " continue on" << endl;
                player->SetExp(player->GetExp() + dragon.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }
            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() >= 0 && dragon.GetHp() >= 0);

        cout << player->GetName() << " Has slain the " << dragon.GetName()
                << " and returns to the village\n"
                << "and receives a heroes welcome!" << endl;
        cout << "Congratulations: " << player->GetName()
                << ", you have beaten the fighters story.\n"
                << "Restart game to try a new story or replay!" << endl;

        myfile.open("PlayerStat.txt", ios::out | ios::binary);
        myfile.write(reinterpret_cast<char *> (player), sizeof (player));
        myfile << player->GetExp();
        myfile.close(); //Close File
        delete[] player;
        return 0;
    }
    //Mage story
    if (player->GetJclass() == "Mage" ||
            player->GetJclass() == "mage") {

        Potion pot;
        srand(static_cast<unsigned int> (time(0)));
        Enemy rat("rat", 10, rand() % 2 + 1, 5);
        Enemy vampire("vampire", 20, rand() % 8 + 1, 10);
        Enemy ghoul("ghoul", 25, rand() % 15 + 1, 20);
        player->SetHealth(40);
        pot.hpot = 8;
        fstream myfile("PlayerStat.txt", ios::out | ios::binary);

        cout << "You chose Mage \nGet ready!" << endl;
        cout << "Tutorial on how to play!\n\n" << endl;
        cout << "Your magic does 1-20 damage" << endl;
        cout << "You have 40 starting health" << endl;
        cout << "Potions will heal you for 8 health" << endl;
        cout << "The monster will always hit you" << endl;
        cout << "You can choose whether to attack or drink a potion" << endl;
        cout << "You will fight a rat first to learn how to play" << endl;
        cout << "Type attack to cast your magic or potion to gain health" << endl;

        //Tutorial fight
        while (player->GetHealth() >= 0 && rat.GetHp() >= 0) {
            string turn;
            rat.SetHp(10);
            rat.SetDmg(rand() % 2 + 1);
            rat.SetExp(5);
            player->GetMagic();

            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Rat fight
            if (turn == "attack" || turn == "Attack") {
                cout << "You cast fire for: " << player->GetMagic() << endl;
                rat.SetHp(rat.GetHp() - player->GetMagic());
                ;
                cout << rat.GetName() << " has: " << rat.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (rat.GetHp() <= 0) {
                cout << "Good job! You killed the " << rat.GetName() << " continue on" << endl;
                player->SetExp(player->GetExp() + rat.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }

        //Start
        cout << "Now that you know how to play, lets get going! \n" << endl;
        cout << player->GetName() << " a wizard in search of a new lair,\n "
                << player->GetName() << "stumbles upon the lair off a "
                << vampire.GetName() << " coven\n"
                << "and sets about claiming it for themself.\n"
                << player->GetName() << " encounters a " << vampire.GetName() <<
                ".\n " << "Begin combat!" << endl;
        //Vampire Fight
        while (player->GetHealth() >= 0 && vampire.GetHp() >= 0) {
            string turn;

            player->GetMagic();
            vampire.GetDmg();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You cast fire for: " << player->GetMagic() << endl;
                vampire.SetHp(vampire.GetHp() - player->GetMagic());
                cout << vampire.GetName() << " has: " << vampire.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - vampire.GetDmg());
                cout << vampire.GetName() << " attacked for: " << vampire.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - vampire.GetDmg());
                cout << vampire.GetName() << " attacked for: " << vampire.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (vampire.GetHp() <= 0) {
                cout << "Good job! You killed the" << vampire.GetName() << " continue on" << endl;
                player->SetExp(player->GetExp() + vampire.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }
        cout << "After defeating the" << vampire.GetName() << " with fire" << player->GetName()
                << "makes their way deeper into the cave.\n"
                << "By this point, the " << ghoul.GetName() << " of the lair has taken notice of "
                << player->GetName() << ". \nBegin combat!" << endl;

        //Ghoul Fight
        while (player->GetHealth() > 0 && ghoul.GetHp() > 0) {
            string turn;
            player->GetMagic();
            ghoul.GetDmg();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You cast fire for: " << player->GetMagic() << endl;
                ghoul.SetHp(ghoul.GetHp() - player->GetMagic());
                cout << ghoul.GetName() << " has: " << ghoul.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - ghoul.GetDmg());
                cout << ghoul.GetName() << " attacked for: " << ghoul.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to: " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - ghoul.GetDmg());
                cout << ghoul.GetName() << " attacked for: " << ghoul.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (ghoul.GetHp() <= 0) {
                cout << "Good job! You killed the" << ghoul.GetName() << " continue on" << endl;
                player->SetExp(player->GetExp() + ghoul.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }
        Enemy archmage("Archmage Farts Mcgarts", 40, rand() % 12 + 1, 50);
        cout << player->GetName()
                << "slays the ghoul before advancing into the final chamber,\n "
                << "where" << player->GetName()
                << " meets against "
                << archmage.GetName() << endl;

        //boss Arch Mage FartsMcgarts


        while (player->GetHealth() >= 0 && archmage.GetHp() >= 0) {
            string turn;

            //Variables of damage loop
            archmage.GetDmg();
            player->GetMagic();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You cast fire for: " << player->GetMagic() << endl;
                archmage.SetHp(archmage.GetHp() - player->GetMagic());
                cout << archmage.GetName() << " has: " << archmage.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - archmage.GetDmg());
                cout << archmage.GetName() << "attacked for: " << archmage.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - archmage.GetDmg());
                cout << archmage.GetName() << "attacked for: " << archmage.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (archmage.GetHp() <= 0) {
                cout << "Good job! You have slain " << archmage.GetName() << endl;
                player->SetExp(player->GetExp() + archmage.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }

        cout << "After incinerating " << archmage.GetName()
                << "," << player->GetName() << "sets about furnishing their new home" << endl;
        cout << "Congratulations: " << player->GetName()
                << ", you have beaten the Mages story.\n"
                << "Restart game to try a new story or replay!" << endl;
        myfile.open("PlayerStat.txt", ios::out | ios::binary);
        myfile.write(reinterpret_cast<char *> (player), sizeof (player));
        myfile << player->GetExp();
        myfile.close(); //Close File
        delete[] player;
    }

    //Rogue Story
    if (player->GetJclass() == "Rogue" || player->GetJclass() == "rogue") {
        srand(static_cast<unsigned int> (time(0)));
        Potion pot;
        Enemy rat("rat", 10, rand() % 2 + 1, 5);
        Enemy thief("thief", 20, rand() % 8 + 1, 10);
        Enemy guard("guard", 25, rand() % 10 + 1, 20);
        Enemy armor("armored boss", 40, rand() % 15 + 1, 50);
        player->SetHealth(25);
        player->GetDagger();
        pot.hpot = 5;
        fstream myfile("PlayerStat.txt", ios::out | ios::binary);
        cout << "You chose Rogue \nGet ready!" << endl;
        cout << "Tutorial on how to play!\n\n" << endl;
        cout << "You have two daggers each dagger does 1-15 damage" << endl;
        cout << "You have 15 starting health" << endl;
        cout << "Potions will heal you for 5 health" << endl;
        cout << "The monster will always hit you" << endl;
        cout << "You can choose whether to attack or drink a potion" << endl;
        cout << "You will fight a rat first to learn how to play" << endl;
        cout << "Type attack to fight or potion to gain health" << endl;

        //Rat Fight
        do {
            string turn;
            rat.SetHp(10);
            rat.SetDmg(rand() % 2 + 1);
            rat.SetExp(5);
            player->GetDagger();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You swung for: " << player->GetDagger() << endl;
                rat.SetHp(rat.GetHp() - player->GetDagger());
                cout << rat.GetName() << " has: " << rat.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - rat.GetDmg());
                cout << rat.GetName() << " attacked for: " << rat.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (rat.GetHp() <= 0) {
                cout << "Good job! You killed the rat continue on" << endl;
                player->SetExp(player->GetExp() + rat.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() >= 0 && rat.GetHp() >= 0);

        cout << "Now that you know how to play, lets get going!\n" << endl;
        cout << player->GetName() << ", a wandering treasure hunter, " << player->GetName()
                << "\n stumbles into a thieves hideout and encounters the thief"
                << "Begin combat!" << endl;


        //Thief Fight
        while (player->GetHealth() > 0 && thief.GetHp() > 0) {
            string turn;

            //Variables of damage loop
            Enemy thief("thief", 20, rand() % 8 + 1, 10);
            player->GetDagger();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You cast fire for: " << player->GetDagger() << endl;
                thief.SetHp(thief.GetHp() - player->GetDagger());
                cout << thief.GetName() << " has: " << thief.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - thief.GetDmg());
                cout << thief.GetName() << " attacked for: " << thief.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - thief.GetDmg());
                cout << thief.GetName() << " attacked for: " << thief.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (thief.GetHp() <= 0) {
                cout << "Good job! You killed the " << thief.GetName()
                        << "continue on" << endl;
                player->SetExp(player->GetExp() + thief.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }
        cout << "After searching through several rooms " << player->GetName()
                << " encounters a " << guard.GetName() << "\n "
                << "Begin combat!" << endl;

        //Guard Fight
        while (player->GetHealth() >= 0 && guard.GetHp() >= 0);
        {
            string turn;

            //Variables of damage loop
            guard.GetDmg();
            player->GetDagger();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            //Determine
            if (turn == "attack" || turn == "Attack") {
                cout << "You Double Stab for: " << player->GetDagger() << endl;
                guard.SetHp(guard.GetHp() - player->GetDagger());
                cout << guard.GetName() << " has: " << guard.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - guard.GetDmg());
                cout << guard.GetName() << " attacked for: " << guard.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }

            if (guard.GetHp() <= 0) {
                cout << "Good job! You have slain the Guard" << endl;
                player->SetExp(player->GetExp() + guard.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }

            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        }
        cout << "After fighting the guard " << player->GetName() << " extracted the layout"
                << " of the hideout\n stealing anything of value on the way.\n"
                << "In the furthest back room, " << player->GetName() << "engages in combat"
                << " with the " << armor.GetName() << ".\n" << "Begin combat!" << endl;
        //Armor guard boss fight
        do {
            string turn;
            //Variables for damage loop
            armor.GetDmg();
            player->GetDagger();
            cout << "Choose your action! Attack | Potion " << endl;
            cin>>turn;

            if (turn == "attack" || turn == "Attack") {
                cout << "You Double Stab for: " << player->GetDagger() << endl;
                armor.SetHp(armor.GetHp() - player->GetDagger());
                cout << armor.GetName() << " has: " << armor.GetHp() << " left" << endl;
                player->SetHealth(player->GetHealth() - armor.GetDmg());
                cout << armor.GetName() << " attacked for: " << armor.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (turn == "potion" || turn == "Potion") {
                player->SetHealth(pot.hpot + player->GetHealth());
                cout << "You healed to : " << player->GetHealth() << " Health" << endl;
                player->SetHealth(player->GetHealth() - armor.GetDmg());
                cout << armor.GetName() << " attacked for: " << armor.GetDmg() << endl;
                cout << "You now have: " << player->GetHealth() << " Health" << endl;
            }
            if (armor.GetHp() <= 0) {
                cout << "Good job! You killed the Armored boss continue on" << endl;
                player->SetExp(player->GetExp() + armor.GetExp());
                myfile.open("PlayerStat.txt", ios::out | ios::binary);
                myfile.write(reinterpret_cast<char *> (player), sizeof (player));
                myfile.close();
            }
            if (player->GetHealth() <= 0) {
                cout << "You have Died!" << endl;
                return 0;
            }
        } while (player->GetHealth() >= 0 && armor.GetHp() >= 0);
        cout << "Finally after furiously fighting with the" << armor.GetName()
                << ", " << player->GetName()
                << "\n loots all that they can from the hideout and goes on their merry way."
                << endl;
        cout << "Congratulations: " << player->GetName() << ", you have beaten the Rogues story.\n"
                << "Restart game to try a new story or replay!" << endl;
        myfile.open("PlayerStat.txt", ios::out | ios::binary);
        myfile.write(reinterpret_cast<char *> (player), sizeof (player));
        myfile << player->GetExp();
        myfile.close(); //Close File
        delete[] player;
        return 0;
    }
    return 0;

}
