#include <iostream>
#include "Logger.h"
int main() {
    Logger logger = Logger("toz",0,true,"std::cout");
    //std::cout << logger.isAnError(logger.messageErrorLevel);
    logger.log("Ahcheum zebi", 2);


    //Need mess [Mettre date sur meme ligne que message cri]
    return 0;
}
