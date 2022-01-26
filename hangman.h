#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <curses.h>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> //pour std::find

class Hangman
{
public:
    //Initialization
    void LaunchGame();

    //Accessors
    int get_xc() const {return x_c;}
    int get_yc() const {return y_c;}

    //Mutators
    void desc_letters_to_find() {letters_to_find -= 1;}
    void desc_lifes() {n_lifes -= 1;}

    void add_char(char ch) {l_asked.push_back(ch);}

    void move_cursor(){move(x_c, y_c); y_c += 3;}

    //Methods
    bool in_hword(char ch) const;
    bool in_asked(char ch) const;
    int word_found() const;
    int still_alive() const;
    void choose_word();
    void choose_random__word();

    //Print
    void print_action(char * action) const;
    void print_letters(char ch) const;
    void print_lifes() const;
    void print_h_word() const;

    //Drawing the Hangman
    void drawing();

private:
    std::vector<char> h_word ={} ;
    int letters_to_find;
    std::vector<char> l_asked = {};

    int n_lifes = 7;
    int x_c = 11;
    int y_c = 2;

    WINDOW *wdraw;
    WINDOW *waction;
    WINDOW *whearts;
    WINDOW *wword;
    WINDOW *wchar;
};

#endif // HANGMAN_H_INCLUDED
