import InventoryProcessor;
import BasicProduct;
import <fstream>;
import <iostream>;
import "json.hpp";

using json = nlohmann::json;

/*
* Macro for allowing json to convert to custom type, in this case baseItem
* https://json.nlohmann.me/features/arbitrary_types/
*/
//NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BasicProduct, name, category, quantity, price);


template<>
InventoryProcessor<BasicProduct>::~InventoryProcessor() {
	file.close();
}

template<typename T>
InventoryProcessor<T>::~InventoryProcessor() {
	file.close();
}

template<>
InventoryProcessor<BasicProduct>::InventoryProcessor(const std::string& filePath) : file(filePath), vectorData(), product() {
	if (!file.is_open()) {
		throw std::string("Failed to open file");
	}
	else {
		fillVector();
	}
}

template<typename T>
InventoryProcessor<T>::InventoryProcessor(const std::string& filePath) : file(filePath), vectorData(), product() {
	if (!file.is_open()) {
		throw std::string("Failed to open file");
	}
	else {
		fillVector();
	}
}

template<>
void InventoryProcessor<BasicProduct>::fillVector() {
	json data = json::parse(file);
	for (auto& i : data["inventory"]) {
		product.from_json(i);
		vectorData.push_back(product);
	}
}

template<typename T>
void InventoryProcessor<T>::fillVector() {
	json data = json::parse(file);
	for (auto& i : data["inventory"]) {
		product.from_json(i);
		vectorData.push_back(product);
	}
}

template<>
void InventoryProcessor<BasicProduct>::printData() {
	for (auto i : vectorData) {
		std::cout << i << "\n" << std::endl;
	}
}

template<typename T>
void InventoryProcessor<T>::printData() {
	for (auto i : vectorData) {
		std::cout << i << "\n" << std::endl;
	}
}