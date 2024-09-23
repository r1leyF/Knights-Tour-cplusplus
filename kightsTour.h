#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int const BOARD_ROWS = 8;
int const BOARD_COLUMNS = 8;

class Board{
  //2d array to represent the chess board
  int board[BOARD_ROWS][BOARD_COLUMNS] = {{0}};

public : 

  //return the index at row and col
  int getIndex(int row, int col);

  //set the index are row and col
  void setIndex(int row, int col, int value);

  //print out all indices of board array
  void printBoard();

  //return false if any index of board is equal to 0
  bool finished();
};

class Space{ 
  //the position of this space
  int row;
  int col;
  //pointer to this space's board
  Board* board;

  //numbers to add to a spaces row and col to get all possible knight moves
  static constexpr int MOVE_MOD[16] = 
  {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};

  public:
  //default constructor
  Space(){}
  Space(int row, int col, Board* board){
    this -> row = row;
    this -> col = col;
    this -> board = board;
  }

  //return space's row
  int getRow(){
    return row;
  }

  //return space's col
  int getCol(){
    return col;
  }

  //adds all the valid moves this space can make to the given vector
  void getAllMoves(vector<Space>& spaces);

  //returns how many moves this space can make
  int getAllMoves();

  //returns true if space is on the board and has not been visted yet
  bool validMove();

  //return the move with the least possilbe moves
  Space getBestMove();
};