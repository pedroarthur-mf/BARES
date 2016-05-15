#include <iostream>
#include <vector>

#include "queuear.h"

template < class Object >
QueueAr<Object>::QueueAr (int _size){
	if (_size < 1)
        throw std::invalid_argument("[QueueAr()]: Invalid Queue size!");
    else{
	this->f = -1;
	this->l = -1;
	this->size = _size;
	this->Q = new Object [size];
	}
}
template < class Object >
QueueAr<Object>::~QueueAr (){
	delete [] this->Q;
}
template < class Object >
void QueueAr<Object>::enqueue ( const Object & x ){

	int fim = (this->l+1)%this->size;
	if (this->l == -1)
	{
		this->f++;
		this->l++;
		this->Q[this->l] = x;
	}
	
	else if (fim == this->f){
		resize(2*size);
	}
	else if(this->l == this->size){

	}
	else if(this->l > 0){
		this->l = (this->l+1)%this->size;
		this->Q[this->l] = x;
	}
}
template < class Object >
Object QueueAr<Object>::dequeue ( ){
	if (isEmpty())
        throw std::out_of_range("[dequeue()]: The Queue is empty!");
	
	Object result= this->Q[this->f];
	this->f = (this->f+1)%this->size;
	return result;
}
template < class Object >
Object QueueAr<Object>::getFront ( ) const{
	if (isEmpty())
        throw std::out_of_range("[dequeue()]: The Queue is empty!");

	return this->Q[this->f];
}
template < class Object >
bool QueueAr<Object>::isEmpty ( ) const{
	if (this->l == -1)
		return true;
	else return false;
}
template < class Object >
void QueueAr<Object>::makeEmpty ( ){
	this->f = -1;
	this->l = -1;
	this->size = 0;
}
template < class Object >
void QueueAr<Object>::resize(int _size){
	int auxisize = this->size;
	this->Q = new Object [_size];
	this->size = _size;
	int mult = (_size/auxisize);

	for (int i = this->f; i > auxisize; i++)
	{
		this->Q[i*mult] = this->Q[i];
	}
	this->f *= mult;
}

