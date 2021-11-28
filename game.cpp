//============================================================================
// Name        : .cpp
// Author      : Musa Dildar Ahmed Cheema
// Version     : 2.0
// Copyright   : @ MusaDAC 2020
// Description : Basic 2D game of Gem Crush
// Date        : May 22, 2020 (10:36 pm)
//============================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Libaray Used
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GEMCRUSH_CPP_
#define GEMCRUSH_CPP_
#include "util.h"  // Header File for OpenGL and Glut
#include <iostream>// For ostream and ofstream
#include "grid.h"// Custom Header File which Supports the Game Basic Skeleton Code / Functioning
#include<string>// for manuplation of Strings Mostly Used for Saving and Reading Files
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include "main_menu.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Libaray Used
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Grid_and_Game_Function a; // Only Global Variable Used For Passing to Every Single Function this calls a Class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GameDisplay(){
    
    srand(time(NULL));// for Random Intializer
	glClearColor(0, 0,0.0, 0 );// Clear all a the Colours i.e Black
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Static int used for adjusting parameters of Different Features
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static int Level=1; // Used to Tell the Level of Game
    static int k=0; // Torus Locations x-Coordinate
    static int m=0; // Torus Locations y-Coordinate
    static int size_torus=30;// Inital size of Different Pattrens
    static int progressbar_end=650, progressbar_start=50;// Start and End Coordinates
    static int progressbar_level=40;// Progress Bar Level y-Coordinate
    static int progress=50;// Progress Start from this x-Coordinates
    static int set_clock=45;//In Seconds Required
    static int clock =set_clock*2;//FPS RELEATED TIME WROKING
    static int end_clock=0;// End Point Where Clocks Stop
    static double score_prefix=2.5; // Score Prefix to Increase the Required Score Per Level
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Static int used for adjusting parameters of Different Features
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Menu Sceeens and Their BackGrounds Game Functionality
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
    if(a.get_meun_reference()==0){
        menu1(k,m,size_torus);
    }
    else if(a.get_meun_reference()==1){
        static int grid_end=650, grid_start=50;// Start and End Coordinates
           static int grid_level=180;// Progress Bar Level y-Coordinate
           static int progress=50;
           
        DrawLine( grid_start , grid_level ,  grid_end ,grid_level , 30 , colors[AQUA] );
        DrawLine( grid_start , grid_level + 600,  grid_end ,grid_level +600 , 20 , colors[AQUA] );
        DrawLine( grid_start , grid_level -15,  grid_start ,grid_level +610 , 20 , colors[AQUA] );
        DrawLine( grid_end , grid_level -15,  grid_end ,grid_level +610 , 20 , colors[AQUA] );
        DrawRectangle(50,900,600,1000,colors[DARK_SEA_GREEN]);
        DrawRectangle(50,900,100,110,colors[YELLOW]);
        DrawRectangle(50,900,500,110,colors[YELLOW]);
        DrawLine( 80 , 930 , 80 , 990 , 15 , colors[RED] );
        DrawLine( 110 , 930 ,110 , 990 , 15 , colors[RED] );
        
        DrawLine( 160 , 900 , 160 , 1000 , 15 , colors[BLACK] );
        DrawLine( 300 , 900 , 300 , 1000 , 15 , colors[BLACK] );
        
        DrawLine( 180 , 935 , 180 , 970 , 15 , colors[AQUA] );
        DrawLine( 280 , 935 , 280 , 970 , 15 , colors[AQUA] );
        DrawLine( 230 , 935 , 230 , 990 , 15 , colors[AQUA] );
        DrawLine( 230 , 990 , 210 , 960 , 15 , colors[BLACK] );
        DrawLine( 230 , 990 , 250 , 960 , 15 , colors[BLACK] );
        DrawLine( 180 , 940 , 280 , 940 , 15 , colors[AQUA] );
        
         DrawString(  400,950, "???", colors[RED]);
        
        DrawLine( 580 , 990 , 610 , 940 , 15 , colors[MAROON] );
        DrawLine( 580 , 940 , 610 , 990 , 15 , colors[MAROON] );
        
        DrawString(  65,910, "Pause", colors[MISTY_ROSE]);
        DrawString(  175,910, "Save Game", colors[MISTY_ROSE]);
        DrawString(  385,910, "HINT", colors[MISTY_ROSE]);
        DrawString(  575,910, "Exit", colors[MISTY_ROSE]);
        
        DrawString(  550, 800, "Score  "+Num2Str(a.get_score()), colors[MISTY_ROSE]);
        DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
        if(a.get_music_status()==1){
            DrawString(  0, 5, "M) Mute Sound", colors[MISTY_ROSE]);
        }
        else{
            DrawString(  0, 5, "M) Play Sound", colors[MISTY_ROSE]);
        }
        a.Checking_Of_Grid_Drop_Break();
        a.Delete_and_drop();
        a.Display();
        DrawLine( progressbar_start , progressbar_level ,  progressbar_end ,progressbar_level , 2 , colors[MISTY_ROSE] );
        DrawLine( progressbar_start , progressbar_level + 30,  progressbar_end ,progressbar_level +30 , 2 , colors[MISTY_ROSE] );
        DrawLine( progressbar_start , progressbar_level +15 ,  progress ,progressbar_level +15 , 15 , colors[RED] );
        progress=50+(score_prefix*a.get_score());
        if (progress>=650) {
            Level++;
            a.set_Level(Level);
            glClearColor(0, 0,0.0, 0 );
            glClear (GL_COLOR_BUFFER_BIT);
            DrawString( 250, 500, "Next Level", colors[MISTY_ROSE]);
            a.t_set_score(a.get_score());
            a.set_score();
            progress=50;
            set_clock-=15;
            clock=set_clock*2;
            score_prefix=2.0;
            
        }
        DrawString(50, 800, "Clock="+Num2Str(clock/2), colors[MISTY_ROSE]);
        clock--;
        if(clock==end_clock){
            a.set_meun_reference(5);
        }
    }
    else if(a.get_meun_reference()==2){
        menu3(k,m,size_torus,a);
    }
    else if(a.get_meun_reference()==5 && a.get_Level()<3){
        Moving_Shapes(k,m,size_torus);
        DrawString( 250, 500, "GAME OVER", colors[MISTY_ROSE]);
        Level=1;
        k=0; // Torus Locations x-Coordinate
        m=0; // Torus Locations y-Coordinate
        size_torus=30;// Inital size of Different Pattrens
        progressbar_end=650, progressbar_start=50;// Start and End Coordinates
        progressbar_level=40;// Progress Bar Level y-Coordinate
        progress=50;// Progress Start from this x-Coordinates
        set_clock=45;//In Seconds
        clock =set_clock*2;//Start Clock From and Saves the Progress of Seconds 0 Onwards
        end_clock=0;
        score_prefix=2.5;
        DrawString( 250, 450, "Press 0 to go to Menu", colors[MISTY_ROSE]);
        DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
    }
    else if(a.get_meun_reference()==3){
        menu4(k,m,size_torus,a);
    }
    else if(a.get_meun_reference()==6){
        Moving_Shapes(k,m,size_torus);
        DrawString( 250, 800,"Save Your Game", colors[MISTY_ROSE]);
        DrawString( 250, 700,"Enter Your Name", colors[MISTY_ROSE]);
         DrawString( 200, 600, a.get_user_name(), colors[MISTY_ROSE]);
        progress=50;
        k=0; // Torus Locations x-Coordinate
        m=0; // Torus Locations y-Coordinate
        size_torus=30;// Inital size of Different Pattrens
        progressbar_end=650, progressbar_start=50;// Start and End Coordinates
        progressbar_level=40;// Progress Bar Level y-Coordinate
        progress=50;// Progress Start from this x-Coordinates
        set_clock=45;//In Seconds
        clock =set_clock*2;//Start Clock From and Saves the Progress of Seconds 0 Onwards
        end_clock=0;
        score_prefix=2.5;
        DrawString(0, 5, "Press Enter to save", colors[MISTY_ROSE]);
        DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
    }
    else if(a.get_meun_reference()==7){
    Moving_Shapes(k,m,size_torus);
    DrawString( 250, 800,"Load Your Game", colors[MISTY_ROSE]);
    DrawString( 250, 700,"Enter Your Name", colors[MISTY_ROSE]);
    DrawString( 200, 600, a.get_user_name(), colors[MISTY_ROSE]);
    DrawString( 0, 5, "Press Enter to Load", colors[MISTY_ROSE]);
    DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
    }
    else if(a.get_meun_reference()==100){
    Moving_Shapes(k,m,size_torus);
        DrawString( 250,500,"Game Paused", colors[MISTY_ROSE]);
        DrawString( 250,400,"Press P to Continue", colors[MISTY_ROSE]);
         DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
    }
    else{
        static bool reset=true;
               progress=50;
               if(reset==true){
               k=0; // Torus Locations x-Coordinate
               m=0; // Torus Locations y-Coordinate
               size_torus=30;// Inital size of Different Pattrens
               progressbar_end=650, progressbar_start=50;// Start and End Coordinates
               progressbar_level=40;// Progress Bar Level y-Coordinate
               progress=50;// Progress Start from this x-Coordinates
               set_clock=45;//In Seconds
               clock =set_clock*2;//Start Clock From and Saves the Progress of Seconds 0 Onwards
               end_clock=0;
               score_prefix=2.5;
               reset=false;
               }
        Moving_Shapes(k,m,size_torus);
        DrawString( 250, 550, "Your Score is "+ Num2Str(a.t_get_score()), colors[MISTY_ROSE]);
        DrawString( 250, 450, "Enter Your Name:", colors[MISTY_ROSE]);
        a.set_name_time();
        DrawString( 200, 410, a.get_user_name(), colors[MISTY_ROSE]);
    }
    k+=10;m+=1;
    if(k>700){
        k=0;
    }
    if(m>10){
        m=0;
    }
    
    glutSwapBuffers(); // do not modify this line..
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Menu Sceeens and Their BackGrounds Game Functionality
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void NonPrintableKeys(int key, int x, int y) {
    if (key== GLUT_KEY_LEFT) {
        // what to do when left key is pressed...
    }
    else if (key== GLUT_KEY_RIGHT) {

    }
    else if (key== GLUT_KEY_UP) {

    }
    else if (key== GLUT_KEY_DOWN) {

    }
    glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y) {
    if (a.get_name_time()==false) {
        if (key == 27/* Escape key ASCII*/) {
        
            exit(1); // exit the program when escape key is pressed.
        }

        if (key == '1' || key == '1' && a.get_meun_reference()== 0) //Key for placing the bomb
                {
                    a.set_meun_reference(1);
        }
        if (key == '0' || key == '0' ) //Key for placing the bomb
                {
                    a.set_meun_reference(0);
        }
        if (key=='P' || key=='p'){
            a.set_meun_reference(1);
        }
        if (key == '2' || key == '2' && a.get_meun_reference()== 0) //Key for placing the bomb
                {
                    a.set_meun_reference(2);
        }
        if (key == '4' || key == '4' && a.get_meun_reference()== 0) //Key for placing the bomb
                {
                    a.set_meun_reference(7);
                    a.set_name_time();
        }
        if (key == 'm' || key == 'M' && a.get_meun_reference()== 0) //Key for placing the bomb
                {
                    if(a.get_music_status()==1){
                        a.set_music_status(0);
                    }
                    else{
                        a.set_music_status(1);
                    }
        }
        if (key=='3') {
            a.set_meun_reference(3);
            a.read_file();
        }
        if ((key == 's'|| key == 'S') && a.get_meun_reference()==1)
        {
            a.set_meun_reference(6);
            a.set_name_time();
        }
    }
    else{
        static int name_display_apart=5;
        if(int(key)==13){
            if(a.get_meun_reference()==6){
                a.save_game_state();
                a.set_meun_reference(0);
                a.set_name_time(false);
            }
            if (a.get_meun_reference()==7) {
                 a.load_state();
                 a.set_meun_reference(1);
                 a.set_name_time(false);
            }
            else{
            a.save_file();
            }
        }
        else if (int(key)==8) {
            a.remove_last_word();
        }
        else{
        a.set_user_name(key);
        }
       
    }
    glutPostRedisplay();
}


