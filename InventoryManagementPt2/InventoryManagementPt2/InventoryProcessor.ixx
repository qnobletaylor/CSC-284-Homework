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

public:
	InventoryProcessor();
	InventoryProcessor(const std::string& filePath);

	void readFromFile(const std::string& filePath);
	void process();
	void printData();
};