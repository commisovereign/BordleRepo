#ifndef BORDLE_H_
#define BORDLE_H_
#include <string>

namespace Bordle
{
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
            
            //std::string attempt_answer();
            
            void fillRow();

            int checkAnswer();

    };

}



#endif