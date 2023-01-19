#include <iostream>
#include "prototype.h"

bool is_valid_number(const std::string& numStr) {
    int i = 0;
    int j = numStr.length() - 1;

    while (i < numStr.length() && numStr[i] == ' ')
    {
       i++;
    }
    
    while (j >= 0 && numStr[j] == ' ')
    {
        j--;
    }

    if(i > j) { return 0;}  //spacees

    if(numStr.length() == 1 && !(numStr[i] >= '0' && numStr[i] <= '9'))
    { return 0;}

    //if 1st char is not '+','-','.' or digit
    if (numStr[i] != '.' && numStr[i] != '+'
        && numStr[i] != '-' && !(numStr[i] >= '0' && numStr[i] <= '9'))
        { return 0; }

    for(i; i < j; ++i) {
        if(numStr[i] != 'e' && numStr[i] != ' ' && numStr[i] != '.'
           && !(numStr[i] >= '0' && numStr[i] <= '9')) {
            return 0;
        }

        if(numStr[i] == '.') {
            if(i + 1 > numStr.length()) { return 0;}
            std::string newStr = numStr.substr(i + 1);
            for(int m = 0; m < newStr.length(); ++m) {
                if(!(newStr[m] >= '0'&& newStr[m] <= '9')) {
                    return 0;
                }
            }
        } else if  (numStr[i] == 'e') {
            if(!(numStr[i - 1] >= '0' && numStr[i - 1] <= '9')) {
                 return 0;                         // if there is no digit before 'e'.
            }

            if (i + 1 > numStr.length()) {            //if 'e' is the last chapter
                return 0;
            }

            if (numStr[i + 1] != '+' && numStr[i + 1] != '-'
                && (numStr[i + 1] >= '0' && numStr[i + 1] <= '9')) {
                    return 0;                              
                }
        }
    }
   return 1;
}


void validate_number() {
    std::string str{};         
	std::cout << "Please enter email, for validation: \n";
	std::cin >> str;
    if (is_valid_number(str)) {
        std::cout << "Is valid number\n";
    } else {
        std::cout << "Invalid number\n";
    }
}
