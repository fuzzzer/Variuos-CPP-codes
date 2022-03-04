
#include <iostream>
#include "simpio.h"
#include "strlib.h"
#include "console.h"
#include "tokenscanner.h"
#include "strlib.h"
using namespace std;



void CensorString2(string &text, string remove){
	
	for(int i=0; i<text.length(); i++){
		for(int j=0; j<remove.length(); j++){
			if(text[i] == remove[j]) {
				text.erase(i, 1);
				i--;
				break;
			}
		}
	}
}


string CensorString1(string text, string remove){
	string result = "";
	for(int i=0; i<text.length(); i++){
		bool toRemove = false;
		for(int j=0; j<remove.length(); j++){
			if(text[i] == remove[j]) {
				toRemove = true;
				break;
			}
		}
		if(!toRemove) {
			char curr = text[i];
			result = result + curr;
		}
	}
	return result;
}

int main(){
	string a = getLine("enter word:");
	string b = getLine("enter forbidden characters: ");
	a = CensorString1(a, b);
	cout << a << endl;
	return 0;
}


