#ifndef FONE
#define FONE
#include <iostream>
using namespace std;
class Fone
{
    string foneid;
    string numero;
public:
    Fone(string foneid = "", string numero = ""){
        this->foneid = foneid;
        this->numero = numero;
    }

    bool validate(){
        string data = "1234567890()- ";
            for(auto c : numero)
                if(data.find(c) == string::npos)
                    return false;
            return true;
    }

    string getFoneid(){
        return foneid;
    }

    string getNumero(){
        return numero;
    }
};
#endif // FONE

