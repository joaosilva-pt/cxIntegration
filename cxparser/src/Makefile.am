noinst_PROGRAMS = cxparser

cxparser_SOURCES = main.cpp \
    applicationconfig.cpp \
    cxxmlparser.cpp \
    cxmailbodycreator.cpp

# set the include path found by configure
cxparser_CPPFLAGS= $(all_includes) --std=c++11

# the library search path.
cxparser_LDFLAGS = $(all_libraries) -lboost_program_options -lboost_filesystem -lboost_system
