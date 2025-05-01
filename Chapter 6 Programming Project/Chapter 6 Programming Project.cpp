#include <iostream>
#include <iomanip> // Requiered for setprecision
using namespace std;

// Function Prototypes
void getJudgeScore(double& score);
double findLowest(const double scores[], int size);
double findHighest(const double scores[], int size);
double calcAverage(const double scores[], int size);

int main() {
	const int NUM_JUDGES = 5;
	double scores[NUM_JUDGES];

	// Get scores from judges
	for (int i = 0; i < NUM_JUDGES; ++i) {
		cout << "Enter score for Judge " << (i + 1) << "; ";
		getJudgeScore(scores[i]);
	}

	// Calculateand display the final average score
	double finalScore = calcAverage(scores, NUM_JUDGES);

	cout << fixed << setprecision(2);
	cout << "Final score (after dropping highest and lowest): " << finalScore << endl;

	return 0;
}

// Function to get and validate a score from a judge
void getJudgeScore(double& score) {
	while (true) {
		cin >> score;
		if (cin.fail() || score < 0.0 || score > 10.0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Enter a score between 0 and 10: ";
		}
		else {
			break;
		}
	}
}

// Function to find the lowest score
double findLowest(const double scores[], int size) {
	double lowest = scores[0];
	for (int i = 1; i < size; ++i) {
		if (scores[i] < lowest) {
			lowest = scores[i];
		}
	}
	return lowest;
}

// Function to find the highest score
double findHighest(const double scores[], int size) {
	double highest = scores[0];
	for (int i = 1; i < size; ++i) {
		if (scores[i] > highest) {
			highest = scores[i];
		}
	}
	return highest;
}

// Function to calculate average after dropping highest and lowest
double calcAverage(const double scores[], int size) {
	double total = 0.0;
	double highest = findHighest(scores, size);
	double lowest = findLowest(scores, size);

	for (int i = 0; i < size; ++i) {
		total += scores[i];
	}

	total -= (highest + lowest); // Drop the highest and lowest
	return total / (size - 2);	 // Average the remaining 3
}