#include <iostream>
#include <string>

bool is_valid_url(const std::string& url) {
    
    if(!(url.substr(0, 7) == "http://" || url.substr(0, 8) == "https://")) {
        return 0;
    }
    
    if(url.find("www") == std::string::npos) {
        return 0;
    } else {
        const int www_true_pos1 = 8;
        const int www_true_pos2 = 9;
        if(!(url.find("www") == www_true_pos1 || url.find("www") == www_true_pos2)) {
            return 0;
        }
    }

    if (url.find('.') == std::string::npos) {
        return 0;    
    } else {
        const int dot_true_pos1 = 11;
        const int dot_true_pos2 = 12;
        if(!(url.find('.') == dot_true_pos1 || url.find('.') == dot_true_pos2)) {
            return 0;
        }
    }

    if (url.find(' ') != std::string::npos) {
        return 0;    
    }
    return 1;
}

void validate_url() {
    std::string str{};              //"https://wwW.something.org/somedir";
	std::cout << "Please enter url, for validation: \n";
	std::cin >> str;

    if(is_valid_url(str)) {
        std::cout <<  "is valid\n";
    } else {
        std::cout << "not valid\n";
    }
}
