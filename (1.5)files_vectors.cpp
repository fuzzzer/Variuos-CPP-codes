
#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
#include "vector.h"
using namespace std;



int maxNumber = 100;
int groupSize = 10;

Vector<int> scores;


void printGroups(Vector<Vector<int>> &groups){
	for(int i=0; i<groups.size(); i++){
		string currentPrint = integerToString(i*10) + "-" + integerToString((i+1)*10-1) + ": ";
		
		for(int j=0; j<groups.get(i).size(); j++){
			currentPrint += "X";
		}
		cout << currentPrint << endl;
	}

}

void createGroups(Vector<Vector<int>> &groups){
	for(int i=0; i < maxNumber/groupSize; i++){
		int current = i * 10;
		Vector<int> members;
		for(int j=0; j<scores.size(); j++){
			if((scores[j] / 10) * 10 == current) {
				cout<< "added: " << scores[j] << " to: " << current << endl;
				members.add(scores[i]);
			}

		}
		groups.add(members); 
	}
}

int storeLines(ifstream &inh){
	scores.clear();
	TokenScanner sc(inh);
	sc.ignoreWhitespace();

	while(sc.hasMoreTokens()){
	string word = sc.nextToken();
	int next = stringToInteger(word);
	scores.add(next);
	}

	return 0;
}


int main(){
	Vector<Vector<int>> groups;
	ifstream inh;

	while(true){
		cout<< "Enter file name: ";
		string name = getLine();
		inh.open(name.c_str());
		if(!inh.fail()) break;
		cout << "couldn't open file try again!"<< endl;
		inh.close();
	}

	storeLines(inh);
	createGroups(groups);
	printGroups(groups);

	inh.close();

	return 0;
}

