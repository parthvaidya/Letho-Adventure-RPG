#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
// initialize class enemy
class Enemy {
protected:
  int health;
  int maxHealth;
  int damage;
  int defence;

public:
  Enemy(int level);
  virtual void attack(Player &player);
  void applyDamage(int damage);
  bool isAlive() const;
  void displayStats() const;
};

// Derived Murloc class with special abilities
class Murloc : public Enemy {
private:
  bool groundSlashUnlocked;
  bool speedDashUnlocked;

public:
  Murloc(int level);
  void attack(Player &player) override;
};

#endif