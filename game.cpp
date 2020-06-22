// For Windows Users:- Find and replace "clear" with "cls"

#include <iostream>

char board[3][3] = {
  {'-', '-', '-'},
  {'-', '-', '-'},
  {'-', '-', '-'}
};

void get_board() {
  std::cout << "\n";
  for(int row = 0; row < 3; row = row + 1) {
    for(int item = 0; item < 3; item = item + 1) {
      std::cout << board[row][item] << "\t";
    }
    std::cout << "\n\n";
  }
}

bool is_board_full() {
  int check = 0;
  for(int row = 0; row < 3; row = row + 1) {
    for(int item = 0; item < 3; item = item + 1) {
      if(board[row][item] != '-') {
        check = check + 1;
      }
    }
  }
  return (check == 9);
}

int check_victory(char player) {
  int victory = 0;
  if((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
    victory = victory + 1;
  }
  else if((board[2][0] == player) && (board[1][1] == player) && (board[0][2] == player)) {
    victory = victory + 1;
  }
  else {
    for(int check_row = 0; check_row < 3; check_row = check_row + 1) {
      if((board[check_row][0] == player) && (board[check_row][1] == player) && (board[check_row][2] == player)) {
        victory = victory + 1;
      }
    }
    for(int check_column = 0; check_column < 3; check_column = check_column + 1) {
      if((board[0][check_column] == player) && (board[1][check_column] == player) && (board[2][check_column] == player)) {
        victory = victory + 1;
      }
    }
  }
  return victory;
}

int main() {
  system("clear");
  get_board();
  int player_X1, player_X2, player_O1, player_O2;
  while(true) {
    std::cout << "Enter a position (Player X): ";
    std::cin >> player_X1 >> player_X2;

    if(board[player_X1 - 1][player_X2 - 1] == '-') {
      board[player_X1 - 1][player_X2 - 1] = 'X';
    }
    else { std::cout << "Invalid Move!" << std::endl; }

    system("clear");
    get_board();
    if(check_victory('X')) { std::cout << "Player X Wins!" << std::endl; break; }
    if(is_board_full()) { std::cout << "Both of you win!" << std::endl; break; }

    std::cout << "Enter a position (Player O): ";
    std::cin >> player_O1 >> player_O2;
    if(board[player_O1 - 1][player_O2 - 1] == '-') {
      board[player_O1 - 1][player_O2 - 1] = 'O';
    }
    else { std::cout << "Invalid Move!" << std::endl; }

    system("clear");
    get_board();
    if(check_victory('O')) { std::cout << "Player O Wins!" << std::endl; break; }
    if(is_board_full()) { std::cout << "Both of you win!" << std::endl; break; }
  }

  return 0;
}
