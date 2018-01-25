#!/bin/bash

readonly EMAIL_RECIPIENTS="recipient1@gmail.com,recipient2@example.com"
readonly GIT_REPO_URL="https://github.com/boostorg/boost.git"
readonly STAGING_BASE="$HOME/checkmarx/staging"
readonly REPO_SHORT_NAME="bricks"
readonly LOCAL_REPO="$STAGING_BASE/$REPO_SHORT_NAME"

function pullCode()
{
	if [[ ! -d "$STAGING_BASE" ]]; then
		# Staging path does not exist. Create it
		mkdir -p %STAGING_BASE
	fi

	# Clones repo
	git clone "$GIT_REPO_URL" "$LOCAL_REPO"
}

function scanSourceCode()
{
	local readonly CX_CONSOLE=$HOME/checkmarx/CxConsolePlugin-8.51.0-20171024-0825/runCxConsole.sh

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

pullCode
XML_REPORT=scanSourceCode
analyzeReport $XML_REPORT
sendSummaryEmail
