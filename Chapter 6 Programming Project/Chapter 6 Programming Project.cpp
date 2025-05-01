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
	do {
		cout << region << " region: ";
		cin >> accidents;
		if (accidents < 0) {
			cout << "Number of accidents cannot be negative. Please try again." << endl;
		}
	} while (accidents < 0);
	return accidents;
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
