#include <iostream>
using namespace std;

// Base class SWE
class SWE {
public:
    // Function to display message for SWE
    void display() {
        cout << "I am a software student" << endl;
    }
};

// Base class NWS
class NWS {
public:
    // Function to display message for NWS
    void display() {
        cout << "I am a network and security student" << endl;
    }
};

// Base class CSN
class CSN {
public:
    // Function to display message for CSN
    void display() {
        cout << "I am a computer network and security student" << endl;
    }
};

// Derived class ICT inheriting from SWE, NWS, and CSN
class ICT : public SWE, public NWS, public CSN {
public:
    // Function to display message for ICT
    void displayICT() {
        cout << "I belong to all categories: SWE, NWS, and CSN" << endl;
    }
};

int main() {
    // Creating objects for each class
    SWE sweObj;
    NWS nwsObj;
    CSN csnObj;
    ICT ictObj;

    // Calling function of SWE by the object of SWE
    sweObj.display();
    
    // Calling function of NWS by the object of NWS
    nwsObj.display();
    
    // Calling function of CSN by the object of CSN
    csnObj.display();
    
    // Calling function of ICT by the object of ICT
    ictObj.displayICT();
    
    // Calling the function of each of its parent by the object of ICT
    ictObj.SWE::display();
    ictObj.NWS::display();
    ictObj.CSN::display();

    return 0;
}

/*
Comment on the type of inheritance:
The inheritance used here is multiple inheritance because the ICT class inherits from three base classes: SWE, NWS, and CSN.

Resolving ambiguity:
In the main method, when calling the display() function for the ICT object, it is necessary to specify which parent class's display() function to call using the scope resolution operator (::). This resolves the ambiguity arising from the multiple inheritance, as all parent classes have a function named display().
*/
