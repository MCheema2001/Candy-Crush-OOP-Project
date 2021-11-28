#ifndef player_h
#define player_h

#include <iostream>

using namespace std;

class Player{
protected:
    string User_name;
    bool name_time;
    int score;
    int turns;
    int total_score;
    int last_word;
    int time_remain;
public:
    void set_time(int k);
    void set_user_name(char name);
    string get_user_name();
    void remove_last_word();
    Player();
    int t_get_score();
    void t_set_score(int score);
    int get_score();
    void set_score();
    void set_name_time(bool f=true);
    bool get_name_time();
};


#endif /* player_h */
