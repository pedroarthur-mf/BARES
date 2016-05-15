# ifndef STACKAR_H
# define STACKAR_H
# include "AbsStack.h" // Inclui a interface abstrata da pilha .
// Implementando interface via heran¸ca .
template < class Object >
class StackAr : public AbsStack<Object> {
 public:
 	StackAr(int _size = 10);
 	~StackAr();

 	void push( const Object &);
 	Object pop(void);
	Object top (void) const;
 	bool isEmpty(void) const;
	void makeEmpty(void);

 private:
 	int capacity;
 	int topo;
 	Object *P;

 	void resize(int _size);
};


#include "stackar.inl"
# endif
