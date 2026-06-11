#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void playgame()
{
    int r_number = 0;
    int guess = 0;
    int attempts = 7;
    int lowest = 0;
    int highest = 0;
    char letter;


    cout << "Guess the random number GAME " << endl;

    cout << "Choose the lowest number possible: ";
    cin >> lowest;
    cout << "\nChoose the highest number possible: ";
    cin >> highest;

    r_number = random_number(lowest, highest);

    cout << "\nYou only have 7 attempts. Good luck " << endl;

    cout << "Guess the random number: ";

    for (int i = 1; i <= 7; i++)
    {
        cin >> guess;

        if (guess < r_number && attempts > 0)
        {
            attempts--;
            cout << "\nYou now have " << attempts << " attempts" << endl;
            cout << "\nThe random_number is higher then that, try again: ";
        }
        else if (guess > r_number && attempts > 0)
        {
            attempts--;
            cout << "\nYou now have " << attempts << " attempts" << endl;
            cout << "\nThe random_number is lower then that, try again: ";
        }
        else
        {
            cout << "\nCONGRATS, you found the random_number!" << endl;
            cout << "With " << 8 - attempts << " attempts.";
            if (attempts > 5)
            {
                cout << " What a pro!" << endl;
            }
            else if (attempts > 1)
            {
                cout << " Not bad!" << endl;
            }
            else
            {
                cout << " Lucky lucky!" << endl;
            }
            break;
        }
        if (attempts == 0)
        {
            cout << "Game over, nice try" << endl;
        }
    }
    cout << "Do you want to play again? (Y/N): ";
    cin >> letter;

    if (letter == 'Y') {
        system("cls");
        playgame();
    }
    else
        return;
    
}

int main()
{
    // Initialize random seed
    srand(unsigned(time(nullptr)));

    playgame();    

    return 0;
}