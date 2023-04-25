#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

class PmergeMe {
public:
	PmergeMe();
	void setSequence(const std::vector<int>& seq);
	void mergeInsertionSortVector();
	void mergeSortList();
	void displayResults() const;
private:
	std::vector<int> m_sequence;
	std::vector<int> m_sortedSequenceVector;
	std::list<int> m_sortedSequenceList;
	double m_timeVector;
	double m_timeList;
};

#endif
