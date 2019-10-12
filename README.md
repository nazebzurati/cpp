# README.md

You can compile the source code individually by executing below command.

```bash
g++ -std=c++11 -g <source-file> -o exec.out
```

or 

```bash 
make <option>
option:
- all
- clean
- algorithm-scheduling-elevator
- algorithm-sort-bubble
- algorithm-sort-insertion
- algorithm-thread-queue
- data-structure-linked-list
- data-structure-queue
- data-structure-stack
- design-pattern-factory
- design-pattern-monostate
- design-pattern-observer
- design-pattern-singleton
- design-pattern-solid
- design-pattern-state
- design-pattern-strategy
```

## Design Pattern

- Strategy: Strategy design pattern focused on a system behaviour partially specified at runtime. Algorithms can be decomposed into higher and lower level parts. It enables the exact behaviour of a system to be selected either at run-time (dynamic) or compile time (static).
- State: A state pattern is a pattern in which the objects's behaviour is determined by its state. An object transition from one state to another (something needs to trigger a transition). A formalized construct which manages state and transitions is called a state machine. Classic state pattern is a classic state pattern implementation that uses pointer and transition function while handmade state pattern uses map and rules.
- SOLID: SOLID is an abbreviation for:-
  - **S**ingle responsibility: Which a class should have single responsibility.
  - **O**pen-close principle: A principle where it opens for extension while its close for modification.
  - **L**iskov principle: A principle where subtype should to be immediately substitutable for their base type.
  - **I**nterface segregation: To prevent creating too large interface.
  - **D**ependency segragation: A principle where high level modules should not depend on low-level modules and abstraction should not depend on details.
- Singleton: A pattern where an object is required to be instantiated once and only once but accessible application-wide global. Other thing about singleton is a singleton is self construct, it cannot be created or copied by reference.
- Monostate: An alternative of singleton. It is basically having the same static object being shared to all instances of constructed object.
- Observer: To get notified by events when any change happens. An observer is an object that wishes to be informed about events happening in the system. The entity generating the events is an 'observable'. Some problems in this approach are dependencies problem and reentrancy (threads safety).
- Factory: A method to deal with the problem of creating objects without having to specify the exact class of the object that will be created. Abstract Factory is quite similar to Functional Factory, but Abstract Factory does require an interface.

## Algorithm

- Thread Queue: A queue of a singleton (only one instance and globally available) with one running thread. In this example shows that if you are implementing multithread, cout will have this interleaving state / race condition on who can display on the console at one point of time. The reason why use thread queue is basically to have one thread to sequentially display out the "cout" stored in a queue. This method would prevent interleaving state / race condition from happening and improve your application performance (using other threads instead the main thread to do this operation: also suitable for filestream writing and reading) although this problem may solve just by using printf or a mutex lock guard.
- Sort:
  - Bubble: Swapping the adjacent elements.
  - Insertion: Shift elements one by one.
- Scheduling:
  - Elevator: Schedule job based on current position, current direction and the job destination.

## Data Structure

- Linked List: A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. A linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list. The number of nodes in a list is not fixed and can grow and shrink on demand.
- Queue: First-In-First-Out (FIFO) linear abstract data structure.
- Stack: Last-In-First-Out (LIFO) linear abstract data structre.
