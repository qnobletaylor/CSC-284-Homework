import SpreadsheetCell;
import StringSpreadsheetCell;
import DoubleSpreadsheetCell;
import <vector>;
import <memory>;
import <iostream>;

int main() {
	std::vector<std::unique_ptr<SpreadsheetCell>> spreadSheet{};

	auto string1 = std::make_unique<StringSpreadsheetCell>("hello");
	auto string2 = std::make_unique<StringSpreadsheetCell>("10");
	auto double1 = std::make_unique<DoubleSpreadsheetCell>(18.5);

	spreadSheet.push_back(std::move(string1));
	spreadSheet.push_back(std::move(string2));
	spreadSheet.push_back(std::move(double1));

	std::cout << "[";
	for (int i = 0; i < spreadSheet.size(); i++) {
		std::cout << spreadSheet.at(i)->getString();
		if (i != spreadSheet.size() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;

}
