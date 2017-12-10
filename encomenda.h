#ifndef ENCOMENDA
#define ENCOMENDA
#include "data.h"
#include "produto.h"
class Encomenda{
    string hora;
    Data* data;
    Produto *produto;
    string cliente;
    int qtd;
    float valorDevido = 0;
    float precoFinal;
    string descricao;
    string status = "Não paga";
public:


    Encomenda(Data *data = nullptr, string hora = "", Produto* produto = nullptr, string descricao = "", string cliente = "", int qtd = 0){
        this->hora = hora;
        this->data = data;
        this->qtd = qtd;
        this->produto = produto;
        this->cliente = cliente;
        this->descricao = descricao;
    }

    void setvalorDevido(float preco){
        valorDevido = preco;
    }

    void setStatus(string status){
        this->status = status;
    }
    string getStatus(){
        return status;
    }

    float getPreco(){

        precoFinal = produto->getPreco() * qtd;
        valorDevido = precoFinal;
        return precoFinal;
    }

    float getPrecoFinal(){
        return valorDevido;
    }

    Produto getProduto(){
       return *produto;
    }

    Data getData(){
        return *data;
    }

    string getHora(){
        return hora;
    }

    string getDescricao(){
        return descricao;
    }

    int getQtd(){
        return qtd;
    }

    string toString(){
        stringstream ss;
        ss << "Cliente: " << cliente << endl
            << "Data: " << data->toString() << endl
            << "Hora: " << hora  << endl
            << "Produto: " << produto->getDescricao() << endl
            << "Descrição: " << descricao << endl
            << "Preco: " << getPreco() << endl
            << "Quantidade: " << to_string(qtd) << endl
            << "Status: " << getStatus() << endl
            << "---------------------------------------" << endl;
        return ss.str();
    }

};


#endif // ENCOMENDA

