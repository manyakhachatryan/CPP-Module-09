#include "PmergeMe.hpp"

std::deque <int> PmergeMe::_contD;
std::vector <int> PmergeMe::_contV;
PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe& ){};

PmergeMe& PmergeMe::operator=(const PmergeMe&)
{
    return *this;
};


void PmergeMe::sortCont(char **str)
{
     unsigned int start;
    std::string str1;
    int value;
    int i = 1;
    std::string a;
    while(str[i]!=NULL){
        a = str[i];
    if (a.find_first_not_of("0123456789 ")!= std::string::npos)
        throw "Error : Invalid Input";
    for(unsigned int i = 0; i<a.length(); i++)
    {
        while(a[i] == ' ')
            i++;
        start = i;
        while(a[i] != ' ' && i<a.length())
            i++;
        if(i - start != 0)
        {
            str1 = a.substr(start, i - start);
            value = stoi(str1);
            _contD.push_back(value);
            _contV.push_back(value);
        }   
    }
        i++;
    }
   
    
    std::cout <<"Before: ";
    int smt = 0;
    for (std::vector<int>::iterator it = PmergeMe::_contV.begin(); it != PmergeMe::_contV.end(); it++)
    {
        if ( smt < 5)
        {
            std::cout << *it << " ";
            smt++;
        }
        else 
        {
            std::cout<<"[...]";
            break;
        }
    }
    std::cout<<std::endl; 
    clock_t start1 = clock();
    mySort(_contV, 0, _contV.size());
    clock_t end1 = clock();
    clock_t start2 = clock();
    mySort(_contD, 0, _contD.size());
    clock_t end2 = clock();
    std::cout <<"After: ";
    smt = 0;
    for (std::vector<int>::iterator it = PmergeMe::_contV.begin(); it != PmergeMe::_contV.end(); it++)
    {
        if ( smt < 5)
        {
            std::cout << *it << " ";
            smt++;
        }
        else 
        {
        std::cout<<"[...]";
        break;
        }
    }
    std::cout<<std::endl;
    std::cout << "Time to process a range of  " << _contV.size() << " elements with std::[...]: " << std::fixed <<( static_cast<double>(end1-start1))/ CLOCKS_PER_SEC<<" us"<< std::endl;
    std::cout << "Time to process a range of  " << _contV.size() << " elements with std::[...]: " << std::fixed<< ( static_cast<double>(end2-start2))/ CLOCKS_PER_SEC<<" us"<< std::endl;
}

std::deque<int> PmergeMe::mySort(std::deque<int> &array, int begin, int end)
{
    if (end - begin <= 5) 
            PmergeMe::insertionSort(array, array.size());
    else
    {
        int mid = begin + (end - begin) / 2;
        PmergeMe::mySort(array, begin, mid);
        PmergeMe::mySort(array, mid + 1, end);
        PmergeMe::merge(array, begin, mid, end);
    }
    return array;
}



void PmergeMe::merge(std::deque<int> &array, int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    std::deque<int > leftArray(subArrayOne) ;
       std::deque<int >  rightArray(subArrayTwo);

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void PmergeMe::insertionSort(std::deque<int> &array, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

std::vector<int> PmergeMe::mySort(std::vector<int> &array, int begin, int end)
{
   
    if (end - begin <= 5) 
            PmergeMe::insertionSort(array, array.size());
    else
    {
        int mid = begin + (end - begin) / 2;
        PmergeMe::mySort(array, begin, mid);
        PmergeMe::mySort(array, mid + 1, end);
        PmergeMe::merge(array, begin, mid, end);
    }
    return array;
}



void PmergeMe::merge(std::vector<int> &array, int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    std::deque<int > leftArray(subArrayOne) ;
       std::deque<int >  rightArray(subArrayTwo);

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void PmergeMe::insertionSort(std::vector<int> &array, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}