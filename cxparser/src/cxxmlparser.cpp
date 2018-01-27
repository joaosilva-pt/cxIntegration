/**
 * @file cxxmlparser.cpp
 * @brief Implementation file for class cxXmlParser
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 27, 2018
 */


#include "cxxmlparser.h"

#include <iostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

//
//
//void readXmlFromStdIn()
//{
//	// don't skip the whitespace while reading
//	cin >> noskipws;
//
///*
//	// use stream iterators to copy the stream to a string
//	istream_iterator<char> it(cin);
//	istream_iterator<char> end;
//	string results(it, end);
//*/
//	ptree xmlResults;
//	try
//	{
//		read_xml(cin, xmlResults);
//	}
//	catch(const xml_parser::xml_parser_error &ex)
//	{
//		cerr << "Error parsing XML input: " << ex.message()
//			<< " at line " << ex.line()
//			<< endl;
////		cerr << "Received XML:" << endl
////			<< results << endl;
//			return;
//	}
//
//	printTree(xmlResults, 0);
//	return;
//}
//
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
	catch(const xml_parser::xml_parser_error &ex)
	{
		ostringstream oss;
		oss << "Error parsing XML input: " << ex.message()
			<< " at line " << ex.line()
			<< endl;
		throw oss.str();
	}
	
}

void cxIntegration::cxXmlParser::printTree()
{
	printTree(_data, 0);
}

void cxIntegration::cxXmlParser::printTree(ptree& theTree, unsigned int nLevel)
{
    for(auto & node : theTree.get_child(""))
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
