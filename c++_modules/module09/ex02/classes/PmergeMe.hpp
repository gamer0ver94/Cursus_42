#pragma once
#include <ctime>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <iomanip>
#define RESET   "\033[0m"   
#define RED     "\033[31m"
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m" 
#define WHITE   "\033[37m"
//not forget canonical
class PmergeMe{
    public :
        PmergeMe(char **unsortedStr);
        ~PmergeMe();
        void operate();
        void printVector(std::string msg);
        void printVectorTime();
        void printDequeTime();
    private :
       void mergeInsertionSort(std::vector<int>& vector, int threshold);
        PmergeMe();
        void merge(std::vector<int>& vector, int left, int mid, int right);
        void insertionSort(std::vector<int>& vector, int left, int right);
        void mergeInsertionSort(std::deque<int>& deque, int threshold);
        void insertionSort(std::deque<int>& deque, int left, int right);
        void merge(std::deque<int>& dq, int left, int mid, int right);
        std::vector<int> unsortedArray;
        std::deque<int> unsortedDeque;
        int arraySize;
        double getMicroSeconds(clock_t& start, clock_t& end);
        clock_t startDeque;
        clock_t endDeque;
        clock_t startVector;
        clock_t endVector;
};