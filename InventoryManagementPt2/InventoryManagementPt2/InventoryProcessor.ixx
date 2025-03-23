module;

export module InventoryProcessor;

import "json.hpp";
import <fstream>;
import <vector>;
import <string>;

using json = nlohmann::json;

export template <typename T>
class InventoryProcessor {
private:
	std::ifstream file;
	std::vector<T> vectorData;

	void fillVector();
public:
	~InventoryProcessor();
	InventoryProcessor(const std::string& filePath);

	void printData();
};
