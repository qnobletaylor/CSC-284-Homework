import Library;
import <stdexcept>;
import <iostream>;
#include <ranges>
import <ranges>;
import <vector>;


Library::Library() : storage() {};

Book Library::add_book(const Book& book) {
	storage.push_back(book);
	return book;
}

Book Library::remove_book(const std::string& title) {
	for (auto iter = storage.begin(); iter != storage.end(); iter++) {
		if (!iter->title.compare(title)) {
			storage.erase(iter);
			return *iter;
		}
	}

	return Book{};
}

Book Library::find_book(const std::string& title) const {
	for (auto iter = storage.begin(); iter != storage.end(); iter++) {
		if (!iter->title.compare(title)) {
			return *iter;
		}
	}

	throw std::invalid_argument(title + " not found in library");
}

std::vector<Book> Library::get_books_by_author(const std::string& author) const {
	std::vector<Book> temp{};

	for (auto& i : storage | std::views::filter([author](Book b) {return b.author == author;})) {
		temp.push_back(i);
	}

	return temp;

}

std::vector<Book> Library::get_books_by_genre(const std::string& genre) const {
	std::vector<Book> temp;


	for (auto& i : storage | std::views::filter([genre](Book b) {return b.genre == genre;})) {
		temp.push_back(i);
	}

	return temp;
}


//std::string Library::toString() const {
//	std::stringstream ss{};
//
//
//}
