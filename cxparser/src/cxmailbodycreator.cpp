/**
 * @file cxmailbodycreator.cpp
 * @brief Implementation file for class cxMailBodyCreator
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 30, 2018
 */


#include "cxmailbodycreator.h"
#include <sstream>
#include <boost/algorithm/string.hpp>

const string cxIntegration::cxMailBodyCreator::TAG_SEVERITIES_DATA = "%%SEVERITIES_RESULTS%%";
const string cxIntegration::cxMailBodyCreator::TAG_VULNERABILITIES_DATA = "%%VULNERABILITIES_RESULTS%%";

const string cxIntegration::cxMailBodyCreator::TAG_SEVERITY_NAME = "%%SEVERITY_NAME%%";
const string cxIntegration::cxMailBodyCreator::TAG_SEVERITY_OCCURRENCES = "%%SEVERITY_OCCURRENCES%%";

const string cxIntegration::cxMailBodyCreator::TAG_VULNERABILITY_NAME = "%%VULNERABILITY_NAME%%";
const string cxIntegration::cxMailBodyCreator::TAG_VULNERABILITY_OCCURRENCES = "%%VULNERABILITY_OCCURRENCES%%";

cxIntegration::cxMailBodyCreator::cxMailBodyCreator() { }

cxIntegration::cxMailBodyCreator::cxMailBodyCreator(string bodyMailTemplate,
		string vulnerabilityTemplate,
		string severityTemplate) :
_sBodyMailTemplate(bodyMailTemplate),
_sVulnerabilitiesTemplate(vulnerabilityTemplate),
_sSeveritiesTemplate(severityTemplate) { }

cxIntegration::cxMailBodyCreator::cxMailBodyCreator(const cxIntegration::cxMailBodyCreator& orig) { }

cxIntegration::cxMailBodyCreator::~cxMailBodyCreator() { }

string cxIntegration::cxMailBodyCreator::getBodyMail(
	queriesData_t& queries, severities_t& severities) const 
{
	string vulnerabilities_content = expandVulnerabilities(queries);
	string severities_content = expandSeverities(severities);

	string result = boost::algorithm::replace_all_copy(_sBodyMailTemplate,
		TAG_VULNERABILITIES_DATA,
		vulnerabilities_content);

	boost::algorithm::replace_all(result,
		TAG_SEVERITIES_DATA,
		severities_content);
	return result;
}

string cxIntegration::cxMailBodyCreator::expandSeverities(severities_t& severities) const
{
	ostringstream output;
	
	for(auto& severity:severities)
	{
		string sevText = boost::algorithm::replace_all_copy(_sSeveritiesTemplate, 
			TAG_SEVERITY_NAME,
			severity.first);

		boost::algorithm::replace_all(sevText, 
			TAG_SEVERITY_OCCURRENCES,
			std::to_string(severity.second));
		output << sevText;
	}
	return output.str();
}

string cxIntegration::cxMailBodyCreator::expandVulnerabilities(queriesData_t& queries) const
{
	ostringstream output;
	for(auto& query:queries)
	{
		string vulnText = boost::algorithm::replace_all_copy(_sVulnerabilitiesTemplate, 
			TAG_VULNERABILITY_NAME,
			query._name);

		boost::algorithm::replace_all(vulnText, 
			TAG_VULNERABILITY_OCCURRENCES,
			std::to_string(query._results));
		output << vulnText;
	}
	return output.str();
}

