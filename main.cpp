#include <iostream>
#include "SocialNetworkTester.h"

using namespace codesmith;
using namespace std;

const int OPTION_UI = 1;
const int OPTION_TEST = 2;

// Very simple entry point for the program
int main(int /* argc */, char** /* argv */)
{
	SocialNetworkTester::instance().RunAll();
	cout << "Tests succeeded: " << SocialNetworkTester::instance().SuccessCount() << endl;
	cout << "Tests failed: " << SocialNetworkTester::instance().FailCount() << endl;
	return 0;
}