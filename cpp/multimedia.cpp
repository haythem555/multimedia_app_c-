#include "multimedia.h"

Multimedia::Multimedia(){}
Multimedia::Multimedia(string name, string path):name(name), path(path)  {}
Multimedia::~Multimedia(){}

//Getters
string Multimedia::get_name()const {
    return name;
}
string Multimedia::get_path() const {
    return path;
}

//Setters
void Multimedia::set_name(string name){
    this->name = name;
}

void Multimedia::set_path(string path){
    this->path = path;
}

void Multimedia::display(ostream& out )const {
    out<<"Name of file : '"<<name <<"', full path : '"<<path<<"'"<<endl;
}