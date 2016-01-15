#include "manager.h"
#include "borrow.h"
#include "return.h"
#include "classic.h"
#include "drama.h"
#include "dvd.h"
#include "tree.h"
#include "movie.h"
#include "nodemovie.h"
#include <iostream>
using namespace std;

int main() {

	/*
	cout << "TESTING PERSON AND CUSTOMER ---------------------------" << endl << endl;

	Person p1("Alex", "Matt");
	cout << p1.getFirst() << p1.getLast() << endl;

	Customer c1("Annie", "Zed", 100);
	cout << c1.getFirst() << c1.getLast() << c1.getId() << endl;

	Customer c2(p1, 101);
	cout << c2.getFirst() << c2.getLast() << c2.getId() << endl;
	
	Date d1(4, 2, 1997);
	cout << d1.getMonth() << "/" << d1.getDay() << "/" << d1.getYear() << endl;
	Date d2(d1);
	Date d3(4, 6, 1997);
	Date d4(7, 14, 1980);
	cout << "date comparisons, should all be 1: ";
	((d1 == d2) == 1) ? cout << 1 : cout << 0;
	((d1 != d2) == 0) ? cout << 1 : cout << 0;
	((d1 == d3) == 0) ? cout << 1 : cout << 0;
	((d1 != d3) == 1) ? cout << 1 : cout << 0;
	((d1 == d4) == 0) ? cout << 1 : cout << 0;
	((d1 != d4) == 1) ? cout << 1 : cout << 0;
	((d1 > d3) == 0) ? cout << 1 : cout << 0;
	((d1 < d3) == 1) ? cout << 1 : cout << 0;
	((d1 >= d3) == 0) ? cout << 1 : cout << 0;
	((d1 <= d3) == 1) ? cout << 1 : cout << 0;
	((d1 >= d2) == 1) ? cout << 1 : cout << 0;
	((d1 <= d2) == 1) ? cout << 1 : cout << 0;
	((d1 == d1) == 1) ? cout << 1 : cout << 0;
	((d1 != d1) == 0) ? cout << 1 : cout << 0;
	((d1 > d1) == 0) ? cout << 1 : cout << 0;
	((d1 < d1) == 0) ? cout << 1 : cout << 0;
	((d1 >= d1) == 1) ? cout << 1 : cout << 0;
	((d1 <= d1) == 1) ? cout << 1 : cout << 0;


	cout << endl;

	cout << endl << "TESTING MEDIA/MOVIES ----------------------------------";


	DVD dvd1;
	dvd1.addQuantity(10);
	cout << dvd1.getType() << " " << dvd1.getCurrStock() << "/" << dvd1.getQuantity() << endl;
	dvd1.sub(); dvd1.sub(); dvd1.sub(); dvd1.sub(); dvd1.sub();
	dvd1.sub(); dvd1.sub(); dvd1.sub(); dvd1.sub(); dvd1.sub(); dvd1.sub();
	cout << dvd1.getType() << " " << dvd1.getCurrStock() << "/" << dvd1.getQuantity() << endl;
	dvd1.add();
	cout << dvd1.getType() << " " << dvd1.getCurrStock() << "/" << dvd1.getQuantity() << endl;

	Classic movie1(Person("George", "Cukor"), "Holiday", Person("Katherine", "Hepburn"), Date(9, 1930));
	movie1.addFormat(new DVD(10));

	cout << movie1.getTitle() << endl;
	cout << movie1.getGenre() << endl;
	cout << movie1.getReleaseDate().getYear() << endl;
	cout << movie1.getDirector().getLast() << endl;
	cout << movie1.getActor().getLast() << endl;
	

	Classic *movie2 = new Classic(Person("George", "Cukor"), "Holiday", Person("Cary", "Grant"), Date(9, 1930));
	movie2->addFormat(new DVD(10));
	
	
	cout << "compare: " << (movie1 == *movie2) << endl;

	Movie *movie3 = &movie1;
	Movie *movie4 = movie3->clone();
	cout << movie4->getGenre() << endl;

	cout << endl << "TESTING ACTION ----------------------------------------" << endl << endl;

	Action *a1 = new Borrow;
	Action *a2 = new Return;
	a1->setCustomer(&c1);
	cout << a1->getCustomer()->getFirst() << endl;

	// not done testing action

	cout << endl << "TESTING TREE ------------------------------------------" << endl << endl;

	NodeData *nd1 = new NodeInt(100);
	NodeData *nd2 = new NodeInt(100);
	cout << (*nd1 == *nd2) << endl;
	
	
	Tree tree1;
	cout << "size: " << tree1.getSize() << endl << endl;

	tree1.insert(new NodeMovie(movie2));

	cout << tree1;
	cout << "size: " << tree1.getSize() << endl << endl;

	//tree1.remove(NodeInt(5));
	//cout << tree1;

	cout << "size: " << tree1.getSize() << endl << endl;

	//NodeData *p;
	//tree1.retrieve(NodeInt(16), p);

	
	NodeData *nd3 = new NodeMovie(movie2);
	cout << *nd3 << endl;

	cout << "Classic: " << 'C' - 'A' << endl;
	cout << "Drama: " << 'D' - 'A' << endl;
	cout << "Comedy: " << 'F' - 'A' << endl;

	// deleting all pointers here
	delete movie2, movie3, movie4;
	delete a1, a2;
	delete nd1, nd2, nd3;
	*/

	Manager store;

	ifstream datamovies("data4movies.txt");
	ifstream datacustomers("data4customers.txt");
	ifstream commands("data4commands.txt");

	cout << endl << "BUILDING MOVIE DATABASE ---------------------------------------------------" << endl << endl;
	store.buildMovies(datamovies);

	cout << endl << "BUILDING CUSTOMER DATABASE ---------------------------------------------------" << endl << endl;
	store.buildCustomers(datacustomers);

	cout << endl << "READING COMMANDS ------------------------------------------------------------" << endl << endl;
	store.read(commands);

	cout << endl << "RUNNING COMMANDS -------------------------------------------------------------" << endl << endl;
	store.run();


	return 0;
}