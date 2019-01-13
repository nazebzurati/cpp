#include <iostream>
#include <cstring>
using namespace std;

struct Document {};

struct InterfacePrint {
    virtual void print(Document& doc) = 0; // pure abstraction: where it'll not require derived class to have the function
};

struct InterfaceFax {
    virtual void fax(Document& doc) = 0;
};

struct Printer: InterfacePrint {
    void print(Document& doc) override { /* NOP */ };
};

struct MFP: InterfaceFax, InterfacePrint {
    void print(Document& doc) override { /* NOP */ };
    void fax(Document& doc) override { /* NOP */ };
};

int main() {
    
    Document doc;

    // print only
    Printer printer;
    printer.print(doc);

    // multi function printer (print and fax)
    MFP mfp;
    mfp.print(doc);
    mfp.fax(doc);

    return 0;
}

// Interface segregation is to prevent creating too large interface
// --------------------------------------------------------------------------------------------------------
// Interface segregation help programmer to prevent an interface to have too much unused methods. For example
// for this case, it's possible to create a printer class with print and fax interface. If the printer class
// is to be inherit by a derived class (let say Printer) and the derived class only want to use the print method
// only. Thus, this will create an unused fax method that the derived class required to inherit from the base
// class. Interface segregation extract this method into seperate interface. Then, the printer class can inherit
// this extracted interface and make the code better and more efficient. It follows YAGNI (You ain't gonna to 
// need it) as all interface only be inherited when we want to use.
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g SOLID/interface_segregation.cpp -o exec.out