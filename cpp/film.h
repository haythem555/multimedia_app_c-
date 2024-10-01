#ifndef FILM_H
#define FILM_H

#include<string>
#include<iostream>
#include "video.h"


class Film : public Video{

private : 
    int* chapters {nullptr}; 
    int nbr_chapters{0};
    
public :    
    Film();
    Film(string name, string path,int duration ,int * chapters,int nbr_chapters);
    virtual ~Film();

    // getter and setter 
    int* get_chapters () const;
    int get_nbr_chapters() const;
    void set_chapters(int* chapters,int nbr_chapters);

    virtual void display(ostream& out) const override;
   



};


#endif