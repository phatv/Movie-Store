Phat Tran
Zander, Lab 4 readme

1. Everything works. (i hope)

2. - Customer hash table, used to store customers - hashcustomer.cpp
   - Item hash table, used to store items - hashitem.cpp
   - Action factory, used to create actions ex. borrow, return, history, display- factoryaction.cpp
   - Movie factory, used to create movies ex. classic, comedy, drama - factorymovie.cpp
   - Format factory, used to create formats ex. dvd - factoryformat.cpp

3. Manager reads the movie list, creates a movie, then stores it into the inventory class. 

4. Manager reads the command list, creates a command, then stores it into a queue. The queue is later
	ran using the run function. 

5. - When creating movie, it is assumed a DVD.
   - Date class is used (after begging to keep it)
   - Director is stored as a person, with two strings. First string is first name, everything after
	is last name. 
   - FactoryFormat is only one format, DVD. Made to be extensible. 

6. - Date class. 
   - I made many classes to be as true to OOP as I could. 
   - Item has it's own hash function. Allows for O(1) retrieval. Creates hash based on the unique
	sorting criteria for each item, so a movie's full detail isn't required. 
   - Shorting my code by moving frequently used child functions to the parent. 
	Ex. setMovieData in movies is used by all childs, setData and validate in transaction is used
	by borrow and return. 
   - 