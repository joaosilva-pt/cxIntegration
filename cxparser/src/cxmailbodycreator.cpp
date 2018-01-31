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

const char* TAG_SEVERITIES_DATA = "%%SEVERITIES_RESULTS%%";
const char* TAG_VULNERABILITIES_DATA = "%%VULNERABILITIES_RESULTS%%";

const char* TAG_SEVERITY_NAME = "%%SEVERITY_NAME%%";
const char* TAG_SEVERITY_OCCURRENCES = "%%SEVERITY_OCCURRENCES%%";

const char* TAG_VULNERABILITY_NAME = "%%VULNERABILITY_NAME%%";
const char* TAG_VULNERABILITY_OCCURRENCES = "%%VULNERABILITY_OCCURRENCES%%";

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
	ostringstream output;

	return output.str();
}

string cxIntegration::cxMailBodyCreator::expandSeverities(severities_t& severities) const
{
	ostringstream output;
	for(auto& severity:severities)
	{
		string result = boost::algorithm::replace_all_copy(_sSeveritiesTemplate, 
			TAG_SEVERITY_NAME,
			severity.first);

		boost::algorithm::replace_all(result, 
			TAG_SEVERITY_OCCURRENCES,
			std::to_string(severity.second));
		output << result;
	}
	return output.str();
}

string cxIntegration::cxMailBodyCreator::expandVulnerabilities(queriesData_t& queries) const
{
	ostringstream output;
	for(auto& query:queries)
	{
		string result = boost::algorithm::replace_all_copy(_sVulnerabilitiesTemplate, 
			TAG_VULNERABILITY_NAME,
			query._name);

		boost::algorithm::replace_all(result, 
			TAG_VULNERABILITY_OCCURRENCES,
			std::to_string(query._results));
		output << result;
	}
	return output.str();
}

