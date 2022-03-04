

#include "grid.h"
#include "console.h"
#include "random.h"


int neigborhoodSize = 0;// shows how far does neighborhood strech

void Randomize(){
}

void printBoolGrid(Grid<bool> board){
	for(int i=0; i<board.numCols(); i++){
		for(int j=0; j<board.numRows(); j++){
			int temp = 0;
			if(board.get(i,j)) temp = 1;
				cout << temp << " " ;
		}
		cout << " " << endl;
	}
}

void printIntGrid(Grid<int> board){
	for(int i=0; i<board.numCols(); i++){
		for(int j=0; j<board.numRows(); j++){
			cout << board.get(i,j) << " " ;
		}
		cout << " " << endl;
	}
}

void setEnd(int & lineCoefficient, int & toSet, int limit){

	if(lineCoefficient < limit - 1 - neigborhoodSize){ 
		toSet = lineCoefficient + neigborhoodSize + 1;
	} else {
		toSet = limit - 1;
	}
}

void setStart(int & lineCoefficient, int & toSet){

	if(lineCoefficient > neigborhoodSize){ 
		toSet = lineCoefficient - neigborhoodSize - 1;
	} else {
		toSet = 0;
	}
}


void addOneToAdjacents(Grid<int> & result,int row,int column){

	int startingRow;
	int endingRow;
	int startingColumn;
	int endingColumn;

	setStart(row, startingRow);
	setStart(column, startingColumn);
	setEnd(row, endingRow, result.numRows());
	setEnd(column, endingColumn, result.numCols());

	for(int i=startingRow; i<=endingRow; i++){
		for(int j=startingColumn; j<=endingColumn; j++){
			int newCoefficient = result.get(i, j) + 1;
			result.set(i, j, newCoefficient);
		}
	}
}


Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations){
	Grid<int> result(bombLocations.numRows(), bombLocations.numCols());

	for(int i=0; i<bombLocations.numRows(); i++){
		for(int j=0; j<bombLocations.numCols(); j++){
			if(bombLocations.get(i,j)) addOneToAdjacents(result, i, j);
		}
	}
	return result;
}

Grid<bool> arrangeBombs(int n, int m, int numberOfBombs){
	Grid<bool> board(n,m);


	for(int i=0; i<numberOfBombs; i++){
		int rowToPutBomb = randomInteger(0, n-1);
		int columnToPutBomb = randomInteger(0, m-1);

		if(board.get(rowToPutBomb, columnToPutBomb) != true){
			board.set(rowToPutBomb, columnToPutBomb, true);
		} else {
			i--;
		}
	}
	return board;
}


int main(){
	Randomize();

	Grid<bool> board = arrangeBombs(6, 6, 10);
	Grid<int> numberOfBombs = MakeGridOfCounts(board);

	printIntGrid(numberOfBombs);
	cout << "----------------" << endl;
	printBoolGrid(board);

	return 0;
}

