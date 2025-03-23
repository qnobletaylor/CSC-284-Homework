/*
* Website I found particularly helpful:
* https://www.studyplan.dev/pro-cpp/json#The%20JSON%20Data%20Format
*/

import "json.hpp";
import <iostream>;
import <fstream>;
import "json.hpp";
import InventoryProcessor;
import BasicProduct;


using json = nlohmann::json;

// ** Using this to test template class **
//class anotherObject {
//public:
//	std::string name;
//	std::string category;
//	unsigned int quantity;
//	double price;
//
//	void from_json(const json& j) {
//		j.at("name").get_to<std::string>(this->name);
//		j.at("category").get_to<std::string>(this->category);
//		j.at("quantity").get_to<unsigned int>(this->quantity);
//		j.at("price").get_to<double>(this->price);
//	}
//
//	friend std::ostream& operator<<(std::ostream& stream, const anotherObject& product) {
//		stream << "product.toString()";
//		return stream;
//	}
//};

int main() {

	try {
		InventoryProcessor<BasicProduct> inventory;
		inventory.readFromFile("./inventory.json");
		inventory.process();
		inventory.writeToFile("./test.json");
	}
	catch (const std::string& e) {
		std::cerr << e << std::endl;
	}

	return 0;
}
