/*
* Website I found particularly helpful:
* https://www.studyplan.dev/pro-cpp/json#The%20JSON%20Data%20Format
*/

import "json.hpp";
import <iostream>;
import <fstream>;
import InventoryProcessor;
import BasicProduct;

using json = nlohmann::json;

int main() {

	try {
		InventoryProcessor<BasicProduct> inventory("./inventory.json");
		inventory.printData();
	}
	catch (const std::string& e) {
		std::cerr << e << std::endl;
	}

	return 0;
}
