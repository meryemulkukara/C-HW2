/*
 * LibrarySystem.h
 *
 *  Created on: 30 Kas 2020
 *      Author: Ulku
 */

#ifndef LIBRARYSYSTEM_H_
#define LIBRARYSYSTEM_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class LibrarySystem {
public:

	LibrarySystem();
	virtual ~LibrarySystem();

	void readFile(string fileName);

	void addMovie(const int movieId , const string movieTitle, const int year);
	void deleteMovie(const int movieId);

	void addUser(const int userId, const string userName);
	void deleteUser(const int userId);

	void checkoutMovie(const int movieId, const int userId);
	void returnMovie(const int movieId);

	void showAllMovies();
	void showMovie();
	void showUser();

};

#endif /* LIBRARYSYSTEM_H_ */
