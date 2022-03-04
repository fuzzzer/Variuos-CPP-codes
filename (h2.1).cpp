
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

struct eMailMsg{
	Vector<string> to;
	string from;
	string message;
	string subject;
	int date;
	int time;
}

Vector<eMailMsg> myMail;

void RemoveSpam(Vector<eMailMsg> &myMail){
	for(int i=0; i<myMail.size(); i++) {
		if(startsWith(myMail.get(i).subject, "SPAM") {
			myMail.remove(i);
			i--;
		}
	}

	string lastOne = myMail.to.get(myMail.to.size() - 1);
}

void ReverseQueue(Queue<int> & q){

	Stack<int> stack;

	while(q.size() > 0){
		stack.push(q.dequeue());
	}

	while(stack.size() > 0){
		q.enqueue(stack.pop());
	}
}

bool IsCorrectlyNested(string htmlStr)

}