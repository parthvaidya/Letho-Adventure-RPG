#include "Enemy.h"
#include <iostream>

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