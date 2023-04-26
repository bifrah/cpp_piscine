#include "PmergeMe.hpp"

std::vector<int> merge_vector(const std::vector<int>& v1, const std::vector<int>& v2) {
	std::vector<int> result;
	result.reserve(v1.size() + v2.size());
	std::vector<int>::const_iterator it1 = v1.begin();
	std::vector<int>::const_iterator it2 = v2.begin();
	while (it1 != v1.end() && it2 != v2.end()) {
		if (*it1 < *it2) {
			result.push_back(*it1++);
		} else {
			result.push_back(*it2++);
		}
	}
	result.insert(result.end(), it1, v1.end());
	result.insert(result.end(), it2, v2.end());
	return result;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& v, size_t start, size_t end) {
	if (start < end) {
		if (end - start <= 10) {
			// Insertion sort for small sequences
			for (size_t i = start; i <= end - 1; ++i) {
				int key = v[i];
				size_t j = i;
				while (j > start && v[j - 1] > key) {
					v[j] = v[j - 1];
					--j;
				}
				v[j] = key;
			}
		} else {
				size_t middle = (start + end) / 2;
				mergeInsertSortVector(v, start, middle);
				mergeInsertSortVector(v, middle + 1, end);
				std::vector<int> merged = merge_vector(std::vector<int>(v.begin() + start, v.begin() + middle + 1),
													   std::vector<int>(v.begin() + middle + 1, v.begin() + end + 1));
				std::copy(merged.begin(), merged.end(), v.begin() + start);
		}
	}
}

std::list<int> merge_list(const std::list<int>& l1, const std::list<int>& l2) {
	std::list<int> result;
	std::list<int>::const_iterator it1 = l1.begin();
	std::list<int>::const_iterator it2 = l2.begin();
	while (it1 != l1.end() && it2 != l2.end()) {
		if (*it1 < *it2) {
			result.push_back(*it1++);
		} else {
			result.push_back(*it2++);
		}
	}
	result.insert(result.end(), it1, l1.end());
	result.insert(result.end(), it2, l2.end());
	return result;
}

void PmergeMe::mergeInsertSortList(std::list<int>& l) {
	if (l.size() > 1) {
		std::list<int>::iterator middle = l.begin();
		std::advance(middle, l.size() / 2);

		std::list<int> left(l.begin(), middle);
		std::list<int> right(middle, l.end());

		mergeInsertSortList(left);
		mergeInsertSortList(right);

		l = merge_list(left, right);
	}
}
