#include "rpn.hpp"

 std::stack <int> Rpn::_num;

Rpn::Rpn(){}

Rpn::~Rpn(){}
         
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
  
    for(unsigned int i = 0; i<str.length(); i++)
    {
        while(str[i]==' ')
            i++;
        if (isdigit(str[i]))
        {
            int value = str[i] - '0';
            _num.push(value);
        }
        else if(_num.size() >= 2)
            {
                int num1 = _num.top();
                _num.pop();
                int num2 = _num.top();
                _num.pop();
                switch (str[i])
                {
                    case '-' :
                     _num.push(num2-num1);
                     break;
                        case '+' :
                     _num.push(num2+num1);
                      break;
                        case '/' :
                     _num.push(num2/num1);
                      break;
                        case '*' :
                     _num.push(num2*num1);
                      break;
                }
            }
    }
    if(_num.size()==1)
        std::cout<<"The result is: "<<_num.top()<<std::endl;
    else
        std::cout<<"Error : Invalid Input"<<std::endl;
        return (0);
}

