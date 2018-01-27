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

using namespace std;
using namespace boost::property_tree;

namespace cxIntegration
{

	
	class cxXmlParser
	{
	public:
		
		struct queryData
		{
			queryData(long, string, long);
			long _id;
			string _name;
			long _results;
		};

		typedef vector<queryData> queriesData_t;
		typedef map<string, unsigned int> severities_t;

		cxXmlParser();
		cxXmlParser(const cxXmlParser& orig);
		virtual ~cxXmlParser();

		void parse(std::basic_istream<
				typename ptree::key_type::value_type
				>&);

		void printTree();

		queriesData_t getQueries();
		severities_t getSeverities();
		unsigned int getTotalResultsWithSeverity(string);
		
	private:
		ptree _data;
		queriesData_t _queries;
		severities_t _severities;

		static void printTree(ptree &, unsigned int);
		
		static const string KEY_XML_RESULTS;
		static const string KEY_QUERY;
		static const string KEY_QUERY_ID;
		static const string KEY_QUERY_NAME;
		static const string KEY_QUERY_RESULTS;
		static const string KEY_RESULT_SEVERITY;
	};
}
#endif /* CXXMLPARSER_H */

