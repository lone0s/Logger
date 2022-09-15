
#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <iostream>
// Fichier d'entete tjr libre pdt que source devient biblio & exec

class Logger {
private:
    enum errorLevel { INFORMATION = 0, WARNING, CRITICAL };
    static const int nbErrors = 3 ;

    std::string loggerName;
    int verboseLevel;
    std::string output;
    bool allowTimeStamping;

public:
    Logger(const std::string& name, int vLevel, bool showTime, const std::string& output);

    static std::string getStrErrorLevel(errorLevel error) ;
    void log(const std::string &message, int errorVal) const;

    static bool isAnError(int errorVal) ;
    bool wantedLevelOfError(int errorVal) const;
    static void levelsOfErrors() ;
};

#endif //LOGGER_LOGGER_H