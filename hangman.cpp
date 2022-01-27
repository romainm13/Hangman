#include "hangman.h"

//Initialization
void Hangman::LaunchGame(){
    initscr();
	cbreak();
	noecho();
	//raw();
	                   //Line buffering disabled


    //TITLE
    const char * title = "# Hangman Game #";
    mvprintw(1,(COLS-38),title); //Move cursor, write, let it at the end !
    /*getyx(stdscr,y,x);
    mvprintw(1,15,"After title : %d %d",x,y);
    getch();
    */
    move(0,0);
    refresh();

    // Initialize windows and boxes
    wdraw = newwin(27, COLS/2, 3, COLS/2);
    box(wdraw,0, 0);
    mvwhline(wdraw,23,6, '_', 15); //base
    mvwhline(wdraw,21,6, '_', 15);
    mvwvline(wdraw,22,5, '|', 2);
    mvwvline(wdraw,22,21, '|', 2);

    mvwvline(wdraw,2,8, '|', 20);  //trunk
    mvwvline(wdraw,4,10, '|', 18);
    mvwhline(wdraw,2,8, '_', 35);
    mvwhline(wdraw,3,10, '_', 33);
    mvwvline(wdraw,3,43, '|', 1);

    wrefresh(wdraw);

    waction = newwin(3, COLS/2, 0, 0);
    box(waction,0, 0);
    mvwprintw(waction,1,1,"Action : Press enter to begin");
    wrefresh(waction);

    whearts = newwin(3, 15, 3, 0);
    box(whearts,0, 0);
    mvwprintw(whearts,1,1,"Lifes : x %d",7);
    wrefresh(whearts);

    wword = newwin(3, COLS/2, 6, 0);
    box(wword,0, 0);
    mvwprintw(wword,1,1,"Word to guess : ");
    wrefresh(wword);

    wchar = newwin(4, COLS/2, 9, 0);
    box(wchar,0, 0);
    mvwprintw(wchar,1,1,"Characters asked : ");
    wrefresh(wchar);
    move(1, 30);

    refresh();
    getch();
}

//Methods
bool Hangman::in_hword(char ch) const{
    return std::find(h_word.begin(), h_word.end(), ch) != h_word.end();
}

bool Hangman::in_asked(char ch) const{
    return std::find(l_asked.begin(), l_asked.end(), ch) != l_asked.end();
}

int Hangman::word_found() const{
    if(letters_to_find == 0){return 1;}
    else{return 0;}
}

int Hangman::still_alive() const{
    if(n_lifes > 0){return 1;}
    else{return 0;}
}

void Hangman::choose_word(){
    wclear(waction);
    box(waction,0, 0);
    mvwprintw(waction,1,1,"Word to guess (then press ;): ");
    wrefresh(waction);
    int x_temp = 1;
    int y_temp = 31;
    move(x_temp,y_temp);

    std::vector<char> l_no_double = {};
    int no_double = 0; //nb letters to find
    char ch = getch();
    while(ch != ';')
    {
        if(std::find(l_no_double.begin(), l_no_double.end(), ch) == l_no_double.end())
        {
            l_no_double.push_back(ch);
            no_double += 1;
        }
        h_word.push_back(ch);
        printw("%c",ch);
        refresh();
        y_temp += 2;
        move(x_temp,y_temp);
        ch = getch();
    }
    letters_to_find = no_double;

    y_temp = 0;
    for(int i = 0; i < h_word.size(); i++){
        mvwprintw(wword,1,17 + y_temp,"%c",'_');
        y_temp += 2;
    }
    wrefresh(wword);
}

void Hangman::choose_random__word(){
    std::vector<std::string> dict;
    std::string ligne;
    std::string motHasard;
    int nombre(0);

    std::ifstream monFlux("frenchssaccent.dic");  //Ouverture d'un fichier en lecture

    if(monFlux){
        while(getline(monFlux, ligne)){
        dict.push_back(ligne);
        }
        srand(time(0));
        int random_number = (rand()*10000 % dict.size());
        motHasard = dict[random_number];
    }
    monFlux.close();

    std::vector<char> l_no_double = {};
    int no_double = 0; //nb letters to find

    for(std::string::size_type i = 0; i < motHasard.length(); ++i)
    {
        char ch = motHasard[i];
        if(std::find(l_no_double.begin(), l_no_double.end(), ch) == l_no_double.end())
        {
            l_no_double.push_back(ch);
            no_double += 1;
        }
        h_word.push_back(ch);
    }
    letters_to_find = no_double;

    int y_temp = 0;
    for(int i = 0; i < h_word.size(); i++){
        mvwprintw(wword,1,17 + y_temp,"%c",'_');
        y_temp += 2;
    }
    wrefresh(wword);
}

//Print
void Hangman::print_action(char * action) const{
    wclear(waction);
    box(waction,0, 0);
    mvwprintw(waction,1,1,"Notes : %s", action);
    wrefresh(waction);
}

void Hangman::print_letters(char ch) const{
    int compt = 0;
    for(std::vector<char>::size_type i = 0; i != h_word.size(); i++){
        if(h_word[i] == ch){
                mvwprintw(wword,1, 17+compt,"%c",ch);
    }
    wrefresh(wword);
    compt += 2;
    }
}

void Hangman::print_h_word() const{
    int compt = 0;
    for(std::vector<char>::size_type i = 0; i != h_word.size(); i++){
        mvwprintw(wword,1, 17+compt,"%c",h_word[i]);
        compt += 2;
    }
    wrefresh(wword);
    }

void Hangman::print_lifes() const{
    mvprintw(4, 1,"Lifes : x %d ",n_lifes);
}

//Drawing the Hangman
void Hangman::drawing(){
    switch(n_lifes){
        case 6:
            mvwvline(wdraw,4,40, '|', 3);
            wrefresh(wdraw);
            break;
        case 5:
            mvwhline(wdraw,6,39, '_', 3);
            mvwvline(wdraw,6,40, '|', 1);
            mvwvline(wdraw,7,38, '/', 1);
            mvwvline(wdraw,7,42, '\\', 1);
            mvwvline(wdraw,8,42, '/', 1);
            mvwvline(wdraw,8,38, '\\', 1);
            mvwhline(wdraw,8,39, '_', 3);
            wrefresh(wdraw);
            break;
        case 4:
            mvwvline(wdraw,9,40, '|', 6);
            wrefresh(wdraw);
            break;
        case 3:
            mvwvline(wdraw,11,39, '/', 1);
            mvwvline(wdraw,12,38, '/', 1);
            mvwvline(wdraw,13,37, '/', 1);
            wrefresh(wdraw);
            break;
        case 2:
            mvwvline(wdraw,11,41, '\\', 1);
            mvwvline(wdraw,12,42, '\\', 1);
            mvwvline(wdraw,13,43, '\\', 1);
            wrefresh(wdraw);
            break;
        case 1:
            mvwvline(wdraw,15,39, '/', 1);
            mvwvline(wdraw,16,38, '/', 1);
            mvwvline(wdraw,17,37, '/', 1);
            wrefresh(wdraw);
            break;
        case 0:
            mvwvline(wdraw,15,41, '\\', 1);
            mvwvline(wdraw,16,42, '\\', 1);
            mvwvline(wdraw,17,43, '\\', 1);
            wrefresh(wdraw);
            break;
    }
}
