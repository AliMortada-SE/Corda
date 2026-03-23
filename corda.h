#pragma once
#ifndef CORDA_H
#define CORDA_H
#include <string>
#include <iostream>
#include <utility>
#include <vector>
class CORDA{
public:
std::pair<int,int> find(std::string target, std::string line){
    size_t pos = line.find(target);
    while(pos != std::string::npos){
        size_t after = pos + target.size();
        // skip spaces
        while(after < line.size() && line[after] == ' ') after++;
        // bounds check
        if(after >= line.size()){
            return {-1, -1};
        }
        if(line[after] == ':'){
            return {(int)pos, (int)(after + 1)};
        }
        // search again after this occurrence
        pos = line.find(target, pos + 1);
    }
    return {-1, -1};
}
bool isExist(std::string target,std::string line){
    std::pair<int,int> offset = find(target,line);
    if(offset.first == -1 && offset.second == -1) return 0;
    return 1;
}
std::string get(std::string target,std::string line){
    std::pair<int,int> offset = find(target,line);
    if(offset.first == -1 && offset.second == -1) return "";
    int x = offset.second;
    std::string value;
    while(x<line.size() &&  line[x]!=';'){
        value+=line[x];
        x++;
    }
    return value;
}
std::string addValue(std::string tag,std::string value){
    return tag + ':' + value + ';';
}
int locateIndex(std::string target,std::string type, std::string line){
    std::string Target = get(type,line);
    Target+=';';
    std::string temp;
    int counter = 0;
    int x = 0;
    while(x<Target.size()){
        while(x < Target.size() && Target[x]!=','){
            temp+=Target[x];
            x++;
        }
        x++;
        if(temp == target){
            return counter;
        }
        else{
            if(x >= Target.size() || Target[x]==';') return -1;
            temp.clear();
            counter++;
        }
    }
    return -1;
}
std::string getByIndex(std::string target, std::string line, int index){
    std::string Target = get(target,line);
    Target+=';';
    int counter = 0;
    int x=0;
    std::string temp;
    while(counter != index && x<Target.size()){
        while(Target[x]!=','&& x<Target.size()){
            x++;
        }
        x++;
        counter++;
    }
    if(counter==index){
        while(Target[x]!=',' && Target[x]!=';' && x<Target.size()){
            temp+=Target[x];
            x++;
        }
    }
    return temp;
}
std::string createArray(std::string tag, std::vector<std::string> list){
    std::string array;
    array += tag + ':';
    int x = 0;
    while(x<list.size()){
        array += list[x];
        array += ',';
    }
    array+=';';
    return array;
}
};
#endif