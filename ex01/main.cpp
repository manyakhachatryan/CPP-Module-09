#include "rpn.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
        Rpn::calculator(argv[1]);
    else 
        std::cout<<"Must be one argument"<<std::endl;
    return 0;
}