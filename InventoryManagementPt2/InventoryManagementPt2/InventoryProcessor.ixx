module;
#include "json.hpp" // include must go before export module

export module InventoryProcessor;

import <fstream>;
import <vector>;
import <string>;

using json = nlohmann::json;

export class basicItem
{
public:
	std::string name;
	std::string category;
	unsigned int quantity;
	double price;
};

export template <typename T>
class InventoryProcessor {
private:
	std::ifstream file;
	std::vector<T> vectorData;

	void fillVector();
public:
	InventoryProcessor(const std::string& filePath);
};
