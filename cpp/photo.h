#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "multimedia.h"

class Photo : public Multimedia {

private :
    double height {0.0};
    double width {0.0};

public :

    Photo(){}
    Photo(string name, string path, double height, double width ) : Multimedia(name,path),height(height),width(width){}
    virtual ~Photo(){
        cout<<"photo named "<<this->get_name()<<" is destroyed"<<endl;
    }

    //Additional getter
    double get_height() const{
        return height;
    }

    double get_width()const {
        return width;
    }

    //Additional setter
    void set_height(double height){
        this->height =height;
    }

    void set_width(double width){
        this->width= width;
    }

    virtual void display (ostream& out )const override {
         out<<"Name of photo : '"<<this->get_name() <<"', full path : '"<<this->get_path()<<"' with dimensions (h,w)= ("<<height<<","<<width<<")"<<endl;
    }

    virtual void play ()const override {
        string str = "start "+this->get_path()+"&";
        system(str.c_str());

    }


};


#endif