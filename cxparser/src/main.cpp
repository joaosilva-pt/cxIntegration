/**
 * @file main.cpp
 * @brief Application main file
 *
 *  @author		Joao Silva <jazzy.blog at gmail.com>
 */

#include <iostream>
#include <iterator>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;
using namespace boost::property_tree;

void printTree(ptree &theTree, unsigned int nLevel)
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

void readXmlFromStdIn()
{
	// don't skip the whitespace while reading
	cin >> noskipws;

/*
	// use stream iterators to copy the stream to a string
	istream_iterator<char> it(cin);
	istream_iterator<char> end;
	string results(it, end);
*/
	ptree xmlResults;
	try
	{
		read_xml(cin, xmlResults);
	}
	catch(const xml_parser::xml_parser_error &ex)
	{
		cerr << "Error parsing XML input: " << ex.message()
			<< " at line " << ex.line()
			<< endl;
//		cerr << "Received XML:" << endl
//			<< results << endl;
			return;
	}

	printTree(xmlResults, 0);
	return;
}

/**
 * App entrance point.
 */
int main(int argc, char** argv)
{
	/*
	// don't skip the whitespace while reading
	std::cin >> std::noskipws;

	// use stream iterators to copy the stream to a string
	std::istream_iterator<char> it(std::cin);
	std::istream_iterator<char> end;
	std::string results(it, end);
*/
	readXmlFromStdIn();
	
	return 0;
}


