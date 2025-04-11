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
	Book remove_book(const std::string& title);
	Book find_book(const std::string& title);
	std::vector<Book> get_books_by_author(const std::string& author);
	std::vector<Book> get_books_by_genre(const std::string& genre);

	std::string toString();
};
