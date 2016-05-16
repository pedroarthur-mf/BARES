#include <iostream>


#include "stackar.h"
#include "queuear.h"

class Operation{
 private:

 	//QueueAr<Token> operation;
 	struct element{
 		std::string symbol;
 		int col;
 	};
 	element e; // auxiliar to compare
 	QueueAr<element> token;
 	StackAr<element> _symbol;
 	QueueAr<element> posfix;
 	StackAr<int> calc;

 	int result;

 	int weight(std::string);
 	bool term(char);
 	bool expresion(char);
 	bool number(char);
 	int changetonumber(std::string);
 	void printtoken ();

 public:

 	Operation();
 	~Operation();

 	bool tokenize (std::string);
 	void makeposfix ();
 	bool calculation ();
 	int getresult();

};


#include "operation.inl"