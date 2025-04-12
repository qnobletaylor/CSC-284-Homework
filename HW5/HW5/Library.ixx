export module Library;

import Book;
import <vector>;
import<string>;

export class Library {

private:
	std::vector<Book> storage;

public:
	Library();

	Book add_book(const Book& book);
	void remove_book(const std::string& title);
	Book find_book(const std::string& title) const;
	std::vector<Book> get_books_by_author(const std::string& author) const;
	std::vector<Book> get_books_by_genre(const std::string& genre) const;
	void sortDescending();
	void sortAscending();

	std::string toString() const;
};
