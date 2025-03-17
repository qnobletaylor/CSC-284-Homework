import DoubleSpreadsheetCell;

DoubleSpreadsheetCell::DoubleSpreadsheetCell(double value) {
	set(value);
}

void DoubleSpreadsheetCell::set(std::string_view value) {
	this->data = stringToDouble(value);
}

void DoubleSpreadsheetCell::set(double value) {
	this->data = value;
}

std::string DoubleSpreadsheetCell::getString() const {
	return doubleToString(data.value());
}

std::string DoubleSpreadsheetCell::doubleToString(double value) {
	return std::to_string(value);
}

double DoubleSpreadsheetCell::stringToDouble(std::string_view value) {
	return std::strtod(value.data(), nullptr);
}
