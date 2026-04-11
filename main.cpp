#include "corda.h"
#include <iostream>
CORDA corda;
int main(){
    std::string line = "name:Ali;age:21;";
    std::cout << corda.remove("name",line)<<"\n";
    return 0;
}