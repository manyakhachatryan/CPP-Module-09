#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    (void)argv;
    if(argc==2)
    {
        BitcoinExchange obj;
        obj._fileName = argv[1];
        obj.change();

        //std::map<std::string, double>::iterator it = obj.dataMap.begin();
        // while (it != obj.dataMap.end())
        // {
        //     std::cout << "Key: " << it->first << "  |  Value: " << it->second << std::endl;
        //     ++it;
        // }
    } 
    else if(argc > 2)
        std::cout<<"Error: should be one file name."<<std::endl;
    else
        std::cout<<"Error: could not open file."<<std::endl;
}