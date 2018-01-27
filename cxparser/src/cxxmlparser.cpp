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

cxIntegration::cxXmlParser::queryData::queryData(long id, string name) : _id(id), _name(name) { }

cxIntegration::cxXmlParser::cxXmlParser() { }

cxIntegration::cxXmlParser::cxXmlParser(const cxXmlParser& orig) { }

cxIntegration::cxXmlParser::~cxXmlParser() { }

void cxIntegration::cxXmlParser::parse(std::basic_istream<
		typename ptree::key_type::value_type
		>& stream)
{
	// don't skip the whitespace while reading
	stream >> noskipws;

	try
	{
		// Clears current data before parsing
		_data.clear();
		boost::property_tree::read_xml(stream, _data);
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

vector<cxIntegration::cxXmlParser::queryData> cxIntegration::cxXmlParser::getQueries()
{
	vector<cxIntegration::cxXmlParser::queryData> queries;
	for (auto & node : _data.get_child(KEY_XML_RESULTS))
	{
		if (node.first == KEY_QUERY)
		{

		}
	}
	return queries;
}
