#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout<<"Default constructor called"<<std::endl;
}


BitcoinExchange::BitcoinExchange(std::string argv)
{
    _fileName = argv;
   std::cout<<"Parameterized constructor called"<<std::endl;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange&  t)
{
    (void)t;
	std::cout<<"Copy constructor called"<<std::endl;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange& t)
{
    (void)t;
	std::cout<<"Copy assignment operator"<<std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout<<"Destructor called"<<std::endl;
}



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
        getline(ifs, data);
        while (getline(ifs, data))
        {
        inputPars(data);
        }
        ifs.close();
    }
    else
        std::cout<<"Error: could not open file."<<std::endl;
}

void BitcoinExchange::inputPars(std::string data)
{
    size_t found = data.find('|');
    if (found == std::string::npos)
    {
        std::cout<< "Error: bad input =>"<<data<< std::endl;
        return;
    }
    std::string str1 = data.substr(0, found);
    std::string str2 = data.substr(found+1, data.length()); 
    if(parsLeft(str1) && parsRight(str2))
     {
        std::map<std::string, double>::iterator it = dataMap.begin();
        std::map<std::string, double>::iterator tmp;
        while (it != dataMap.end())
        {
            if(it->first <= _data)
                tmp = it;
             ++it;
        }
            std::cout<<_data<<" => "<<_value<<" = "<<tmp->second * _value<<std::endl;
     }
    return;
}

int  BitcoinExchange::parsLeft(std::string str1)
{
    std::string str;
    str = trim(str1);
    _data = str;
    if (str.find_first_not_of("0123456789-")!= std::string::npos || str[4] != '-' || str[7] != '-' || str.length() != 10) //ete tiv ch eu -  che
    {
        std::cout<< "Error: bad input => " <<str<< std::endl;
        return (0);
    }
    std::string dataYear = str.substr(0, 4);
    std::string dataMonth = str.substr(5, 2);
    std::string dataDay =  str.substr(8, 2);

    double valueYear = atof(dataYear.c_str());
    double valueMonth = atof(dataMonth.c_str());
    double valueDay = atof(dataDay.c_str());
    int year = currentYear();
    if (valueYear > year || valueYear < 2009 || valueMonth > 12 || valueMonth < 1)
    {
        std::cout<< "Error: bad input => " <<str<< std::endl;
        return (0);
    }
    if(static_cast<int>(valueYear) % 4 == 0)
    {
       if(valueDay <1 || valueDay > 29)
       {
        std::cout<< "Error: bad input => " <<str<< std::endl;
        return (0);
       }
    }
    else 
    {
        if(valueDay <1 || valueDay > 28)
       {
        std::cout<< "Error: bad input => " <<str<< std::endl;
        return (0);
       }
    }
    return (1);
}


int  BitcoinExchange::parsRight(std::string str2)
{
    std::string str;
    str = trim(str2);
    if(str[0] == '+' || str[0] == '-')
    {
        if (str.find_first_not_of("0123456789.", 1)!= std::string::npos){
            std::cout<< "Error: bad input =>" <<str2<< std::endl;
        return (0);
        }
    }
    else if (str.find_first_not_of("0123456789.")!= std::string::npos)
    {
        std::cout<< "Error: bad input =>" <<str2<< std::endl;
        return (0);
    }
    long int value = static_cast<long int> (strtold(str.c_str(), NULL));
    if (value < 0)
    {
        std::cout<< "Error: not a positive number."<< std::endl;
        return (0);
    } 
    else if(value > 1000)
    {
        std::cout<< "Error: too large a number."<< std::endl;
        return (0);
    }
    _value = atof(str.c_str());
    return (1);
}

int BitcoinExchange::currentYear()
{
    std::time_t currentTime = std::time(nullptr);
    struct std::tm* timeInfo = std::localtime(&currentTime);

    int currentYear = 1900 + timeInfo->tm_year;
    return (currentYear);
}

std::string BitcoinExchange::trim(std::string& input)
{
    std::string::size_type start = input.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) 
    {
        return "";
    }
    std::string::size_type end = input.find_last_not_of(" \t\n\r");
    return input.substr(start, end - start + 1);
}