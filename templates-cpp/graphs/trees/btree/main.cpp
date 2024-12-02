#include <iostream>
#include <string>
#include <vector>

struct data{
    unsigned int key;
    std::string name;
};


int main(){

    std::vector<data*> elements;
    std::vector<unsigned int> keys = {10,80,30,90,85,40,50,60,70,95,100}
    
    for(unsigned int i : keys){
        data * d = new data;
        d->key = i;
        d->name = "name " + std::to_string(i);
        elements.push_back(d);
    }

   return 0; 
}
