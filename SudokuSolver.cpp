#include <iostream>
#define N 9
using namespace std;
int grid[N][N] = {
};
bool presentInCol(int col, int num){ 
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool presentInRow(int row, int num){ 
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool presentInBox(int boxStartRow, int boxStartCol, int num){
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ 
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool emptyPlace(int &row, int &col){ 
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) 
            return true;
   return false;
}
bool validPlace(int row, int col, int num){
   return !presentInRow(row, num) && !presentInCol(col, num) && !presentInBox(row - row%3 ,
col - col%3, num);
}
bool solveSudoku(){
   int row, col;
   if (!emptyPlace(row, col))
      return true; 
   for (int num = 1; num <= 9; num++){ 
      if (validPlace(row, col, num)){ 
         grid[row][col] = num;
         if (solveSudoku())
            return true;
         grid[row][col] = 0; 
      }
   }
   return false;
}
int main(){
	
	for(int i=0;i<N;i++){
		if(i>0)
			cout<<"Next row\n";
		for(int j=0;j<N;j++){
			cin>>grid[i][j];
			
		}
	}
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
    
}
