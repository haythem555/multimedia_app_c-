#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

using namespace std;

class Multimedia {

private :
    
    string name {""};
    string path {"None"};

public :
    Multimedia ();
    Multimedia (string name, string path);
    virtual ~Multimedia();

    //Getters 
    string get_name () const; 
    string get_path () const;

    //Setters
    void set_name(string name);
    void set_path(string path);

    virtual void display (ostream& out ) const;
    
    // This is an abstruct method and thus this is an abstruct class
    // and we can no longer create objects of this class
     virtual void play() const=0; 

};


#endif