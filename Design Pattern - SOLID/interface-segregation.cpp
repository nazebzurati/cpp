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