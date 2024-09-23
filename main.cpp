#include "kightsTour.h"

//prototype
void askForInput(int& startRow, int& startCol);

int main() {
  //intialize starting row and column for the knight
  int kStartRow = 5;
  int kStartCol = 1;

  //ask for user input to set starting postions
  askForInput(kStartRow, kStartCol);

  //create a board and a space the represents the knight
  Board board;
  Board* boardPoint = &board;
  Space knight = Space(kStartRow, kStartCol, boardPoint);

  //set a random seed for random move picking
  srand((unsigned) time(NULL));

  //set the board's index at the knight's postion to 1
  //thisis where the knight is starting
  board.setIndex(knight.getRow(), knight.getCol(), 1);

  //if a board could not finish create another board until a finished one is made
  while (!board.finished()){
    //loop through all the moves the knight will make
    for(int i = 2; i <= BOARD_ROWS*BOARD_COLUMNS; ++i){    

      //if knight encounts a deadend before completion break out loop and restart
      if(knight.getAllMoves() == 0){
        break;
      }

      //set the knight to the knight's best move
      knight = knight.getBestMove();  

      //set the board index at knight's new position to the move number
      board.setIndex(knight.getRow(), knight.getCol(), i);
    }
  }

  //prrint out header
  cout << "Knight's Tour\n***************\nStarting at row " << 
    kStartRow+1 << ", column " << kStartCol+1 << "\n\n"; 
  //print the final board
  board.printBoard();
}

void askForInput(int& startRow, int& startCol){
  cout << "Enter the knight's starting row 1-8: ";
  cin >> startRow;
  while(startRow > 8 || startRow < 1){
    cout << "Row out of board. Please enter a differnt row 1-8: ";
    cin >> startRow;
  }
  
  cout << "Enter the knight's starting column 1-8: ";
  cin >> startCol;
  while(startRow > 8 || startRow < 1){
    cout << "Column out of board. Please enter a differnt column 1-8: ";
    cin >> startCol;
  }

  cout << endl;
  startRow -= 1;
  startCol -= 1;
}