import Library;
import <stdexcept>;
import <sstream>;
#include <ranges>
import <ranges>;
import <vector>;


Library::Library() : storage() {};

/**
 * Simply adds a book to the vector of books.
 *
 * Returns the added book.
 *  */
Book Library::add_book(const Book& book) {
	storage.push_back(book);
	return book;
}

/**
 * Uses erase function and remove_if to iterate through the vector of books and remove all books with the given matching title.
 *
 * If there are more than one book with a matching title, then multiple removals will be made.
 *  */
void Library::remove_book(const std::string& title) {
	storage.erase(std::remove_if(storage.begin(), storage.end(),
		[title](Book b) { return b.title == title; }), storage.end());
}

/**
 * Iterates through the list of books until a matching title is found and returns the book.
 *
 * Else, throws a invalid_argument exception indicating the book is not present.
 *  */
Book Library::find_book(const std::string& title) const {
	for (auto iter = storage.begin(); iter != storage.end(); iter++) {
		if (!iter->title.compare(title)) {
			return *iter;
		}
	}

	throw std::invalid_argument(title + " not found in library");
}

/**
 * Filters the list of books to find all books by a given author.
 *
 * Return the list of books with matching author.
 *  */
std::vector<Book> Library::get_books_by_author(const std::string& author) const {
	std::vector<Book> temp{};

	for (auto& i : storage | std::views::filter([author](Book b) {return b.author == author;})) {
		temp.push_back(i);
	}

	return temp;
}

/**
 * Filters the list of books to find all books in a given genre.
 *
 * Return the list of books with matching genre.
 *  */
std::vector<Book> Library::get_books_by_genre(const std::string& genre) const {
	std::vector<Book> temp{};

	for (auto& i : storage | std::views::filter([genre](Book b) {return b.genre == genre;})) {
		temp.push_back(i);
	}

	return temp;
}

/**
 * Returns a string with all books in the library.
 *  */
std::string Library::toString() const {
	std::stringstream ss{};
	ss << "Library Contents:\n";
	for (auto iter = storage.begin(); iter != storage.end(); iter++) {
		ss << iter->toString() << "\n";
	}
	return ss.str();
}
