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

namespace cxIntegration
{

	/**
	 * @brief Application command line parser and configuration
	 * @details Parses command line options
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
		 * @brief Destructor
		 */
		virtual ~ApplicationConfig();

		string version() const;

        string outputFile() const
        {
        	return _sOutputFile;
        }

        string inputFile() const
        {
        	return _sInputFile;
        }

        std::string helpText() const
        {
        	return _sHelpText;
        }

        bool hasVersion() const
        {
        	return _bHasVersion;
        }

        bool hasHelp() const
        {
        	return _bHasHelp;
        }

        string mailTemplate() const
        {
        	return _sMailTemplate;
        }

        string severityTemplate() const
        {
        	return _sSeverityTemplate;
        }

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
	};
}
#endif /* APPLICATIONCONFIG_H */

