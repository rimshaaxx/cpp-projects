#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

const int WIDTH = 50;
const int HEIGHT = 14;

std::vector<std::string> grid(HEIGHT, std::string(WIDTH, ' '));
std::map<char, std::pair<int, int>> pos;

void placeText(std::string text, int row, int startCol, int spacing, bool addToMap = true);
void renderBoard();
void spellWord(std::string word);
void highlightWord(std::string text, int row, int startCol, int spacing);
std::string getRandomAnswer();

int main() {
    srand(time(0));

    placeText("YES", 1, 2, 2, false);
    placeText("NO", 1, 45, 2, false);
    placeText("ABCDEFGHIJKLM", 4, 6, 3, true);
    placeText("NOPQRSTUVWXYZ", 6, 6, 3, true);
    placeText("1234567890", 9, 10, 3, true);
    placeText("GOODBYE", 12, 17, 2, false);


    renderBoard();

    std::string userQuestion;
    while (true) {
        // Move to row 19/20, then use \033[K to erase anything currently on that line
        std::cout << "\033[19;1H\033[K"; 
        std::cout << "\033[20;1H\033[K";

        std::cout << "\033[19;1HQuestion: ";
        std::cout << "\033[?25h" << std::flush; //show cursor
        std::getline(std::cin, userQuestion);

        std::cout << "\033[?25l" << std::flush; //hide cursor now

        std::cout << "\033[20;1HAnswer: " << std::flush;

        if (userQuestion == "GOODBYE") {
            highlightWord("GOODBYE", 12, 17, 2);
            break;
        }
        
        std::string answer = getRandomAnswer();

        if (answer == "YES") {
            highlightWord("YES", 1, 2, 2);
        } 
        else if (answer == "NO") {
            highlightWord("NO", 1, 45, 2);
        } 
        else {
            spellWord(answer);
        }
    }
    std::cout << "\033[?25h\033[22;1H"; //cursor on again before program ends
    return 0;

}

void placeText(std::string text, int row, int startCol, int spacing, bool addToMap) {
    int col = startCol;
    for (char c : text) {
        if (c == ' ') {
            col += spacing;
            continue;
        }
        grid[row][col] = c;

        if (addToMap) {
            pos[c] = {row, col};
        }
        col += spacing;

    }
}

void renderBoard() {
    std::cout << "+" << std::string(WIDTH, '-') << "+" << std::endl;

    for (int i=0 ; i < HEIGHT ; i++) {
        std::cout << "|" << grid[i] << "|" << std::endl;
    }

    std::cout << "+" << std::string(WIDTH, '-') << "+" << std::endl;
}

void spellWord(std::string word) {
    int answerCol = 10;

    for (char letter : word) {

        if (letter == ' ') {
            std::cout << "\033[20;" << answerCol << "H " << std::flush;
            answerCol++;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            continue;
        }

        if (pos.find(letter) == pos.end()) continue;

        int row = pos[letter].first;
        int col = pos[letter].second;

        int terminalRow = row + 3;
        int terminalCol = col + 2;

        std::cout << "\033[" << terminalRow << ";" << terminalCol << "H" << "\033[31m" << letter << "\033[0m";
        std::cout << "\033[20;" << answerCol << "H" << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        std::cout << "\033[" << terminalRow << ";" << terminalCol << "H" << letter;
        answerCol++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void highlightWord(std::string text, int row, int startCol, int spacing) {
    std::cout << "\033[20;10H" << text << std::flush;

    int col = startCol;
    for (char c : text) {
        int termRow = row + 3;
        int termCol = col + 2;
        std::cout << "\033[" << termRow << ";" << termCol << "H" << "\033[31m" << c << "\033[0m" ;
        col += spacing;
    }
    std::cout << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    col = startCol;
    for (char c : text) {
        int termRow = row + 3;
        int termCol = col + 2;
        std::cout << "\033[" << termRow << ";" << termCol << "H" << c;
        col += spacing;
    }
    std::cout << std::flush;
}

std::string getRandomAnswer() {
    std::vector<std::string> answers = {
        "YES",
        "NO",
        "SKILL ISSUE",
        "WOMP WOMP",
        "TRY AGAIN",
        "NUH UH",
        "MAYBE",
        "NEVER",
        "WHO KNOWS",
        "ASK NICELY",
        "SAY MOMMY",
        "WRONG",
        "TOO LATE",
        "GOOD LUCK",
        "MISS ME",
        "NO ONE LOVES YOU",
        "UNLUCKY",
        "DONT LIE"
        "GO TOUCH GRASS",
        "404 ANSWER NOT FOUND",
        "YOU THOUGHT HUH",
        "NICE TRY BUDDY",
        "THAT AIN'T HAPPENING",
        "KEEP DREAMING",
        "TRY HARDER NEXT TIME",
        "YOUR LUCK RAN AWAY",
        "THE GHOST IS LAUGHING",
        "THATS WHY YOU ARE SINGLE",
        "BRO IS DELUSIONAL",
        "ASK AGAIN AFTER CRYING",
        "YOU ARE EMBARRASSING",
        "YOU HAD ONE JOB",
        "BETTER LUCK NEVER",
        "THAT'S A CERTIFIED SKILL ISSUE",
        "YOU FUMBLED SO HARD",
        "NOT EVEN CLOSE",
        "YOU'RE COOKED",
        "CONGRATS YOU FAILED",
        "YOU SCARED THE GHOST AWAY",
        "COME BACK WHEN YOU LEVEL UP",
        "THAT'S WHY YOU'RE SINGLE",
        "YOUR EX WAS RIGHT",
        "YOU ARE EWWW",
        "EVEN FAILURE FEELS BAD FOR YOU",
        "DON'T TURN AROUND",
        "I KNOWS YOUR NAME",
        "THE DOOR WASN'T OPEN BEFORE",
        "LOOK IN THE MIRROR",
        "I'M STANDING RIGHT BEHIND YOU",
        "THE LIGHTS WILL FLICKER SOON",
        "I CAN SEE YOU",
        "YOU SHOULDN'T HAVE ASKED THAT",
        "I'LL WATCHING YOU SLEEP",
        "EVEN A GHOST WONT CHOOSE YOU",
        "I'M NOT TALKING TO YOU."
    };
    int randomIndex = rand() % answers.size();
    return answers[randomIndex];
}