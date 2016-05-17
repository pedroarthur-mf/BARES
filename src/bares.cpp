#include <iostream>
#include <fstream>

#include "operation.h"

int main(int argc, char *argv[]){
	std::string arq;
    // std::ofstream out_data;
    // std::ostream *out;

    if (argc == 1){
        std::cerr << "No file specified. Can't run the program\n\n";
        exit(1);
    }
    else {
        arq = argv[1];
        // if(argc == 2){
        //     // out = &std::cout;
        // } else{
        //     out_data.open("data/" + std::string(argv[2]) + ".txt");
        //     out = &out_data;
        // }
    }
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
            P.calculation();
//<<<<<<< HEAD
//<<<<<<< HEAD
            //*out << P.getresult() << "\n";
//=======
            // *out << P.getresult() << "\n";
//>>>>>>> 0e0818ce200d833a76dd8cebca96157529463b2f
//=======
            // *out << P.getresult() << "\n";
//>>>>>>> 210e8b41abda2ffd0c845528dbd62582ea2c4884
    	}
    }
    file_data.close();
    // out_data.close();
	return EXIT_SUCCESS;
}
