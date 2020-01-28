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
		if(argc>2){}//at least 3 
		else if(argv[2]=="-i")
		{
			infile = argv[3];
		}
		else if (argv[2] == "-o")
		{
			outfile = argv[3];
		}
		if (argc > 4){}
		else if(argv[4] == "-i")
		{
			infile = argv[5];
		}
		else if (argv[4] == "-o")
		{
			outfile = argv[5];
		}
		Label* head = nullptr;
		readInput(&head, infile);
		writeOutput(&head, outfile);
		Book* tmp = head->head;
		destroyLabels(&head);
	}

	//_CrtMemDumpStatistics(&s1);
	//_CrtDumpMemoryLeaks();
}