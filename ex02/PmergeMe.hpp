#ifndef  PMERGEME_HPP
#define  PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    public:
        static std::deque<int> mySort(std::deque<int> &t, int begin, int end);
        static std::vector<int> mySort(std::vector<int> &t, int begin, int end);
        static void sortCont(char ** );
        static void merge(std::deque<int> &array, int const left, int const mid,
           int const right);
        static void insertionSort(std::deque<int> &array, int n);
        static void merge(std::vector<int> &array, int const left, int const mid,
           int const right);
        static void insertionSort(std::vector<int> &array, int n);
    private:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& );
        PmergeMe& operator=(const PmergeMe&);
        static std::deque <int> _contD;
        static std::vector <int> _contV;
};

#endif