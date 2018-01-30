# Introduction
It was requested an integration solution to upload a repo-residing source code to Chechmarx cloud server, parse the source's scan result and send an email with the parsing results to a list of recipients.

A custom application was developed using portable C++11 to parse the XML report generated by Checkmarx scan tool and produce the email's body content. Besides this application's source code, both Windows and Linux binaries are provided.

# Script
## Configuration
The script configuration is on the script it self. For easy of use, all configuration settings is at the script's very beginning, in a well defined area.

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


# Parsing application
It is implemented a template-based mail body buyilding system, that allows for both text and HTML emails.
 
## Application dependencies

The parsing application only depends on the [boost library](http://www.boost.org/).

It was tested against boost release 1.62, although it might work with both older and newer boost releases.

## Command line options
Please run the application with the --help option to see all available options:

    $ ./cxparser --help

## Templates
There are three templates to be considered for the email.

### Mail body template

The mail body template determines the general content of the sent emails' body.

Within it, where the tags described bellow appear, the information of both the vulnerabilities and the severities are inserted, according to their respective templates.

#### Tags
The following tags are supported within the mail body template:

- **%%VULNERABILITIES_RESULTS%%** -  Replaces the tag by each vulnerability's data, according to the Vulnerabilities template.

- **%%SEVERITIES_RESULTS%%** -  Replaces the tag by each severity's data, according to the Severities template.

### Vulnerabilities template
The vulnerabilities template allows to define how each vulnerability will be inserted within the email's body.

The following tags are available:

- **%%VULNERABILITY_NAME%%**

- **%%VULNERABILITY_OCCURRENCES%%**


### Severities template
The severities template allows to define how each severity level will be inserted within the email's body.

The following tags are available:

- **%%SEVERITY_NAME%%**

- **%%SEVERITY_OCCURRENCES%%**
