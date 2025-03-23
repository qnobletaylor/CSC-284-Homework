#include <json.hpp>
import <iostream>;
import <fstream>;
import InventoryProcessor;

using json = nlohmann::json;

int main() {

	try {
		InventoryProcessor<basicItem> inventory("./inventory.json");
		inventory.printData();
	}
	catch (const std::string& e) {
		std::cout << e << std::endl;
	}

	return 0;
}
