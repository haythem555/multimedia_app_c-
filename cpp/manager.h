#ifndef MANAGER_H
#define MANAGER_H

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include <map>
#include <memory>
#include <ostream>
#include <sstream>

using Obj_dic = map<string,shared_ptr<Multimedia>>;
using Group_dic = map<string,shared_ptr<Group>>;
using Spm = shared_ptr<Multimedia>; 
using Spg = shared_ptr<Group>;

class Manager {
private :

    Obj_dic obj_dic {};
    Group_dic group_dic {};

public :

    Manager(){};
    ~Manager(){};

    Spm add_photo(string name,string path,double height,double width);
    Spm add_video(string name,string path,int duration);
    Spm add_film(string name,string path, int duration, int* chapters, int nbr_chapters);
   
    Spg add_group (string name);

    Spm find_obj (string name) const;
    Spg find_group (string name) const; 

    void play_obj(string name) const ;
    string process_request(string request) ;

};


#endif