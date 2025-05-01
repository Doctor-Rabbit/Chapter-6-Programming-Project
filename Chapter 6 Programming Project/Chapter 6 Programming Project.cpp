#include <iostream>
#include <iomanip> 
using namespace std;

// Constants
const double laborCostPerHour = 25.00;
const double paintCoverage = 110.0; // 1 gallon of paint covers110 square feet

// Function Prototypes
int getNumberOfRooms();
double getPricePerGallon();
double getSquareFootage(int roomNumber);
double calculateGallons(double squareFeet);
double calculateLaborHours(double squareFeet);
void displayResults(double totalGallons, double totalHours, double totalPaintCost, double totalLaborCost, double totalCost);

int main() {
	int numberOfRooms = getNumberOfRooms();
	double pricePerGallon = getPricePerGallon();

	double totalSquareFeet = 0.0;
	double totalGallons = 0.0;
	double totalLaborHours = 0.0;
	for (int i = 1; i <= numberOfRooms; ++i) {
		double squareFeet = getSquareFootage(i);
		totalSquareFeet += squareFeet;
		totalGallons += calculateGallons(squareFeet);
		totalLaborHours += calculateLaborHours(squareFeet);
	}

	double totalPaintCost = totalGallons * pricePerGallon;
	double totalLaborCost = totalLaborHours * laborCostPerHour;
	double totalCost = totalPaintCost + totalLaborCost;

	displayResults(totalGallons, totalLaborHours, totalPaintCost, totalLaborCost, totalCost);

	return 0;
}

// Function to get the number of rooms
int getNumberOfRooms() {
	int rooms;
	while (true) {
		cout << "Enter the number of rooms to be painted: ";
		cin >> rooms;
		if (rooms < 1) {
			cout << "Invalid input. Number of rooms must be at least 1.\n";
		}
		else {
			break;
		}
	}
	return rooms;
}

// Function to get the price per gallon of paint
double getPricePerGallon() {
	double price;
	while (true) {
		cout << "Enter the price of paint per gallon: $";
		cin >> price;
		if (price < 10.00) {
			cout << "Invalid Input. Price per gallon must be at least $10.00.\n";
		}
		else {
			break;
		}
	}
	return price;
}

// Function to get the square footage of the room
double getSquareFootage(int roomNumber) {
	double squareFeet;
	while (true) {
		cout << "Enter the square footage for room " << roomNumber << ": ";
		cin >> squareFeet;
		if (squareFeet < 0) {
			cout << "Invalid input. Square footage cannot be negative.\n";
		}
		else {
			break;
		}
	}
	return squareFeet;
}

// Function to calculate gallons of paint needed for a given square footage
double calculateGallons(double squareFeet) {
	return squareFeet / paintCoverage;
}

// Function to calculate labor hours needed for a given square footage
double calculateLaborHours(double squareFeet) {
	return (squareFeet / paintCoverage) * 8; // 8hours per gallon of paint
}

// Function to display the results of the calculations
void displayResults(double totalGallons, double totalHours, double totalPaintCost, double totalLaborCost, double totalCost) {
	cout << fixed << setprecision(2);
	cout << "\n--- Painting Job Summary ---\n";
	cout << "Total gallons of paint requiered: " << totalGallons << " gallons\n";
	cout << "Total hours of labor requiered: " << totalHours << " hours\n";
	cout << "Total cost of paint: $" << totalPaintCost << endl;
	cout << "Total labor charges: $" << totalLaborCost << endl;
	cout << "Total cost of the paint job: $" << totalCost << endl;
}