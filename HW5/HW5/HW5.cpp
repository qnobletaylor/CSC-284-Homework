import Book;
import Library;
import <iostream>;

int main() {

	Library lib{};

	lib.add_book(Book{ "book1", "author1", 2022, "genre1" });
	lib.add_book(Book{ "book2", "author2", 2022, "genre1" });
	lib.add_book(Book{ "book3", "author3", 2022, "genre2" });
	lib.add_book(Book{ "book4", "author2", 2022, "genre3" });
	lib.add_book(Book{ "book5", "author1", 2022, "genre1" });
	lib.add_book(Book{ "book6", "author1", 2022, "genre1" });


	auto list = lib.get_books_by_author("author1");

	auto list2 = lib.get_books_by_genre("genre1");

	for (auto i : list) {
		std::cout << i.toString() << "\n";
	}
	for (auto i : list2) {
		std::cout << i.toString() << "\n";
	}



	return 0;
}
