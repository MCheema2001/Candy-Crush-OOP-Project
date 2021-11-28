#ifndef gem_h
#define gem_h

#include <iostream>

using namespace std;

class Gem{
protected:
    string colour;// to store colour
    int *Location_in_Grid;// array to store x and y Co-ordinates
public:
    Gem();// Default Constructor
    Gem(string *color , int Locationx, int Locationy);// Parametrized Constructor
    void set_color(string color);// Function to set Colour
    void set_location(int Locationx , int Locationy);// Function to
    string get_color();// Function to get Colour
    int * get_locations();// Function to get x and y coordiantes
    ~Gem();// De-constructor
};

#endif /* gem_h */
