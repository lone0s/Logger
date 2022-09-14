
#include <ctime>
#include <chrono>
#include "Logger.h"

//BruteForce, penser usage reference & const

Logger::Logger(const std::string &name, int vLevel, bool showTime, const std::string &output) {
    this -> loggerName = name;
    this -> verboseLevel = vLevel;
    this -> output = output;
    this -> allowTimeStamping = showTime;
}

std::string Logger::getStrErrorLevel(errorLevel error) {
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

//F° de log
void Logger::log(const std::string &message, int errorVal) const {
    if (isAnError(errorVal)){
        if (wantedLevelOfError(errorVal)) {
            std::string currentTime;
            if (allowTimeStamping) {
                std::time_t res = time(nullptr);
                currentTime = std::asctime(std::localtime(&res));
                currentTime.erase(currentTime.size() - 1); //Faire sauter le \n
            }
            if (Logger::output == ("std::cout")) {
                //check ostream
                std::cout << currentTime << " | [" << getStrErrorLevel((errorLevel)errorVal) << "] | " << message + "\n";
            } else if (Logger::output == ("std::cerr")) {
                //check ostream aussi
                std::cerr << currentTime << " | [" << getStrErrorLevel((errorLevel)errorVal)  << "] | " << message + "\n";
            } else {
                // Check fstream !!!!
                FILE *fp = std::fopen(Logger::output.c_str(), "a+");
                if (!fp)
                    std::perror("Couldn't create file");
                std::string outputMsg = currentTime + " | [" + getStrErrorLevel((errorLevel)errorVal)  + "] | " + message + "\n";
                size_t fw = fwrite(outputMsg.c_str(), sizeof(char), outputMsg.size(), fp);
                printf("%zu elements written out of %zu requested\n", fw, outputMsg.size());
                fclose(fp);
            }
        }

    } else
        std::cerr << "this isn't a correct error type, it goes from 0 to 2" << std::endl;
}

bool Logger::isAnError(int errorVal) {
    return (errorVal>= 0 && errorVal < nbErrors);
}

bool Logger::wantedLevelOfError(int errorVal) const {
    return (errorVal >= Logger::verboseLevel);
}

void Logger::levelsOfErrors() {
    std::cout << "There's " << Logger::nbErrors << " levels of error :" << std::endl;
    for(int i = 0 ; i < Logger::nbErrors ; i++) {
        std::cout << "["<<i<<"] -- "<< Logger::getStrErrorLevel(Logger::errorLevel(i)) << std::endl;
    }
}







