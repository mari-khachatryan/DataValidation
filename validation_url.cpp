#include <iostream>
#include <string>

bool is_valid_url(const std::string& url) {
	const unsigned start = 0;
	const unsigned start_true_pos1 = 7;
	const unsigned start_true_pos2 = 8;
    
    if(!(url.substr(start, start_true_pos1) == "http://"
	 || url.substr(start, start_true_pos2) == "https://")) {
        return 0;
    }
    
    if(url.find("www") == std::string::npos) {
        return 0;
    } else {
        const unsigned www_true_pos1 = 8;
        const unsigned www_true_pos2 = 9;
        if(!(url.find("www") == www_true_pos1 || url.find("www") == www_true_pos2)) {
            return 0;
        }
    }

    if (url.find('.') == std::string::npos) {
        return 0;    
    } else {
        const unsigned dot_true_pos1 = 11;
        const unsigned dot_true_pos2 = 12;
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
