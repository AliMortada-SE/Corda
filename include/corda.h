#include <string>
#include <iostream>
#include <utility>
#include <vector>
#ifndef CORDA_H
#define CORDA_H

//Type A:
//Normal Value Like Previus Scanner tool     10
//can handle mutiple values like -> name:ali;age:21;live:Iraq;
//every Tag have only 1 value
//Age:21;Username:ali;User:Player;
//Username -> 8
//User     -> 4
//pos will read Username as User and give pos as 8
//after check and know that Username is not user, we will add size of User (4) to pos (8) to 3
//so we will get 15
//removing the first 15 char of string while saving the real pos 
//new pos will be 6 (Find User)
//after checking User is Real Target(by read the ':' after it) return new pos(6) + old pos (15)
//will give 21 which is the Real pos of line.
//Type B:
//Every Tag have Array
//Example-> name:Ali,John,Mark,;age:21,27,18,;
//target(Mark) -> type(name) -> line(the string)
//locate the index in array, string have multiple Arrays(name,age,ID,etc..)
//by geting index, can get all data of the same person

class CORDA{
    public:
    std::pair<int,int> find(std::string target,std::string line);
    bool isExist(std::string target,std::string line);
    std::string get(std::string target,std::string line);
    std::string addValue(std::string tag,std::string value);
    int locateIndex(std::string target,std::string type,std::string line);
    std::string getByIndex(std::string target,std::string line,int index);
    std::string createArray(std::string tag,std::vector<std::string> list);
    std::string addToArray(std::string value);
};



#endif