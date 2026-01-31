#include "corda.h"

std::pair<int,int> CORDA::find(std::string target,std::string line){
    int pos = line.find(target);
    int targetSize = target.size();
    int start = pos;
    int end = 0;
    while(pos != std::string::npos){
        while(line[pos+targetSize]==' '){
            line.erase(pos+targetSize,1);
            end++;
        }
        if(line[pos+targetSize]==':'){
            return {start,start+targetSize+end+1};
        }
        if(pos + targetSize < line.size() && line[pos+targetSize]!=':'){
            std::cout<<"Before Skipping:"<<line<<"\n";
            line.erase(0,pos+targetSize+1);
            std::cout<<"After Skipping:"<<line<<"\n";
            pos = line.find(target);
            start+=pos+targetSize+1;
        }
        if(pos == std::string::npos) return {-1,-1};
    }
    return {-1,-1};
}
bool CORDA::isExist(std::string target,std::string line){
    std::pair<int,int> offset = CORDA::find(target,line);
    if(offset.first == -1 && offset.second == -1) return 0;
    return 1;
}
std::string CORDA::get(std::string target,std::string line){
    std::pair<int,int> offset = CORDA::find(target,line);
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
int CORDA::locateIndex(std::string target,std::string type, std::string line){
    std::string Target = CORDA::get(type,line);
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
std::string CORDA::getByIndex(std::string target, std::string line, int index){
    std::string Target = CORDA::get(target,line);
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
std::string CORDA::createArray(std::string tag, std::vector<std::string> list){
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