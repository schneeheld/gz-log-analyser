/*
 * Build the source:
 * g++ report.cpp -o report
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Keywords, search patterns
#define RESULTS "results"
#define INDICES "indices"

/*
 *  Keyword codes
 */
enum string_code {
	results_code, indices_code, other
};

/*
 * Keyword hashing function
 */
string_code string_hash(string const& inString) {
	if (inString == RESULTS)
		return results_code;
	else if (inString == INDICES)
		return indices_code;
	else
		return other;
}

/*
 * Sum vector elements
 */
size_t vSum(vector<int> &v) {
	size_t sum = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		sum += *it;
	}
	return sum;
}

/*
 * Compute the % distribution value from a set of numbers
 * Index rounded to a smaller integer
 */
int vPcent(vector<int> &v, float percent) {
	int indx = percent / 100 * v.size();
	return v[indx];
}

/*
 * Sort the vector
 */
void vSort(vector<int> &v) {
	sort(v.begin(), v.end());
}

/*
 * Median of a vector
 */
float vMedian(vector<int> &v) {
	int size = v.size();

	// empty vector
	if ( !size ) return 0;

	// Odd number of elements
	if (size % 2) {
		return v[size / 2];
	} else {
		return ((v[size / 2 - 1] + v[size / 2]) / 2.0);
	}
}

/*
 * Print stats report
 */
void vReport(vector<int> &v) {
	cout << "  size   " << v.size() << endl;
	cout << "  sum    " << vSum(v) << endl;
	cout << "  mean   " << static_cast<float>(vSum(v)) / v.size() << endl;
	cout << "  median " << vMedian(v) << endl;
	cout << "  75%    " << vPcent(v, 75) << endl;
	cout << "  90%    " << vPcent(v, 90) << endl;
	cout << "  99.9%  " << vPcent(v, 99.9) << endl;
}

/*
 * Print vector elements
 */
void vPrint(vector<int> &v) {
	for (int i = 0; i != v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {

	string lineInput;
	int value;
	vector<int> vResults, vIndices;

	// Read shell input word-by-word
	// Assume input data to be valid
	while (cin >> lineInput) {

		cin >> value;

		switch (string_hash(lineInput)) {

		case results_code:
		vResults.push_back(value);
		break;

		case indices_code:
		vIndices.push_back(value);
		break;

		default:
		// OPTIONAL warning output here
		break;
		}
	}

	// Sorting the vectors
	vSort(vResults);
	vSort(vIndices);

	// Report
	cout << RESULTS << endl << "----------------" << endl;
	vReport(vResults);
	cout << endl;
	cout << INDICES << endl << "----------------" << endl;
	vReport(vIndices);

	return 0;
}
