#ifndef BORDLE_H_
#define BORDLE_H_
#include <string>
#include <map>
#include <fstream>
#include <iostream>



class Player
{
    private:
        int livesRemaining;
        int gamesWon;
        int gamesLost;
        std::string playerName;
        
    public:
        Player();
        Player(std::string playerName);
        void set_lives(int lives);
        int get_lives_remaining(void);

        void decrement_lives(void);

};

class Board
{
    private:
        std::string currentWord;
        int numRows;
        int numCols;
        int curRow;
        std::string fileName;
        std::map <char, int> letterMap;

        //returns the length of the txt file containing all words of a specific length
        //as measured by the number of lines in the files
        int get_file_lines();

    public:
        Board();
        Board(std::string currentWord);
        Board(int numRows, int numCols);
        Board(std::string currentWord, int numRows, int numCols);
        
        int get_num_rows();
        //std::string attempt_answer();

        void set_cur_word();

        std::string get_cur_word();

        void fill_row();

        int check_answer();

        void display_board();

        void create_letters();

        void available_letters();

        void crossOutLetters();
};



#endif