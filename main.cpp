/*
    TO DO
    you must make sure the user only enters small letter between a-z
    You must add hits
    you must fix isValidchar fuction
*/
#include "hangman.h"

using namespace hangmanSpace;

int main(int argc, char const *argv[])
{

    bool blnContinue = true;
    int intWin = -1;

    srand(time(0));
    int intRandomMunber = randomNumber(0,79);
    Hangman* hangman = new Hangman(intRandomMunber);

    do
    {
        system("clear");
        hangman->display();
        intWin = hangman->won();
         
        if(intWin == SUCCESS || intWin == GAME_OVER)
        {
            char charIn = '\0';

            system("clear");
            cout <<"\n\n\t\t\t\tThe correct word is " << endl << endl << endl;
            cout << "\t\t\t\t ";
            for(int i = 0; i < hangman->getLength(); i++)
            {
                cout << hangman->getCharArrray(i) <<".";
            }
            cout << endl;
            if(SUCCESS)
            {
                cout <<"\n\n\t\t\t\tYou have won!!!! " << endl; 
            }
            else
            {
                cout <<"\n\n\t\t\t\tGame Over!!" << endl; 
            }
            cout <<"\n\n\t\t\t\tDo you want to play again? (Y/n): ";

            //cin.ignore(100,'\n');
            cin >> charIn;
            //charIn = isValideChar(charIn, hangman);
            if(charIn == 'Y' || charIn == 'y')
            {
                intRandomMunber = randomNumber(0,79);
                delete hangman;
                hangman = nullptr;
                hangman =  new Hangman(intRandomMunber); 
            }
            else if(charIn == 'N' || charIn == 'n')
            {
                cout <<"\n\n\t\t\t\tThank You For Playing" << endl;
                blnContinue = !blnContinue;
            }
        }

    }while(blnContinue);

    delete hangman; 
    return 0;
}
