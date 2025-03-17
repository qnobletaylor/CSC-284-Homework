export module StringSpreadsheetCell;

import SpreadsheetCell;
import <optional>;

export class StringSpreadsheetCell : public SpreadsheetCell {
public:
	StringSpreadsheetCell() = default;
	StringSpreadsheetCell(std::string_view value);

	void set(std::string_view value) override;
	std::string getString() const override;
private:
	std::optional<std::string> data;
};
