#include "hangman.h"

int main()
{
    Hangman game;
    game.LaunchGame();

    //Choosing 1 or 2 players
    game.print_action("One player : o // Two player : t");
    char ch = getch();
    switch(ch){
        case 'o':
            game.choose_random__word();
            break;
        case 't':
            game.choose_word(); //choosing the word to guess + letters to find
            break;
    }

    game.print_action("Let's go ! Choose a letter");
    game.move_cursor();

    while(game.word_found() == 0 && game.still_alive() == 1){
        char ch = getch();
        //Stock
        if(game.in_asked(ch)){
            game.print_action("Already asked, choose another letter");
        }
        else{
            game.add_char(ch);
            //Drawing
            printw("%c",ch);
            //Good ?
            if(game.in_hword(ch))
            {
                game.desc_letters_to_find();
                game.print_letters(ch);
                game.print_action("True, choose another letter");
            }
            else{
                game.desc_lifes();
                game.print_lifes();
                game.print_action("False, choose another letter");
                game.drawing();
            }
            game.move_cursor();
        }
    }
    if(game.word_found() == 1){
        game.print_action("V I C T O R Y, press enter to quit");
    }
    else{
        game.print_action("D E F E A T, press enter to quit");
        game.print_h_word();
    }
    getch();
    endwin();

    return 0;
}

