import InventoryProcessor;
import <fstream>;
import <iostream>;
#include "json.hpp"

using json = nlohmann::json;

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
		i.at("name").get_to(item.name);
		i.at("category").get_to(item.category);
		i.at("quantity").get_to(item.quantity);
		i.at("price").get_to(item.price);

		vectorData.push_back(item);
	}

	std::cout << vectorData.at(0).category << std::endl;
}
