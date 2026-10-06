#include <cstdlib>
#include <ctime>
#include "zyannkenn2.cpp.h"

int main() 
{
    
    srand(static_cast<unsigned int>(time(nullptr)));

   
    string name = "nanashi";

    
    array<int, 3> results = { 0, 0, 0 };
    int round = 1;

    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Welcome, " << name << "! Let's start Janken (Rock-Paper-Scissors)!\n";
    cout << "First to 3 wins is the victor.\n";
    cout << "-----------------------------------------\n";

    
    while (results[static_cast<int>(Result::Win)] < 3 && results[static_cast<int>(Result::Lose)] < 3) 
    {
        cout << "\n[Round " << round << "]\n";
        cout << "Choose your hand (0: Rock, 1: Scissors, 2: Paper): ";

        int inputHand = 0;
        cin >> inputHand;

       
        if (inputHand < 0 || inputHand > 2)
        {
            cout << "Invalid choice. Please choose 0, 1, or 2.\n";
            continue;
        }

       
        const Hand playerHand = static_cast<Hand>(inputHand);
        
        const Hand cpuHand = static_cast<Hand>(rand() % 3);

       
        cout << name << ": " << JankenManager::getHandName(playerHand) << "\n";
        cout << "CPU: " << JankenManager::getHandName(cpuHand) << "\n";

        
        const Result gameResult = JankenManager::judge(playerHand, cpuHand);

        
        if (gameResult == Result::Win) 
        {
            cout << "Result: You WIN this round!\n";
            results[static_cast<int>(Result::Win)]++;
            round++;
        }
        else if (gameResult == Result::Lose) 
        {
            cout << "Result: You LOSE this round!\n";
            results[static_cast<int>(Result::Lose)]++;
            round++;
        }
        else 
        {
            cout << "Result: DRAW!\n";
            results[static_cast<int>(Result::Draw)]++;
           
        }

        
        cout << "Current Score -> Wins: " << results[static_cast<int>(Result::Win)]
            << ", Losses: " << results[static_cast<int>(Result::Lose)]
            << ", Draws: " << results[static_cast<int>(Result::Draw)] << "\n";
        cout << "-----------------------------------------\n";
    }

    
    cout << "\n=========================================\n";
    cout << "GAME OVER\n";
    cout << "=========================================\n";

    if (results[static_cast<int>(Result::Win)] == 3) 
    {
        cout << "Congratulations, " << name << "! You won the game!\n";
    }
    else 
    {
        cout << "Too bad, " << name << "! CPU won the game!\n";
    }

    
    cout << "Final Record: " << results[static_cast<int>(Result::Win)] << " Win(s), "
        << results[static_cast<int>(Result::Lose)] << " Loss(es), "
        << results[static_cast<int>(Result::Draw)] << " Draw(s)\n";
    cout << "=========================================\n";

    return 0;
}