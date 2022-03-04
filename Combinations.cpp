/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <cmath>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
#include "hashmap.h"

using namespace std;

Vector<int> lastLine;
HashMap<int, Vector<int>> lines;
int N;


string ind(Vector<int> line, int spaces){
	int spacesInFront = N/2 + ceil((double)N/2) * spaces - line.size()/2 - ceil((double)line.size()/2) * spaces ;
	if(line.size() % 2 == 1) spacesInFront++;
	if(line.size() == N) spacesInFront -= 1;
	string result = "";


	for( int i = 0 ; i<spacesInFront ; i++){
		result +=" ";
	}

	for( int i = 0 ; i<line.size() ; i++){
		string temp = integerToString(line[i]);
		int spaceCounts = temp.length();

		if(line.size() == N+1 && i == 0){
		 
		} else {
			for(int j=0; j<spaces-spaceCounts ; j++){
			
			 temp = " " + temp;
		 }
		}
		result += temp + " ";
	}
	return result;

}

void printMap(){

		string temp = integerToString(lines.get(N).get((N)/2));
		

		int spaceCounts = temp.length();
		

		for(int i=0 ; i<lines.size(); i++){
			cout << ind(lines.get(i), spaceCounts) << endl;

		}
	
	
}

void updatelastLine(int currentLineCoefficient){
	Vector<int> currentLine;

	if(currentLineCoefficient == 0) {
		 currentLine.add(1);
	  } else {

		for(int i=0; i<=currentLineCoefficient; i++){
			int tempSum;

			if(i == 0) {
				tempSum = lastLine.get(0);

			} else if(i == currentLineCoefficient){
				tempSum = lastLine.get(currentLineCoefficient-1);

			} else{
				tempSum = lastLine.get(i-1) + lastLine.get(i);
			}

			currentLine.add(tempSum);
		}
	}
	
	lines.put(currentLineCoefficient, currentLine);
	lastLine.clear();
	lastLine = currentLine;

}

void setLine(int currentLineCoefficient, int n){

	updatelastLine(currentLineCoefficient);
	currentLineCoefficient++;

	if(currentLineCoefficient<=n){
		setLine(currentLineCoefficient, n);
	}

	
}


int findC(int n, int k){

	int currentLineCoefficient = 0;
	setLine(currentLineCoefficient, n);

	return lastLine.get(k);
}

int main() {
	N = getInteger("enter n for C(n,k): ");
	int K = getInteger("enter k for C(n,k): ");


    int CNK = findC(N, K);
	printMap();
	cout << "C(" << N << "," << K << ") is: " << CNK << endl;

	return 0;
}
