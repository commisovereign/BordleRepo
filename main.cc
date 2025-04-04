#include "bordle.h"
#include <iostream>


int main(int argc, char* argv[]){
    std::string playerName;
    std::cout << "Enter player name: ";
    std::cin >> playerName;
    Player curPlayer = Player(playerName);
    Board defaultBoard = Board();
    curPlayer.set_lives(defaultBoard.get_num_rows());
    curPlayer.get_lives_remaining();
    defaultBoard.display_board();
    return 1;
}