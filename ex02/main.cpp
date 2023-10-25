#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc >= 2)
    {
        try
        {
            PmergeMe::sortCont(argv);
        }
        catch(const char  * msg)
        {
            std::cerr << msg << '\n';
        }
    }
        else 
            std::cout<<"Must be more than 2 argument"<<std::endl;
    return 0;
}