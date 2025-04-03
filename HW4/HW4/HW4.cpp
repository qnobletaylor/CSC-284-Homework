// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
import <iostream>;
import <string>;
import <stdexcept>;
#include <limits.h>; // for MAX_INT
import "cpr/cpr.h";

cpr::Response readPost(const int& postID);
cpr::Response addPost();
cpr::Payload createPayload();
cpr::Response updatePost(const int& postID);
cpr::Response deletePost(const int& postID);
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
		case(1): // GET
			try
			{
				std::cout << "Post ID: ";
				checkInputError(postID);
				response = readPost(postID);

				std::cout << "Fetching Post: \n" << response.text << std::endl;
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}

			break;
		case(2): // POST
			response = addPost();
			std::cout << "Created Post: \n" << response.text << std::endl;

			break;
		case(3): // PUT
			try
			{
				std::cout << "Post ID: ";
				checkInputError(postID);
				response = updatePost(postID);
				std::cout << "Updated Post: \n" << response.text << std::endl;
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}

			break;
		case(4): // DELETE
			try
			{
				std::cout << "Post ID: ";
				checkInputError(postID);
				response = deletePost(postID);
				std::cout << response.status_code << " Post deleted successfuly." << std::endl;
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}

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

/**
 * Returns a get Response from the server using postID to determine what data to get.
 *
 * Throws invalid_argument if there is no post for the given postID param.
 *  */
cpr::Response readPost(const int& postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };
	cpr::Response temp = cpr::Get(url);

	if (temp.status_code != 200) throw std::invalid_argument("Error: post does not exist.");

	return temp;
}

/**
 * Returns a Response for posting a new json item, calls createPayload() to get input from the user.
 *  */
cpr::Response addPost() {
	cpr::Url url{ BASE_URL };

	return cpr::Post(url, createPayload());
}

/**
 * Returns a Payload object, prompts the user to enter a title and body for the json post.
 *  */
cpr::Payload createPayload() {
	std::string title{}, body{};

	std::cout << "Please enter a title: ";
	std::getline(std::cin, title);
	std::cout << "Please enter a body: ";
	std::getline(std::cin, body);

	return cpr::Payload{ {"title", title}, {"body", body}, {"userId", "1"} };
}

/**
 * Returns a Response for updating a post, will call createPayload() to get new input for the post.
 *
 * Throws invalid_argument if there is no post for the given postID param.
 *  */
cpr::Response updatePost(const int& postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };

	try
	{
		std::cout << "Updating:\n" << readPost(postID).text << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		throw e; // rethrow the exception
	}

	return cpr::Put(url, createPayload());
}

/**
 * Returns a response for deleting a post.
 *
 * Throws invalid_argument if there is no post for the given postID param.
 *  */
cpr::Response deletePost(const int& postID) {
	cpr::Url url{ BASE_URL + std::to_string(postID) };
	cpr::Response temp = cpr::Delete(url);

	if (temp.status_code != 200) throw std::invalid_argument("Error: post does not exist.");

	return temp;
}

/**
 * Gets numeric input from a user and validates that correct input has been given.
 *  */
void checkInputError(int& input) {
	std::cin >> std::setw(1) >> input;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cerr << "Enter a valid integer: ";
		std::cin >> input;
	}

	std::cin.ignore(INT_MAX, '\n');
}