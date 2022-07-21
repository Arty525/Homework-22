#include <iostream>
#include <string>
#include <map>

int main() {
	std::map<int, std::string> queue;
	std::string surname;
	std::string command;
	std::string next;
	int n = 0;
	
	do {
		std::cout << "Enter data: ";
		std::cin >> command;
		if (command == "Exit" || command == "exit") {
			break;
		}
		if ((command != "next" || command != "Next") && (command[0] >= 'A' && command[0] <= 'Z')) {
			surname = command;
			queue.insert(std::pair<int, std::string>(n, surname));
			std::cout << "Data recorded." << std::endl;
			++n;
		}
		else if (command == "next" || command == "Next") {
			if (queue.size() > 0) {
				int num = queue.begin()->first;
				next = queue.begin()->second;
				for (std::map<int, std::string>::iterator it = queue.begin(); it != queue.end(); ++it) {
					if (it->second < next && it != queue.end()) {
						next = it->second;
						num = it->first;
					}
				}
				std::cout << next << std::endl;
				queue.erase(num);
			}
			else {
				std::cout << "There is no one in the queue" << std::endl;
			}
		}
		else if ((command != "Exit" || command != "exit") && (command[0] < 'A' || command[0] > 'Z')) {
			std::cout << "Surname is capitalized." << std::endl;
		}
	} while (command != "exit" || command != "Exit");
	
	return 0;
}