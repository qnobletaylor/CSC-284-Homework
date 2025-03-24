import InventoryProcessor;
import BasicProduct;
import <fstream>;
import <iostream>;
import <sstream>;
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
		throw std::string("Error opening json file to read from.");
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
 * Writes the processedData json object to a file of a given name.
 *  */
template<typename T>
void InventoryProcessor<T>::writeToFile(const std::string& filePath) {
	std::ofstream file(filePath);

	if (!file.good()) {
		throw std::string("Error opening file to write to.");
	}
	else {
		file << processedData.dump(4); //argument '4' sets tab size to 4 which makes output pretty
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
template<typename T>
void InventoryProcessor<T>::process() { // Will be used to fill processedData json attribute
	std::map<std::string, std::pair<int, double>> categories{};
	double totalValue{ 0 }, value{ 0 };
	T highestValue{};

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

	createCustomJson(categories, highestValue, totalValue);
}

/**
 * Takes data in a map, product, and totalValue:double and puts parses it back to json format.
 * This method is fairly specific to BasicProduct, it needs to be made more generic or any other data type
 * woudl also need to have at least the same attributes as BasicProduct (name, category, quantity, and price)
 *  */
template<typename T>
void InventoryProcessor<T>::createCustomJson(const std::map<std::string, std::pair<int, double>>& map, const T& product, const double& totalValue) {
	processedData["total_stock_value"] = totalValue;
	processedData["most_expensive_product"]["name"] = product.name;
	processedData["most_expensive_product"]["price"] = product.price;

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		processedData["category_summary"][iter->first]["total_items"] = iter->second.first;
		processedData["category_summary"][iter->first]["total_value"] = iter->second.second;
	}
}

/**
 * Puts each item toString into a stringstream and returns the result. Also checks if data has been parsed yet.
 *  */
template<typename T>
std::string InventoryProcessor<T>::getData() const {
	std::ostringstream ss{};

	if (data.empty()) {
		ss << "No data has been parsed yet.";
	}
	else {
		for (const auto& item : data) {
			ss << item << "\n\n";
		}
	}

	return ss.str();
}

/**
 * Checks if data has been processed yet, returns it as a neatly formatted string if so.
 *  */
template<typename T>
std::string InventoryProcessor<T>::getProcessedData() const {
	if (processedData.empty()) {
		return "Data has not been processed yet.";
	}
	else {
		return processedData.dump(4);
	}
}
