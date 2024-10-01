#include "group.h"

void Group::display(ostream& out)const{
    out<<" Reading group "<<name<<endl;
    for (auto &it : *this){
        if(it){
            it->display(out);
        }
    }
    out<<" Done reading"<<endl;

}