#ifndef game_c_h
#define game_c_h

#include <iostream>

using namespace std;

class Game{
protected:
    bool reset=false;// A Variable bool to  Store Status of Reset to Play Game from Zero Again Resets Everything
    int meun_reference;// Stores at which menu the current GUI is
    string music_name;// Variable to Store Music Name
    bool music_status;// Variable to Store Music is either On or Off
    int Level;// Stores the Level at which player is Playing
    string *highscores_in_game; // Array to Get Scores of Players having Highsscores
    string *Playername_with_high_score;// Array to Get Names of Players having Highsscores
public:
    Game(); // A Default Constructor
    void set_meun_reference(int num); //Function to Set the Menu Referenece
    int get_meun_reference();//Function to Gets the menu Reference
    bool get_music_status();//Function to Gets the Status of Music On or Off
    void set_music_status(bool i);//Function to set the Status of Music
    int get_Level();//Function to get the Level of Player Playing at
    void set_Level(int n=1);//Function to set the Level
    string get_highscorers(int i=0);//Function to get Highscores from File
    string get_Playernames(int i=0);//Function to get Player Name from File 
};


#endif /* game_c_h */

