#include <iostream>
#include <string>

bool is_char(const char c) {
	return ((c > 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_valid_email(const std::string& email) {
	if(!is_char(email[0])) { 
		return 0;             //check the first chapter is an alphabet or not
}

	int At = -1, Dot = -1;    //for find postion Dot and At
	for(size_t i = 0; i < email.length(); i++) {
		if(email[i] == ' ') { return 0;}
		if(email[i] == '@') {
			At = i;
		} else if (email[i] == '.' ) {
			Dot = i;
		}
	}

	if(At == -1 || Dot == -1) { return 0; }    //if  "@"" or "." not present
	if(At > Dot) { return 0; }                 //if "." present befor "@""
	return !(Dot >= (email.length() - 1));     //if "." in end or no	               
}

void validate_email() {
	std::string str{};         //"mariam.khachatryan.89.m@gmail.com";
	std::cout << "Please enter email, for validation: \n";
	std::cin >> str;
	
	if(is_valid_email(str)) {
		std::cout << str << " : " << "is valid" << std::endl;
	} else {
		std::cout << str << " : " << "is not valid" << std::endl;
	}
}
