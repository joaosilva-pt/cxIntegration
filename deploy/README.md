# Introduction
It was requested an integration solution to upload a repo-residing source code to Chechmarx cloud server, parse the source's scan result and send an email with the parsing results to a list of recipients.

A custom application was developed using portable C++11 to parse the XML report generated by Checkmarx scan tool and produce the email's body content. Besides this application's source code, Linux binaries are provided.

In order to get a flexible solution regarding the email's body generation, to allow the generation of both text-only or HTML emails, it was implemented a template-based solution. It defines a general template for the email's body and sub-templates for defining the contents to be inserted in the email body of both each vulnerability and severity.

# Deliverables
- Readme file - this file
- The hookup script, `integration.sh`, that triggers the whole process is provided in the folder `scripts`. It is the same as the one provided in the Deploy files with the same name.
- Parsing application source code - the parsing application source code is provided in the folder `cxparser`. In the folder `cxparser\templates` are example templates.
- Deploy files - For convenience's sake, the files required to deploy are provided in the `deploy` folder. They are:
 - integration.sh: the hookup script
 - cxparser: the XML parsing and mail body generator application
 - \*.template: example templates to be used by `cxparser`
 
# Script
## Requirements
The script assumes the following pre-requisites are met:

- Checkmarx CLI plugin is installed
- A working email setup exists to allow for sending emails

## Configuration
The script configuration is in the script it self. For easy of use, all configuration settings is at the script's very beginning, in a well defined area.

The configuration begins with

	# =================
	# BEGIN OF CONFIG
	#
	# Edit the vars in this area according to project's needs
	#==================

and goes to where appears the text

	# =================
	# END OF CONFIG
	#
	# DO NOT EDIT BELLOW THIS POINT!!!!
	#==================

### Configuration parameters
- EMAIL\_RECIPIENTS - list of comma-separated of the email's recipients
- GIT\_REPO\_URL - Repository's URL of the source code to be analysed
- CX\_CONSOLE - Location of Checkmarx CLI plugin
- CX\_SERVER - Checkmarx CLI plugin `-CxServer` option value
- CX\_USER - Checkmarx CLI plugin `-CxUSer` option value
- CX\_PASSWORD - Checkmarx CLI plugin `-CxPassword` option value
- CX\_LOCATION\_TYPE - Checkmarx CLI plugin `-LocationType` option value
- CX\_LOCATION\_URL - Checkmarx CLI plugin `-LocationURL` option value
- CX\_LOCATION\_BRANCH - Checkmarx CLI plugin `-LocationBranch` option value
- CX\_PROJECT - Checkmarx CLI plugin `-ProjectName` option value
- CX\_XML\_REPORT - Checkmarx CLI plugin `-ReportXML` option value
- CX\_PARSER - Location of `cxparser` 
- CX\_TEMLATE\_BODY - Email's body template
- CX\_TEMLATE\_VULNERABILITIES - Email's vulnerabilities template
- CX\_TEMLATE\_SEVERITIES - Email's severities template

# Parsing application

It is implemented a template-based mail body buyilding system, that allows for both text and HTML emails.
 
## Application dependencies

The parsing application only depends on the [boost library](http://www.boost.org/).

It was tested against boost release 1.62, although it might work with both older and newer boost releases.

## Building form source

Although the C++11 source code strictly follows the standard and no platform dependent dependencies are used (which means that the parsing tool can be build using any recent compiler), it is only provided the building infrastructure to produce Linux binaries.

In order to allow for easy compilation across diferent Linux configurations, the provided building infrastructure relies on `autotools`:

    aclocal;
    libtoolize --force;
    autoheader;
    automake -a;
    autoconf;
    ./configure


## Command line options
Please run the application with the --help option to see all available options:

    $ ./cxparser --help
    Available options:
	  -h [ --help ]                       Prints options usage
	  -v [ --version ]                    Prints application version
	  -i [ --input ] arg                  Sets input XML file (default: standard
	                                      input)
	  -o [ --output ] arg                 Sets output HTML file (default: standard
	                                      output)
	  -m [ --mail-template ] arg          Sets the global mail template to use
	  -u [ --vulnerability-template ] arg Sets the vulnerability template to use
	  -s [ --severity-template ] arg      Sets the severity template to use


## Templates
There are three templates to be considered for the email.

### Mail body template

The mail body template determines the general content of the sent emails' body.

Within it, where the tags described bellow appear, the information of both the vulnerabilities and the severities are inserted, according to their respective templates.

#### Tags
The following tags are supported within the mail body template:

- **%%VULNERABILITIES_RESULTS%%** -  Replaces the tag by every vulnerabilities' data, according to the Vulnerabilities template.

- **%%SEVERITIES_RESULTS%%** -  Replaces the tag by every severities' data, according to the Severities template.

### Vulnerabilities template
The vulnerabilities template allows to define how each vulnerability will be inserted within the email's body. The processing of this template is applied to each vulnerability found, ie, the contents of this template is repeated for every vulnerability. 

The following tags are available:

- **%%VULNERABILITY_NAME%%** - Replaces the tag by the vulnerability's name 

- **%%VULNERABILITY_OCCURRENCES%%** - Replaces the tag by the vulnerability's number of occurrences.


### Severities template
The severities template allows to define how each severity will be inserted within the email's body. The processing of this template is applied to each severity found, ie, the contents of this template is repeated for every severity.

The following tags are available:

- **%%SEVERITY_NAME%%** - Replaces the tag by the severity's level ("High", "Medium", etc.)

- **%%SEVERITY_OCCURRENCES%%** - Replaces the tag by the nr of vulnerabilities found with the given severity.
