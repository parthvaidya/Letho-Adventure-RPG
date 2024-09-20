#include "Character.h"
#include <cstdlib>
#include <iostream>

// Implementation of Player methods
Player::Player()
    : health(100), maxHealth(100), meleeDamage(10), rangedDamage(5), defence(5),
      hasSword(false), hasShield(false), hasArmour(false), hasBow(false),
      criticalHitUnlocked(false), blockerUnlocked(false),
      lifeStealUnlocked(false), rangedAttackUnlocked(false) {}

// player attacks
void Player::attack() {
  int damage = meleeDamage;

  // Check for special abilities
  if (criticalHitUnlocked && rand() % 100 < 10) {
    damage *= 2;
    std::cout << "Critical Hit Activated!" << std::endl;
  }

  std::cout << "You have attacked and  the enemy is dealing with " << damage
            << " damage!" << std::endl;
}

// player heals with 20 units of health
void Player::heal() {
  health = health + 20;
  if (health > maxHealth)
    health = maxHealth;
  std::cout << "You healed and earned 20 health points!" << std::endl;
}

// Player is levelled up
void Player::levelUp(int level) {
  maxHealth = maxHealth + 20;
  health = maxHealth;
  meleeDamage = meleeDamage + 5;
  defence = defence + 3;
  // level increment

  switch (level) {
  case 2:
    hasSword = true;
    criticalHitUnlocked = true;
    break;
  case 3:
    hasShield = true;
    blockerUnlocked = true;
    break;
  case 4:
    hasArmour = true;
    lifeStealUnlocked = true;
    break;
  case 5:
    hasBow = true;
    rangedAttackUnlocked = true;
    break;
  }
  std::cout
      << "Congratulations KalEl you Leveled Up! Great Going Stats increased!"
      << std::endl;
  std::cout
      << "Now on the enemies will increase and so does your abilities KalEl"
      << std::endl;
  std::cout << " " << std::endl;
}

// player gives damage

void Player::applyDamage(int damage) {
  if (blockerUnlocked && rand() % 100 < 10) {
    std::cout << "Blocker Activated! No damage taken!" << std::endl;
    return;
  }
  health = health - (damage - defence);
  if (health < 0)
    health = 0;
  std::cout << "You received " << damage << " damage!" << std::endl;
}

// check if player is alive or dead
bool Player::isAlive() const { return health > 0; }

// display player current statistics
void Player::displayStats() const {
  std::cout << " " << std::endl;
  std::cout << "The stats for KalEL are " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "CurrentHealth: " << health << "/" << maxHealth << std::endl;
  std::cout << "Melee Damage: " << meleeDamage << std::endl;
  std::cout << "Defence: " << defence << std::endl;
  std::cout << (hasSword ? "Sword Equipped" : "No Sword") << std::endl;
  std::cout << (hasShield ? "Shield Equipped" : "No Shield") << std::endl;
  std::cout << (hasArmour ? "Armour Equipped" : "No Armour") << std::endl;
  std::cout << (hasBow ? "Bow Equipped" : "No Bow") << std::endl;
}

int Player::getMeleeDamage() const {
  return meleeDamage; // meledamage
}

// Implementation of Enemy methods
Enemy::Enemy(int level)
    : health(50 + level * 10), maxHealth(50 + level * 10),
      damage(10 + level * 2), defence(3 + level * 1) {}

void Enemy::attack(Player &player) {
  std::cout << "Enemy attacks!" << std::endl;
  player.applyDamage(damage);
}

void Enemy::applyDamage(int damage) {
  health = health - (damage - defence);
  if (health < 0)
    health = 0;
}

bool Enemy::isAlive() const { return health > 0; }

void Enemy::displayStats() const {

  std::cout << " " << std::endl;
  std::cout << "The enemy stats are as follows: " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "Enemy Health: " << health << "/" << maxHealth << std::endl;
  std::cout << "Enemy Damage: " << damage << std::endl;
  std::cout << "Enemy Defence: " << defence << std::endl;
  std::cout << " " << std::endl;
}
