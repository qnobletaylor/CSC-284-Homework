import StringSpreadsheetCell;

StringSpreadsheetCell::StringSpreadsheetCell(std::string_view value) {
	set(value);
}

void StringSpreadsheetCell::set(std::string_view value) {
	this->data = value;
}

std::string StringSpreadsheetCell::getString() const {
	return data.value_or("");
}
