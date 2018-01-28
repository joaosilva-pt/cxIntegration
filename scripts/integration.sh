#!/bin/bash

# =================
# BEGIN OF CONFIG
#
# Edit the vars in this area according to project's needs
#==================
readonly EMAIL_RECIPIENTS="recipient1@gmail.com,recipient2@example.com"
readonly GIT_REPO_URL="https://github.com/joaosilva-pt/bricks"
readonly CX_CONSOLE="$HOME/bin/CxConsolePlugin-8.51.0-20171024-0825/runCxConsole.sh"

readonly CX_SERVER="https://cxprivatecloud.checkmarx.net/"
readonly CX_USER="m.joao.silva.ml@gmail.com"
readonly CX_PASSWORD="0x12heckM@rx"
readonly CX_LOCATION_TYPE="GIT"
readonly CX_LOCATION_URL="https://github.com/joaosilva-pt/bricks"
readonly CX_LOCATION_BRANCH="refs/head/master"
readonly CX_PROJECT="CxServer\\SP\\EMEA\\gmail.com-56\\Bricks"
readonly CX_XML_REPORT="/home/jsilva/develop/cxIntegration/scripts/report.xml"
# =================
# END OF CONFIG
#
# DO NOT EDIT BELLOW THIS POINT!!!!
#==================


function scanSourceCode()
{
	`"$CX_CONSOLE" scan -CxServer "$CX_SERVER" -CxUSer "$CX_USER" -CxPassword "CX_PASSWORD" -LocationType "$CX_LOCATION_TYPE" -LocationURL "$CX_LOCATION_URL" -LocationBranch "$CX_LOCATION_BRANCH" -ProjectName "$CX_PROJECT" -ReportXML "CX_XML_REPORT" -v`
}

function analyzeReport()
{
	local readonly XML_REPORT="$1"
}

function sendSummaryEmail()
{
	local readonly MAIL_CONTENT="$1"
	
	# Sends email
	echo "$MAIL_CONTENT" | mail -s "CI summary report" $EMAIL_RECIPIENTS
}

scanSourceCode
HTML_BODY=analyzeReport "$CX_XML_REPORT"
sendSummaryEmail "$HTML_BODY"
