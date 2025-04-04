#ifndef BORDLE_H_
#define BORDLE_H_
#include <string>


class Player:
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
    public:
        Board();
        Board(std::string currentWord);
        Board(int numRows, int numCols);
        Board(std::string currentWord, int numRows, int numCols);
        
        int get_num_rows();
        //std::string attempt_answer();

        void fill_row();

        int check_answer();

        void display_board();

};

class GamePlay
{
    private:
        

    public:
        void available_letters();
        void crossOutLetters();
};

#endif