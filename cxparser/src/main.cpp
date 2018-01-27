/**
 * @file main.cpp
 * @brief Application main file
 *
 *  @author		Joao Silva <jazzy.blog at gmail.com>
 */

#include <iostream>

#include "cxxmlparser.h"

using namespace std;

/**
 * App entrance point.
 */
int main(int argc, char** argv)
{
	cxIntegration::cxXmlParser parser;
	try
	{
		parser.parse(cin);

		parser.printTree();
	}
	catch (runtime_error &e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}


