import InventoryProcessor;
import <fstream>;
import <iostream>;
#include "json.hpp"

using json = nlohmann::json;

/*
* Macro for allowing json to convert to custom type, in this case baseItem
* https://json.nlohmann.me/features/arbitrary_types/
*/
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(basicItem, name, category, quantity, price);

template<>
InventoryProcessor<basicItem>::InventoryProcessor(const std::string& filePath) : file(filePath), vectorData() {
	if (!file.is_open()) {
		std::cout << "failed to open" << std::endl;
	}
	else {
		fillVector();
	}

}

template<>
void InventoryProcessor<basicItem>::fillVector() {
	json data = json::parse(file);
	for (auto i : data["inventory"]) {
		basicItem item;

		item = i.template get<basicItem>();

		vectorData.push_back(item);
	}

	std::cout << vectorData.at(0).category << std::endl;
}
