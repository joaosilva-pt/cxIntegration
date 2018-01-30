/**
 * @file cxxmlparser.cpp
 * @brief Implementation file for class cxXmlParser
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 27, 2018
 */


#include "cxxmlparser.h"

#include <iostream>
#include <stdexcept>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

// Const values
const string cxIntegration::cxXmlParser::KEY_XML_RESULTS = "CxXMLResults";
const string cxIntegration::cxXmlParser::KEY_QUERY = "Query";
const string cxIntegration::cxXmlParser::KEY_QUERY_ID = "<xmlattr>.id";
const string cxIntegration::cxXmlParser::KEY_QUERY_NAME = "<xmlattr>.name";
const string cxIntegration::cxXmlParser::KEY_QUERY_RESULTS = "Result";
//const string cxIntegration::cxXmlParser::KEY_RESULT_SEVERITY = "Severity";
const string cxIntegration::cxXmlParser::KEY_RESULT_SEVERITY = "<xmlattr>.Severity";

cxIntegration::cxXmlParser::cxXmlParser() { }

cxIntegration::cxXmlParser::cxXmlParser(const cxXmlParser& orig) { }

cxIntegration::cxXmlParser::~cxXmlParser() { }

void cxIntegration::cxXmlParser::parse(
/*std::basic_istream<
		typename ptree::key_type::value_type
		>*/istream& stream)
{
	// don't skip the whitespace while reading
	stream >> noskipws;

	try
	{
		// Clears current data before parsing
		_data.clear();
		boost::property_tree::read_xml(stream, _data);

		// Parse the queries
		for (auto & query_node : _data.get_child(KEY_XML_RESULTS))
		{
			// Processes only if it is a "Query" node
			if (query_node.first == KEY_QUERY)
			{
				queryData newQuery(query_node.second.get<long>(KEY_QUERY_ID),
						query_node.second.get<string>(KEY_QUERY_NAME),
						query_node.second.count(KEY_QUERY_RESULTS));
				_queries.push_back(
						newQuery);

				// Parse the results for the current query
				for (auto & result_node : query_node.second)
				{
					// Processes only if it is a "Result" node
					if (result_node.first == "Result")
					{
						cout << "\t Query "
								<< query_node.second.get<string>(KEY_QUERY_NAME)
								<< " has a severity "
								<< result_node.second.get<string>("<xmlattr>.Severity")
								<< endl;
						string severity =
								result_node.second.get<string>("<xmlattr>.Severity");
						if (_severities.find(severity) == _severities.end())
						{
							_severities[severity] = 1;
						}
						else
						{
							_severities[severity]++;
						}
					}
				}
			}
		}

	}
	catch (const xml_parser::xml_parser_error &ex)
	{
		ostringstream oss;
		oss << "Error parsing XML input: " << ex.message()
				<< " at line " << ex.line()
				<< endl;
		throw runtime_error(oss.str());
	}

}

void cxIntegration::cxXmlParser::printTree()
{
	printTree(_data, 0);
}

void cxIntegration::cxXmlParser::printTree(ptree& theTree, unsigned int nLevel)
{
	for (auto & node : theTree.get_child(""))
	{
		ptree subtree = node.second;
		string nodestr = node.second.get_value<string>();
		boost::algorithm::trim(nodestr);

		// print current node 
		cout << string("").assign(nLevel * 2, ' ') << "* ";
		cout << node.first;
		if (nodestr.length() > 0)
		{
			cout << "=\"" << nodestr << "\"";
		}
		cout << endl;

		// recursive go down the hierarchy 
		printTree(subtree, nLevel + 1);

	}
}

vector<cxIntegration::queryData> cxIntegration::cxXmlParser::getQueries()
{
	return _queries;
}

cxIntegration::severities_t cxIntegration::cxXmlParser::getSeverities()
{
	return _severities;
}

unsigned int cxIntegration::cxXmlParser::getTotalResultsWithSeverity(string severity) const
{
	if (_severities.find(severity) == _severities.end())
		return 0;

	return _severities.at(severity);
}

