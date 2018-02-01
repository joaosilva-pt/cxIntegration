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
#include <map>
#include <boost/property_tree/ptree.hpp>

#include "cxdata.h"

using namespace std;
using namespace boost::property_tree;

namespace cxIntegration
{

	class cxXmlParser
	{
	public:

		cxXmlParser();
		cxXmlParser(const cxXmlParser& orig);
		virtual ~cxXmlParser();

		void parse(istream&);

		queriesData_t getQueries();
		severities_t getSeverities();
		unsigned int getTotalResultsWithSeverity(string) const;

	private:
		ptree _data;
		queriesData_t _queries;
		severities_t _severities;

		static const string KEY_XML_RESULTS;
		static const string KEY_QUERY;
		static const string KEY_QUERY_ID;
		static const string KEY_QUERY_NAME;
		static const string KEY_QUERY_RESULTS;
		static const string KEY_RESULT_SEVERITY;
	};
}
#endif /* CXXMLPARSER_H */

