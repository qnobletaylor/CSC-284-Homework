export module DoubleSpreadsheetCell;

import SpreadsheetCell;
import <optional>;

export class DoubleSpreadsheetCell : public SpreadsheetCell {
public:
	DoubleSpreadsheetCell() = default;
	DoubleSpreadsheetCell(double value);

	void set(double value);
	void set(std::string_view value) override;
	std::string getString() const override;
private:
	std::optional<double> data;

	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);
};
