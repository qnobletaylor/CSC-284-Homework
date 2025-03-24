module;

export module BasicProduct;

import "json.hpp";
import <string>;
import <iostream>;

using json = nlohmann::json;

// ** Using this to test template class **
//class anotherObject {
//public:
//	std::string name;
//	std::string category;
//	unsigned int quantity;
//	double price;
//	std::string desc;
//
//	void from_json(const json& j) {
//		j.at("name").get_to<std::string>(this->name);
//		j.at("category").get_to<std::string>(this->category);
//		j.at("quantity").get_to<unsigned int>(this->quantity);
//		j.at("price").get_to<double>(this->price);
//		j.at("desc").get_to<std::string>(this->desc);
//	}
//
//	friend std::ostream& operator<<(std::ostream& stream, const anotherObject& product) {
//		stream << "product.toString()";
//		return stream;
//	}
//};

export class BasicProduct {
public:
	std::string name;
	std::string category;
	unsigned int quantity;
	double price;

	BasicProduct();
	BasicProduct(const json& j);
	friend std::ostream& operator<<(std::ostream& stream, const BasicProduct& product);

	std::string toString() const;
	void from_json(const json& j);
};


