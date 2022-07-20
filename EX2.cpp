#include <iostream>
#include <string>
#include <map>

int main() {
	std::map<int, std::string> queue;
	std::string surname;
	std::string command;
	
	for (int n = 0; command != "exit"; ++n) {
		std::cout << "Enter data: ";
		std::cin >> command;
		if (command != "next") {
			surname = command;
			queue.insert(std::pair<int, std::string>(n, surname));
			std::cout << "Data recorded." << std::endl;
		}
		else {
			for (std::map<int, std::string>::iterator it = queue.begin(); it != queue.end(); ++it) {
				if (it->second == surname) std::cout << it->second << std::endl;
			}
		}
	}

	//Цикл сортировки аналогичный сортировке векторов
	return 0;
}