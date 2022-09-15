#include "Logger.h"
int main() {
    Logger logger = Logger("test",2,true,R"(E:\ohno\Documents\C++\TPs\TP1\test.txt)");
    logger.log("a",0);
    logger.log("b",1);
    logger.log("c",2);
    logger.log("d",3);
    return 0;
}
