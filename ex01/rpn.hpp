#ifndef  RPN_HPP
#define  RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class Rpn
{
    public:
        static int calculator(std::string str);
        // static  Data* deserialize(uintptr_t raw);
    private:
        Rpn();
        ~Rpn();
        Rpn(const Rpn& );
        Rpn& operator=(const Rpn&);
        static std::stack <int> _num;
};

#endif