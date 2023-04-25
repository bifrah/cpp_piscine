#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " sequence" << std::endl;
		return 1;
	}

	// Parse the input sequence
	std::vector<int> sequence;
	int i = 1;
	while (argv[i])
	{
		std::istringstream iss(argv[i]);
		int num;
		while (iss >> num) {
			sequence.push_back(num);
		}
		i++;
	}

	// Create a PmergeMe object and set the sequence to sort
	PmergeMe pmergeMe;
	pmergeMe.setSequence(sequence);

	// Run the sorting algorithms and display the results
	pmergeMe.mergeInsertionSortVector();
	pmergeMe.mergeSortList();
	pmergeMe.displayResults();

	return 0;
}
