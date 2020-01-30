#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "file_oper.h"

int main(int argc, char * argv[])
{
	//_CrtMemState s1;
	//_CrtMemCheckpoint(&s1);
	{
		std::string infile = "input.txt";
		std::string outfile = "results.txt";
		if (argc > 2) 
		{//at least 3 
			if (!strcmp(argv[1],"-i"))
			{
				infile = argv[2];
			}
			else if (!strcmp(argv[1],"-o"))
			{
				outfile = argv[2];
			}
		}
		if (argc > 4)
		{
			if (!strcmp(argv[3],"-i"))
			{
				infile = argv[4];
			}
			else if (!strcmp(argv[3],"-o"))
			{
				outfile = argv[4];
			}
		}
		Label* head = nullptr;
		readInput(&head, infile);
		if (head) 
		{
			writeOutput(&head, outfile);
			Book* tmp = head->head;
			destroyLabels(&head);
		}
	}

	//_CrtMemDumpStatistics(&s1);
	//_CrtDumpMemoryLeaks();
}