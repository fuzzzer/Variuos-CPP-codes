#include <iostream>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;


Vector<string> initials;

void setup(){
	initials.add("AEIOUHWY");
	initials.add("BFPV");
	initials.add("CGJKQSXZ");
	initials.add("DT");
	initials.add("MN");
	initials.add("L");
	initials.add("R");
}

string clean(string &word){
	char firstChar = word[0];
	string result;
	result += word[0];

	for(int i=1; i<word.length(); i++){
		if(word[i] != '0' && word[i] != word[i-1]) result += word[i];
	}
	cout << result << endl;

	if(result.length() < 4) {
		int length = result.length();
		for(int i=0; i<4-length; i++){
			result += '0';
		}
	}
	return result;
}

int findCoefficient(char ch){
	for(int i=0; i<initials.size(); i++){
		for(int j=0; j<initials.get(i).length(); j++){
			if(ch == initials.get(i)[j]) return i;
		}
	}
	return -1;
}


string process(string &word){

	word = toUpperCase(word);
	char firstChar = word[0];
	string result;
	result += firstChar;

	for(int i=1; i<word.length(); i++){
		int coefficient = findCoefficient(word[i]);
		result += integerToString(coefficient);
	}
	
	result = clean(result);

	return result;
}

int main(){
	setup();

	while(true){
		string word = getLine("Enter surname (RETURN to quit): ");
		if(word == "") break;
		string soundex = process(word);
		cout << "Soundex code for " + word + " is " << soundex << endl;
	}

	return 0;
}