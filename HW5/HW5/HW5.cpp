import Book;
import Library;
import <iostream>;


int main() {
	Library lib{};

	// Adding books to Library
	lib.add_book(Book{ "1984", "George Orwell", 1949, "Dystopian" });
	lib.add_book(Book{ "Animal Farm", "George Orwell", 1945, "Dystopian" });
	lib.add_book(Book{ "The Hobbit", "J.R.R. Tolkien", 1937, "Fantasy" });
	lib.add_book(Book{ "The Fellowship of the Ring", "J.R.R. Tolkien", 1954, "Fantasy" });
	lib.add_book(Book{ "Pride and Prejudice", "Jane Austen", 1813, "Romance" });
	lib.add_book(Book{ "Jane Eyre", "Charlotte Brontë", 1847, "Romance" });
	lib.add_book(Book{ "The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction" });
	lib.add_book(Book{ "To Kill a Mockingbird", "Harper Lee", 1960, "Fiction" });
	lib.add_book(Book{ "Frankenstein", "Mary Shelley", 1818, "Fiction" });
	lib.add_book(Book{ "Dracula", "Bram Stoker", 1897, "Fiction" });

	std::cout << "Printing Library: \n" << lib.toString(); // Example of Library prior to changes/filtering

	std::cout << "Searching for books by author \"J.R.R. Tolkien\"\n"; // Example of filtering by author
	std::cout << Library{ lib.get_books_by_author("J.R.R. Tolkien") }.toString();

	std::cout << "Searching for books by genre \"Fiction\"\n"; // Example of filtering by genre
	std::cout << Library{ lib.get_books_by_genre("Fiction") }.toString();

	std::cout << "Sorting library by release date, descending...\n"; // Example of sorting books by year
	lib.sortDescending(); // Also possible to do in ascending order
	std::cout << lib.toString();

	std::cout << "Filtering List for books published after 1945\n"; // Example of filtering by a given year
	std::cout << Library{ lib.filter_by_year(1945) }.toString();

	std::cout << "Searching for book \"Animal Farm\"...\n";
	try { // Examples of searching for a deleting books
		std::cout << lib.find_book("Animal Farm").toString();
		std::cout << "\nBook found, now removing and attempting to search again...";
		lib.remove_book("Animal Farm");
		std::cout << lib.find_book("Animal Farm").toString();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "End of demo..." << std::endl;

	return 0;
}
