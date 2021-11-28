#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "util.h"
#include "gem.h"
#include "player.h"
#include "game_c.h"
#include "grid.h"

void Grid_and_Game_Function::set_first_coo(int x,int y){
    first_coo[0]=(x/70)-1;// Set the First Gem needed to be Swapped at [0] position stores x
    first_coo[1]=(y/75)-3;// Set the First Gem needed to be Swapped at [1] position stores y
    if (first_coo[0]==-1) {// Condtion to Store x as Zero if x is -1
        first_coo[0]=0;// x Stroed as 0 if Condtion is true
    }
}
void Grid_and_Game_Function::set_sec_coo(int x,int y){
    sec_coo[0]=(x/70)-1;// Set the Second Gem needed to be Swapped at [0] position stores x
    sec_coo[1]=(y/75)-3;// Set the Second Gem needed to be Swapped at [1] position stores y
    if (sec_coo[0]==-1) {// Condtion to Store x as Zero if x is -1
        sec_coo[0]=0;// x Stroed as 0 if Condtion is true
    }
}
int * Grid_and_Game_Function::get_first_coo(){
    return first_coo;//Get Co-ordinates of First gem to Swap
}
int * Grid_and_Game_Function::get_sec_coo(){
    return sec_coo;//Get Co-ordinates of Second gem to Swap
}


