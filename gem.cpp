#include "gem.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "util.h"



Gem::Gem(){
    Location_in_Grid=new int [2]; // Intialize the Array 2D to Store x and y Co-ordinates
}
Gem::Gem(string *color , int Locationx, int Locationy){
    int random_color=rand()%5; // Random Number is generated to access Color String
    colour=color[random_color];// Colour is Stored for that Jump
    Location_in_Grid=new int [2];// Array to Store x and y is Intialized
    Location_in_Grid[0]=Locationx; // at Position 0 x coordinated is Stored
    Location_in_Grid[1]=Locationy;// at Position 1 y coordinated is Stored
}
void Gem::set_color(string color){
    this->colour=color;// to set Colour
}
void Gem::set_location(int Locationx , int Locationy){
    this->Location_in_Grid[0]=Locationx;// to set x Co-oordinate
    this->Location_in_Grid[1]=Locationy;// to set y Co-oordinate
}
string Gem::get_color(){
    return this->colour; // Rerturns the Colour
}
int * Gem::get_locations(){
    return this->Location_in_Grid; // Returns the arrays having x and y Coordinates
}
Gem::~Gem(){
       
}
