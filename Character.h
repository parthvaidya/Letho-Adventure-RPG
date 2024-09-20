#ifndef CHARACTER_H
#define CHARACTER_H

// initialize class player with attributes
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
