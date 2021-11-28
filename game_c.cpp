#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "game_c.h"

using namespace std;



   Game:: Game(){
        highscores_in_game=new string[3];// Intialize the array that holds Highscore scored in game
        Playername_with_high_score=new string [3];// Intialize the array that holds Username of the Highscore Acheivers
        Level=1;// Intialize the Level to 1
        meun_reference=0;// Menu referenece 0 means that it is on the main screen of GUI
        music_name="";// Music Name is Intialized to Empty for now
        music_status=true;// Music is on
    }
    void Game::set_meun_reference(int num){
        meun_reference=num;// To set Menu to num
    }
    int Game::get_meun_reference(){
        return meun_reference;// To get Menu_refernece
    }
    bool Game::get_music_status(){
        return music_status;// To get music status
    }
    void Game::set_music_status(bool i){
        music_status=i;// To set music status
    }
    int Game::get_Level(){
        return Level;// To get Level at which player is
    }
    void Game::set_Level(int n){
        Level=n;// To set Level
    }
    string Game::get_highscorers(int i){
        return highscores_in_game[i];// To get highscore at i position
    }
    string Game::get_Playernames(int i){
        return Playername_with_high_score[i];// To get Payername at i position
    }
