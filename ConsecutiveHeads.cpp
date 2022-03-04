/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

const int TRIALS = 500;
string desiredCombinaion;

Vector<int> useHForTrue(){
	

	desiredCombinaion = getLine("Enter desired combination, use H for heads and T for tails: ");
	desiredCombinaion = toUpperCase(desiredCombinaion);

	Vector<int> COMBINATION_TO_WIN;

	for(int i=0; i<desiredCombinaion.length(); i++){
		if(desiredCombinaion[i] == 'H'){
			COMBINATION_TO_WIN.add(1);
		} else if(desiredCombinaion[i] == 'T'){
			COMBINATION_TO_WIN.add(0);
		} else {
			useHForTrue();
		}
	}

	return COMBINATION_TO_WIN;
}

void Randomize(){

}

bool checkIfCombinationsMatch(Vector<int> vec1, Vector<int> vec2){
	if(vec1.size() != vec2.size()) return false;

	for(int i=0; i<vec1.size(); i++){
		if(vec1.get(i) != vec2.get(i)){
			return false;
		}
	}
	return true;
}


int oneGameSimulation(Vector<int> COMBINATION_TO_WIN){
	int countGames = 0;
	Vector<int> currentCombination;

	while(true){
		bool flip = randomChance(0.5);

		if(flip){
			
			currentCombination.add(1);
		} else {
			
			currentCombination.add(0);
		}

		
		countGames++;

		if(currentCombination.size() > COMBINATION_TO_WIN.size()){
			currentCombination.remove(0);	

		}

		if(checkIfCombinationsMatch(currentCombination, COMBINATION_TO_WIN)){
			
			break;
		}
	}
	return countGames;
}

int main() {
	Randomize();

	Vector<int> COMBINATION_TO_WIN = useHForTrue();

	int statistics = 0;
	for( int i=0; i<TRIALS; i++){

		statistics = statistics + oneGameSimulation(COMBINATION_TO_WIN);
	}

	statistics = statistics / TRIALS;

	cout << "average of flips needed is: "  << statistics << endl;


    return 0;
}
