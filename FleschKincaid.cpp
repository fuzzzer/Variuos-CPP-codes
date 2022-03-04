/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;

const double C0 = -15.59;
const double C1 = 0.39;
const double C2 = 11.8;


bool containsSentenceMark(string word){
	for(int i=0; i < word.length(); i++){
		char k = word[i];
		if(k == '!' || k == '.' || k == '?') return true;
	}

	return false;
}

int sylInWord(string word){
	int result = 0;
	bool prev = false;
	for(int i=0; i < word.length(); i++){
		char k = word[i];
		if(k == 'a' || k == 'o' || k == 'u' || k == 'i' || ( i != word.length()-1 && k == 'e')){
			if(prev == false) result++;
			prev = true;
		} else {
			prev = false;
		}
	}

	if(result == 0) result = 1;

	return result;
}



void countNumbers(ifstream &inh, int &numSentences, int &numWords, int &numSyl){
	TokenScanner sc(inh);
	sc.ignoreWhitespace();
	sc.addWordCharacters(".!',?-_#");
	while(sc.hasMoreTokens()){
		string word = sc.nextToken();
		numWords++;
		if(containsSentenceMark(word)) numSentences++;
		numSyl = numSyl + sylInWord(word);
	}
}


int main() {
	ifstream inh;

	while(true){
		cout<< "Enter file name: ";
		string name = getLine();
		inh.open(name.c_str());
		if(!inh.fail()) break;
		cout << "couldn't open file try again!"<< endl;
		inh.close();
	}

	int numSentences = 0;
	int numWords = 0;
	int numSyl = 0;

	countNumbers(inh, numSentences, numWords, numSyl);

	if(numSentences == 0) numSentences++;
	if(numWords == 0) numWords++;

	double grade = C0 + C1 * ((double)numWords / numSentences) + C2 * ((double) numSyl / numWords);

	cout << "numWords: " << numWords << " |numSent: " << numSentences << " |numSyl: " << numSyl << " |grade: " << grade << endl;

	inh.close();

    return 0;
}	 
