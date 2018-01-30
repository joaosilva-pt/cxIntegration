/**
 * @file cxmailbodycreator.cpp
 * @brief Implementation file for class cxMailBodyCreator
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 30, 2018
 */


#include "cxmailbodycreator.h"

cxIntegration::cxMailBodyCreator::cxMailBodyCreator() { }

cxIntegration::cxMailBodyCreator::cxMailBodyCreator(string bodyMailTemplate,
		string vulnerabilityTemplate,
		string severityTemplate) :
_sBodyMailTemplate(bodyMailTemplate),
_sVulnerabilitiesTemplate(vulnerabilityTemplate),
_sSeveritiesTemplate(severityTemplate) { }

cxIntegration::cxMailBodyCreator::cxMailBodyCreator(const cxIntegration::cxMailBodyCreator& orig) { }

cxIntegration::cxMailBodyCreator::~cxMailBodyCreator() { }

ostringstream cxIntegration::cxMailBodyCreator::getBodyMail() const 
{
	ostringstream output;
	return output;
}
