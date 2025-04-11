export module Book;

import <string>;

export class Book {
public:
	std::string title;
	std::string author;
	int year;
	std::string genre;



	Book();
	Book(std::string, std::string, int, std::string);

	std::string toString() const;
};
