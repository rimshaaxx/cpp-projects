#include <iostream>
#include <random>
#include <windows.h>
#include <string>

int randNo();
void guess(int random_num);

int main() {

    int random_num = randNo();

    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[\x1b[38;2;243;58;106m" << "────୨ GUESS THE NUMBER ৎ────" << "\033[0m" << std::endl;

    std::string yn;
    std::cout << "Ready to start?" ;
    std::cin >> yn;

    if (yn == "Yes" || yn == "yes" || yn == "YES" || yn == "y") {
        std::cout << "\033[38;2;231;161;176m" << "Lessgooo!" << "\033[0m" << std::endl;
        guess(random_num);
    }
    else {
        std::cout << "\033[94m" << "Your choices don't matter anyways. Lessstart." << "\033[0m" << std::endl;
        guess(random_num);
    }


    return 0;
}

int randNo() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000);
    return dist(gen);
}

void guess(int random_num) {
    int uGuess, attempts = 1;
    std::cout << "Guess a number between 1 and 1000: ";
    std::cin >> uGuess;
    while ( uGuess != random_num) {
        if (uGuess < random_num) {
        std::cout << "Too Low!";
        }
        else if (uGuess > random_num) {
            std::cout << "Too High!";
        }
        std::cout << "\n Guess again: ";
        std::cin >> uGuess;
        attempts++;
    }
    
    if (uGuess == random_num) {
        std::cout << "\033[38;2;201;169;166m" << "Einstein Newton spotted! You Won! "
                  << "\033[0m" << "\n The number was: " 
                  << random_num << "\n You guessed the number in " 
                  << attempts << " attempts." << std::endl;
    }

}