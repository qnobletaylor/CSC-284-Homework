import Book;
import Library;
import <iostream>;

int main() {
	Library lib{};

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

	std::cout << "Printing Library: \n" << lib.toString() << std::endl;

	std::cout << "Searching for books by author \"J.R.R. Tolkien\"\n";
	std::cout << Library{ lib.get_books_by_author("J.R.R. Tolkien") }.toString();

	std::cout << "Searching for books by genre \"Fiction\"\n";
	std::cout << Library{ lib.get_books_by_genre("Fiction") }.toString();

	std::cout << "Sorting library by release date, descending...\n";
	lib.sortDescending();
	std::cout << lib.toString();


	return 0;
}
