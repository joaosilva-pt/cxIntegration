/**
 * @file main.cpp
 * @brief Application main file
 *
 *  @author		Joao Silva <jazzy.blog at gmail.com>
 */

#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>

#include "applicationconfig.h"
#include "cxxmlparser.h"
#include "cxmailbodycreator.h"

using namespace std;

string getFileContents(const string filename)
{
	boost::filesystem::path file(filename);
	if (boost::filesystem::exists(file) &&
			boost::filesystem::is_regular_file(file))
	{
		try
		{
			std::ifstream in(filename, std::ios::in | std::ios::binary);
			if (in)
			{
				std::string contents;
				in.seekg(0, std::ios::end);
				contents.resize(in.tellg());
				in.seekg(0, std::ios::beg);
				in.read(&contents[0], contents.size());
				in.close();
				return contents;
			}
		}
		catch (exception &ex)
		{
			ostringstream oss;
			oss << "Error reading file "
					<< boost::filesystem::canonical(filename)
					<< " contents: " << ex.what();
			throw runtime_error(oss.str());
		}
	}
	else
	{
		ostringstream oss;
		oss << "File "
				<< boost::filesystem::canonical(filename)
				<< " does not exist.";
		throw runtime_error(oss.str());
	}
}

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
		if (!options.inputFile().empty())
		{
			boost::filesystem::path theFile(options.inputFile());
			if (boost::filesystem::exists(theFile) &&
					boost::filesystem::is_regular_file(theFile))
			{
				ifstream inputFile(options.inputFile());
				if (inputFile)
				{
					parser.parse(inputFile);
				}
				else
				{
					cerr << "Unable to read file "
							<< boost::filesystem::canonical(theFile)
							<< endl;
					return EXIT_FAILURE;
				}
			}
			else
			{
				cerr << "Unable to locate file "
						<< boost::filesystem::canonical(theFile)
						<< endl;
				return EXIT_FAILURE;
			}
		}
		else
		{
			parser.parse(cin);
		}

		/*
				cxIntegration::queriesData_t allQueries;
				allQueries = parser.getQueries();

				for (auto & q : allQueries)
				{
					cout << "Query: "
							<< q._id << " = "
							<< q._name
							<< "(" << q._results << ")"
							<< endl;
				}

				cxIntegration::severities_t sevs =
						parser.getSeverities();
				for (auto & sev : sevs)
				{
					cout << sev.first << " = " << sev.second << endl;
				}
		 */
		cxIntegration::queriesData_t allQueries;
		allQueries = parser.getQueries();
		cxIntegration::severities_t sevs =
				parser.getSeverities();



		cxIntegration::cxMailBodyCreator bodyCreator(
				getFileContents(options.mailTemplate()),
				getFileContents(options.vulnerabilityTemplate()),
				getFileContents(options.severityTemplate()));
		string body = bodyCreator.getBodyMail(allQueries, sevs);
		cout << body << endl;
	}
	catch (runtime_error &e)
	{
		cerr << "Runtime error: "
				<< e.what() << endl;
	}

	return 0;
}


