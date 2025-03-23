module;

export module InventoryProcessor;

import "json.hpp";
import <vector>;
import <string>;
import BasicProduct;

using json = nlohmann::json;


export template <typename T>
class InventoryProcessor {
private:
	std::vector<T> data;
	json processedData;

	void createCustomJson(const std::map<std::string, std::pair<int, double>>&, const T&, const double&);
public:
	InventoryProcessor();
	InventoryProcessor(const std::string& filePath);

	void readFromFile(const std::string& filePath);
	void writeToFile(const std::string& filePath);
	void process();
};