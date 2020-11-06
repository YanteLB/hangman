#include "hangman.h"

namespace hangmanSpace
{
    
    Hangman::Hangman(int intNumber)
    {
        strRandomWorld = ARRAY_OF_WORDS[intNumber];
        intLength = strRandomWorld.length();
        intLife = intLength;
        charAlphabet ='\0';

        charArray = new char[intLength];
        for(int i = 0; i < intLength; i++)
        {
            charArray[i] = '*';
        }

    }

    int Hangman::getLife() const
    {
        return intLife; 
    }

    char Hangman::getCharArrray(int intIndex) const
    {
        return charArray[intIndex];
    }

    char isValideChar(char& charIn,Hangman hangman)
    {
        while(!(charIn == 'y') || !(charIn =='Y')
            || !(charIn == 'N') || !(charIn == 'n'))
            {
                cout << charIn << endl;
                //system("clear");
                cout <<"\n\n\t\t\t\tGuess the word below " << endl << endl << endl;
                cout << "\t\t\t\t ";
                for(int i = 0; i < hangman.getLength(); i++)
                {
                    cout << hangman.getCharArrray(i)<<".";
                }
                //cin.ignore(100, '\n');
                cout <<"\n\n\t\t\t\tEnter a valid charactor: "; 
                cin >> charIn;
            }
        return charIn;
    }

    void Hangman::display()
    {
        cout <<"\n\n\t\t\t\tGuess the word below " << endl << endl << endl;
        cout << "\t\t\t\t ";
        for(int i = 0; i < intLength; i++)
        {
            cout << charArray[i] <<".";
        }
        cout << endl;
        cout <<"\n\n\t\t\t\tRemaining life: " << getLife() << endl; 
        cout <<"\n\n\t\t\t\tEnter your alphabet: ";
        //cin.ignore(100, '\n');
        //cin >> charAlphabet; 
        cin.get(charAlphabet);

    }

    int Hangman::getLength() const
    {
        return intLength;
    }
    string Hangman::getRandomWord() const
    {
        return strRandomWorld;
    }
    
    int Hangman::won()
    {
        int intCounterBF = 0;
        int intCounterAF = 0;

        if(charAlphabet == '1')
        {
            system("clear");
            cout <<"\n\n\t\t\t\tGuess the word below " << endl << endl << endl;
            cout << "\t\t\t\t ";
            for(int i = 0; i < getLength(); i++)
            {
                cout << ARRAY_OF_WORDS[i] <<".";
            }
            cout <<"\n\n\t\t\t\t Thank you for Playing " << getLife() << endl; 
            exit(EXIT_FAILURE);
        }

        for(int i = 0 ; i < getLength(); i++)
        {
            if('*' == charArray[i])
            {
                intCounterBF++;
            }
        }
       
        for(int i = 0; i < getLength(); i++)
        {
            if(charAlphabet == strRandomWorld[i])
            {
               charArray[i] = charAlphabet;
            }
        }

        for(int i = 0 ; i < getLength(); i++)
        {
            if('*' == charArray[i])
            {
               intCounterAF++;
            }
        }

        if(intCounterBF == intCounterAF)
        {
           intLife--;
        }
        else
        {
            intLife = intLife + 2;
        }
        
        if(intCounterAF == 0 && intLife !=0)
        {
            return SUCCESS;
        }

        else if(intLife == 0)
        {
            return GAME_OVER;
        }

        else
        {
            return CONTINUE;
        }
    } 

    
    int randomNumber(int intLB, int intUB)
    {
        int intRange = intUB - intLB + 1;
        return rand()% intRange + intLB;
    }
}