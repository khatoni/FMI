#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
const int MAX_SIZE = 128;
const int MAX_LENGTH = 100;
struct User {
	char Name[MAX_SIZE];
	char Email[MAX_SIZE];
	char Password[MAX_SIZE];
};
struct System {
	size_t numberOfUsers;
	User users[MAX_LENGTH];
};
void parse(System& system, const char* buff, size_t position) {
	int i = 0;
	char name[MAX_SIZE];
	char email[MAX_SIZE];
	char password[MAX_SIZE];
	while (buff[i] != ' ') {
		name[i] = buff[i];
		i++;
	}
	name[i] = '\0';
	i++;
	size_t counter_length = 0;
	while (buff[i] != ' ') {
		email[counter_length] = buff[i];
		i++;
		counter_length++;
	}
	email[counter_length] = '\0';
	i++;
	counter_length = 0;
	while (buff[i] != '\0') {
		password[counter_length] = buff[i];
		counter_length++;
		i++;
	}
	password[counter_length] = '\0';
	strcpy(system.users[position].Name, name);
	strcpy(system.users[position].Email, email);
	strcpy(system.users[position].Password, password);
}
void read(System& system) {
	size_t numb;
	std::ifstream inFile("users.txt");
	if (!inFile.is_open()) {
		std::cout << "Error while opening the file";
		return;
	}
	inFile >> numb;
	system.numberOfUsers = numb;
	size_t position = 0;
	char buffer[MAX_SIZE];
	for (int i = 0; i < numb; i++) {
		parse(system, buffer, position);
	}
	inFile.close();
}
void writeToFile(const System& system) {
	std::ofstream outFile("users.txt", std::ios::app);
	if (!outFile.is_open()) {
		std::cout << "Error while opening the file";
		return;
	}
	size_t NumberOfUsers = system.numberOfUsers;
	outFile << NumberOfUsers << std::endl;
	for (int i = 0; i < NumberOfUsers; i++) {
		outFile << system.users[i].Name << " " << system.users[i].Email << " " << system.users[i].Password <<std::endl;
	}
	outFile.close();
}
int main() {
	System system;
	/*system.numberOfUsers = 2;
	for (int i = 0; i < system.numberOfUsers; i++) {
		char name[MAX_SIZE];
		char email[MAX_SIZE];
		char password[MAX_SIZE];
		std::cin.getline(name, MAX_SIZE);
		strcpy(system.users[i].Name, name);
		std::cin.getline(email, MAX_SIZE);
		strcpy(system.users[i].Email, email);
		std::cin.getline(password, MAX_SIZE);
		strcpy(system.users[i].Password, password);
	}
	writeToFile(system);*/
	read(system);
	size_t NumberOfUsers = system.numberOfUsers;
	for (int i = 0; i < NumberOfUsers; i++) {
		std::cout << system.users[i].Name << " " << system.users[i].Email << " " << system.users[i].Password << std::endl;
	}

	return 0;
}