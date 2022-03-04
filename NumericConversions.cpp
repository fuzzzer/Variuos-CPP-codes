/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);



string convertToStringLast(int n, string word){
	int last = n % 10;
	n = n / 10;
	char lastOneChar = char(last + '0');
	word = lastOneChar + word;
	if(n != 0){
		word = convertToStringLast(n, word);
	} 
	return word;
}


string intToString(int n){
	string word = "";

	word = convertToStringLast(n, word);
	return word;
}

int convertToIntFirst(string str, int n){
	int first = str[0] - '0';
	n = n * 10 + first;
	
	if(str.length() != 1){
		str = str.substr(1, str.length() - 1);
	} else { 
		str = "";
	}
	
	if(str != "" ) n = convertToIntFirst(str, n);
	

	return n;
}

int stringToInt(string str){
	int n = 0;

	n = convertToIntFirst(str, n);

	return n;

}

int main() {
    cout << intToString(0) << endl;
    return 0;
}
