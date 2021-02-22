#include "bignum_calculator.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

typedef bignum_calculator::bignum bignum;

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "You need 2 arguments: an input file and an output file"; 
        return -1; //a non-zero means there was an error in execution
    }

    bignum_calculator *bc = new bignum_calculator();
    std::ifstream reader(argv[1]);
    std::ofstream writer(argv[2]); 
    std::string op;
    std::string num_1; 
    std::string num_2; 
    std::string line;

    while (std::getline(reader, line)) {
        std::istringstream line_splitter(line);

        //not best practice as it assumes properly formatted input but alas
        line_splitter >> op;
        line_splitter >> num_1;
        line_splitter >> num_2;

        //important to create bignums in here so they get reset every iteration
        bignum bignum_1;
        bignum bignum_2;
        bignum res;

        bc->str_to_bignum(num_1, &bignum_1);
        bc->str_to_bignum(num_2, &bignum_2);
        
        if (op == "add") {
            bc->add(bignum_1, bignum_2, &res);
            writer << num_1 << " + " << num_2 << " = ";
            writer << bc->bignum_to_str(res) << "\n";
        } else if (op == "multiply") {
            bc->multiply(bignum_1, bignum_2, &res);
            writer << num_1 << " * " << num_2 << " = ";
            writer << bc->bignum_to_str(res) << "\n";
        } else {
            std::cout << "Can only add or multiply, please check input file formatting and spelling.";
            return -1;
        }
    }
    return 0;
}