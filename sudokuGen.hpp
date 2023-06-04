#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define UNASSIGNED 0

class Sudoku {
private:
  int grid[9][9];
  int solnGrid[9][9];
  int guessNum[9];
  int gridPos[81];
  int difficultyLevel;
  bool grid_status;
  
  // random device sets seed for rng
  std::mt19937 rng{std::random_device{}()};
  void clearGrid();
  void fillEmptyDiagonalBox(int);
  void createSeed();
  bool solveGrid();
  void countSoln(int &number);
public:
  Sudoku ();
  Sudoku (std::string, bool row_major=true);
  static bool isRightSolved(std::string puzzle, bool row_major);
  void printGrid();
  std::string getGrid();
  void genPuzzle();
  bool verifyGridStatus();
  void printSVG(std::string);
  int  calculateDifficulty();
  int  branchDifficultyScore();
};
