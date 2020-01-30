/** @file */
#pragma once
#include <string>
/**
 *Book is Linked List struct consists of 2 string, author and title. And pointer to next list element. It has two simple constructors.
 */
struct Book
{
	std::string author;
	std::string title;
	Book*next;
	Book() :next(nullptr){};
	Book(std::string a, std::string t) :author(a), title(t), next(nullptr) {}

};

/**
 *Label is LL of Linked List Book. It also have string relating to label. 
 */
struct Label
{
	std::string lblName;
	Book*head;
	Label*next;
	Label() :next(nullptr), head(nullptr) {}
	Label(std::string name) :next(nullptr), head(nullptr),lblName(name) {}
};

/**
 * Pushes and allocate Book with given author and titel in alphabetical order.  
 * @param head pointer to head of list.
 * @param athr author of pushed Book
 * @param ttle titel of pushed Book
 * @return pointer to newly allocated Book
 */
Book*pushBook(Book**head, std::string athr, std::string ttle);

/**
 * Pushes on front newly allocated Label with given string representing name of label
 * @param head pointer to head of list
 * @param lbl lblname of pushed Label
 * @return pointer to newly allocated Label
 */
Label* pushLabel(Label **head, std::string lbl);

/**
 * Operate with pushLabel and pushBook. Function pushes label if it was not contained in list. Then pushes Book to Book list contained in this Label
 * @param hd Label list pointer
 * @param lbl name of Label to which Book is pushed
 * @param author author of pushed Book
 * @param title pushed Book title
 * @return returns 1
 */
bool pushBookToLabel(Label**hd, std::string lbl, std::string author, std::string title);