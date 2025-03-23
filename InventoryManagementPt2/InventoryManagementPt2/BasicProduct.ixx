module;

export module BasicProduct;

import "json.hpp";
import <string>;
import <iostream>;

using json = nlohmann::json;

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


