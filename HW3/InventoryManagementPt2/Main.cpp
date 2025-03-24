/*
* Sources I found particularly helpful for using nlohmann/json in addition to the documentation:
* https://www.studyplan.dev/pro-cpp/json#The%20JSON%20Data%20Format
*
* https://www.youtube.com/watch?v=NuWQp_uAvwo
*/

import <iostream>;
import <fstream>;
import <filesystem>;
import <string>;
import InventoryProcessor;
import BasicProduct;


int main() {
	char choice{ 'x' };
	std::filesystem::path filePath{};
	InventoryProcessor<BasicProduct> inventory;

	// Prompt for read file name
	std::cout << "Please enter a json file name/path to read from: ";
	std::cin >> filePath;
	// Validate file existence
	while (!std::filesystem::exists(filePath) || filePath.extension() != ".json") {
		std::cerr << "Please enter valid json file name/path to read from (including extension): ";
		std::cin >> filePath; // std::filesystem::path overloads '>>' operator, converts string to path
	}
	// Reading from file/processing
	try {
		inventory.readFromFile(filePath.string());

		std::cout << "Succesfully read from file, contents:\n\n" << inventory.getData() << std::endl;
		std::cout << "Processing Data..." << std::endl;

		inventory.process();
	}
	catch (const std::string& e) {
		std::cerr << e << std::endl;
		return -1;
	}

	// Prompt for write file name
	std::cout << "Please enter a file name/path to write processed data to: ";
	std::cin >> filePath;
	// Validate input
	while (std::filesystem::exists(filePath)) {
		std::cout << "File already exists, would you like to make a copy or choose a new filename to create:";
		std::cout << "\n\tA) Make a copy\n\tB) Choose new file name\n";
		std::cin >> std::setw(1) >> choice; // setw(1) only allows single char input

		switch (choice)
		{
		case 'A':
		case 'a':
			std::filesystem::rename(filePath, "old_" + filePath.string());
			break;
		case 'B':
		case 'b':
			std::cout << "Enter new file name to write to: ";
			std::cin >> std::setw(0) >> filePath;
			break;
		default:
			std::cout << "Unknown choice entered..." << std::endl;
			break;
		}
	}

	// Check for proper extension
	if (filePath.extension() != ".json" || !filePath.has_extension()) {
		std::cerr << "Incorrect file extension, replacing with .json" << std::endl;
		filePath.replace_extension(".json");
	}

	// Writing to file
	try {
		inventory.writeToFile(filePath.string());
		std::cout << "Writing to file successful...Output:\n\n";
		std::cout << inventory.getProcessedData() << std::endl;
	}
	catch (const std::string& e) {
		std::cerr << e << std::endl;
		return -1;
	}

	std::cout << "Program ending..." << std::endl;

	return 0;
}
