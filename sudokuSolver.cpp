#include<bits/stdc++.h>
using namespace std;

bool findEmptyLocation(int board[][9], int &row, int &col){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int board[][9], int row, int num){
    for(int i=0; i<9; i++){
        if(board[row][i]==num){
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int board[][9], int col, int num){
    for(int i=0; i<9; i++){
        if(board[i][col]==num){
            return false;
        }
    }
    return true;
}


bool isSafeInBoard(int board[][9], int row, int col, int num){
    int rowFactor= row- (row%3);
    int colFactor= col- (col%3);
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+rowFactor][j+colFactor]==num){
                return false;
            }
        }
    }
    return true;
}


bool isSafe(int board[][9], int row, int col, int num){
    if(isSafeInRow(board,row,num) && isSafeInColumn(board,col,num) && isSafeInBoard(board,row,col,num)){
        return true;
    }
    return false;
}


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row,col;
    if(!findEmptyLocation(board,row,col)){
        return true;
    }
    for(int i=1; i<=9; i++){
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(sudokuSolver(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;


}
int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }       
  }
  if(sudokuSolver(board)){
    cout << "true"; 
  }else{
    cout << "false";    
  }
}
