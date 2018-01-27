/**
 * @file cxxmlparser.h
 * @brief Declaration file for class cxXmlParser
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 27, 2018
 */

#ifndef CXXMLPARSER_H
#define CXXMLPARSER_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

using namespace std;
using namespace boost::property_tree;

namespace cxIntegration
{

	
	class cxXmlParser
	{
	public:

		struct queryData
		{
			queryData(long id, string name);
			long _id;
			string _name;
		};

		cxXmlParser();
		cxXmlParser(const cxXmlParser& orig);
		virtual ~cxXmlParser();

		void parse(std::basic_istream<
				typename ptree::key_type::value_type
				>&);

		void printTree();

		vector<queryData> getQueries();
	private:
		ptree _data;

		static void printTree(ptree &theTree, unsigned int nLevel);
		
		static const string KEY_XML_RESULTS;
		static const string KEY_QUERY;
	};
}
#endif /* CXXMLPARSER_H */

