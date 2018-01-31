/**
 * @file cxmailbodycreator.h
 * @brief Declaration file for class cxMailBodyCreator
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 30, 2018
 */

#ifndef CXMAILBODYCREATOR_H
#define CXMAILBODYCREATOR_H

#include <string>
#include "cxdata.h"

using namespace std;

namespace cxIntegration
{

	class cxMailBodyCreator
	{
	public:
		cxMailBodyCreator(string bodyMailTemplate, 
				string vulnerabilityTemplate, 
				string severityTemplate);
		cxMailBodyCreator(const cxMailBodyCreator& orig);
		virtual ~cxMailBodyCreator();
		
		string getBodyMail(queriesData_t& queries, severities_t& severities) const;
	private:
		cxMailBodyCreator();	// Disables default constructor
		
		string _sBodyMailTemplate;
		string _sVulnerabilitiesTemplate;
		string _sSeveritiesTemplate;

		string expandSeverities(severities_t& severities) const;
		string expandVulnerabilities(queriesData_t& queries) const;
	};
}
#endif /* CXMAILBODYCREATOR_H */

