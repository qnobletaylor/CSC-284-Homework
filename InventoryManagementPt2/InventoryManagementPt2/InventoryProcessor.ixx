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

//void to_json(json& j, const basicItem& i) {
//	j = json{ {"name", i.name},
//		{"category", i.category},
//		{"quantity", i.quantity},
//		{"price", i.price} };
//}
//
//void from_json(const json& j, basicItem& i) {
//	j.at("name").get_to(i.name);
//	j.at("category").get_to(i.category);
//	j.at("quantity").get_to(i.quantity);
//	j.at("price").get_to(i.price);
//}

export template <typename T>
class InventoryProcessor {
private:
	std::ifstream file;
	std::vector<T> vectorData;

	void fillVector();
public:
	InventoryProcessor(const std::string& filePath);
};
