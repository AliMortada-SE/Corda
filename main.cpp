#include "corda.h"
#include <iostream>
CORDA corda;
int main(){
    std::string line = "name:Ali,John,Mark,;age:21,27,18,;live:IQ,US,UK,;";
    int index = corda.locateIndex("John","name",line);
    std::string age = corda.getByIndex("live",line,index);
    std::string getAges = corda.get("age",line);
    std::cout<<"All Ages:"<<getAges<<"\n";
    std::cout<<"Age:"<<age<<"\n";
    return 0;
}