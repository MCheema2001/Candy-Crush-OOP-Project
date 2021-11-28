#ifndef grid_h
#define grid_h

#include <iostream>
#include "gem.h"
#include "player.h"
#include "game_c.h"

using namespace std;

class Grid_and_Game_Function: public Player,  public Gem, public Game{
private:
    Gem **a;// Variable for 2d array of Gem Class
    int size_of_Grid;// to store size of grid
    int *first_coo;// first coo to swap gem
    int *sec_coo;// second gem to swap
public:
    void set_first_coo(int x,int y);// Function to set Swap coordinates of First gem
    void set_sec_coo(int x,int y);// Function to set Swap coordinates of Second gem
    int * get_first_coo();// Function to get Swap coordinates of First gem
    int * get_sec_coo();// Function to get Swap coordinates of Second gem
    void Display();// Function to Display
    Gem ** array();// Function to get array
    void Delete_and_drop();// Function to drop the upper gems
    void Checking_Of_Grid_Drop_Break();// Function to break the gems
    void swap_of_gem(Gem ** a, int *loc_a, int *loc_b);// Function to swap the gems
    Grid_and_Game_Function();// Constructor
    void read_file();// Function to read file
    void save_file();// Function to sav efile with highscore
    bool reset_e(bool f=false);// Function to reset
    void hint();// Function to get hints
    void save_game_state();// Function to save game state
    void load_state();// Function to load state
};

#endif /* grid_h */
