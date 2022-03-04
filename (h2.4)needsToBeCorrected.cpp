#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
#include "hashmap.h"
using namespace std;




char MostFrequentCharacter(ifstream &inh, int &numOccurrences){
	HashMap<char, int> map;
	
	while(true){
	char ch = inh.get();
	if(inh.fail()) break;
	if(map.containsKey(ch)) map[ch]++;
	else map.put(ch, 1);
	}

	char max;

	for(char curr : map.keys()){
		if(max != NULL){
			if(map[max] < map[curr]) max = curr;
		} else {
			max = curr;
		}
	}

	numOccurrences = map[max];

	return max;
}




int main(){

	ifstream inh;
	
	while(true){
		string name = getLine("enter file name");
		inh.open(name.c_str());
		if(!inh.fail()) break;
		inh.close();

	}

	int numOccurrences = 0;
	char ch = MostFrequentCharacter(inh, numOccurrences);

	cout << "famous char: " << ch << " is presented: " << numOccurrences << " times" << endl;




	return 0;
}