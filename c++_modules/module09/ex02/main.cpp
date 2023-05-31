#include "classes/PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2){
    return -1;
  }
  argv++;
  try{
      PmergeMe *test = new PmergeMe(argc, argv);
      test->printVector("Before: ");
      test->operate();
      test->printVector("After: ");
      test->printVectorTime();
      test->printDequeTime();
  }
  catch(std::exception &e){
      std::cout << RED << "Error: " << e.what()<< RESET << std::endl;
  }

    return 0;
}