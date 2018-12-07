#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{

    const int MAX_WRONG = 8;

    vector<string> words;
    words.push_back("PIZZA");
    words.push_back("BACON");
    words.push_back("COMPLICATED");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";

    cout << "\t\t\tWelcome to Hangman!";
    cout<<"\n\t\t\t-------------------\n\n";
    cout<<"You have exactly " <<(MAX_WRONG - wrong)<< " guesses, goodluck!";


    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "So far, the word is: " << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); //make uppercase since secret word in uppercase

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            ++wrong;
            cout << "Sorry, " << guess << " isn't in the word.\n";
            cout<<"You have " <<(MAX_WRONG - wrong)<< " guesses left.\n";

        }
    }
    if (wrong == MAX_WRONG)
    {
        cout << "Game over, you've been hanged!";

    }
    else
    {
        cout << "Congratulation! You've successfully guessed the secret word!";
    }

    //This is a little something i like to do at the end of my games ;)
    cout << "\nThe word was " << THE_WORD<<"\n\n";
    int rate;
    cout<<"Please take a moment of your time and rate the game\n";
    cout<<"1 - It was fun!\n";
    cout<<"2 - It was ok\n";
    cout<<"3 - It was bad\n";
    cin>>rate;
    switch (rate)
    {
    case 1:
        cout<<"We are so glad to hear that! thanks for the positive feedback!\n";
        break;
    case 2:
        cout<<"We'll do better next time, thanks for your feedback!\n";
        break;
    case 3:
        cout<<"We are terribly sorry about that, we'll do better next time\n";
        break;
    default:
        cout<<"Good-bye\n";
        break;
    }
    system("pause");
    return 0;
}
