# ifndef QUEUEAR_H
# define QUEUEAR_H

#include <iostream>
#include <vector>

using namespace std;

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
	    int getsize();

	    bool isEmpty ( ) const;
	    void makeEmpty ( );
	    //inline int getsize(){return this->size;}
	    //inline int getf(){return this->f;}
	    
	    inline friend std::ostream &operator<< (std::ostream& _os, const QueueAr<Object>& _oList ){
        	if ( _oList.l == -1 ) { _os << "[ ]"; return _os; } // olocar erro.
        	if ( _oList.l >= _oList.f ){
            _os << "[";
	            for( int i(_oList.f) ; i <= _oList.l ; ++i )
	                _os << _oList.Q[ i ].symbol;
	            _os << "]";
	            return _os;        		
        	}
        	else{ 
	            _os << "[";
	            for( int i(_oList.f) ; i < _oList.size ; ++i )
	                _os << _oList.Q[ i ].symbol;
	            for( int i(0) ; i <= _oList.l ; ++i )
	                _os << _oList.Q[ i ].symbol;
	            _os << "]";
	            return _os;
       		}
       	}
};

#include "queuear.inl"
# endif