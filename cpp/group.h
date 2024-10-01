#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include <memory>
#include <list>

class Group : public list<shared_ptr<Multimedia>> {
    
private :
    string name {""};

public :
    Group(){}
    Group(string name):name(name){}
    virtual ~Group(){
        cout<<"Destroying Group "<<name<<endl;
    }    

    string get_name(){
        return name;
    }

    virtual void display(ostream& out) const;


};

#endif