/**
 * @file cxdata.h
 * @brief 
 *
 *  @author		Joao Silva <jazzy.blog at gmail.com>
 *  @date		Jan 30, 2018
 */

#ifndef CXDATA_H
#define CXDATA_H

#include <string>

using namespace std;

namespace cxIntegration
{

	struct queryData
	{

		queryData(long id, string name, long results) :
		_id(id), _name(name), _results(results) { }
		long _id;
		string _name;
		long _results;
	};

	typedef vector<queryData> queriesData_t;
	typedef map<string, unsigned int> severities_t;

}

#endif /* CXDATA_H */

