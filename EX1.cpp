#include <iostream>
#include <string>
#include <map>

int main() {
	std::map<std::string, std::string> phonebook;
	std::string number, family;
	do {
		number.clear();
		family.clear();
		do {
			std::cout << "Enter data: ";
			std::cin >> number;
			if (number[0] >= 48 && number[0] <= 57) {
				if (std::cin.peek() >= 32) {
					std::cin >> family;
				}
			}
			else if ((number[0] >= 'A' && number[0] <= 'Z') || (number[0] >= 'a' && number[0] <= 'z')) {
				family = number;
				number.clear();
			}
			else {
				number.clear();
				std::cout << "Wrong data!" << std::endl;
			}
		} while (!number.size() && !family.size());

		std::cout << number << "|" << family << std::endl;

		if (!family.size()) {
			std::cout << phonebook[number] << std::endl;
		}
		else if (!number.size()) {
			for (std::map<std::string, std::string>::iterator it = phonebook.begin(); it != phonebook.end(); ++it) {
				if (it->second == family) std::cout << it->first << std::endl;
			}
		}
		else {
			phonebook.insert(std::pair<std::string, std::string>(number, family));
			std::cout << "Data recorded." << std::endl;
		}
	} while (family != "exit");
	
	
	return 0;
}