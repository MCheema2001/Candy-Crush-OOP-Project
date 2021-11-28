//
//  main_menu.h
//  Project
//
//  Created by Musa Dildar Ahmed Cheema on 5/4/20.
//  Copyright © 2020 Musa Dildar Ahmed Cheema. All rights reserved.
//
#ifndef main_menu_h
#define main_menu_h

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "util.h"
#include "grid.h"

void Moving_Shapes(int k, int m , int size_torus){
    // Random Moving Shapes are generated using this code using size ,x coordinate and y coordinates This movement
    // is Controlled by Static int in Game Display Function
    Torus2d(100+k, 200, 0, 360 , 100,rand()%size_torus ,(11-m)%10, colors[RED]);
    Torus2d(700, 0+k, 0, 360 , 100, rand()%size_torus ,(8+m)%10, colors[GREEN]);
    Torus2d(0+k, 900-k, 0, 360 , 100, rand()%size_torus ,(6+m)%10, colors[RED]);
    Torus2d(700-k, 1100-k, 0, 360 , 100, rand()%size_torus ,( 3+m)%10, colors[PURPLE]);
    Torus2d(550, 800-k, 0, 360 , 100, rand()%size_torus ,( 6+m)%10, colors[GOLD]);
    Torus2d(400-k, 700+k, 0, 360 , 100, rand()%size_torus ,( 9+m)%10, colors[GREEN_YELLOW]);
    Torus2d(500-k, 500, 0, 360 , 100, rand()%size_torus ,( 7+m)%10, colors[MEDIUM_AQUA_MARINE]);
    
    Torus2d(100+k, 200, 0, 360 , 50,rand()%size_torus ,(11-m)%10, colors[GREEN_YELLOW]);
    Torus2d(700, 0+k, 0, 360 , 50, rand()%size_torus ,(8+m)%10, colors[RED]);
    Torus2d(0+k, 900-k, 0, 360 , 50, rand()%size_torus ,(6+m)%10, colors[PURPLE]);
    Torus2d(700-k, 1100-k, 0, 360 , 50, rand()%size_torus ,( 3+m)%10, colors[YELLOW]);
    Torus2d(550, 800-k, 0, 360 , 50, rand()%size_torus ,( 6+m)%10, colors[MEDIUM_AQUA_MARINE]);
    Torus2d(400-k, 700+k, 0, 360 , 50, rand()%size_torus ,( 9+m)%10, colors[BLUE]);
    Torus2d(500-k, 500, 0, 360 , 50, rand()%size_torus ,( 7+m)%10, colors[GOLD]);
    // Random Moving Shapes are generated using this code using size ,x coordinate and y coordinates This movement
    // is Controlled by Static int in Game Display Function
}
void menu1(int k, int m, int size_torus){
    Moving_Shapes(k,m,size_torus);
    DrawString( 200, 900, "Welcome to Gem Crush", colors[MISTY_ROSE]);
    DrawString( 200, 600, "Press the Following Button", colors[MISTY_ROSE]);
    DrawString( 200, 550, "1) Play", colors[MISTY_ROSE]);
    DrawString( 200, 500, "2) Settings", colors[MISTY_ROSE]);
    DrawString( 200, 450, "3) Highest Score", colors[MISTY_ROSE]);
    DrawString( 200, 400, "4) Load Game", colors[MISTY_ROSE]);
    DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
}

void menu3(int k, int m, int size_torus, Grid_and_Game_Function a){
    Moving_Shapes(k,m,size_torus);
    DrawString( 200, 900, "Settings", colors[MISTY_ROSE]);
    if(a.get_music_status()==true){
         DrawString( 200, 550, "1) Sound = ON", colors[MISTY_ROSE]);
     }
     else{
          DrawString( 200, 550, "1) Sound = OFF", colors[MISTY_ROSE]);
     }
    DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
}
void menu4(int k, int m, int size_torus, Grid_and_Game_Function a){
   Moving_Shapes(k,m,size_torus);
    DrawString( 200, 800,"HighScore", colors[MISTY_ROSE]);
    DrawString( 200, 500,"Name   \t\t\t\t\t\t\t\t\t\t\t    Score", colors[MISTY_ROSE]);
    DrawString( 200, 450,"1)"+a.get_Playernames()+"   \t\t\t\t\t\t\t\t\t\t\t      "+ a.get_highscorers(), colors[MISTY_ROSE]);
    DrawString( 200, 400,"2)"+a.get_Playernames(1)+"    \t\t\t\t\t\t\t\t\t\t\t      "+ a.get_highscorers(1), colors[MISTY_ROSE]);
    DrawString( 200, 350,"3)"+a.get_Playernames(2)+"   \t\t\t\t\t\t\t\t\t\t\t       "+ a.get_highscorers(2), colors[MISTY_ROSE]);
    DrawString( 500, 100,"Press 0 to Return.", colors[MISTY_ROSE]);
    DrawString( 450, 5, "@CopyRight MusaDAC", colors[MISTY_ROSE]);
}

#endif /* main_menu_h */
