#include"SnakeGame.h"


//To detect and display a memory-leaks
//use --- _CrtDumpMemoryLeaks() --- before program exit point
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main() {


	{
		SnakeGame sn;
		sn.run();





	}
	_CrtDumpMemoryLeaks();


	return 0;
}