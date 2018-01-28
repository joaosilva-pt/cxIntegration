/**
 * @file main.cpp
 * @brief Application main file
 *
 *  @author		Joao Silva <jazzy.blog at gmail.com>
 */

#include <iostream>

#include "cxxmlparser.h"
#include "applicationconfig.h"

using namespace std;

/**
 * App entrance point.
 */
int main(int argc, char** argv)
{
	cxIntegration::ApplicationConfig options;
	try
	{
		options.parse(argc, argv);
	}
	catch (std::exception &e)
	{
		cerr << "Error parsing configuration: "
				<< e.what() << endl;
		return EXIT_FAILURE;
	}
	if (options.hasHelp())
	{
		cout << options.version() << endl;
		cout << options.helpText() << endl;
		return EXIT_SUCCESS;
	}

	if (options.hasVersion())
	{
		cout << options.version() << endl;
		return EXIT_SUCCESS;
	}

	cxIntegration::cxXmlParser parser;
	try
	{
		parser.parse(cin);

		vector<cxIntegration::cxXmlParser::queryData> allQueries;
		allQueries = parser.getQueries();

		//		for(auto & q : allQueries)
		//		{
		//			cout << "Query: " 
		//					<< q._id << " = " 
		//					<< q._name 
		//					<< "(" << q._results << ")"
		//					<< endl;
		//		}
		//		
		//		cxIntegration::cxXmlParser::severities_t sevs =
		//				parser.getSeverities();
		//		for(auto & sev : sevs)
		//		{
		//			cout << sev.first << " = " << sev.second << endl;
		//		}
	}
	catch (runtime_error &e)
	{
		cerr << "Runtime error: "
				<< e.what() << endl;
	}

	return 0;
}


