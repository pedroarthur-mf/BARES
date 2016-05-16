#include <iostream>
#include <fstream>

#include "operation.h"

int main(int argc, char *argv[]){
	std::string arq;
	if (argc == 1){
		std::cerr << "No file specified. Can't run the program\n\n";
		exit(1);
	}
	else
		arq = argv[1];

	//open file
	std::ifstream file_data(arq);

	if(!file_data){
		std::cerr << ">>> The file cannot be read\n";
        file_data.close();
        exit(1);
    }

    std::string op;

    while(getline(file_data, op)){
    	Operation P;
    	if(P.tokenize(op)){
    		P.makeposfix();
    	}
    }

	return EXIT_SUCCESS;
}
