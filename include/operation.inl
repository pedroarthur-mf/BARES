#include <iostream>
#include <cmath>

#include "stackar.h"
#include "queuear.h"

Operation::Operation(){
	this->e.symbol = " ";
	this->e.col = -1;
	//token (1);

}
Operation::~Operation(){
	this->e.symbol = " ";
	this->e.col = 0;
	//token (1);

}
// void Operation::printtoken(){
// 	this-> e = this->token.getFront();
// 	std::cout << "first element: " << this->e.symbol << std::endl;
// 	//std::cout << "size : " << this->sizetoken << std::endl;
// }

bool Operation::tokenize(std::string line){
	auto count = 0;
	int sizeline = line.size();
	auto dif = 0;
	auto parentcol = -1;

	while(count < sizeline){
		if (line[count] != 32 and line[count] != 9){
			if(number(line[count]) and number(e.symbol[0])) {
				std::cerr << "E4 "<< count+1 << std::endl;//Extraneous symbol
			  	return false;
			}
			else if(number(line[count])){
				this->e.col = count;
				this->e.symbol = line[count];

				while(number(line[count+1])){
			  		this->e.symbol += line[count+1];
			  		count++;
			  	}
			  	if (changetonumber(e.symbol) > 32768){
			  		std::cerr << "E1 "<< e.col+1 << std::endl;//Numeric constant out of range
			  		return false;
			  	}
			  	count++;
			}
			else if(line[count] == 45){ // see if is -
				int i = count+1;
				for(; (line[i] == 9 or line[i] == 32); i++);
				if(number(line[i])){
					this->e.col = count;
					this->e.symbol = line[count];
					count = i;
				}
				else{
					std::cerr << "E2 " << count+1 << std::endl;//Ill-formed expression or missing term detected
					return false;
				}
			}
			else if(line[count] == 43 or line[count] == 47 or line[count] == 42
				or line[count] == 94 or line[count] == 37 or line[count] == 37){ // see if is +, /, *, ^, %

				int i = count+1;
				for(; (line[i] == 9 or line[i] == 32); i++);
				if(!(number(e.symbol[0]) or e.symbol[0] == 41)){
					std::cerr << "E5 " << count+1 << std::endl;//Lost operator
					return false;
				}
				else if(!(term(line[i]))){
					std::cerr << "E2 " << i+1 << std::endl;//Ill-formed expression or missing term detected
					return false;
				}
				else{
					this->e.col = count;
					this->e.symbol = line[count];
					count = i;
				}
			}
			else if (line[count] == 40){//see if is (
				if((e.col == -1) or (term(e.symbol[0]))){
					this->e.col = count;
					this->e.symbol = line[count];
					count++;
					if(parentcol == -1)
						parentcol = e.col;
					dif ++;
				}
				else{
					std::cerr << "E4 "<< count+1 << std::endl;//Extraneous symbol
			  		return false;
			  	}
			}
			else if(line[count] == 41){//see if is )
				if(parentcol == -1){
					std::cerr << "E6 " << count+1 << std::endl;//Mismatch ')'
					return false;
				}
				else{
					this->e.col = count;
					this->e.symbol = line[count];
					count++;
					parentcol = this->e.col;
					dif --;
				}
			}
			else {
				std::cerr << "E3 " << count+1 << std::endl;//Extraneous symbol:
				return false;
			}
			this->token.enqueue(this->e);
		}
		else count++;
	}
	if(dif != 0){
		std::cerr << "E7 " << parentcol+1 << std::endl;//Missing closing ')' to match opening '(' at
		return false;
	}
	std::cout << token <<std::endl;
  	return true;
}

void Operation::makeposfix(){
	while(!(this->token.isEmpty())){
		this->e = this->token.dequeue();
		if (number(this->e.symbol[0])){
		 	this->posfix.enqueue(this->e);
		}
		else{
			element top = this->_symbol.top();
			while(!(this->_symbol.isEmpty()) and (weight(this->e.symbol)) >= (weight(top.symbol))){
				if ((weight(this->e.symbol)) >= (weight(top.symbol))){
					this->posfix.enqueue(this->_symbol.pop());
				}
			}
			this->_symbol.push(this->e);
		}
	}
	while(!(this->_symbol.isEmpty())){
		this->posfix.enqueue(this->_symbol.pop());
	}

	std::cout << "posfix: "<< posfix << std::endl;
}
int Operation::weight(std::string s){
	if (s == "(" or s == ")") return 1;
	else if(s == "^") return 2;
	else if(s == "*" or s == "/" or s[0] == '%') return 3;
	else if(s == "+" or s == "-") return 4;
	else return 0;
}
bool Operation::expresion(char s){
	if ((number(this->e.symbol[0]) or this->e.symbol[0] == '-' or this->e.symbol[0] == '^' or this->e.symbol[0] == '*' or this->e.symbol[0] == '/' or this->e.symbol[0] == '%' or this->e.symbol[0] == '+')
		and (number(s) or s == '-' or s == '^' or s == '*' or s == '/' or s == '%' or s == '+') and (s != 32 and s != 9) )
		return true;
	else return false;
}

bool Operation::number(char s){
	if(s <= 57 and s >= 48) return true;
	else return false;
}
bool Operation::term(char s){
	if ((number(s) or s == '-' or s == '^' or s == '*' or s == '/' or s == '%' or s == '+' or s == '(') and (s != 32 and s != 9)) return true;
	else return false;
}
int Operation::changetonumber(std::string n){
 	int result = 0;
 	int _size = n.size();

    if(n.size()==1){
		result = n[0] - '0';
	}
	else{
		for (int i = 0; i < _size; ++i){
			result = result * 10 + (n[i] - '0');
		}
	}
	return result;
}
bool Operation::calculation (){
	int op, op1, op2;
	while(!_symbol.isEmpty()){
		e = _symbol.pop();
		if(number(e.symbol[0])){
			op = changetonumber(e.symbol);
			calc.push(op);
		}
		else if(e.symbol == "+"){
			op1 = calc.pop();
			op2 = calc.pop();
			op = op1 + op2;
		}
		else if(e.symbol == "*"){
			op1 = calc.pop();
			op2 = calc.pop();
			op = op1 * op2;
		}
		else if(e.symbol == "/"){
			op1 = calc.pop();
			op2 = calc.pop();
			if(op2 != 0)
				op = op1 / op2;
			else
				std::cerr << "E8"<< std::endl; //Numeric overflow error!
			return false;
		}
		else if(e.symbol[0] == '%'){
			op1 = calc.pop();
			op2 = calc.pop();
			op = op1 % op2;
		}
		else if(e.symbol == "^"){
			op1 = calc.pop();
			op2 = calc.pop();
			op = pow(op1, op2);
		}
	}
	if (op > -332768 and op < 332768){
		this->result = op;
		return true;
	}
	else{
		std::cerr << "E9"<< std::endl; //Numeric overflow error!
		return false;

	}
}
int Operation::getresult(){
	return this->result;
}