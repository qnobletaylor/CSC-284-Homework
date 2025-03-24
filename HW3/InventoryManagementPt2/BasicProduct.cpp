import BasicProduct;
import "json.hpp";
import <format>;

using json = nlohmann::json;

BasicProduct::BasicProduct() {
	this->name = "";
	this->category = "";
	this->quantity = 0;
	this->price = 0;
}

/**
 * Constructor for initializing attributes with a given json object.
 *  */
BasicProduct::BasicProduct(const json& j) {
	from_json(j);
}

/**
 * Overloading << operator to call this class' toString method when an object of this class is put into an ostream.
 *  */
std::ostream& operator<<(std::ostream& stream, const BasicProduct& product) {
	stream << product.toString();
	return stream;
}

/**
 * Takes a json object and sets the attributes of a BasicProduct to the corresponding json types.
 *  */
void BasicProduct::from_json(const json& j) {
	j.at("name").get_to<std::string>(this->name);
	j.at("category").get_to<std::string>(this->category);
	j.at("quantity").get_to<unsigned int>(this->quantity);
	j.at("price").get_to<double>(this->price);
}

/**
 * Returns a string with each object attribute formatted neatly.
 *  */
std::string BasicProduct::toString() const {
	return std::format("name: {}\ncategory: {}\nquantity: {}\nprice: {}", name, category, quantity, price);
}
