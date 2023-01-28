

#include "LibrarySystem.h"

#include "UserNode.h"

#include "MovieNode.h"


//UserNode::Node *headUser = NULL;

int controlMovie=0;
int ControladdUser=0;
int ControlDeleteUser=0;
int ControlShowUser=0;
int ControlDeleteMovie=0;
int ControlAddMovie=0;
int ControlShowAllMoives=0;
void LibrarySystem::readFile(string fileName)
{
	std::ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line="";
	string last_call="";



	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else {
		cout << "			===Movie Library System==="<<endl<<endl;
		while(getline(commands,line)) //read file
		{
			string s=line;
			std::string delimiter = "\t";

			size_t pos = 0;
			std::string token;


			//cout << s <<endl;


			string first_word = s.substr(0, s.find(delimiter)); //add first word in a string
			if(first_word=="addUser")//control  line's first word "IT IS ADDUSER OR NOT"
			{	if (ControladdUser==0)
				{
					cout << "\n\n			===addUser() Method Test===";
					ControladdUser++;
				}
				string user_arr[3];
				int i=0;
				while ((pos = s.find(delimiter))  != std::string::npos) //split tab by tab and add an array
				{
							    token = s.substr(0, pos);
							    //cout << token <<endl;
							    user_arr[i]=token;
							    i++;
							    s.erase(0, pos + delimiter.length());
							    //cout<<"s"<<s<<endl;
							}
				user_arr[i]=s;
				const int user_ID=stoi(user_arr[1] );
				const string user_Name=user_arr[2];
				addUser(user_ID, user_Name);//call addUser method
			}//if end


			if(first_word=="deleteUser")//control  line's first word "IT IS ADDUSER OR NOT"
						{
								if (ControlDeleteUser==0)
								{
									cout << "\n\n			===deleteUser() Method Test==="<<endl;
									ControlDeleteUser++;
								}
							string user_arr[2];
							int i=0;
							while ((pos = s.find(delimiter))  != std::string::npos) //split tab by tab and add an array
							{
										    token = s.substr(0, pos);
										    //cout << token <<endl;
										    user_arr[i]=token;
										    i++;
										    s.erase(0, pos + delimiter.length());
										    //cout<<"s"<<s<<endl;
										}
							user_arr[i]=s;
							const int user_ID=stoi(user_arr[1] );
							deleteUser(user_ID);//call deleteUser method
						}//if end

			if (first_word=="showUser")//control  line's first word "IT IS SHOWUSER OR NOT"
			{
				if (ControlShowUser==0)
					{
						cout << "\n\n	 		===showUser() Method Test==="<<endl;
						ControlShowUser++;
								}
				showUser();//call showUser method
			}

			if (first_word=="showAllMovies")//control  line's first word "IT IS SHOWALLMOVÝES OR NOT"
						{
							if (ControlShowAllMoives==0)
								{
									cout << "\n\n	 		===showAllMovies() Method Test==="<<endl;
									ControlShowAllMoives++;
											}
							showAllMovies();//call showAllMovies method
						}



			if(first_word=="addMovie")//control  line's first word "IT IS ADDMOVÝE OR NOT"
						{
							if (ControlAddMovie==0)
							{
								cout << "\n\n			===addMovie() Method Test==="<<endl;
								ControlAddMovie++;
												}
							string movie_arr[4];
							int i=0;
							while ((pos = s.find(delimiter))  != std::string::npos) //split tab by tab and add an array
							{
										    token = s.substr(0, pos);
										    //cout << token <<endl;
										    movie_arr[i]=token;
										    i++;
										    s.erase(0, pos + delimiter.length());
										    //cout<<"s"<<s<<endl;
										}
							movie_arr[i]=s;
							const int movie_ID=stoi(movie_arr[1] );
							const string movie_Title=movie_arr[2];
							const int movie_Year=stoi(movie_arr[3]);
							addMovie(movie_ID, movie_Title, movie_Year);//call addMovie function
						}//if end
			if(first_word=="deleteMovie")//control  line's first word "IT IS DELETEMOVÝE OR NOT"
									{
										if (ControlDeleteMovie==0)
										{
											cout << "\n\n			===deleteMovie() Method Test==="<<endl;
											ControlDeleteMovie++;
														}
										string movie_delete_arr[2];
										int i=0;
										while ((pos = s.find(delimiter))  != std::string::npos) //split tab by tab and add an array
										{
													    token = s.substr(0, pos);
													    movie_delete_arr[i]=token;
													    i++;
													    s.erase(0, pos + delimiter.length());
													}
										movie_delete_arr[i]=s;
										const int movie_ID=stoi(movie_delete_arr[1] );
										deleteMovie(movie_ID);//call deleteMovie function
									}//if end

		}//while end
	}//else end
}//function end

UserNode userNode;
void LibrarySystem::addUser(const int userId, const string userName)
{	userNode.insert_last(userId, userName);}


void LibrarySystem::deleteUser(const int userId)
{	userNode.delete_pos(userId);}


void LibrarySystem::showUser()
{	userNode.display();}

MovieNode::Node *last=NULL;
MovieNode movieNode;

void LibrarySystem::addMovie(const int movieId , const string movieTitle, const int year)
{
			movieNode.add_begin(movieId, movieTitle, year);
			//movieNode.display_list();

}

void LibrarySystem::deleteMovie(const int movieId)
{
	movieNode.delete_element(movieId);
}

void LibrarySystem::showAllMovies()
{	movieNode.display_list();
	}

LibrarySystem::LibrarySystem() {
	// TODO Auto-generated constructor stub

}

LibrarySystem::~LibrarySystem() {
	// TODO Auto-generated destructor stub
}

