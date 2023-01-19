#include <iostream>
#include "prototype.h"

int main() {
	std::cout << "Please select number whose validation you want to check!\n";
    std::cout << "\t[1] Validate email\n\t[2] Validate URL\n\t[3] Validate date\n\t[4] Validate number\n\t[5] Exit\n\n\t";
    int number{};
    do {
        std::cout << "Enter your choice [ ]\b\b";
        std::cin >> number;
        switch (number) {
            case 1:
                validate_email();
                break;
            case 2:
                validate_url();
                break;
            case 3:
                validate_date();
                break;
            case 4:
                validate_number();
                break;
            case 5:
                std::cout << "Nothing is select";
                exit(0);
            default:
                std::cout << "Wrong input\n";
        }
    } while (number != 5);
	return 0;
}
