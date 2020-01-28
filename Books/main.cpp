#include "Books.h"


int main()
{
	Book* headBook = nullptr;
	pushBook(&headBook, "Mikolow", "0");
	pushBook(&headBook, "Bikolow", "1");
	pushBook(&headBook, "Oikolow", "2");
	pushBook(&headBook, "Dikolow", "3");
	pushBook(&headBook, "Zikolow", "4");

	Label* head = nullptr;
	pushLabel(&head, "Physics");
	pushLabel(&head, "Philosophy");
	pushLabel(&head, "Maths");
	int z = 0;
}