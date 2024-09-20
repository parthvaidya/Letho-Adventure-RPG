#include "Player.h"
#include "Battle.h"
#include "Enemy.h"
#include <cstdlib>
#include <iostream>



int main() {

  srand(time(0));
  Player player;
  std::cout
      << "Welcome to the RPG Adventure Game! Your adventure is about to begins!"
      << std::endl;
  std::cout << "Your name is KAL EL. You reside in a small house in krypton"
            << std::endl;
  std::cout << "You are a brave warror of krypton Village and this is the "
               "quest to defeat the mighty MURLOC!!!!!"
            << std::endl;
  std::cout << "You need to cross levels where your abilities increase as the "
               "level increases. So brace yourself my friend the journey is "
               "gonna be next level"
            << std::endl;
  std::cout << "" << std::endl;

  char choice;
  int attempts = 0;
  const int maxAttempts = 5;

  // Input loop for the initial choice with attempts limit
  while (attempts < maxAttempts) {
    std::cout << "Press S to start the game or E to exit: ";
    std::cin >> choice;

    if (choice == 'S' || choice == 's') {
      for (int level = 1; level <= 6; ++level) {
        std::cout << "\n--- Welcome to Level " << level << " ---" << std::endl;
        int numEnemies = level;

        for (int i = 0; i < numEnemies; ++i) {
          std::cout << "\n--- Enemy " << i + 1 << " just spawned!  ---"
                    << std::endl;
          Enemy enemy(level);
          battle(player, enemy);

          if (!player.isAlive()) {
            std::cout << "Game Over! You were defeated!" << std::endl;
            return 0;
          }
        }

        player.levelUp(level);
      }

      std::cout << "\n--- Boss Fight! Embrace the Wrath of mighty Murloc ---"
                << std::endl;
      std::cout << "\n---HAAAHAHAHAHAHAHAHAHAHA you are so dead KalEl! ---"
                << std::endl;
      std::cout << " " << std::endl;
      Enemy murloc(6);
      battle(player, murloc, true);

      if (player.isAlive()) {
        std::cout << "Congratulations! You have defeated Murlocs and saved "
                     "your village!"
                  << std::endl;
      } else {
        std::cout << "You were defeated by Murlocs. The village remains under "
                     "his control."
                  << std::endl;
      }

    } else if (choice == 'E' || choice == 'e') {
      std::cout << "Exiting the game. Goodbye KalEl see you soon!\n";
      exit(1);
    } else {
      attempts++;
      std::cout << "Invalid input. Please enter 'S' to start or 'E' to exit."
                << std::endl;

      // Check if max attempts have been reached
      if (attempts >= maxAttempts) {
        std::cout
            << " Invalid attempts have exahusted .You did not obey rules. "
               "Exiting the game.\n";
      }
      exit(1);
    }

    return 0;
  }
}