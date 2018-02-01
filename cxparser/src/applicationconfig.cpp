/**
 * @file applicationconfig.cpp
 * @brief Implementation file for class applicationconfig
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 25, 2018
 */


#include "applicationconfig.h"

const char* APP_VERSION = "cxparser-0.0.1-build_1";

const char* OPT_HELP = "help,h";
const char* OPT_VERSION = "version,v";
const char* OPT_INPUT = "input,i";
const char* OPT_OUTPUT = "output,o";
const char* OPT_MAIL_TEMPLATE = "mail-template,m";
const char* OPT_VULNERABILITY_TEMPLATE = "vulnerability-template,u";
const char* OPT_SEVERITY_TEMPLATE = "severity-template,s";

const char* OPT_HELP_LONG = "help";
const char* OPT_VERSION_LONG = "version";
const char* OPT_INPUT_LONG = "input";
const char* OPT_OUTPUT_LONG = "output";
const char* OPT_MAIL_TEMPLATE_LONG = "mail-template";
const char* OPT_VULNERABILITY_TEMPLATE_LONG = "vulnerability-template";
const char* OPT_SEVERITY_TEMPLATE_LONG = "severity-template";

const char* OPT_HELP_DESC = "Prints options usage";
const char* OPT_VERSION_DESC = "Prints application version";
const char* OPT_INPUT_DESC = "Sets input XML file (default: standard input)";
const char* OPT_OUTPUT_DESC = "Sets output HTML file (default: standard output)";
const char* OPT_MAIL_TEMPLATE_DESC = "Sets the global mail template to use";
const char* OPT_VULNERABILITY_TEMPLATE_DESC = "Sets the vulnerability template to use";
const char* OPT_SEVERITY_TEMPLATE_DESC = "Sets the severity template to use";

const char* DEFAULT_MAIL_TEMPLATE = "mail.template";
const char* DEFAULT_VULNERABILITY_TEMPLATE = "vulnerability.template";
const char* DEFAULT_SEVERITY_TEMPLATE = "severity.template";

namespace po = boost::program_options;

cxIntegration::ApplicationConfig::ApplicationConfig() :
_bHasHelp(false),
_bHasVersion(false),
_sInputFile(""),
_sOutputFile(""),
_sMailTemplate(DEFAULT_MAIL_TEMPLATE),
_sVulnerabilityTemplate(DEFAULT_VULNERABILITY_TEMPLATE),
_sSeverityTemplate(DEFAULT_SEVERITY_TEMPLATE) { }

cxIntegration::ApplicationConfig::ApplicationConfig(const ApplicationConfig& orig) { }

cxIntegration::ApplicationConfig::~ApplicationConfig() { }

void cxIntegration::ApplicationConfig::parse(int argc, char** argv)
{
	po::options_description desc("Available options");
	desc.add_options()
			(OPT_HELP, OPT_HELP_DESC)
			(OPT_VERSION, OPT_VERSION_DESC)
			(OPT_INPUT, po::value<string>(), OPT_INPUT_DESC)
			(OPT_OUTPUT, po::value<string>(), OPT_OUTPUT_DESC)
			(OPT_MAIL_TEMPLATE, po::value<string>(), OPT_MAIL_TEMPLATE_DESC)
			(OPT_VULNERABILITY_TEMPLATE, po::value<string>(), OPT_VULNERABILITY_TEMPLATE_DESC)
			(OPT_SEVERITY_TEMPLATE, po::value<string>(), OPT_SEVERITY_TEMPLATE_DESC)
			;

	po::store(po::parse_command_line(argc, argv, desc), _optionsMap);

	if (_optionsMap.count(OPT_HELP_LONG))
	{
		_bHasHelp = true;
		ostringstream oss;
		oss << desc;
		_sHelpText = oss.str();
	}

	if (_optionsMap.count(OPT_VERSION_LONG))
	{
		_bHasVersion = true;
	}
	if (_bHasHelp || _bHasVersion)
	{
		// Help or Version options means app is not meant to run, 
		// it is unnecessary to continue
		return;
	}

	if (_optionsMap.count(OPT_INPUT_LONG))
	{
		_sInputFile = _optionsMap[OPT_INPUT_LONG].as<string>();
	}

	if (_optionsMap.count(OPT_OUTPUT_LONG))
	{
		_sOutputFile = _optionsMap[OPT_OUTPUT_LONG].as<string>();
	}

	if (_optionsMap.count(OPT_MAIL_TEMPLATE_LONG))
	{
		_sMailTemplate = _optionsMap[OPT_MAIL_TEMPLATE_LONG].as <string>();
	}

	if (_optionsMap.count(OPT_VULNERABILITY_TEMPLATE_LONG))
	{
		_sVulnerabilityTemplate = _optionsMap[OPT_VULNERABILITY_TEMPLATE_LONG].as <string>();
	}

	if (_optionsMap.count(OPT_SEVERITY_TEMPLATE_LONG))
	{
		_sSeverityTemplate = _optionsMap[OPT_SEVERITY_TEMPLATE_LONG].as <string>();
	}
}

string cxIntegration::ApplicationConfig::version() const
{
	return APP_VERSION;
}

