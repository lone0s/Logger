#include <iostream>
#include "Logger.h"
int main() {
    Logger logger = Logger("test",0,true,"E:\\ohno\\Documents\\C++\\TPs\\TP1\\test.txt");
    Logger::levelsOfErrors();
    logger.log("a",0);
    logger.log("b",1);
    logger.log("c",2);
    logger.log("d",3);
    //Need mess [Mettre date sur meme ligne que message cri]
    return 0;
}
