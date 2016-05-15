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
 	StackAr<element> calc;

 	int sizetoken;

 	int weight(std::string);
 	bool term(char);
 	bool expresion(char);
 	bool number(char);
 	int changetonumber(std::string);
 	

 public:

 	Operation();
 	~Operation();
 	void printtoken ();
 	bool tokenize (std::string);
 	bool makeposfix ();
 	
 	/*inline std::ostream &operator<<(std::ostream &_os, const QueueAr &_term) {
    return _os << "\"" << _term.symbol << "\"";
	}*/
};


#include "operation.inl"