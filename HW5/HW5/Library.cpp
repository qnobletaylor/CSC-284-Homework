import Library;
import <stdexcept>;
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

	return Book();
}

Book Library::find_book(const std::string& title) {
	for (auto iter = storage.begin(); iter != storage.end(); iter++) {
		if (!iter->title.compare(title)) {
			return *iter;
		}
	}

	throw std::invalid_argument(title + " not found in library");
}

std::vector<Book> Library::get_books_by_author(const std::string& author) {
	auto temp = storage | std::views::filter([author](Book b) {return b.author == author;});

	return temp;
}

std::vector<Book> Library::get_books_by_genre(const std::string& genre) {
	auto temp = storage | std::views::filter([genre](Book b) {return b.genre == genre;}) | std::ranges::to<std::vector>();

	return temp;
}
