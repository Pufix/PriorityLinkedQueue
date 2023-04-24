#include <iostream>
#include "PriorityQueue.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;




int main() {
	testAll();
	testAllExtended();
	cout << "End" << endl;
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
	system("pause");

}
