#ifndef BATTLE_H
#define BATTLE_H

#include "Enemy.h"
#include "Player.h"
void murlocAttack(Player &player);
void battle(Player &player, Enemy &enemy, bool isMurloc = false);

#endif