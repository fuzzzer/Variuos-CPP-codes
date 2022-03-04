
#include <iostream>
#include <fstream>
#include "simpio.h"
#include "strlib.h"
#include "console.h"
#include "tokenscanner.h"
#include "strlib.h"
#include "math.h"
#include "hashmap.h"
using namespace std;




void printLetters(HashMap<char, int> &letters){
	for(char i='a'; i<='z'; ++i){
		cout << i << ": " << letters.get(i) << endl;
	}
}

void initializeLetters(HashMap<char, int> &letters){
	for(char i='a'; i<='z'; i++){
		letters.put(i, 0);
	}
}


void countLetters(string name, HashMap<char, int> &letters){

	ifstream inh;


	while(true){
	inh.open(name.c_str());
	if(!inh.fail()) break;
	inh.close();
	}

	if(!inh.fail()){


	TokenScanner sc(inh);
	sc.ignoreWhitespace();

	int count = 0;

	while(sc.hasMoreTokens()){
		string word = sc.nextToken();
		for(int i=0; i<word.length(); i++){
			string temp;
			temp += word[i];
			temp = toLowerCase(temp);
			char current = temp[0];
			int save = letters.get(current) + 1;
			letters[current] = save;
		}
	}
	}
}



int main(){
	HashMap<char, int> letters;
	initializeLetters(letters);
	countLetters("text.txt", letters);
	printLetters(letters);

	return 0;
}