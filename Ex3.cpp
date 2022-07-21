#include <iostream>
#include <map>
#include <string>

bool compare(std::map <char,char> anagram){
	bool anagrama = true;
	for (std::map<char, char>::iterator it = anagram.begin(); it != anagram.end(); ++it) {
		char buffer = it->second;
		for (std::map<char, char>::iterator itf = anagram.begin(); itf != anagram.end(); ++itf) {
			if (it->first == itf->second) {
				buffer = itf->second;
				itf->second = it->second;
			}
		}
		it->second = buffer;
	}
	for (std::map<char, char>::iterator it = anagram.begin(); it != anagram.end(); ++it) {
		anagrama = it->first == it->second;
		if (!anagrama) {
			return anagrama;
		}
	}	
}

int main() {
	std::string first;
	std::string second;
	std::map <char, char> anagram;

	std::cout << "Enter first word: ";
	std::cin >> first;
	std::cout << "Enter second word: ";
	std::cin >> second;

	if (first.length() == second.length()) {
		for (int i = 0; i < first.length(); ++i) {
			anagram.insert(std::pair<char, char>(first[i], second[i]));
		}
	}
	else {
		std::cout << "False" << std::endl;
		return 0;
	}

	compare(anagram) ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;

	return 0;
}