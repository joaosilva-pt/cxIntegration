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
#include <sstream>

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
		
		ostringstream getBodyMail() const;
	private:
		cxMailBodyCreator();	// Disables default constructor
		
		string _sBodyMailTemplate;
		string _sVulnerabilitiesTemplate;
		string _sSeveritiesTemplate;
	};
}
#endif /* CXMAILBODYCREATOR_H */