void Grid_and_Game_Function::Display(){
    int X_C=80;// Stores starting Position of x Co=ordinate on GUI and Dispaly
    int Dis_X=70;// To maintain a Distance between each x Co-ordinate
    int Dis_Y=70;// To maintain a Distance between each y Co-ordinate
    int Y_C=700;// Stores starting Position of y Co=ordinate on GUI and Dispaly
    int Size_of_Gems=60;// Displays the Size of Gem
    for (int i=size_of_Grid-1; i>=0; i--) {// For Loop to Display Row of Gem on GUI
        for (int j=size_of_Grid-1; j>=0; j--) {// For Loop to Display Column of Gem on GUI
            if (a[i][j].get_color()=="R") {// If Gem has a Colour Red (R)
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 25,8 ,6, colors[RED]); //Makes the Hexagon Red
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 15,8 ,6, colors[ORANGE_RED]);//Makes the Hexagon Red
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 5,8 ,6, colors[RED]);//Makes the Hexagon Red
            }
            else if(a[i][j].get_color()=="G"){// If Gem has a Colour Green (G)
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 25,8 ,3, colors[GREEN]);//Makes the Triagle on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 10,8 ,3, colors[ALICE_BLUE]);//Makes the Triagle on GUI
            }
            else if(a[i][j].get_color()=="B"){// If Gem has a Colour Blue (B)
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 25,8 ,100, colors[BLUE]);//Makes the Circle on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 5,8 ,100, colors[LIME]);//Makes the Circle on GUI
            }
            else if(a[i][j].get_color()=="Y"){// If Gem has a Colour Yellow (Y)
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 25,8 ,4, colors[YELLOW]);//Makes the Square on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 2,8 ,100, colors[MAROON]);//Makes the Square on GUI
                //DrawSquare( X_C+(i*Dis_X) , Y_C-(j*Dis_Y) ,Size_of_Gems,colors[YELLOW]);
            }
            else if(a[i][j].get_color()=="W"){// If Gem has a Colour Red (W)
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 25,8 ,4, colors[WHITE]);//Makes the Square on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 100, 360 , 25,8 ,4, colors[WHITE]);//Makes the Square on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 250, 360 , 25,8 ,4, colors[WHITE]);//Makes the Square on GUI
                Torus2d(X_C+(i*Dis_X+30), Y_C-(j*Dis_Y-25), 0, 360 , 3,8 ,100, colors[AQUA]);//Makes the Circle on GUI
            }
            else if(a[i][j].get_color()=="H"){
                srand(time(NULL));
                int k=rand()%3;
                if (k==0) {// Condition for Different Colors
                    DrawSquare( X_C+(i*Dis_X) , Y_C-(j*Dis_Y) ,Size_of_Gems,colors[YELLOW]);//Makes the Square on GUI
                }
                if (k==1) {// Condition for Different Colors
                    DrawSquare( X_C+(i*Dis_X) , Y_C-(j*Dis_Y) ,Size_of_Gems,colors[RED]);//Makes the Square on GUI
                }
                if (k==2) {// Condition for Different Colors
                    DrawSquare( X_C+(i*Dis_X) , Y_C-(j*Dis_Y) ,Size_of_Gems,colors[GREEN]);//Makes the Square on GUI
                }
            }
        }
    }
}
Gem ** Grid_and_Game_Function::array(){
    return a;// Returns the Array of Gem
}
 void Grid_and_Game_Function::Delete_and_drop(){
     static int count_this_function_called=0; // Has a record this Function is Called
     string color[5]={"R","B","G","W","Y"};// String to Store all Possible Colours
     srand(time(NULL));// randomize the seed
     for (int i=0; i<size_of_Grid; i++) { // For loop to Check all the rows of Grid
         for (int j=0; j<size_of_Grid; j++) { // For loop to Check all the columns of Grid
             if (a[i][j].get_color()=="d") {// Condition to check if Colour is D
                 for (int k=0; k<8; k++) {// This for loop works as Drop loop
                     if (j-k>0) {// if row is not 0
                         a[i][j-k].set_color(a[i][j-k-1].get_color()); // The Above Colour will Shift down and set for Down One Gem
                     }
                     else{
                         sleep(0.5);// Sleep
                         a[i][0].set_color(".");// If Row is Zero Its Colour is Stored to a "." or NuLL
                         break;// and it Breaks
                     }
                 }
             }
         }
     }
     for (int i=0; i<size_of_Grid; i++) { // For loop to Check all ROws
         for (int j=0; j<size_of_Grid; j++) {// For loop to Check all Columns
             if (a[j][i].get_color()==".") {// If to Check if Colour is Null or . it will be Replaced by new Colour
                 a[j][i].set_color(color[rand()%5]);//Colour is set
             }
             
         }
     }
 }

    void Grid_and_Game_Function::Checking_Of_Grid_Drop_Break(){
    again:// A label that runs the Function from Start Again
    for (int i=0; i<size_of_Grid ; i++) { // Maximum we can go for rows check
        int temp_x=i;// Stores the i as temp x coordinate to manipulate
        for (int j=0; j<size_of_Grid ; j++) {// Maximum we can go for column check
            int temp_y=j;// Stores the j as temp y coordinate to manipulate
            bool horizontal=true;// Bool for Horizonatal Match Check;
            bool vertical =true;// Bool for Vertical Match Check;
            string temp_colour_for_checking= a[temp_x][temp_y].get_color();// Stores the gem Colour for i and j Position
            int match_colour_count=0;// To Store the Consective Colur Count
            for (int k=0; temp_colour_for_checking== a[temp_x][temp_y+k].get_color() && temp_colour_for_checking != "d" && temp_colour_for_checking != "." &&temp_y+k<size_of_Grid-1; k++) {
                // for loop to check if Consective rows have same Colour with Condition that the Colour is not d and Row NULL and Doesn't Exceed the size of Row when Checking so Actually it runs till 0 to 5
                match_colour_count++;// Increments if Colur is Matched
            }
            if ((match_colour_count>2) || (match_colour_count>1 && temp_colour_for_checking== a[temp_x][7].get_color())) {// if condition to show that colurs matched are 3 or more so it will break gem and if last row is their then match colur will be gretaer then 2 + last row at j Column
                if (match_colour_count>1 && temp_colour_for_checking== a[temp_x][7].get_color()) {
                    match_colour_count++;
                }
                for (int l=0; l<match_colour_count; l++) {
                    a[temp_x][temp_y+l].set_color("d");// set the colur to delete meaning delete it
                     score+=2;// adds the score
                }
                goto again;// and moves to start label(again) to recheck for any other match
            }
            else{
                match_colour_count=0;// match colour counts go to zero if previously was below
            }
            for (int k=0; temp_colour_for_checking== a[temp_x+k][temp_y].get_color() && temp_colour_for_checking != "d" && temp_colour_for_checking != "." && temp_x+k<size_of_Grid-1; k++) {// if condition to show that colurs matched are 3 or more so it will break gem and if last column is their then match colur will be gretaer then 2 + last row at j row
                match_colour_count++;
            }
            if (match_colour_count>2 || (match_colour_count>1 && temp_colour_for_checking== a[7][temp_y].get_color())) {
                if (match_colour_count>1 && temp_colour_for_checking== a[7][temp_y].get_color()) {// set the colur to delete meaning delete it
                    match_colour_count++;// Increments the match count
                }
                for (int l=0; l<match_colour_count; l++) {
                    a[temp_x+l][temp_y].set_color("d");// set the colur to delete meaning delete it
                    score+=2;// adds the score
                }
                goto again;// and moves to start label(again) to recheck for any other match
            }
            else{
                match_colour_count=0;// match colour counts go to zero if previously was below
            }
        }
    }
}

