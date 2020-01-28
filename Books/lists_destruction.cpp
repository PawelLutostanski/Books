#include "lists_destruction.h"

void destroyBooks(Book** hd)
{
	while (*hd)
	{
		auto tmp = *hd;
		*hd = (*hd)->next;
		delete tmp;
	}
	*hd = nullptr;
}

void destroyLabels(Label** hd)
{
	while (*hd)
	{
		destroyBooks(&((*hd)->head));
		auto tmp = *hd;
		*hd = (*hd)->next;
		delete tmp;
	}
	*hd = nullptr;
}