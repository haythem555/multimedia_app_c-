#include "manager.h"

Spm Manager::add_photo(string name,string path,double height,double width){

    // Check if the element that we want to add is present
    auto it = obj_dic.find(name);
    // if not add it
    if (it==obj_dic.end()){
        shared_ptr<Photo> photo ( new Photo(name,path,height,width));
        obj_dic [name]= photo;
    }
    else {
        cout<<"This photo already exists, no need to add it again"<<endl;
    }
    
    return obj_dic[name];

}

Spm Manager::add_video(string name, string path,int duration){
    
    auto it = obj_dic.find(name);
    if (it==obj_dic.end()){
        shared_ptr<Video> video (new Video(name,path,duration));
        obj_dic[name]= video;
    }
    else {
        cout<<"This video is already here, no need to add it again"<<endl;
    }
    return obj_dic[name];
    }

Spm Manager::add_film(string name,string path,int duration,int* chapters,int nbr_chapters){
    auto it = obj_dic.find(name);
    if(it == obj_dic.end()){
        shared_ptr<Film> film(new Film (name,path,duration,chapters,nbr_chapters));
        obj_dic[name]=film;
    }
    else {
        cout<<"This film is already here try another one"<<endl;
    
    }
    return obj_dic[name];
    }

Spg Manager::add_group(string name){
    auto it = group_dic.find(name);

    if(it== group_dic.end()) {
        Spg group (new Group(name));
        group_dic[name]= group;
    }
    else 
        cout<<"This is already here try something else"<<endl;

    return group_dic[name];
}


Spm Manager::find_obj(string name) const{
    auto it = obj_dic.find(name);
    if (it!=obj_dic.end())
        return it->second;
    else {
        cout<<"object no found"<<endl;
        return nullptr;
    }
}

Spg Manager::find_group(string name) const{
    auto it =group_dic.find(name);
    if (it!=group_dic.end())
        {   
            return it->second;
        
        }
    else {
        cout<<"object not found"<<endl;
        return nullptr;
    }
}

void Manager::play_obj(string name) const {
    Spm media = find_obj(name);
    if (media!= nullptr ){
        media->play();
    }
    else
        cout<<"Object not found ! cannot play !";
}

    
string Manager::process_request(string request)  {
    cout << "\nRequest: '" << request << "'" << endl;

	// Request parsing
	string action, _name;
	stringstream str;
	str << request;
	str >> action;
	str >> _name;

	// Treating request
	stringstream answer_str;
	bool searched, played;
	shared_ptr<Multimedia> search_obj;
	shared_ptr<Group> search_grp;
	searched = false;
	played = false;
	if (action == "search")
	{
		shared_ptr<Multimedia> obj = find_obj(_name);
		if (obj != nullptr){
			obj->display(answer_str);
			searched = true;
            
		}
		else {
			shared_ptr<Group> grp = find_group(_name);
			if(grp != nullptr){
				grp->display(answer_str);
				searched = true;
                
			}
		}
        
	}
	if (action == "play") { 
        shared_ptr<Multimedia> obj = find_obj(_name);
        if (obj!=nullptr) {
            play_obj(_name) ; 
        return "found and currently playing";
        }
        else 
        {
            return "Can't play "+ _name + ", File not found";
        }
    }

    if(action == "add_photo"){
        string _path,height,width;
        str>>_path>>height>>width;
        //cout<<_path<<height<<width;
        double  _height = stoi(height);
        double _width = stoi (width); 
        add_photo(_name, _path, _height, _width);
        return "added photo successfully" ;
    }
    if(action == "add_video"){
        string _path,_duration;
        str>>_path>>_duration;
        //cout<<_path<<height<<width;
        double duration = stoi (_duration); 
        add_video(_name, _path, duration);
        return "added video successfully" ;
    }

    if(action == "add_group"){
        add_group(_name);
        return "added group successfully" ;
    }
    if(action == "add_to_group"){
        string name_media_to_add;
        str>>name_media_to_add;
        //cout<<_path<<height<<width;
        Spg group_to_add = find_group(_name);
        if(group_to_add != nullptr){
            Spm obj = find_obj(name_media_to_add);
            if (obj!=nullptr)
                group_to_add->push_back(obj);
            else 
                return "object with name "+name_media_to_add+" is not found \n" ;
        }
        else 
                return "group with name "+_name +" is not found\n";

        return "added video successfully" ;
    }


    


	// Sending response
	if (played || searched)
		return answer_str.str();
	else
		return "Error : no such file";



}