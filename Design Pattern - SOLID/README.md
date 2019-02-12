## [S] Single responsibility is a class should have single responsibilty.

In this use case, we are not recommended to have save the journal functionality inside the journal because journal class only have the resposibility to save and keep the journal added into it. Because of it, you might have the complication if there is changes in the class. The save and load function would not be relevent and you required to update all the class that have this same save and load function in it. 'Seperation of concern' is used to seperate this common operation from the class and maintain its persistence. Persistence is the continueance of an subject after a class not remain relevent.

## [O] Open Close Principle is a principle where it open for extension while its close for modifiction

## [L] Liskov Principle is a principle where subtype should to be immediately subtitutable for their base type.

In the other hand, Liskov says that the code should work without knowing the actual class. The tutorial actually use rectangle-square problem (circle-eclipse problem) and it's hard to be understand as it only show the problem and not the solution. This approach is to reduce the posibilites that you need to refactor everthing in order to make up a slight changes in code or creating new element (in current case other bird type and you have to add the if statement for each available derived-bird class).

## [I] Interface segregation is to prevent creating too large interface

Interface segregation help programmer to prevent an interface to have too much unused methods. For example for this case, it's possible to create a printer class with print and fax interface. If the printer class is to be inherit by a derived class (let say Printer) and the derived class only want to use the print method only. Thus, this will create an unused fax method that the derived class required to inherit from the base class. Interface segregation extract this method into seperate interface. Then, the printer class can inherit this extracted interface and make the code better and more efficient. It follows YAGNI (You ain't gonna to need it) as all interface only be inherited when we want to use.

## [D] Dependency inversion

Split into 2 ideas:
- high level modules should not depend on low-level modules.
- abstraction should not depend on details.

Abstraction is interface or base class that is generic as possible. If there is changes in low-level module, it would broke the high-level module. In this case, it is not a good implementation if research  interface directly use data from relationship interface. As for that, we can use a dependecy injector (official term used) or we also can call it as mediator (term based my very own opinion). Mediator  injector allow to specify certain default. As an example, the user is require to specify a copy of relationship to use a high level module.