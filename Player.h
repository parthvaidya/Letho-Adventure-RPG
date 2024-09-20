#ifndef PLAYER_H
#define PLAYER_H

// initialize class player with all the attributes
class Player {
private:
  int health;
  int maxHealth;
  int meleeDamage;
  int rangedDamage;
  int defence;
  bool hasSword;
  bool hasShield;
  bool hasArmour;
  bool hasBow;
  bool criticalHitUnlocked;
  bool blockerUnlocked;
  bool lifeStealUnlocked;
  bool rangedAttackUnlocked;

public:
  Player();
  void attack();
  void heal();
  void levelUp(int level);
  void applyDamage(int damage);
  bool isAlive() const;
  void displayStats() const;
  int getMeleeDamage() const;
};


#endif