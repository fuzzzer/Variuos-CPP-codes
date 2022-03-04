
#include <iostream>
#include "random.h"
#include "simpio.h"
#include "console.h"
using namespace std;

int trials = 1000;

void Randomize(){

}

int errors(int &voters, double &votingError){
	int result = 0;

	for(int i=0; i<voters; i++){
		if(randomChance(votingError)) result++;
	}

	return result;
}


bool doOneSimulation(int &voters, double &percentageDifferance, double &votingError){// returns ture if there was an error
	int firstVoters = voters * (0.5 + percentageDifferance);
	int secondVoters = voters * (0.5 - percentageDifferance);

	int errorsOfFirstVoters = errors(firstVoters, votingError);
	int errorsOfSecondVoters = errors(secondVoters, votingError);
	
	firstVoters += (errorsOfSecondVoters - errorsOfFirstVoters);
	secondVoters += (errorsOfFirstVoters - errorsOfSecondVoters);


	if(secondVoters > firstVoters) return true;
	

	return false;
}


double doSimulation(int &voters, double &percentageDifferance, double &votingError){
	double outcome = 0.0;

	for(int i=0; i<trials; i++){
		if(doOneSimulation(voters, percentageDifferance, votingError)) outcome += 1.0;
	}

	outcome =(double) outcome / trials;

	return outcome;
}

void console(){
	int voters = getInteger("Enter number of voters: ");


	double percentageDifferance = -1;
	while ( 0 > percentageDifferance || percentageDifferance > 1 ) {
	percentageDifferance = getReal("Enter percentage spread between candidates: ");
	cout << percentageDifferance << endl;
	} 
	

	double votingError = -1;
	while ( 0 > votingError || votingError > 1 ) {
	votingError = getReal("Enter voting error percentage: ");
	} 

	double simulationResult = doSimulation(voters, percentageDifferance, votingError);

	cout << "Chance of an invalid election result after 500 trials = " << simulationResult * 100 << "%" << endl;

}



int maintemp() {
	console();
    return 0;
}


