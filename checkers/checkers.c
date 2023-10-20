#pragma warning(disable : 4996) //Use this only in Visual Studio
#include <stdio.h>
#include <stdlib.h>

//#include <unistd.h>
#include <stdbool.h>
//function for print the current statements of board
#define rows 9
#define cols 9
void makeboard(char board[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i >= 2 && i <= 3) && (j >= 1 && j <= cols)) {
                board[i][j] = '*';
            } else if ((i >= 6 && i <= 7) && (j >= 1 && j <= cols)) {
                board[i][j] = '-';
            } else if (i == 0 ) {
                board[i][j] = j+ '0';
            } else if (j == 0 ) {
                board[i][j] = i+ '0';    
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void makeboardKingTest(char board[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i >= 2 && i <= 3) && (j >= 1 && j <= cols)) {
                board[i][j] = ' ';
            }
            else if ((i >= 6 && i <= 7) && (j >= 1 && j <= cols)) {
                board[i][j] = ' ';
            }
            else if (i == 0) {
                board[i][j] = j + '0';
            }
            else if (j == 0) {
                board[i][j] = i + '0';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    board[2][2] = 'A';
}


void printboard(char board[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void movepawn(char board[100][100], int k, int l, char movement, char currentplayer) {
  switch (movement) {

    case 'w':
      if (k-1<8){
      board[k][l]=' ';
      if(currentplayer=='b'){
      //a can move if king
      if(board[k-1][l]=='*'){
        if (k==2){
          board[k-1][l]= ' ';
          board[k-2][l]='B';
        }
        else{
          board[k-1][l]= ' ';
          board[k-2][l]='-';
          }
        }
        else{
        board[k-1][l]='-';
        }
      }
    }
      else{
        printf("Please enter a valid move:\n");
      }
      break;
      
    case 'a':
    if (l-1>=0){
      board[k][l]=' ';
      if(currentplayer=='a'){
        if(board[k][l-1]=='-'){
          board[k][l-1]= ' ';
          board[k][l-2]='*';
        }
       else{
      board[k][l-1]='*';
      }
      }
      if(currentplayer=='b'){
      if (board[k][l-1]=='*'){
          board[k][l-1]= ' ';
          board[k][l-2]='-';
        }
      else{
        board[k][l-1]='-';
      }
    }
    }
      else{
        printf("Please enter a valid move:\n");
      }
      break;

case 's':
    if (k + 1 < 8) {
        board[k][l] = ' ';
        if(currentplayer=='a'){
        //b can move if king
      if(board[k+1][l]=='-'){
        if(k==6){
          board[k+1][l]= ' ';
          board[k+2][l]='A';
        }
        else{
          board[k+1][l]= ' ';
          board[k+2][l]='*';
          }
        }
        else{
        board[k+1][l]='*';
        }
    } 
    }
    else {
        printf("Please enter a valid move:\n");
    }
    break;


    case 'd':
    if(l+1<8){
      board[k][l]=' ';
      if(currentplayer=='a'){
        if(board[k][l+1]=='-'){
          board[k][l+1]= ' ';
          board[k][l+2]='*';
        }
       else{
      board[k][l+1]='*';
      }
      }
      if(currentplayer=='b'){
      if (board[k][l+1]=='*'){
          board[k][l+1]= ' ';
          board[k][l+2]='-';
        }
      else{
        board[k][l+1]='-';
      }
    }
    }
      else {
        printf("Please enter a valid move:\n");
      }
      break;

  }
  }
bool isvalidmove(char board[100][100], int k, int l, int coordinate, char moveDirection) {
    if (moveDirection == 'x') {
        if (coordinate > l) {
            for (int i = l; i <= coordinate; i++) {
                if (board[k][i] != ' ') {
                    return false;
                }
            }
            return true;
        } else if (coordinate < l) {
            for (int i = l; i >= coordinate; i--) {
                if (board[k][i] != ' ') {
                    return false;
                }
            }
            return true;
        }
    } else if (moveDirection == 'y') {
        if (coordinate > k) {
            for (int j = k; j <= coordinate; j++) {
                if (board[j][l] != ' ') {
                    return false;
                }
            }
            return true;
        } else if (coordinate < k) {
            for (int j = k; j >= coordinate; j--) {
                if (board[j][l] != ' ') {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

  void kingmove(char board[100][100], int k, int l, char moveDirection, char currentplayer) {
    int coordinate;

    if (moveDirection == 'x') {
        printf("Enter the x coordinate: ");
        scanf("%d", &coordinate);
        if (isvalidmove(board, k, l, coordinate,moveDirection)) {
            board[k][l] = ' ';
            if (currentplayer == 'a') {
                board[k][coordinate] = 'A';
            } else if (currentplayer == 'b') {
                board[k][coordinate] = 'B';
            }
        }
    } else if (moveDirection == 'y') {
        printf("Enter the y coordinate: ");
        scanf("%d", &coordinate);
        if (isvalidmove(board, k, l, coordinate, moveDirection)) {
            board[k][l] = ' ';
            if (currentplayer == 'a') {
                board[coordinate][l] = 'A';
            } else if (currentplayer == 'b') {
                board[coordinate][l] = 'B';
            }
        }
    } else {
        printf("Invalid move direction for 'A'. Please use 'x' or 'y'.\n");
        return; 
    }
}
int main(){
    char board[100][100];
    int k, l;
    char pressedbutton;
    char moveDirection;
    
    char currentplayer = 'a';
    makeboard(board);
    while (1) {
        printboard(board);
        printf("Player %c's turn\n", currentplayer);
        printf("Which pawn do you want to move? Write the coordinates\n");
        scanf("%d%d", &k, &l);
        printf("k:%d l:%d \n", k, l);
        if (currentplayer == 'a' && board[k][l] == 'A') {
            printf("Which coordinate do you want to move (x or y)? ");
            scanf(" %c", &moveDirection);
            kingmove(board, k, l, moveDirection, currentplayer);
        } else if (currentplayer == 'b' && board[k][l] == 'B') {
            printf("Which coordinate do you want to move (x or y)? ");
            scanf(" %c", &moveDirection);
            kingmove(board, k, l, moveDirection, currentplayer);
        }  else {
            printf("Where do you want to move? use wasd\n");
            scanf(" %c", &pressedbutton);
            movepawn(board, k, l, pressedbutton, currentplayer);
        }
        currentplayer = (currentplayer == 'a') ? 'b' : 'a';
        system("clear");
    }
    return 0;
}