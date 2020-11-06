#ifndef HANGMAN_H
#define HANGMAN_H
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cassert>
#include<string>

using namespace std;
namespace hangmanSpace
{
    enum
    {
        GAME_OVER,
        SUCCESS,
        CONTINUE,
    };

    const string ARRAY_OF_WORDS[]= {
     "going", "look", "darling", "fearless", "kindess", 
     "questoins", "awesome", "friend", "little", "charming", 
     "gentle", "happy", "moment", "kind", "patient", 
     "silly", "spontaneous", "change", "unique", "best", 
     "believe", "laugh", "blessed", "breath", "care", 
     "joy", "someone", "collect", "blessing", "linda",
     "massa", "siyabonga", "muzi", "yante", "violet", 
     "ndudu", "thabiso", "momcebo", "given", "gift", 
     "time", "faith", "free", "thanks", "hard", 
     "dream", "promise", "loud", "go", "touch",
     "give", "well", "love", "wish", "decisions", 
     "peace", "good", "beauty", "respect", "goals", 
     "smile", "humble", "strong", "listen", "risk", 
     "big", "star", "amazing", "fabulous", "brave",
     "play", "relax", "secrete", "rise", "hope", 
     "work", "up", "seek", "stress", "new", 
    };

    class Hangman
    {
       private:
        int intLength;
        int intLife;
        char* charArray;
        string strRandomWorld;
        char charAlphabet;
        int intRow;
        
       public:
        Hangman(int intNumber);                  ///constructor
        void display();
        int getLength() const;
        string getRandomWord() const;
        int won(); /// this will check if the game is over or not
        int getLife() const;
        char getCharArrray(int intIndex) const;
    };
    int randomNumber(int intLB, int intUB); 
    char isValideChar(char& charIn ,Hangman hangman);
}
#endif