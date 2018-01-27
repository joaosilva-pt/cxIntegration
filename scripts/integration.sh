#!/bin/bash

# =================
# BEGIN OF CONFIG
#
# Edit the vars in this area according to project's needs
#==================
readonly EMAIL_RECIPIENTS="recipient1@gmail.com,recipient2@example.com"
readonly GIT_REPO_URL="https://github.com/joaosilva-pt/bricks"
readonly CX_CONSOLE="$HOME/bin/CxConsolePlugin-8.51.0-20171024-0825/runCxConsole.sh"
# =================
# END OF CONFIG
#
# DO NOT EDIT BELLOW THIS POINT!!!!
#==================


function scanSourceCode()
{

	echo "$SCAN_RESULT"
}

function analyzeReport()
{
	local readonly XML_REPORT="$1"
}

function sendSummaryEmail()
{
	# Sends email
	echo "$MAIL_CONTENT" | mail -s "CI summary report" $EMAIL_RECIPIENTS
}

XML_REPORT=scanSourceCode
analyzeReport $XML_REPORT
sendSummaryEmail
