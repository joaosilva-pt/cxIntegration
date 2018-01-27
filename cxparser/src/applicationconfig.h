/**
 * @file applicationconfig.h
 * @brief Declaration file for class applicationconfig
 *
 *  @author		Joao Silva <m.joao.silva.ml at gmail.com>
 *  @date		Jan 25, 2018
 */

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

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
	 * @brief Constructor receiving command line args
	 */
	ApplicationConfig(int argc, char** argv);

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
private:

};

#endif /* APPLICATIONCONFIG_H */

