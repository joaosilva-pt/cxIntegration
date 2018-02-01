/**
 * @file applicationconfig.h
 * @brief Declaration file for class applicationconfig
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 25, 2018
 */

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include <string>
#include <boost/program_options.hpp>

using namespace std;

/**
 * @namespace cxIntegration
 * 
 * @brief The application's namespace
 */
namespace cxIntegration
{

	/**
	 * @brief Application command line parser and configuration
	 * @details Parses command line options.
	 */
	class ApplicationConfig
	{
	public:
		/**
		 * @brief Default constructor
		 */
		ApplicationConfig();

		/**
		 * @brief Parses the command line options
		 */
		void parse(int argc, char** argv);

		/**
		 * @brief Copy constructor
		 * 
		 * @param orig The original config
		 */
		ApplicationConfig(const ApplicationConfig& orig);

		/**
		 * @brief      Destructor
		 */
		virtual ~ApplicationConfig();

		/**
		 * @brief      Gets application version
		 */
		string version() const;

		/**
		 * @brief      Gets the output file's name
		 */
        string outputFile() const
        {
        	return _sOutputFile;
        }

        /**
         * @brief      Gets the input file's name
         */
        string inputFile() const
        {
        	return _sInputFile;
        }

        /**
         * @brief      Gets the help text
         */
        std::string helpText() const
        {
        	return _sHelpText;
        }

        /**
         * @brief      Whether the --version option was found.
         */
        bool hasVersion() const
        {
        	return _bHasVersion;
        }

        /**
         * @brief      Whether the --help options was found
         */
        bool hasHelp() const
        {
        	return _bHasHelp;
        }

        /**
         * @brief      Gets the mail's body template filename
         */
        string mailTemplate() const
        {
        	return _sMailTemplate;
        }

        /**
         * @brief      Gets the severities' template filename
         */
        string severityTemplate() const
        {
        	return _sSeverityTemplate;
        }

        /**
         * @brief      Gets the vulnerabilities' template filename
         *
         * @return     { description_of_the_return_value }
         */
        string vulnerabilityTemplate() const
        {
        	return _sVulnerabilityTemplate;
        }
        
	private:

		bool _bHasHelp;
		bool _bHasVersion;

		string _sHelpText;

		string _sInputFile;
		string _sOutputFile;

		string _sMailTemplate;
		string _sVulnerabilityTemplate;
		string _sSeverityTemplate;
		
		boost::program_options::variables_map _optionsMap;

		// Command line options related strings
		static const char* APP_VERSION;
		static const char* OPT_HELP;
		static const char* OPT_VERSION;
		static const char* OPT_INPUT;
		static const char* OPT_OUTPUT;
		static const char* OPT_MAIL_TEMPLATE;
		static const char* OPT_VULNERABILITY_TEMPLATE;
		static const char* OPT_SEVERITY_TEMPLATE;
		static const char* OPT_HELP_LONG;
		static const char* OPT_VERSION_LONG;
		static const char* OPT_INPUT_LONG;
		static const char* OPT_OUTPUT_LONG;
		static const char* OPT_MAIL_TEMPLATE_LONG;
		static const char* OPT_VULNERABILITY_TEMPLATE_LONG;
		static const char* OPT_SEVERITY_TEMPLATE_LONG;
		static const char* OPT_HELP_DESC;
		static const char* OPT_VERSION_DESC;
		static const char* OPT_INPUT_DESC;
		static const char* OPT_OUTPUT_DESC;
		static const char* OPT_MAIL_TEMPLATE_DESC;
		static const char* OPT_VULNERABILITY_TEMPLATE_DESC;
		static const char* OPT_SEVERITY_TEMPLATE_DESC;
		static const char* DEFAULT_MAIL_TEMPLATE;
		static const char* DEFAULT_VULNERABILITY_TEMPLATE;
		static const char* DEFAULT_SEVERITY_TEMPLATE;

	};
}
#endif /* APPLICATIONCONFIG_H */

