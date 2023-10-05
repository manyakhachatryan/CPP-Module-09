#ifndef  BITCOINEXCHANGE_HPP
#define  BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream> 
#include <map>
#include <algorithm>
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(std::string);
        BitcoinExchange(const  BitcoinExchange& );
        BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();
        void change();

    private:
    void dataToMap();
    void parseAndChange();
    void inputPars(std::string data);
    int parsLeft(std::string str1);
    int parsRight(std::string str2);
    int  currentYear();
    std::string _fileName;
    std::string _data;
    double _value;
    std::map<std::string, double> dataMap;
    std::string trim(std::string& input);
};

#endif