#include "bordle.h"
#include <string>
#include <vector>
#include <random>
using namespace std;

//default board of size 6x5
Board::Board(){
    numRows = 6;
    numCols = 5;
    curRow = 0;
    fileName = "allFiveLetterWords.txt";
    set_cur_word();
    currentWord = get_cur_word();
    //create_letters();
    std::cout<<currentWord<<std::endl;
}
void Board::set_cur_word(){
    //uses current time as a seed in order to generate a random int
    std::srand(time(0));
    int numOfWords = get_file_lines();
    int wordIndex = std::rand() % numOfWords;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
        return;
    }
    int curLine = 0;    
    while(std::getline(file, currentWord)){
        if(curLine == wordIndex){
            file.close();
            break;
        }
        curLine++;
    }
    file.close();
}
int Board::get_file_lines(){
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
        return -1;
    }
    int lineCount = 0;
    std::string line;
    while(std::getline(file, line)){
        lineCount++;
    }
    file.close();
    return lineCount;
}
std::string Board::get_cur_word(){
    return currentWord;
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
}

void Player::set_lives(int lives){
    livesRemaining = lives;
}

int Player::get_lives_remaining(){
    std::cout<<"Lives Remaining for "<< playerName<<": "<< livesRemaining<<endl;
    return livesRemaining;
}

