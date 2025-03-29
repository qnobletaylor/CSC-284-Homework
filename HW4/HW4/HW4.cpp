// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
import <iostream>;
import <string>;
import "cpr/cpr.h";

cpr::Response readPost(int postID);
cpr::Response addPost();
cpr::Payload getParams();

int main()
{
	int choice = 0;
	int postID = 0;
	cpr::Response response{};


	do {
		std::cout << "Please choose an action:\n\t1. Read a Post\n\t2. Add a New Post\n\t3. Update a Post\n\t4. Delete a Post\n\t5. Exit";
		std::cout << "\nChoice: ";
		std::cin >> choice;


		switch (choice)
		{
		case(1):
			std::cout << "Post ID: ";
			std::cin >> postID;
			response = readPost(postID);
			std::cout << "Fetching ID: " << postID << "\n" << response.text << std::endl;
			break;
		case(2):
			response = addPost();
			std::cout << "Response: \n" << response.text << std::endl;
			break;
		case(3):
			break;
		case(4):
			break;
		case(5):
			break;
		default:
			break;
		}



	} while (choice != 5);
}

cpr::Response readPost(int postID) {
	cpr::Url url = cpr::Url{ "https://jsonplaceholder.typicode.com/posts/" + std::to_string(postID) };

	return cpr::Get(url);
}

cpr::Response addPost() {
	cpr::Url url{ "https://jsonplaceholder.typicode.com/posts" };

	return cpr::Post(url, getParams());
}


cpr::Payload getParams() {
	std::string title{}, body{};

	std::cin.ignore(1000, '\n');
	std::cout << "Please enter a title for post: ";
	std::getline(std::cin, title);
	std::cout << "Please enter a body: ";
	std::getline(std::cin, body);

	return cpr::Payload{ {"title", title}, {"body", body}, {"userId", "1"} };
}
