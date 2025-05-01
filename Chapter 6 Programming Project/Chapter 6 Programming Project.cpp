#include <iostream>
#include <iomanip> // For setprecision and swtw
using namespace std;

// Function Prototype
double fahrenheitToCelcius(int fahrenheit);

int main() {
	cout << fixed << setprecision(2); // Format output to 2 decimal places
	cout << "Fahrenheit to Celcius Conversion Table (0 - 20)\n";
	cout << "-----------------------------------------------\n";
	cout << setw(12) << "Fahrenheit" << setw(12) << "Celcius\n";

	for (int f = 0; f <= 20; f++) {
		double c = fahrenheitToCelcius(f);
		cout << setw(12) << f << setw(12) << c << endl;
	}
	return 0;
}

// Function to convert Fahrenheit to Celcius
double fahrenheitToCelcius(int fahrenheit) {
	return (5.0 / 9.0) * (fahrenheit - 32);
}