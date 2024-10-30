#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <limits>

class RouletteGame {
private:
    static const std::array<int, 18> BLACK_NUMBERS;
    int chips;
    
    int spinRoulette() const {
        return rand() % 37;
    }
    
    std::string getColor(int number) const {
        if (number == 0) return "green";
        for (int blackNum : BLACK_NUMBERS) {
            if (blackNum == number) return "black";
        }
        return "red";
    }
    
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    int getBetAmount() {
        int betAmount;
        while (true) {
            std::cout << "\nYour current chips: " << chips << "\nEnter your bet amount: ";
            if (std::cin >> betAmount && betAmount > 0 && betAmount <= chips) {
                return betAmount;
            }
            std::cout << "Invalid bet amount. Please enter a number between 1 and " << chips << "\n";
            clearInputBuffer();
        }
    }
    
    int getBetChoice() {
        int choice;
        while (true) {
            std::cout << "\nChoose your bet type:\n"
                      << "1. Bet on Red\n"
                      << "2. Bet on Black\n"
                      << "3. Bet on a specific number (0-36)\n"
                      << "Enter your choice (1-3): ";
            
            if (std::cin >> choice && choice >= 1 && choice <= 3) {
                return choice;
            }
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            clearInputBuffer();
        }
    }
    
    int getChosenNumber() {
        int number;
        while (true) {
            std::cout << "Enter your chosen number (0-36): ";
            if (std::cin >> number && number >= 0 && number <= 36) {
                return number;
            }
            std::cout << "Invalid number. Please enter a number between 0 and 36.\n";
            clearInputBuffer();
        }
    }
    
    bool playAgainPrompt() {
        char response;
        while (true) {
            std::cout << "Do you want to play again? (y/n): ";
            if (std::cin >> response) {
                response = tolower(response);
                if (response == 'y' || response == 'n') {
                    return response == 'y';
                }
            }
            std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
            clearInputBuffer();
        }
    }

public:
    RouletteGame() : chips(100) {
        srand(static_cast<unsigned>(time(0)));
    }
    
    void play() {
        std::cout << "Welcome to the Casino Roulette!\n"
                  << "You start with " << chips << " chips.\n";
        
        while (chips > 0) {
            int betAmount = getBetAmount();
            int choice = getBetChoice();
            
            int chosenNumber = (choice == 3) ? getChosenNumber() : -1;
            int rouletteResult = spinRoulette();
            std::string resultColor = getColor(rouletteResult);
            
            std::cout << "\nRoulette spun... Result: " << rouletteResult 
                      << " (" << resultColor << ")\n";
            
            if ((choice == 1 && resultColor == "red") || 
                (choice == 2 && resultColor == "black")) {
                chips += betAmount;
                std::cout << "You win! You doubled your bet.\n";
            } else if (choice == 3 && chosenNumber == rouletteResult) {
                chips += betAmount * 35;
                std::cout << "Exact match! You win 35 times your bet!\n";
            } else {
                chips -= betAmount;
                std::cout << "You lose.\n";
            }
            
            if (chips <= 0) {
                std::cout << "You ran out of chips! Game over.\n";
                break;
            }
            
            if (!playAgainPrompt()) break;
        }
        
        std::cout << "Thank you for playing! Your final chip count: " << chips << "\n";
    }
};

const std::array<int, 18> RouletteGame::BLACK_NUMBERS = {
    2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35
};

int main() {
    RouletteGame game;
    game.play();
    return 0;
}
