#include "bordle.h"


int main(int argc, char* argv[]){
    std::string playerName;
    std::cout << "Enter player name: ";
    std::cin >> playerName;
    Player curPlayer = Player(playerName);
    Board defaultBoard = Board();
    curPlayer.set_word_size(5);
    curPlayer.set_lives(defaultBoard.get_num_rows());
    defaultBoard.display_board();

    int gameOver = 0;
    while(!gameOver){
        if(curPlayer.get_lives_remaining() < 1){
            gameOver = 1;
            std::cout<<"GAME OVER"<<std::endl;
            continue;
        }
        std::string guess = curPlayer.take_turn();
        if(!defaultBoard.check_answer(guess)){
            curPlayer.decrement_lives();
            defaultBoard.fill_row();
        }
        else{
            gameOver = 1;
            std::cout<<"CORRECT ANSWER"<<std::endl;
            std::cout<<"GAME OVER"<<std::endl;
            continue;
        }

    }

    return 1;
}