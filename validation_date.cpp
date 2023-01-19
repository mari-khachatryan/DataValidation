#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>


bool is_digit(const char c) {
	return (c >= '0' && c <= '9');
}

const int DAYS_IN_MONTH[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool check_date_format(const std::string& date) {
    if (!(date.length() == 8 || date.length() == 10)) {
        std::cout << "Invalid!" << std::endl;
        return 0;
    }
    for(int i = 0; i < date.length(); ++i) {
        if(!(date[i] != ' ' || date[i] != '/' || date[i] != '.' ||
           !is_digit(date[i]))) { 
                return 0; 
        }
    }
    return 1;
}

bool is_leap_year(int y) {
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int days_in_month(int y, int m) {
    if (m < 1 || 12 < m) return 0;
    if (m == 2 && is_leap_year(y) == true) return 29;
    return DAYS_IN_MONTH[m - 1];
}

bool is_valid_date(const std::string& date) {
    std::string dayS{};
    std::string monthS{};
    std::string yearS{};

    if(date.length() == 8) {
        dayS = date.substr(0, 2);
        monthS = date.substr(2, 2);
        yearS = date.substr(4, 4);
    } else {
        dayS = date.substr(0, 2);
        monthS = date.substr(3, 2);
        yearS = date.substr(6, 4);
        std::cout << "d: " << dayS <<std::endl;
        std::cout << "m: " << monthS <<std::endl;
        std::cout << "y: " << yearS << std::endl;
    }

    unsigned int i;
    for (i = 0; i < yearS.length(); i++)
        if (is_digit(yearS[i]) == 0) { return 0; }
    for (i = 0; i < monthS.length(); i++)
        if (is_digit(monthS[i]) == 0) { return 0; }
    for (i = 0; i < dayS.length(); i++)
        if (is_digit(dayS[i]) == 0) { return 0; }

    int day = atoi(dayS.c_str());
    int month = atoi(monthS.c_str());
    int year = atoi(yearS.c_str());
    
    if(month < 1 || month > 12 || day < 1 || day > days_in_month(year, month)) {
        return 0;
    }
    


    return 1;
}

void validate_date() {
    std::cout << "the format of date input is: \nDDMMYYYY \n00/00/0000 \n00.00.0000 \n00 00 0000 " << std::endl;
    std::string str{};                        // "01/02/2010";
	std::cout << "Please enter date, for validation: \n";
	std::cin >> str;

    if(check_date_format(str)) { 
        if(is_valid_date(str)) {
            std::cout << "Format is correct, is valid date!\n";
        } else {
            std::cout << "invalid date!\n";
        }
    } else {
        std::cout << "Format is not correct!\n";
    }
}
