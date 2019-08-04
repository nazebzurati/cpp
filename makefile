# Compiler
GPP		= g++

# Compiler flags
CFLAGS 	= -std=c++11
CFLAGS 	= -pthread

# Projects
PRJ		:= algorithm-scheduling-elevator
PRJ		+= algorithm-sort-bubble
PRJ		+= algorithm-sort-insertion
PRJ		+= algorithm-thread-queue
PRJ		+= data-structure-linked-list
PRJ 	+= data-structure-queue
PRJ		+= data-structure-stack
PRJ		+= design-pattern-factory
PRJ		+= design-pattern-monostate
PRJ		+= design-pattern-observer
PRJ 	+= design-pattern-singleton
PRJ		+= design-pattern-solid
PRJ		+= design-pattern-state
PRJ		+= design-pattern-strategy

# Compile
algorithm-scheduling-elevator:
	$(GPP) $(CFLAGS) "./Algorithm - Scheduling - Elevator/elevator.cpp" -o $@.out
	
algorithm-sort-bubble:
	$(GPP) $(CFLAGS) "./Algorithm - Sort - Bubble/bubble.cpp" -o $@.out
	
algorithm-sort-insertion:
	$(GPP) $(CFLAGS) "./Algorithm - Sort - Insertion/insertion.cpp" -o $@.out
	
algorithm-thread-queue:
	$(GPP) $(CFLAGS) "./Algorithm - Thread Queue/thread-queue.cpp" -o $@.out
	
data-structure-linked-list:
	$(GPP) $(CFLAGS) "./Data Structure - Linked List/linked-list-single.cpp" -o $@.out

data-structure-queue:
	$(GPP) $(CFLAGS) "./Data Structure - Queue/queue.cpp" -o $@.out

data-structure-stack:
	$(GPP) $(CFLAGS) "./Data Structure - Stack/stack.cpp" -o $@.out

design-pattern-factory:
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-abstract.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-direct-simple.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-direct.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-functional.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-inner.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Factory/factory-method.cpp" -o $@.out

design-pattern-monostate:
	$(GPP) $(CFLAGS) "./Design Pattern - Monostate/monostate.cpp" -o $@.out

design-pattern-observer:
	$(GPP) $(CFLAGS) "./Design Pattern - Observer/observer.cpp" -o $@.out

design-pattern-singleton:
	$(GPP) $(CFLAGS) "./Design Pattern - Singleton/singleton.cpp" -o $@.out

design-pattern-solid:
	$(GPP) $(CFLAGS) "./Design Pattern - SOLID/single-responsibility.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - SOLID/open-close.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - SOLID/liskov-substitution.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - SOLID/interface-segregation.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - SOLID/dependency-inversion.cpp" -o $@.out

design-pattern-state:
	$(GPP) $(CFLAGS) "./Design Pattern - State/classic.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - State/handmade.cpp" -o $@.out

design-pattern-strategy:
	$(GPP) $(CFLAGS) "./Design Pattern - Strategy/dynamic-strategy.cpp" -o $@.out
	$(GPP) $(CFLAGS) "./Design Pattern - Strategy/static-strategy.cpp" -o $@.out

# Common compile
all: $(PRJ)
	@echo "Finished!"

clean:
	@rm -rf *.out