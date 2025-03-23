import InventoryProcessor;
import BasicProduct;
import <fstream>;
import <iostream>;
import "json.hpp";

using json = nlohmann::json;

/*
* Macro for allowing json to convert to custom type, in this case baseItem
* https://json.nlohmann.me/features/arbitrary_types/
*
* Decided not to use it, but leaving this here for me to remember.
*/
//NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BasicProduct, name, category, quantity, price);

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

template<typename T>
void InventoryProcessor<T>::process() { // Will be used to fill processedData json attribute
	std::cout << processedData.dump(4) << std::endl;
}

template<typename T>
void InventoryProcessor<T>::printData() {
	for (auto i : data) {
		std::cout << i << "\n" << std::endl;
	}
}
