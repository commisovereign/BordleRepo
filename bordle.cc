#include "bordle.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//default board of size 6x5
Board::Board(){
    numRows = 6;
    numCols = 5;
    curRow = 0;
}

int Board::get_num_rows(){
    return this->numRows;
}
void Board::display_board(void){
    for(int j = 0; j < numCols; j++){
        std::cout << " _ ";
    }
    std::cout << std::endl; 
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            std::cout << "|_|";
        }
        std::cout << std::endl; 
    }
}

Player::Player(std::string playerName){
    playerName = playerName;
    livesRemaining = Board::get_num_rows();

    cout<<"Lives Remaining for "<< playerName<<": "<< livesRemaining<<endl;
}