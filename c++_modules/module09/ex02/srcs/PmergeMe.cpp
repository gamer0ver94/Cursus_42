#include "../classes/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **unsortedStr){
    int n;
    int i = 0;
    if (argc -1 > 1){
        while (unsortedStr[i]){
            std::string str(unsortedStr[i]);
            std::istringstream iss(str);
            if (iss >> n){
                 if (n < 0){
                    throw ErrorHandler();
                }
                unsortedVector.push_back(n);
                unsortedDeque.push_back(n);
            }
            i++;
        }
    }
    else{
        std::string str(*unsortedStr);
        std::istringstream iss(str);
        while (iss >> n){
            if (n < 0){
                    throw ErrorHandler();
            }
            unsortedVector.push_back(n);
            unsortedDeque.push_back(n);
        }
    }
    arraySize = this->unsortedVector.size();
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& copy){
    unsortedVector = copy.unsortedVector;
    unsortedDeque = copy.unsortedDeque;
    arraySize = copy.arraySize;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy){
    if (this != &copy){
        unsortedVector = copy.unsortedVector;
        unsortedDeque = copy.unsortedDeque;
        arraySize = copy.arraySize;
    }
    return *this;
}

// Exception error handler

const char* PmergeMe::ErrorHandler::what()const throw(){
    return "Invalid Input";
}

// Merge sort algorithm
void PmergeMe::merge(std::vector<int>& vector, int left, int mid, int right) {
     int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    for (int i = 0; i < n1; ++i)
        leftArr[i] = vector[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = vector[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            vector[k] = leftArr[i];
            ++i;
        } else {
            vector[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        vector[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        vector[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Perform insertion sort on the subarray
void PmergeMe::insertionSort(std::vector<int>& vector, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = vector[i];
        int j = i - 1;
        while (j >= left && vector[j] > key) {
            vector[j + 1] = vector[j];
            --j;
        }
        vector[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vector, int threshold) {
    int size = vector.size();
    for (int i = threshold; i < size; i *= 2) {
        for (int left = 0; left < size - i; left += 2 * i) {
            int mid = left + i - 1;
            int right = std::min(left + 2 * i - 1, size - 1);
            merge(vector, left, mid, right);
        }
    }
    insertionSort(vector, 0, size - 1);
}
// overload
void PmergeMe::merge(std::deque<int>& deque, int left, int mid, int right) {
    size_t i = 0, j = 0, k = left;
    std::deque<int> leftDeque(deque.begin() + left, deque.begin() + mid + 1);
    std::deque<int> rightDeque(deque.begin() + mid + 1, deque.begin() + right + 1);
    while (i < leftDeque.size() && j < rightDeque.size()) {
        if (leftDeque[i] <= rightDeque[j]) {
            deque[k] = leftDeque[i];
            ++i;
        } else {
            deque[k] = rightDeque[j];
            ++j;
        }
        ++k;
    }
    while (i < leftDeque.size()) {
        deque[k] = leftDeque[i];
        ++i;
        ++k;
    }
    while (j < rightDeque.size()) {
        deque[k] = rightDeque[j];
        ++j;
        ++k;
    }
}

void PmergeMe::insertionSort(std::deque<int>& deque, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = deque[i];
        int j = i - 1;
        while (j >= left && deque[j] > key) {
            deque[j + 1] = deque[j];
            --j;
        }
        deque[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::deque<int>& deque, int threshold) {
    int size = deque.size();
    for (int i = threshold; i < size; i *= 2) {
        for (int left = 0; left < size - i; left += 2 * i) {
            int mid = left + i - 1;
            int right = std::min(left + 2 * i - 1, size - 1);
            merge(deque, left, mid, right);
        }
    }
    insertionSort(deque, 0, size - 1);
}
void PmergeMe::operate(){
    startVector = clock();
    mergeInsertionSort(unsortedVector, 5);
    endVector = clock();
    startDeque = clock();
    mergeInsertionSort(unsortedDeque, 5);
    endDeque = clock();
}

// Print the array
void PmergeMe::printDequeTime() {
    std::cout <<  std::fixed << std::setprecision(5) << GREEN << "Time to process a range of " << unsortedVector.size() <<" elements with std::deque : " << BLUE << getMicroSeconds(startDeque, endDeque)<< " us" << RESET << std::endl;
}

void PmergeMe::printVectorTime() {
     std::cout << std::fixed << std::setprecision(5) << GREEN << "Time to process a range of " << unsortedVector.size() <<" elements with std::vector : " << BLUE << getMicroSeconds(startVector, endVector) << " us" << RESET << std::endl;
}

void PmergeMe::printVector(std::string msg){
    std::cout << msg; 
      for (size_t i = 0; i < unsortedVector.size(); i++) {
        std::cout << unsortedVector[i] << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getMicroSeconds(clock_t& start, clock_t& end){
    return (static_cast<double>((end - start)) / static_cast<double>(CLOCKS_PER_SEC)) * static_cast<double>(1000);
}