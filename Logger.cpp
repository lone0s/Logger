
#include <ctime>
#include <chrono>
#include "Logger.h"

//BruteForce, penser usage reference & const

Logger::Logger(const std::string &name, int vLevel, bool showTime, const std::string &output) {
    this -> loggerName = name;
    this -> verboseLevel = vLevel;
    this -> output = output;
    this -> allowTimeStamping = showTime;
    this -> messageErrorLevel = INFORMATION; //Par défaut on récup tous les messages d'err
}

std::string Logger::getStrErrorLevel(errorLevel error)  {
    switch (error) {
        case INFORMATION:
            return "INFORMATION";
        case WARNING:
            return "WARNING";
        case CRITICAL:
            return "CRITICAL";
        default:
            return "INFORMATION";
    }
}

bool Logger::isAnError(int errorVal) {
    return (errorVal>= 0 && errorVal < nbErrors);
}

bool Logger::wantedLevelOfError(int errorVal) {
    return (errorVal >= Logger::verboseLevel);
}
//F° de log
void Logger::log(const std::string &message, int errorVal) {
    if (isAnError(errorVal) && wantedLevelOfError(errorVal)){
        std::string currentTime;
        Logger::messageErrorLevel = (errorLevel)errorVal;
        Logger::errorMessage = message;
        if (allowTimeStamping) {
            std::time_t res = std::time(nullptr);
//            currentTime = std::asctime(std::localtime(&res));
            currentTime = std::chrono::system_clock::now()
        }
        if (Logger::output == ("std::cout")) {
            //check ostream
            //std::cout << currentTime << getStrErrorLevel(messageErrorLevel) << " | " << errorMessage;
            std::cout << currentTime << "Test";
        }
        else if(Logger::output == ("std::cerr")) {
            //check ostream aussi
            std::cerr << currentTime << getStrErrorLevel(messageErrorLevel) << " | " << errorMessage;
        }
        else {
            // Check fstream !!!!
//            const char* file = Logger::output;
            FILE* fp = std::fopen(Logger::output.c_str(),"w+");
            if (!fp)
                std::perror("Couldn't create/open file");
            std::string outputMsg = currentTime + getStrErrorLevel(messageErrorLevel) + " | " + errorMessage;
            size_t fw = fwrite(outputMsg.c_str(),sizeof (char),outputMsg.size(),fp);
            printf("%zu elements written out of %llu requested",fw,outputMsg.size());
            fclose(fp);
        }
    } else
        std::cerr << "this isn't a correct error type, it goes from 0 to 2";
}







