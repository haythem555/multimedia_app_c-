#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "multimedia.h"


class Video : public Multimedia{

private :
    int duration{0};

public :
    Video(){}
    Video(string name,string path, int duration): Multimedia(name,path),duration(duration){}
    virtual ~Video(){
        cout<<"video named "<<this->get_name()<<" is destroyed"<<endl;
    }

    //Additional getter 
    int get_duration () const {
        return duration;
    }

    //Additional setter
    void set_duration(int duration){
        this->duration =duration;
    }

    virtual void display(ostream& out )const override {
        out<<"Name of video : '"<<this->get_name() <<"', full path : '"<<this->get_path()<<"' , duration :" <<duration<<endl;    
    }

    virtual void play()const override{
        string str = "start "+this->get_path()+"&";
        system(str.c_str());
    }
   
};


#endif