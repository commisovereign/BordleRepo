#include "bordle.h"
#include <string>
#include <random>
using namespace std;

//default board of size 6x5
Board::Board(){
    numRows = 6;
    numCols = 5;
    curRow = 0;
    fileName = "allFiveLetterWords.txt";
    previousGuesses;
    set_cur_word();
    currentWord = get_cur_word();
    create_letters();
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

void Board::create_letters(void){
    std::map <char, int> tempLetterMap;
    char letter = 'a';
    for(int i = 0; i < 26; i++){
        letterMap[letter] = 1;
    }
    if (currentWord.length()){
        for(int i = 0; i < currentWord.length(); i++){
            if(tempLetterMap[i]){
                tempLetterMap[i]++;
            }
            else{
                tempLetterMap[i] = 1;
            }
        }

    }
}

int Board::check_answer(std::string guess){
    //player guesses correct answer
    if(guess == currentWord){
        return 1;
    }

    std::map <char, int> guessLetterMap;
    for(int i = 0; i < guess.length(); i++){
        if(guessLetterMap[i]){
            guessLetterMap[i]++;
        }
        else{
            guessLetterMap[i] = 1;
        }
    }

/*   for(auto i : guessLetterMap){

    }*/
   return 0;

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
void Player::decrement_lives(){
    livesRemaining--;
}
void Player::set_word_size(int wordLength){
    wordSize = wordLength;
}
std::string Player::take_turn(){
    std::string playerGuess;
    while(playerGuess.length() == 0){
        std::cout<<"Your Guess: ";
        std::cin>>playerGuess;
        std::cout<<endl;
        if(playerGuess.length() != wordSize){
            playerGuess = "";
            std::cout<<"Please enter only "<<wordSize<<" characters"<<endl;
            continue;
        }
        //have to add other checkers to ensure that already crossed out letters
        //and non-alphabet characters are not allowed either 
    }
    return playerGuess;
}

void Board::fill_row(){
    for(int j = 0; j < numCols; j++){
        std::cout << " _ ";
    }
    std::cout << std::endl; 
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){            
            if(previousGuesses.size() > i){
                std::cout << "|"<<previousGuesses[i][j]<<"|";
            }
            else{
                std::cout << "|_|";
            }
        }
        std::cout << std::endl; 
    }

}