import BasicProduct;
import "json.hpp";

using json = nlohmann::json;

BasicProduct::BasicProduct() {
	this->name = "";
	this->category = "";
	this->quantity = 0;
	this->price = 0;
}

BasicProduct::BasicProduct(const json& j) {
	from_json(j);
}

void BasicProduct::from_json(const json& j) {
	j.at("name").get_to<std::string>(this->name);
	j.at("category").get_to<std::string>(this->category);
	j.at("quantity").get_to<unsigned int>(this->quantity);
	j.at("price").get_to<double>(this->price);
}
