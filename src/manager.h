#pragma once
#include "inventory.h"
#include "hashcustomer.h"
#include "action.h"
#include "factoryaction.h"
#include "factorymovie.h"
#include "dvd.h"
#include <queue>
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// Manager class: Manages the store by reading data files, storing actions in a
//   a queue, then running the actions in order.
//  -- reads data file and creates appropiate action object through a factory
//  -- stores action in queue FIFO
//  -- runs action from queue FIFO
//  -- holds database of all customers
//  -- holds database of all inventory items
//  -- uses factory to create actions, movies

// used to set how many DVDs are given per movie
static const int NUM_OF_DVD = 10;

class Manager
{
public:
	Manager();
	~Manager();

	// build movie database
	void buildMovies(istream &);
	// build customer database
	void buildCustomers(istream &);
	// reads from file to process
	void read(istream &);
	// runs all transaction in task queue
	void run();

	// retrieves customer from database
	// returns NULL if not found
	Customer* getCustomer(const int &);
	// retrieves item from inventory
	// returns NULL if not found
	Item* getItem(const Item *);
	// displays entire inventory
	void displayInven();

private:
	// database of the customer
	HashCustomer _database;
	// database of the inventory
	Inventory _inventory;
	// queue of transactions to do
	queue<Action *> _task;
	// factory to create action
	FactoryAction _factoryAction;
	// factory to create movies
	FactoryMovie _factoryMovie;
};

