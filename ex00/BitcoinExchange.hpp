
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
    // BitcoinExchange();
    void change();
    void dataToMap();
    void parseAndChange();
    int inputPars(std::string data);
    int parsLeft(std::string str1);
    std::string _fileName;
    std::map<std::string, double> dataMap;

};

#endif