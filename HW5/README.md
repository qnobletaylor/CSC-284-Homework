### STL Ranges, Views, and Iterators

This program implements a Library class which holds  a range (in this case a vector) of Book objects. The Library 
class then implements several methods for filtering, sorting, adding, removing, and searching for Books. Each method 
uses C++ STL methods for accesing or mutating the range of Books. The main method of the program within ``HW5.cpp`` 
will output to the console a preset library of ten books as well as a demo of each method within the Library class, 
this is simply meant to literally demonstrate the functionality of the Library class.

---
- ``add_book(const Book& book)`` : adds a book to the Library

- ``remove_book(const std::string& title)`` : removes a book, or books, of a given title from the Library

- ``find_book(const std::string& title)`` : finds a book of a given title and returns the object

- ``get_books_by_author(const std::string& author)`` : returns a vector of Books that share a given author name

- ``get_books_by_genre(const std::string& genre)`` : returns a vector of books that share a given genre

- ``filter_by_year(const int& year)`` : returns a vector of Books published on or after a given year

- ``sortDescending()`` : sorts the Library by date of publish, descending

- ``sortAscending()`` : sorts the Library by date of publish, ascending

---

To run, simply open the solution file ``~./HW5/HW5.sln`` with Visual Studio 2022 and hit ``ctrl + F5`` on your keyboard.