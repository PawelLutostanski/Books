#include "lists_generation.h"

Book*pushBook(Book**head, std::string athr, std::string ttle)
{
	Book* newBook = new Book(athr, ttle);
	Book* temp = *head;
	if (*head == nullptr)
	{
		*head = newBook;
		return *head;
	}
	else
	{
		if (temp->author >= athr)
		{
			newBook->next = *head;
			*head = newBook;
			return newBook;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (temp->author <= athr&&temp->next->author>athr)
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

bool pushBookToLabel(Label**hd, std::string lbl, std::string author, std::string title)
{
	Label* temp = *hd;
	bool pushed = 0;
	if (*hd == nullptr)//new label
	{
		pushLabel(*&hd, lbl);
		pushBook(&((*hd)->head), author, title);
		pushed++;
		return pushed;
	}
	if ((*hd)->lblName == lbl)
	{
		temp->head = pushBook(&((*hd)->head), author, title);
		pushed++;
		return pushed;
	}
	while (temp->next != nullptr)
	{
		if (temp->lblName == lbl)
		{
			pushBook(&(temp->head), author, title);
			pushed++;
			return pushed;
		}
		temp = temp->next;

	}
	if (temp->lblName == lbl)//case if last label is one we were searching for
	{
		pushBook(&(temp->head), author, title);
		pushed++;
		return pushed;
	}
	pushLabel(*&hd, lbl);//new label
	pushBook(&((*hd)->head), author, title);
	pushed++;
	return pushed;
}
