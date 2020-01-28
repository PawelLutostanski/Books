#pragma once
#include <string>

struct Book
{
	std::string author;
	std::string title;
	Book*next;
	Book() :next(nullptr){};
	Book(std::string a, std::string t) :author(a), title(t), next(nullptr) {}

};

struct Label
{
	std::string lblName;
	Book*head;
	Label*next;
	Label() :next(nullptr), head(nullptr) {}
	Label(std::string name) :next(nullptr), head(nullptr),lblName(name) {}
};

Book*pushBook(Book**head, std::string athr, std::string ttle);

Label* pushLabel(Label **head, std::string lbl);

bool pushBookToLabel(Label**hd, std::string lbl, std::string author, std::string title);