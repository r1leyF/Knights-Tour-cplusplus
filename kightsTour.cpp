#include "kightsTour.h"

int Board::getIndex(int row, int col) { return board[row][col]; }

// set the index are row and col
void Board::setIndex(int row, int col, int value) { board[row][col] = value; }

// print out all indices of board array
void Board::printBoard() {
  for (int i = 0; i < BOARD_ROWS; ++i) {
    for (int j = 0; j < BOARD_COLUMNS; ++j) {
      cout << setw(4) << board[i][j];
    }
    cout << "\n\n";
  }
}

// return false if any index of board is equal to 0
bool Board::finished() {
  for (int i = 0; i < BOARD_ROWS; ++i) {
    for (int j = 0; j < BOARD_COLUMNS; ++j) {
      if (board[i][j] == 0)
        return false;
    }
  }
  return true;
}

// adds all the valid moves this space can make to the given vector
void Space::getAllMoves(vector<Space> &spaces) {
  spaces.clear();

  for (int i = 0; i < 16; i += 2) {
    Space s = Space(row + MOVE_MOD[i], col + MOVE_MOD[i + 1], board);

    if (s.validMove())
      spaces.push_back(s);
  }
}

// returns how many moves this space can make
int Space::getAllMoves() {
  int moves = 0;

  for (int i = 0; i < 16; i += 2) {
    Space s = Space(row + MOVE_MOD[i], col + MOVE_MOD[i + 1], board);

    if (s.validMove())
      ++moves;
  }
  return moves;
}

// returns true if space is on the board and has not been visted yet
bool Space::validMove() {
  // if space is not on board return false
  if (row < 0 || row > BOARD_ROWS - 1 || col < 0 || col > BOARD_COLUMNS - 1)
    return false;

  // if space has been visted by knight before return false
  if (board->getIndex(row, col) != 0)
    return false;

  // if space is on the board and has not been vistied return true
  return true;
}

// return the move with the least possilbe moves
Space Space::getBestMove() {
  vector<Space> moves;
  getAllMoves(moves);
  Space bestMove;

  // intialize bestmove to the first possible move for comparison
  bestMove = moves[0];

  // loop through all possible moves
  for (Space move : moves) {
    // if move has less possible moves than bestmove make it bestmove
    if (move.getAllMoves() < bestMove.getAllMoves())
      bestMove = move;
    // if move and bestmove are equal randomly decide which is best
    else if (move.getAllMoves() == bestMove.getAllMoves()) {
      int rNum = rand() % 10;
      if (rNum < 5)
        bestMove = move;
    }
  }

  // after going through all moves return best move
  return bestMove;
}