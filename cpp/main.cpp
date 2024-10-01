#include <iostream>
#include <string>
#include "multimedia.h"
#include <memory>
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"
#include <sstream>
#include "tcpserver.h"

const int PORT = 3331;

using namespace std;


int main(int argc, const char* argv[]) 
{
/*Step 3 (Test 1 for Multimedia class)

Multimedia* media = new Multimedia("photo","Desktop/photo.jpg");
cout<<"Before changes :\nname ='"<<media->get_name()<<"', path = '"<<media->get_path()<<"'"<<endl; 
media->set_name("new photo");
media->set_path("Downloads/new_photo");
cout<<"----------------------------"<<endl;
cout<<"after changes :"<<endl;
media->display(cout);
*/

/*Answer Step 4 :
the play method in the class multimedia is now abstruct
and thus the whole class becomes abstruct and we can no longer create object from this class 
*/

/*
Step 5

// creating the list
Multimedia* list_media[] = {new Photo("tool","tool.png",15.2,7.4),new Video("video","video.mp4",59),new Photo("phoot2","photo2.jpg",15.2,7.4)} ;

// looping over the media in list
for (Multimedia* media : list_media){
    media->display(cout);
    media->play();
}
// The caracteristic property that allows us to this here is the polymorphisme

// In orer to allow this property it is necessary in c++ to declare the functions using the keyword virtual

// The table has to contain pointers on the elements otherwise the elments will get sliced down to their base properties (Here only the Multimedia layer will remain)
// because the objects declared has to be of the same type and if we try to put a photo in a multimedia objects the size has to be the same

// Compared to java we use the same logic : we create a table of base pointers and we manage everything through it

*/

/*Step 6


int* chapters =new int[4] {1,25,37,59};
cout<<"creating the film table"<<endl;
Film* film =new Film("video","video.mp4",59,chapters,4);
film->display(cout);

cout<<"-----------------------------------------------------"<<endl;

// Now let's modify the paramter passed and verify that the object is not changing
cout<<"changing the first value of original table"<<endl;
chapters[0]=100;
cout<<"original table chapter [0]= "<<chapters[0]<< "\nfilm->chapters[0]= "<<film->get_chapters()[0]<<endl;

cout<<"-----------------------------------------------------"<<endl;
cout<<"setting a new table, deleting it , and displaying using the getter method"<<endl;
int* new_chapters = new int [2]{55,111};
film->set_chapters(new_chapters,2);
delete [] new_chapters;
int* ch = film->get_chapters();
for (int i =0;i<2;i++) {
 cout<<"duration of chapter ["<<i<<"] is "<<ch[i]<<"\n";        
}
*/

/*Step 7 
In the pervious classes only the film class has a dynamically created memory
This memory is pointed at using the member variable chapters in my porgram and it has to be delet with 
in the destructor or else we will have a memory leakage

*/

/*Step 8 and 9
The list has to be of pointers in order to allow polymorphic behaviours on our objects.
In java this is always the case since we cannot manage data directly by only through pointers.


//
	cout << "Test of groups/ automatic memory management(Question 8/9):\n" << endl;
    int size=2;
    int* chapters = new int [size]{55,111};
	shared_ptr<Video> v1(new Video("Video1", "video.mp4", 10));
	shared_ptr<Photo> p1(new Photo("Photo1", "tool.png", 3, 2));
    shared_ptr<Photo> p2(new Photo("Photo2", "tool.png", 3, 2));
	shared_ptr<Film> f1(new Film("film1", "film.mp4", 120, chapters, size));
	
    // Creating new group
	shared_ptr<Group> gr1(new Group("Test group 1"));
	shared_ptr<Group> gr2(new Group("Test group 2"));
	// Putting elements in the group
	gr1->push_back(v1);
	gr1->push_back(p1);
	gr1->push_back(f1);

    gr2->push_back(p1);// commun photo
	gr2->push_back(p2);
	gr2->push_back(v1);// commun video



	if (gr1.use_count() != 0)
	{
		// Printing elements one by one, like in the display method
		cout << "print of group 1 : \n" << endl;
		for (auto & it : *gr1)
		{
			cout << "media name : " << it->get_name() << endl;
            //it->display(cout);
		}
	}

    
	if (gr2.use_count() != 0)
	{
		// Printing elements one by one, like in the display method
		cout << "\nprint of group 2 : \n" << endl;
		for (auto & it : *gr2)
		{
			cout << "media name : " << it->get_name() << endl;
           // it->display(cout);
		}
	}
    cout<<"\nreseting original pointers and g1 \n"<<endl;
	// if p is a smart pointer p.reset () makes sure that it no longer points to anything
	//  deleting original pointers for testing 
    v1.reset();
    p1.reset();
    p2.reset();
    f1.reset();

    gr1.reset();// destruction message will appear here alongside the unique objects that he is pointing to since we reseted every pointer

    cout<<"\ntesting if the unique object of g2 is still present"<<endl;
    (gr2->front())->display(cout); // cheking if the commun photo 1 is still accessabel through the group 2 
    cout<<"\nend of this scope and evey left pointer will be cleared"<<endl;
*/


/*Step 10 

//To prevent that an object is created with new out of the Manager Class, meaning it wouldn't be 
//added to the list, we could make the constructors of photo, video, film, group, 
//protected (for objects of this class (by default) and also for subclasses.)

Manager* manager = new Manager();

manager->add_photo("tool","tool.png",15.2,7.4);
manager->add_photo("photo2","photo2.jpg",15.2,7.4)   ;
manager->add_video("video","video.mp4",59);

int size = 2;
int* chapters = new int [size]{55,111};
manager->add_film("film1", "film.mp4", 120, chapters, size);

// adding groups 
manager->add_group("groupe1");
manager->add_group("groupe2");

// finding and displaying examples 
manager->find_obj("tool")->display(cout);
manager->find_obj("photo2")->display(cout);
manager->find_obj("video")->display(cout);
manager->find_obj("film1")->display(cout);

cout<<"found the groupe named "<<manager->find_group("groupe1")->get_name();

//manager->play_obj("photo2");
//Photo* photo = new Photo("photo2","photo2.jpg",15.2,7.4)   ;
//photo->play();
*/

// Partie 11
/*
  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    response = "RECEIVED: H : " + request;
  
    // return false would close the connecytion with the client
    return true;
  });
  
  
  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;
  
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }
  */
  
  
  // cree l'objet qui gère les données
  shared_ptr<Manager> base(new Manager());
  base->add_photo("tool","tool.png",10,15);
  base->add_video("video","video.mp4",12);

  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer([&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    if(request !="close server")
    {response = base->process_request(request);
    
    // return false would close the connecytion with the client
    return true;
    }
    else 
      return false;
  }));
  

  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }


cout<<"\nprogram terminatred just fine "<<endl;
return 0;

}
