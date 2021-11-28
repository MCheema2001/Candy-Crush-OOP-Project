#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "util.h"
#include "player.h"

using namespace std;

void Player::set_user_name(char name){
    User_name+=name;// set usernmae
    last_word++;
}
string Player::get_user_name(){
    return User_name; // get username
}
void Player::remove_last_word(){
    if (last_word>0) {// Username backspace functionalty deleting last char from string
        string temp="";
        for (int i=0; User_name[i+1]!='\0'; i++) {
            temp+=User_name[i];
        }
        User_name=temp;
    }
}

Player::Player(){
    User_name=""; // username is emptied
    total_score=0;// total score is 0
    score=150;// scpore maximum is 150
    turns=5;// turns maximum
    last_word=-1; //  last word is -1
    name_time=false;// name time is false
}

int Player::t_get_score(){
    return total_score; //  total score gets
}
void Player::t_set_score(int score){
    total_score+=score; // sets score
}
int Player::get_score(){
    return score; // gets score
}
void Player::set_score(){
    score=0;// set score
}
void Player::set_name_time(bool f){
    name_time=f; // set bool name time
}
bool Player::get_name_time(){
    return name_time;
}

void Player::set_time(int k){
    time_remain=k;
}