void Grid_and_Game_Function::swap_of_gem(Gem ** a, int *loc_a, int *loc_b){
    if((loc_a[0]>=0 && loc_a[0]<8) && (loc_a[1]>=0 && loc_a[1]<8) && (loc_b[0]>=0 && loc_b[0]<8) && (loc_b[1]>=0 && loc_b[1]<8)){// Check to see the Coordinates are Up Left Right Down
        if ((loc_a[0]==loc_b[0] && (loc_a[1]==loc_b[1]+1 || loc_a[1]==loc_b[1]-1)) || (loc_a[1]==loc_b[1] && (loc_a[0]==loc_b[0]+1 || loc_a[0]==loc_b[0]-1))) {// Excludes the Diagnols can not be swapped
            string temp_color=a[loc_a[0]][loc_a[1]].get_color();// Color of first gem stored in gem
            a[loc_a[0]][loc_a[1]].set_color(a[loc_b[0]][loc_b[1]].get_color());// First Gem Colour is replaced by colur of Second Gem
            a[loc_b[0]][loc_b[1]].set_color(temp_color);// Second gem Colour is replaced with temp having first Colour
        }
        if(get_music_status()==true){// If to check wheather sound is on or Off
               system("play high.wav");// to play the sound of swap
               }
               Checking_Of_Grid_Drop_Break();// Check if Broken
               Delete_and_drop();// check if Not Broken
    }
    // Return maybe if to Update in Game Display
    
}
Grid_and_Game_Function::Grid_and_Game_Function(){
    size_of_Grid=8;// Intilaie the Size of Square grid
    first_coo= new int [2];// Creates a 2d Array to store x and y for First Gem
    sec_coo =new int[2];// Creates a 2d Array to store x and y for Second Gem
    srand(time(NULL));// Seed to Randomize
    string color[5]={"R","B","G","W","Y"}; // Intialize Color String
    a =new Gem *[size_of_Grid];// Intialize the Gem Array
    for (int i=0; i<size_of_Grid; i++) {
        a[i]=new Gem[size_of_Grid];// Intialize the Gem Array 2D
    }
    for (int i=0; i<size_of_Grid; i++) {
        for (int j=0; j<size_of_Grid; j++) {
            a[j][i].set_location(i, j);// Set the Location
            a[j][i].set_color(color[rand()%5]);// Set Colur random for Gems
        }
    }
    for (int i=0; i<10; i++) { // for loop to delete all possible break when intializing the grid so that score is zero
        this->Checking_Of_Grid_Drop_Break();// to see breaks
        this->Delete_and_drop();// drops the brust to replace
        this->score=0;// score remains zero :)
    }
}

