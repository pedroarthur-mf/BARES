#include <iostream>
#include <stdexcept>

#include "stackar.h"

template <class Object>
StackAr<Object>::StackAr(int _size){
	this->topo = 0;
	this->capacity = _size;
	this->P = new Object [_size];
}
template <class Object>
StackAr<Object>::~StackAr(){
	delete [] this->P;
}
template <class Object>
void StackAr<Object>::resize(int _size){
	this->P = new Object [_size];
}
template <class Object>
void  StackAr<Object>::push (const Object &NewValue){
	if (this->topo == this->capacity){
		resize(2*this->capacity);
	}
	else{
		this->P[this->topo] = NewValue;
		this->topo++;
	}
}
template <class Object>
Object StackAr<Object>::pop(void){
	if (isEmpty())
	{
		throw std::length_error("Underflow"); 
	}
	else{
		Object result;
		result = this->P[this->topo-1];
		this->topo--;
		return result;
	}
}
template <class Object>
Object StackAr<Object>::top(void) const{
	return this->P[this->topo-1];
}
template <class Object>
bool StackAr<Object>::isEmpty(void) const{
	return (this->topo == 0);
}
template <class Object>
void  StackAr<Object>::makeEmpty(void){
	this->topo = 0;
}
