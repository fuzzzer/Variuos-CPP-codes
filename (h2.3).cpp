#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
#include "queue.h"
#include "stack.h"

using namespace std;

string tagName(string str){
	for(int i=0; i<str.length(); i++){
		if(str[i] == '<') {
			return str.substr(0, i+1);
		}
	}
	return "";
}


string nextNonSpace(string str){
	for(int i=0; i<str.length(); i++){
		if(str[i] != ' ') {
			return str.substr(i, str.length() - i);
		}
	}

	return "npos";
}




bool IsCorrectlyNested(string htmlStr){
	Stack<string> st;

	TokenScanner scanner(htmlStr);
	scanner.ignoreWhitespace();
	scanner.addWordCharacters("/!=-_");
	string last = "";
	while(scanner.hasMoreTokens()){
		string curr = scanner.nextToken();

		cout << curr << endl;
		if(last == "<"){
			if(curr[0] != '/'){
				st.push(curr);
			} else {
				string toBeClosed = st.pop();
				if(toBeClosed != curr.erase(0,1)) return false;

			}	
		}
		last = curr;
	}

	return true;



}


int main(){

	string test = "<html> <b> <i>CS106 rules!</i> </b></html><alfa> <alfa> </beta>";

	if(IsCorrectlyNested(test))
		cout << "correct" << endl;
	else cout << "false" << endl;


	

	return 0;
}
