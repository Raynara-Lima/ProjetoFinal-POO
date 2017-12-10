#ifndef PRODUTO_H
#define PRODUTO_H
#include <iostream>
#include <map>
#include "poo_aux.h"
using namespace std;

class Produto
{
    string descricao;
    float preco;
    //int qtd;
public:
    Produto(string descricao = "", float preco = 0){
        this->descricao = descricao;
        this->preco = preco;

    }

    float getPreco(){
        return preco;
    }

    string getDescricao(){
        return descricao;
    }

    string toString(){
        stringstream ss;
        ss << "Descrição: " << descricao << " Preco: " << to_string(preco) << endl;
        return ss.str();
    }
};


#endif // PRODUTO_H
