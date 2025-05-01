#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int getAccidents(const string& region);
void findLowest(int north, int south, int east, int west, int central);

int main() {
	int north, south, east, west, central;

	cout << "Enter the number of automobile accidents in the following regions:\n";

	north = getAccidents("North");
	south = getAccidents("South");
	east = getAccidents("East");
	west = getAccidents("West");
	central = getAccidents("Central");

	findLowest(north, south, east, west, central);

	return 0;
}

// Function to get and validate accident numbers
int getAccidents(const string& region) {
	int accidents;
	while (true) {
		cout << region << " region: ";
		cin >> accidents;

		if (cin.fail()) {
			// Input was not an integer
			cin.clear();				// Clear the error flag
			cin.ignore(10000, '\n');	// Discard invalid input
			cout << "Invalid input. Please enter a numeric value.\n";
		}
		else if (accidents < 0) {
			cout << "Invalid input. Number of accidents cannot be negative.\n";
		}
		else {
			cin.ignore(10000, '\n');	// Clear any extra characters
			return accidents;			// Valid Input
		}
	}
}

// Funtion to find and display the region with the fewest accidents
void findLowest(int north, int south, int east, int west, int central) {
	int lowest = north;
	string region = "North";

	if (south < lowest) {
		lowest = south;
		region = "South";
	}

	if (east < lowest) {
		lowest = east;
		region = "East";
	}

	if (west < lowest) {
		lowest = west;
		region = "West";
	}

	if (central < lowest) {
		lowest = central;
		region = "Central";
	}

	cout << "\nThe region with the fewest accidents last year is: " << region << " with " << lowest << " accidents.\n";
}
