#include "file_oper.h"
#include <vector>


Label* readInput(Label **hd, std::string fileName)
{
	std::ifstream inpt;
	inpt.open(fileName, std::ios::in);
	if (inpt.good())
	{
		std::string line;
		
		while (std::getline(inpt, line))
		{
			Book book;
			bool readAuthor = 0;
			bool searchLabels = 0;
			std::string temp;
			for (char c : line)
			{
				if (c == ';' && !temp.empty() && !readAuthor)
				{
					book.author = temp;
					readAuthor = 1;
					temp.erase(temp.begin(), temp.end());
				}
				else if (c == ';' && !temp.empty() && readAuthor)
				{
					book.title = temp;
					readAuthor = 1;
					temp.erase(temp.begin(), temp.end());
					searchLabels = 1;
				}
				else if ((c == ',') && !temp.empty() && searchLabels)
				{
					pushBookToLabel(&*hd, temp, book.author, book.title);
					temp.erase(temp.begin(), temp.end());
				}
				else
				{
					temp += c;
				}
			}
			//if end of string line then write last one tag
			pushBookToLabel(&*hd, temp, book.author, book.title);
			temp.erase((temp.begin(), temp.end()));
		}

		return *hd;

	}
	else
	{
		std::cout << "\n No file \"" << fileName << "\" found\n";
		return nullptr;
	}
}

void writeOutput(Label **hd, std::string fileName)
{
	std::ofstream outpt;
	outpt.open(fileName, std::ios::out);
	Label* temp = *hd;
	while (temp != nullptr)
	{
		std::string tag = temp->lblName;
		if (tag[0] == ' ')//remove space
		{
			tag.erase(0, 1);
		}
		outpt << tag << ":\n";
		Book* tmp = temp->head;
		while (tmp != nullptr)
		{
			outpt << tmp->author << ";" << tmp->title << "\n";
			tmp = tmp->next;
		}
		outpt << "\n";
		temp = temp->next;
	}
	outpt.close();
}