#include <iostream>

static void DisplayMenu() {

	std::cout << "----------------\n";
	std::cout << "- 1)Add -\n";
	std::cout << "- 2)Subtract -\n";
	std::cout << "- 3)Multiply -\n";
	std::cout << "- 4)Exit -\n";
	std::cout << "----------------\n";
}

// The main function provided by the assembly code
int unsecureMain() {

	// Does not initialize all of the values
	int choice = 0, num1, num2, num3;

	while (true) {
		if (choice == 5) { // Wrong number for the program to exit
			return -1;
		}

		// Menu is hardcoded in instead of using DisplayMenu()
		std::cout << "----------------\n";
		std::cout << "- 1)Add -\n";
		std::cout << "- 2)Subtract -\n";
		std::cout << "- 3)Multiply -\n";
		std::cout << "- 4)Exit -\n";
		std::cout << "----------------\n";
		std::cin >> choice;

		/**
		* 1. Correct operator is not used in each choice
		* 2. The arithmatic string only displays subtraction
		* 3. No handling for incorrect user input for choice
		**/
		if (choice == 1) {
			std::cin >> num1;
			std::cin >> num2;
			num3 = num1 - num2;
			std::cout << num1 << " - " << num2 << " = " << num3 << "\n";
		}
		else if (choice == 2) {
			std::cin >> num1;
			std::cin >> num2;
			num3 = num1 + num2;
			std::cout << num1 << " - " << num2 << " = " << num3 << "\n";
		}
		else if (choice == 3) {
			std::cin >> num1;
			std::cin >> num2;
			num3 = num1 / num2;
			std::cout << num1 << " - " << num2 << " = " << num3 << "\n";
		}
	}
}

// Main function with corrected vulneralbilities
int main() {

	//All values are intialized as 0
	int choice = 0, num1 = 0, num2 = 0, num3 = 0;

	while (true) {
		DisplayMenu(); // Utilized the display menu function for readability

		std::cin >> choice;
		if (choice == 4) { // Correct number to allow program termination
			return 1;
		}

		std::cin >> num1;
		std::cin >> num2;

		/**
		* 1. Corrected arithematic operations
		* 2. Corrected string output to the right operators
		* 3. The choices are handled correctly including incorrect input
		**/
		switch (choice) {
		case 1 :
			num3 = num1 + num2;
			std::cout << num1 << " + " << num2 << " = " << num3 << std::endl;
			break;
		case 2 :
			num3 = num1 - num2;
			std::cout << num1 << " - " << num2 << " = " << num3 << std::endl;
			break;
		case 3 :
			num3 = num1 * num2;
			std::cout << num1 << " * " << num2 << " = " << num3 << std::endl;
			break;
		case 4:
			break;
		default : // Handles invalid input
			std::cout << "Invalid input.  Please try again.\n";
		}
	}

}