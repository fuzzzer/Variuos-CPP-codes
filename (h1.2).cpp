
#include <iostream>
#include <fstream>
#include "simpio.h"
#include "strlib.h"
#include "console.h"
#include "tokenscanner.h"
#include "strlib.h"
#include "math.h"
using namespace std;



struct statistics{
	int min;
	int max;
	int avg;
};

string toString(statistics alfa){
	string result = "avg = " +  integerToString(alfa.avg);
	result = result + " min = " + integerToString(alfa.min);
	result = result + " max = " + integerToString(alfa.max);
	return result;
}


statistics computeStatistics(){

	ifstream inh;


	while(true){
	cout << "enter file name: ";
	string name = getLine();
	inh.open(name.c_str());
	if(!inh.fail()) break;
	cout << "please enter valid name!" << endl;
	inh.close();
	}

	TokenScanner sc(inh);
	sc.ignoreWhitespace();


	statistics result;
	result.avg=0;
	result.max=0;
	result.min=101;

	cout << toString(result) << endl;

	
	int count = 0;

	while(sc.hasMoreTokens()){
		int score = stringToInteger(sc.nextToken());
		if(score > result.max) result.max = score;
		if(score < result.min) result.min = score;
		result.avg += score;
		count++;
	}

	result.avg = result.avg / count;

	return result;
}




int main(){
	statistics currentStatistics = computeStatistics();

	cout << toString(currentStatistics) << endl;
	return 0;
}