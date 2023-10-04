#include "BitcoinExchange.hpp"

void BitcoinExchange::change()
{
    std::ifstream ifs (_fileName);
    if (ifs.is_open()) 
    {
        dataToMap();
        parseAndChange();
    }
    else
        std::cout<<"Error: could not open file."<<std::endl;
}

void BitcoinExchange::dataToMap()
{
    std::ifstream ifs ("data.csv");
    if (ifs.is_open()) 
    {
        std::string data;
        getline(ifs, data);
        while (getline(ifs, data))
        {
            size_t found = data.find(',');
            std::string str1 = data.substr(0, found);
            std::string str2 = data.substr(found+1, data.length());
            double value = atof(str2.c_str());
            dataMap.insert(std::pair<std::string, double>(str1, value));

            // size_t found = data.find(',');
            // double value = atof(data.substr(found+1, data.length()).c_str());
            // dataMap.insert(std::pair<std::string, double>(data.substr(0, found), value));

        }
        ifs.close();
    }
    else
        std::cout<<"Error: could not open data file."<<std::endl; 
}


void BitcoinExchange::parseAndChange()
{
    std::ifstream ifs (_fileName);
    if (ifs.is_open()) 
    {
        std::string data;
        while (getline(ifs, data))
        {
            if (inputPars(data))
            {

            }
        }
        ifs.close();
    }
    else
        std::cout<<"Error: could not open file."<<std::endl;
}

int BitcoinExchange::inputPars(std::string data)
{
   // std::cout<<"data = "<<data<<std::endl;
    size_t found = data.find('|');
    std::string str1 = data.substr(0, found);
    std::string str2 = data.substr(found+1, data.length()); 
    parsLeft(str1);
    return (0);
}

int  BitcoinExchange::parsLeft(std::string str1)
{
        if (str1.find_first_not_of("0123456789- ")!= std::string::npos) //ete tiv ch eu -  che
        {
            std::cout<< "Error: bad input => " <<str1<< std::endl;
            return (0);
        }
        size_t found = str1.find('-');
        std::cout<<"found ->"<<found<<std::endl;
     
   // }
    return (1);
}