void Grid_and_Game_Function::read_file(){
    for (int i=0; i<3; i++) {// for loop to set previous name if any to Empty
        Playername_with_high_score[i]="";// Highscore is NULL
        highscores_in_game[i]="";// Player name is also set to NULL
    }
    fstream read;// file read variable created
         read.open("Highscore.txt",ios::in);// a file is opened
         char temp;// char is used to get from File
         int count=0;// Count variable to store current count of Players loaded and Highscore
         for(int k=0; k<3; k++){// for loop
             for (int i=0; temp!=','; i++) {
                 read>>temp;// reads the char till ", "
                 if(temp!=','){
                 Playername_with_high_score[count]+=temp; // and is appended to name
                 }
             }
             for (int i=0; temp!='.'; i++) {//for loo[
                 read>>temp;// reads till .
                 if(temp!='.'){
                 highscores_in_game[count]+=temp;// and is appended to score
                 }
             }
             count++; // count increased
         }
    for (int i=0; i<2; i++) {// Bubble sort on Basis of Score
        for (int j=0; j<2; j++) {// Bubble sort on Basis of Score
            int temp=stoi(highscores_in_game[i]); // Converts the Highescore to Int
            int temp1=stoi(highscores_in_game[i+1]);// Converts the Highescore to Int
            if (temp<temp1) { // Check if Highscore i is smaller the i+1
                swap(highscores_in_game[i], highscores_in_game[i+1]);// It swaps to make a Order
                swap(Playername_with_high_score[i],Playername_with_high_score[i+1]);// also swaps name so that true score is shown
            }
        }
    }
    
}
void Grid_and_Game_Function::save_file(){// save file Function
    fstream write;// File variable to
    write.open("Highscore.txt",ios::out);// Write Option
    if (int(stoi(highscores_in_game[2]))< total_score) { // New User name is Appended  and Highscore
        Playername_with_high_score[2]=User_name;// Username
        highscores_in_game[2]=Num2Str(total_score);// Highscore
    }
    for (int i=0; i<3; i++) {
        write<<Playername_with_high_score[i]<<","<<highscores_in_game[i]<<"."<<endl;// Writes the top scores to File
    }
    write.close();//File Closed
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Everything is reset
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    meun_reference=0;
    set_name_time(false);
    User_name="";
        total_score=0;
        score=0;
        turns=5;
        last_word=-1;
        name_time=false;
    meun_reference=0;
           music_name="";
           music_status=true;
    size_of_Grid=8;
    string color[5]={"R","B","G","W","Y"};
    for (int i=0; i<size_of_Grid; i++) {
               for (int j=0; j<size_of_Grid; j++) {
                   a[j][i].set_location(i, j);
                   a[j][i].set_color(color[rand()%5]);
               }
           }
           for (int i=0; i<10; i++) {
               this->Checking_Of_Grid_Drop_Break();
               this->Delete_and_drop();
               this->score=0;
           }
    reset =true;
    set_Level();
    for (int i=0; i<3; i++) {
        Playername_with_high_score[i]="";
        highscores_in_game[i]="";
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Everything is reset
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    read_file();//Reads the file
  }
bool Grid_and_Game_Function::reset_e(bool f){
   bool temp =reset;// for reseting
    reset=f;// reset is set to f
    return temp; // temp is returned
}

void Grid_and_Game_Function::save_game_state(){
    fstream file_save;// file to save state
     file_save.open(User_name+".txt",ios::out);// file is named after username
    file_save<<User_name<<endl;// User name is wriiten in the file
    file_save<<Level<<endl;// Level is written
    file_save<<time<<endl;// Time is written
    for (int i=0; i<size_of_Grid; i++) {// for loop
        for (int j=0; j<size_of_Grid; j++) {// for loop
            file_save<<a[i][j].get_color();// colors grid is written
        }
        file_save<<endl;//a new line
    }
    file_save<<score;// score is written in the file
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Everything is reset
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    meun_reference=0;
    set_name_time(false);
    User_name="";
        total_score=0;
        score=0;
        turns=5;
        last_word=-1;
        name_time=false;
    meun_reference=0;
           music_name="";
           music_status=true;
    size_of_Grid=8;
    string color[5]={"R","B","G","W","Y"};
    for (int i=0; i<size_of_Grid; i++) {
               for (int j=0; j<size_of_Grid; j++) {
                   a[j][i].set_location(i, j);
                   a[j][i].set_color(color[rand()%5]);
               }
           }
           for (int i=0; i<10; i++) {
               this->Checking_Of_Grid_Drop_Break();
               this->Delete_and_drop();
               this->score=0;
           }
    reset =true;
    set_Level();
    for (int i=0; i<3; i++) {
        Playername_with_high_score[i]="";
        highscores_in_game[i]="";
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Everything is reset
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    read_file();// File is read once again
}
void Grid_and_Game_Function::load_state(){
    fstream file;// state is loaded
    file.open(User_name+".txt",ios::in);// username is opend
    if (!file){
        goto end_line; // if file not found it go to end
    }
     file>>User_name;// username is set
    file>>Level;// level is set
     file>>time_remain;// time is set
    char color;// color get
     for (int i=0; i<8; i++) {
         for (int j=0; j<8; j++) {
             file>>color; // char comes from file
             string convert="";// string to convert char
             convert+=color;// char to string
             a[i][j].set_color(convert);//  color is loaded
         }
     }
     file>>score;// score is loaded
    end_line:
    meun_reference=1;// and go to game loaded
}

void Grid_and_Game_Function::hint(){
    int inx1=0;// Index 1 is Stored
    int inx2=0;// Index 2 is Stored
    bool horizontal_hint_found=false;// Horizontal hint is found
    for (int i=0; i<6; i++) { //for loop run till 6
        for (int j=0; j<6; j++) { //for loop run till 6
            if ((a[i][j].get_color()==a[i][j+1].get_color()) && (a[i][j+1].get_color() == a[i+1][j+2].get_color())) {// if loop to check the 2 consective and 1 left right ahead hint
                inx1=i;// i is stroed as x
                inx2=j;// i is stroed as y
                horizontal_hint_found=true;// and is true
            }
        }
    }
    if (horizontal_hint_found==true) {// if true
        a[inx1][inx2].set_color("H");// Coordinates are set to H
        a[inx1][inx2+1].set_color("H");// Coordinates are set to H
        a[inx1+1][inx2+2].set_color("H");// Coordinates are set to H
    }
    else{
        bool vertical_hint_found=false;// Vertical hintr is found or not
        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++) {
                if ((a[j][i].get_color()==a[j+1][i].get_color()) && (a[j+1][i].get_color() == a[j+2][i+1].get_color())) {
                    inx1=i;// i is stroed as x
                    inx2=j;// j is stroed as y
                    vertical_hint_found=true;
                }
            }
        }
        if (vertical_hint_found==true) {
            a[inx1][inx2].set_color("H");// Coordinates are set to H
            a[inx1+1][inx2].set_color("H");// Coordinates are set to H
            a[inx1+2][inx2+1].set_color("H");// Coordinates are set to H
        }
    }
    
}