void Timer(int m) {
    if(a.get_meun_reference()!=1){
    glutTimerFunc(200.0, Timer, 0);
    }
    else{
        glutTimerFunc(500.0, Timer, 0);
    }
    glutPostRedisplay();
}

void MousePressedAndMoved(int x, int y) {
    cout << x << " " << y << endl;
    glutPostRedisplay();
}

void MouseMoved(int x, int y) {
    //cout << x << " " << y << endl;
    glutPostRedisplay();
    
}


void MouseClicked(int button, int state, int x, int y ) {
    
    if (button == GLUT_LEFT_BUTTON) // dealing only with left button
            {
                if(state==0){
                    if((x>50 && x< 150 )&& (y>0 && y<100)){
                        a.set_meun_reference(100);
                    }
                    if((x>170 && x< 300 )&& (y>0 && y<100)){
                        a.set_meun_reference(6);
                        a.set_name_time();
                    }
                    if((x>305 && x< 550 )&& (y>0 && y<100)){
                        a.hint();
                    }
                    if((x>555 && x< 650 )&& (y>0 && y<100)){
                        exit(1);
                    }
                    a.set_first_coo(x,y);
                }
                else{
                    a.set_sec_coo(x,y);
                    if(a.get_meun_reference()==1){
                    a.swap_of_gem(a.array(),a.get_first_coo(),a.get_sec_coo());
                    glutPostRedisplay();
                    }
                }

    } else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
            {
            cout<<"Right Button Pressed"<<endl;
    }
}

int main(int argc, char*argv[]) {
    int width = 700 ,height = 1000; // i have set my window size to be 800 x 600

    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(0, 0); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("Gem Crush"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...
    // Register your functions to the library,
    // you are telling the library names of function to call for different tasks.
    //glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
    // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(10.0, Timer, 0);
    glutMouseFunc(MouseClicked);
//    glutPassiveMotionFunc(MouseMoved); // Mouse
  // glutMotionFunc(MousePressedAndMoved); // Mouse

    // now handle the control to library and it will call our registered functions when
    // it deems necessary...
    glutMainLoop();

    return 1;
}
#endif /* AsteroidS_CPP_ */
