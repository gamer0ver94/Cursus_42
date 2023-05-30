#include "classes/PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2){
    return -1;
  }
  argv++;
  PmergeMe *test = new PmergeMe(argv);
  test->printVector("Before: ");
  test->operate();
  test->printVector("After: ");
  test->printVectorTime();
  test->printDequeTime();

    return 0;
}