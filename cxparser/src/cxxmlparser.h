/**
 * @file cxxmlparser.h
 * @brief Declaration file for class cxXmlParser
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 27, 2018
 */

#ifndef CXXMLPARSER_H
#define CXXMLPARSER_H

#include "applicationconfig.h"


#include <boost/property_tree/ptree.hpp>

using namespace boost::property_tree;

namespace cxIntegration
{

	class cxXmlParser
	{
	public:
		cxXmlParser();
		cxXmlParser(const cxXmlParser& orig);
		virtual ~cxXmlParser();
		
		void parse(std::basic_istream<
				typename ptree::key_type::value_type
				>&);
		
		void printTree();
	private:
		ptree _data;
		
		static void printTree(ptree &theTree, unsigned int nLevel);
	};
}
#endif /* CXXMLPARSER_H */

