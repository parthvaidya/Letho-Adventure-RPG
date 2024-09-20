#include "Player.h"
#include "Battle.h"
#include "Enemy.h"
#include <cstdlib>
#include <iostream>

void murlocAttack(Player &player) {
  int damage = 20;                  // Set base damage for Murloc
  int abilityChance = rand() % 100; // Generate a number between 0 and 99
  std::cout << "Murlocs is gonna attack you KalEl" << std::endl;

  if (abilityChance < 20) {
    // 20% chance to use Ground Slash
    int groundSlashDamage = damage * 2;
    std::cout << " " << std::endl;
    std::cout << "Murloc uses Ground Slash! It deals " << groundSlashDamage
              << " damage!" << std::endl;
    player.applyDamage(groundSlashDamage);
  } else if (abilityChance >= 20 && abilityChance < 40) {
    // 20% chance to use Speed Dash (2 attacks)
    std::cout << " " << std::endl;
    std::cout << "Murloc uses Speed Dash! It attacks twice!" << std::endl;
    player.applyDamage(damage);
    player.applyDamage(damage);
  } else {
    // 60% chance for a normal attack
    player.applyDamage(damage);
    std::cout << " " << std::endl;
    std::cout << "Murloc deals " << damage << " damage!" << std::endl;
  }
}

// battle loop where player and enemy plays
void battle(Player &player, Enemy &enemy, bool isMurloc) {
  while (player.isAlive() && enemy.isAlive()) {
    char choice;
    int attempts = 0;
    const int maxAttempts =
        3; // max attempts to attack and heal for invalid inputs

    while (attempts < maxAttempts) {
      std::cout << "Choose your action KalEl and remember to choose wisely "
                   ":\nA/a. Attack\nH/h. Heal\n";
      std::cin >> choice;

      if (choice == 'A' || choice == 'a') {
        player.attack();
        enemy.applyDamage(player.getMeleeDamage());
        break;
      } else if (choice == 'H' || choice == 'h') {
        player.heal();
        break;
      } else {
        attempts++;
        std::cout << "Invalid choice! Attempts remaining: "
                  << (maxAttempts - attempts) << std::endl;
        if (attempts >= maxAttempts) {
          std::cout << "Too many invalid attempts.You did not obey the rules. "
                       "Exiting game."
                    << std::endl;
          exit(1);
        }
      }
    }

    if (enemy.isAlive()) {
      if (isMurloc) {
        // Special Murloc attack logic
        murlocAttack(player);
      } else {
        // Regular enemy attack logic
        enemy.attack(player);
      }
    }

    player.displayStats();
    enemy.displayStats();
  }
}