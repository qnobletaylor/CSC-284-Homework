// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
import <iostream>;
import <string>;
#include <limits.h>; // for MAX_INT
import "cpr/cpr.h";

cpr::Response readPost(int postID);
cpr::Response addPost();
cpr::Payload createPayload();
cpr::Response updatePost(int postID);
cpr::Response deletePost(int postID);
void checkInputError(int& input);

// Global variable for URL, thinking this can be changed in one spot if you wanted to get data from another source
const std::string BASE_URL{ "https://jsonplaceholder.typicode.com/posts/" };

int main()
{
	int choice{ 0 }, postID{ 0 };
	cpr::Response response{};

	do {
		std::cout << "Please choose an action:\n\t1. Read a Post\n\t2. Add a New Post\n\t3. Update a Post\n\t4. Delete a Post\n\t5. Exit";
		std::cout << "\nChoice: ";
		checkInputError(choice);

		switch (choice)
		{
		case(1):
			std::cout << "Post ID: ";
			checkInputError(postID);
			response = readPost(postID);
			std::cout << "Fetching Post: \n" << response.text << std::endl;
			break;
		case(2):
			response = addPost();
			std::cout << "Created Post: \n" << response.text << std::endl;
			break;
		case(3):
			std::cout << "Post ID: ";
			checkInputError(postID);
			response = updatePost(postID);
			std::cout << "Updated Post: \n" << response.text << std::endl;
			break;
		case(4):
			std::cout << "Post ID: ";
			checkInputError(postID);
			response = deletePost(postID);
			std::cout << response.status_code << " Post deleted successfuly." << std::endl;
			break;
		case(5):
			std::cout << "Exiting program..." << std::endl;
			break;
		default:
			std::cerr << "Unknown command entered, please try again." << std::endl;
			break;
		}

	} while (choice != 5);
}

cpr::Response readPost(int postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };

	return cpr::Get(url);
}

cpr::Response addPost() {
	cpr::Url url{ BASE_URL };

	return cpr::Post(url, createPayload());
}

cpr::Payload createPayload() {
	std::string title{}, body{};

	std::cout << "Please enter a title: ";
	std::getline(std::cin, title);
	std::cout << "Please enter a body: ";
	std::getline(std::cin, body);

	return cpr::Payload{ {"title", title}, {"body", body}, {"userId", "1"} };
}

cpr::Response updatePost(int postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };
	std::cout << "Updating:" << readPost(postID).text << std::endl;

	return cpr::Put(url, createPayload());
}

cpr::Response deletePost(int postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };

	return cpr::Delete(url);
}

void checkInputError(int& input) {
	std::cin >> std::setw(1) >> input;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter a valid integer: ";
		std::cin >> input;
	}

	std::cin.ignore(INT_MAX, '\n');
}