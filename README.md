# INF224 - Paradigmes de Programmation
## Júlia Togashi de Miranda - Télécom Paris

###Travaux Pratiques C++/Objet


- Question 1: Makefile and main.cpp copied. Project done on Windows in VisualStudio and tested remotely in The School computer for Linux.

- Question 2: Base Class created paying attention to initialization, Const and way to define the Constructors.

- Question 3: Code tested in Main.

- Question 4: Classes Photo and Video were implemented in the header as suggested.
Answer: When a function it cannot have an implementation at the base class level it's called abstract method = method without implementation.
        It will no longer be possible to instantiate objects of the base class because it will turn into a abstract class.

- Question 5: Code tested in Main.
Answer: OO permits that thanks to polymorphism. In C++ we have upcasting implicite but downcasting interdit. In Java we have dynamic / late binding so it calls the point method, and in C++ it depends.

- Question 6: Class film implemented in .h and .cpp.
Answer: You must copy the content of the array given in parameter. The solution is deep copying (explained in code).

- Question 7: Destructor added for pointers in Films.
Answer: The destruction can be a problem when you copy pointers because if thy are pointing to the same object, you will try to delete it twice.

- Question 8: Group Class created in .h and .cpp.
Answer:  It needs to be a list of pointers because the list will contain objects form multiple classes. That is, at the same time we can have photos, videos and films in the list. (Pointers needed if polymorphism)

- Question 9: Returned to Question 8 to adapted the code to use smart pointers.

- Question 10: Manager Class created in .h and .cpp.
Answer: To prevent that an object is created with new out of the Manager Class, meaning it wouldn't be added to the list, we could make the constructors of photo, video, film, group, protected (for objects of this class (by default) and also for subclasses.)

- Question 11: This part was done in Linux because Version 2 wasn't working. Version 1 code used.

- Question 12: (Optional) -> Not implemented

- Question 13: (Optional) -> Not implemented


###Travaux Pratiques Java/Swing


- Question 1: Active listener 3 chosen (Classes imbriquées).
Answer: The text keeps changing when we keep pressing the buttons. The items displayed are rearranged to better fit the screen when we resize it.

- Question 2: Implemented in the easier way, that it, creating new buttons.

- Question 3: Client Class copied. Code of window changed so that instead of showing a message, pressing the button would either search or play an object/group.

- Question 4: Makefile created

