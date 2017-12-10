#ifndef DATA
#define DATA
#include <iostream>
using namespace std;
class Data{
    string dia;
    string mes;
    string ano;
public:
    Data(string dia = "", string mes = "", string ano = ""){
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    bool validar(){
        if(dia > "30")
            return false;
        if(mes > "12")
            return false;
        return true;
    }
    string toString(){
        string ss;
        ss = dia + "/" + mes + "/" + ano;
        return ss;
    }

    string getDia(){
        return dia;
    }

    string getMes(){
        return mes;
    }

    string getAno(){
        return ano;
    }
};

#endif // DATA

