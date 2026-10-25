#include <iostream>
#include <random>
#include <windows.h>
#include <string>

int randNo();
int displayMenu();
void guess1(int random_num);
void guess2();

int main() {
    std::string re_play;

    do {
        int mode = displayMenu();
        if (mode == 1) {
            int random_num = randNo();

            std::string yn;
            std::cout << "Ready to start?" ;
            std::cin >> yn;

            if (yn == "Yes" || yn == "yes" || yn == "YES" || yn == "y") {
                std::cout << "\033[38;2;231;161;176m" << "Lessgooo!" << "\033[0m" << std::endl;
                guess1(random_num);
            }
            else {
                std::cout << "\033[94m" << "Your choices don't matter anyways. Lessstart." << "\033[0m" << std::endl;
                guess1(random_num);
            }
        }

        else if (mode == 2) {
            guess2();
        }
        
        else {
            std::cout << "Invalid choice." << std::endl;
        }

        std::cout << "Do you want to play again? ";
        std::cin >> re_play;

    } while ( re_play == "YES" || re_play == "yes" || re_play == "Yes" || re_play == "y" );

    std::cout << "\033[38;2;243;58;106m" << "Thanks for playing! \n You owe"
              << "\033[1;38;2;243;58;106m" << " rose" 
              << "\033[0;38;2;243;58;106m" << " $10 now." 
              << "\033[0m" << std::endl;



    return 0;
}

int displayMenu() {
    int choice;

    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\033[1;38;2;243;58;106m" << "────୨ GUESS THE NUMBER ৎ────" << "\033[0m" << std::endl;

    std::cout << "1. I choose a number, you guess. \n";
    std::cout << "2. You choose a number and I'll guess. \n";
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;

    return choice;
}

int randNo() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000);
    return dist(gen);
}

void guess1(int random_num) {
    int uGuess, attempts = 1;
    std::cout << "Guess a number between 1 and 1000: ";
    std::cin >> uGuess;
    while ( uGuess != random_num) {
        if (uGuess < random_num) {
        std::cout << "\033[1;38;2;255;255;255;48;5;0m" << "Too Low!";
        }
        else if (uGuess > random_num) {
            std::cout << "\033[1;38;2;255;255;255;48;5;0m" << "Too High!";
        }
        std::cout << "\033[0m" << "\n Guess again: ";
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

void guess2() {
    std::string start, input, myGuess;
    std::cout << "Think of a number between 1 and 1000. \nReady? ";
    std::cin >> start;

    std::cout << "\nNice. So whats the number?\n ";
    std::cin >> input;
    std::cout << "\n\nJus kidding. Hehe. I will guess myself. \nTell me if my guess is HIGH, LOW or CORRECT. \n"
              << "\033[2;39;49m" << "I would appreciate if you type jus tht and no other nonsense. Thankew.\n"
              << "\033[0m" ;

    int low =1, high = 1000, guess;

    while (low <= high) {
        guess = low + (high - low) / 2;
        std::cout << "Is it " << guess << "?\n";
        std::cin >> myGuess;

        if (myGuess == "CORRECT") {
            std::cout << "I am a masterpiece. 200IQ.\n"; break;
        }
        else if (myGuess == "HIGH") {
            high = guess - 1;
        }
        else if (myGuess == "LOW") {
            low = guess + 1;
        }
        else {
            std::cout << "Invalid input. Please type HIGH, LOW or CORRECT." << std::endl;
        }
    }
    if (low > high) {
        std::cout << "\n\nYou are a cheater dumbass.\n";
    }

}