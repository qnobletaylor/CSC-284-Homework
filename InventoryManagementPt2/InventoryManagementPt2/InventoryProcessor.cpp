import InventoryProcessor;
import BasicProduct;
import <fstream>;
import <iostream>;
import <string>;
import <map>;
import "json.hpp";

using json = nlohmann::json;

/*
* Macro for allowing json to convert to custom type, in this case BasicProduct
* https://json.nlohmann.me/features/arbitrary_types/
*
* Decided not to use it, but leaving this here for me to remember.
* NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BasicProduct, name, category, quantity, price);
*/

/**
 * Ensures that only InventoryProcessors of type BasicProduct can be instatianted. To use another type, another product class would need
 * to be defined as well as have a from_json method implemented. Then added as a explicit specialization of this template class.
 *  */
template class InventoryProcessor<BasicProduct>; // Explicit instatiation

template<typename T>
InventoryProcessor<T>::InventoryProcessor() : data(), processedData() {}

template<typename T>
InventoryProcessor<T>::InventoryProcessor(const std::string& filePath) : data(), processedData() {
	readFromFile(filePath);
}

/**
 * Reads from a file, parsing the file into a json object and further taking that jsonData and putting it into a vector.
 *  */
template<typename T>
void InventoryProcessor<T>::readFromFile(const std::string& filePath) {
	std::ifstream file(filePath);

	if (!file.good()) {
		throw std::string("Error opening json file...");
	}
	else {
		json jsonData = json::parse(file);
		for (auto& i : jsonData["inventory"]) {
			T product(i);
			data.push_back(product);
		}
	}
	file.close();
}

/**
 * Takes the objects stored in this class' vector and groups them by similar categories as well as keeping
 * track of the total items and total value of the categories.
 *
 * Additionally, the highest valued item is found as well as the total value of all items.
 *
 * I can't think of a way to make this generic at the moment so only the BasicProduct instance of this method
 * is currently defined.
 *  */
template<>
void InventoryProcessor<BasicProduct>::process() { // Will be used to fill processedData json attribute
	std::map<std::string, std::pair<int, double>> categories{};
	double totalValue{ 0 }, value{ 0 };
	BasicProduct highestValue{};

	for (const auto& i : data) { // Adds each object to the map, only concerned with category so name is omitted
		value = (i.price * i.quantity);
		if (highestValue.price < i.price) highestValue = i;
		totalValue += value;

		if (categories.emplace(i.category, std::pair<int, double>(i.quantity, value)).second) {
		}
		else { // If map already contains something in that category, then the quantity and total value is increased
			categories.at(i.category).first += i.quantity;
			categories.at(i.category).second += value;
		}
	}
}

template<typename T>
void InventoryProcessor<T>::printData() {
	for (const auto& i : data) {
		std::cout << i << "\n" << std::endl;
	}
}
