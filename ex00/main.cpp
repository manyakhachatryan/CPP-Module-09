#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    (void)argv;
    if(argc==2)
    {
        BitcoinExchange obj(argv[1]);
        obj.change();
    } 
    else if(argc > 2)
        std::cout<<"Error: should be one file name."<<std::endl;
    else
        std::cout<<"Error: could not open file."<<std::endl;
}