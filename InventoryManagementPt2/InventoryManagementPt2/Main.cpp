#include <json.hpp>
import <iostream>;
import <fstream>;
import InventoryProcessor;

using json = nlohmann::json;

int main() {

	InventoryProcessor<basicItem> s("inventory.json");

	return 0;
}
