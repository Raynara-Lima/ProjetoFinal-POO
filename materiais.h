#ifndef MATERIAIS_H
#define MATERIAIS_H
#include <iostream>
#include <sstream>
using namespace std;

class Material
{
    string id;
    int qtd;
    float valorDevido;
    float preco;
    string status = "Não pago";
public:
    Material(string descricao = "", int qtd = 0, float preco = 0.0f){
        this->id = descricao;
        this->preco = preco;
        this->qtd = qtd;
        this->valorDevido = preco;
    }

    float getPreco(){
        return preco;
    }

    float getValorDevido(){
        return valorDevido;
    }

    string getId(){
       return id;
    }

    void setvalorDevido(float valor){
        valorDevido = valor;
    }

    void setStatus(string status){
        this->status = status;
    }

    string getStatus(){
        return this->status;
    }

    string toString(){
        stringstream ss;
        ss <<"Descrição: " << id
           <<" Quantidade: " << to_string(qtd)
           << " Preço: " << to_string(preco)
           <<" Status: " <<  getStatus() << endl;
        return ss.str();
    }
};

#endif // MATERIAIS_H
