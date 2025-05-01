#include <iostream>
using namespace std;

// Function Prototypes
double getLength();
double getWidth();
double calculateArea(double length, double width);
double calculatePerimeter(double length, double width);
bool askToContinue();

int main() {
	double length, width, area, perimeter;

		do {
			length = getLength();
			width = getWidth();

			area = calculateArea(length, width);
			perimeter = calculatePerimeter(length, width);

			cout << "Area: " << area << endl;
			cout << "Perimeter: " << perimeter << endl;
		} while (askToContinue());

	cout << "Goodbye!" << endl;
	return 0;
}

// Function to get and validate the rectangle's length
double getLength() {
	double length;
	while (true) {
		cout << "Enter the length of the rectangle: ";
		cin >> length;

		if (cin.fail()) {
			cin.clear();				// Clear Fail state
			cin.ignore(10000, '\n');	// Discard invalid input
			cout << "Invalid input. Please enter a numeric value.\n";
		}
		else if (length <= 0) {
			cout << "Length must be greater than 0. Please try again.\n";
		}
		else {
			cin.ignore(10000, '\n');	// Discard extra input
			return length;
		}
	}
}

// Funtion to get and validate the rectangle's width
double getWidth() {
	double width;
	while (true) {
		cout << "Enter the width of the rectangle: ";
		cin >> width;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a numeric value.\n";
		}
		else if (width <= 0) {
			cout << "Width must be greater than 0. Please try again.\n";
		}
		else {
			cin.ignore(10000, '\n');
			return width;
		}
	}
}

// Function to calculate area
double calculateArea(double length, double width) {
	return length * width;
}

// Function to calculate perimeter
double calculatePerimeter(double length, double width) {
	return 2 * (length + width);
}

// Function to ask if the user wnats to continue
bool askToContinue() {
	char response;
	while (true) {
		cout << "Would you like to process another rectangle? (Y/N): ";
		cin >> response;
		cin.ignore(10000, '\n');

		if (response == 'Y' || response == 'y')
			return true;
		else if (response == 'N' || response == 'n')
			return false;
		else
			cout << "Invlaid input. Please enter Y or N.\n";
	}
}