import Book;
import <format>;

Book::Book() : Book("", "", 0, "") {};

Book::Book(std::string title, std::string author, int year, std::string genre) {
	this->title = title;
	this->author = author;
	this->year = year;
	this->genre = genre;
}

std::string Book::toString() const {
	return std::format("{} by {}\n\t({}) [{}]", title, author, year, genre);
}
