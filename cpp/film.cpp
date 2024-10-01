#include "film.h"

int* copy_table(int* table, int size ){
    int* copy  = new int[size];
    if(size){ // checking that the table given is not empty
            for (int i=0;i<size;i++){
                copy[i]=table[i];
            }
        }
    else
        copy =nullptr;
    return copy ; 
}

Film::Film(){}
Film::Film(string name, string path,int duration ,int * chapters,int nbr_chapters):Video(name,path,duration){

    this->nbr_chapters=nbr_chapters;
    this->chapters = copy_table(chapters,nbr_chapters);
}

Film::~Film(){
if(chapters)
    delete[] chapters ;
cout<<"film named "<<this->get_name()<< " is destroyed"<<endl;
}

int* Film::get_chapters () const{
        return copy_table(chapters,nbr_chapters);
}
    
int Film::get_nbr_chapters() const{
        return nbr_chapters;
}
void Film::set_chapters(int* chapters,int nbr_chapters){
        this->nbr_chapters = nbr_chapters;
        this->chapters = copy_table(chapters,nbr_chapters);       
}

void Film::display(ostream& out) const {
        if (chapters){ // table non empty
            cout<<"Displaying chapters\n";
            for (int i=0;i<nbr_chapters;i++){
                cout<<"duration of chapter ["<<i<<"] is "<<chapters[i]<<"\n";        
            }
        }

}