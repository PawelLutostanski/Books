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
	std::string Lbl;
	Book*head;
	Label*next;
	Label() :next(nullptr), head(nullptr) {}
	Label(std::string name) :next(nullptr), head(nullptr),Lbl(name) {}
};

Book*pushBook(Book**head,std::string athr,std::string ttle)
{
	Book* newBook=new Book(athr,ttle);

	Book* temp = *head;
	if (*head == nullptr)
	{
		*head = newBook;
		return *head;
	}
	else
	{
		if (temp->author >athr)
		{
			newBook->next = *head;
			*head = newBook;
			return newBook;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (temp->author < athr&&temp->next->author>athr)
				{
					newBook->next = temp->next;
					temp->next = newBook;
					return newBook;
				}
				temp = temp->next;

			}
			temp->next = newBook;
			return temp->next;
		}
	}
	

}

Label* pushLabel(Label **head, std::string lbl)
{
	Label* temp = new Label(lbl);
	temp->next = *head;
	*head = temp;
	return temp;
}

