# ifndef QUEUEAR_H
# define QUEUEAR_H

#include <iostream>
#include <vector>

#include"AbsQueue.h"

template < class Object >
class QueueAr : public AbsQueue <Object> {
	private:
		int f;
		int	l;
		Object *Q;
		int size;	

		void resize(int _size);

	public:
		QueueAr ( int _size = 50);// Default constructor
	    ~QueueAr ();		  // Default destructor

	 // Basic members
	    void enqueue ( const Object & x );
	    Object dequeue ( );
	    Object getFront ( ) const;
	    //int getsize();

	    bool isEmpty ( ) const;
	    void makeEmpty ( );
	    //inline int getsize(){return this->size;}
	    //inline int getf(){return this->f;}
	    
	    /*inline friend
    	std::ostream &operator<<(std::ostream &_os, const QueueAr &_queue) {
        _os << "[ ";
        for (auto i(0u); i < (_queue.getsize()); i++)
            _os << _queue[(_queue.getf() + i) % _queue.getsize()] << " ";
        _os << "]";

        return _os;
    }*/

};

#include "queuear.inl"
# endif