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
	do {
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		if (length <= 0) {
			cout << "Length must be greater than 0. Please try again." << endl;
		}
	} while (length <= 0);
	return length;
}

// Funtion to get and validate the rectangle's width
double getWidth() {
	double width;
	do {
		cout << "Enter the width of the rectangle: ";
		cin >> width;
		if (width <= 0) {
			cout << "Width must be greater than 0. Please try again." << endl;
		}
	} while (width <= 0);
	return width;
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
	char choice;
	cout << "Would you like to process another rectangle? (Y/N): ";
	cin >> choice;
	return (choice == 'Y' || choice == 'y');
}