#include "rpn.hpp"

std::stack <int> Rpn::_num;
Rpn::Rpn()
{

}

Rpn::~Rpn()
{
    
}
         
Rpn::Rpn(const Rpn& t)
{
    (void)t;
}

Rpn& Rpn::operator=(const Rpn& t)
{
    (void)t;
    return (*this);
}


int Rpn::calculator(std::string str)
{
    if (str.find_first_not_of("0123456789-+*/ ")!= std::string::npos)
    {
        std::cout<<"Error : Invalid Input"<<std::endl;
        return (0);
    }
   int intValue;
    std::string str1;
  std::size_t start = 0;

 std::size_t end = start;


 int num1;
//  int num2;
    // str1 = str.substr(start, 1);
    // std::cout<<"str1|"<<str1<<std::endl;
    // start++;
  

        size_t found = str.find(' ');

    while((found!=std::string::npos) && start!=(str.length())) 
    {
        found = str.find(' ',end);
        str1 = str.substr(start, 1);
        end = start;
        start++;
        if (str1.find_first_not_of("-+*/")!= std::string::npos)
        {
            

             intValue = std::atoi(str1.c_str());
            _num.push(intValue);
            std::cout<<intValue<<std::endl;
            // std::cout<<intValue<<std::endl;
            // std::cout<<"Error "<<std::endl;
        } else 
        {

            // num1 = _num.top();
            // _num.pop();
            // num2 = _num.top();
            // _num.pop();
            // std::cout<<"num1|"<<num1<<"|"<<std::endl;
            // std::cout<<"num2|"<<num2<<"|"<<std::endl;
        }

    //     //  std::cout<<start<<std::endl;
    //     //   std::cout<<end<<std::endl;
    }
    // std::size_t found = str.find(' ');
   
    
    // std::cout<<_num.top()<<std::endl;
    return (0);
}