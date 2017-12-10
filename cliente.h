#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <vector>
#include "fone.h"
#include "encomenda.h"
using namespace std;

class Cliente
{
    string nome;
    string endereco;
    Fone * telefone;
    float valorDevido = 0;
    float valorPago = 0;
    vector<Encomenda> encomendas;

public:
    Cliente(string nome = "", Fone * telefone = nullptr, string endereco = ""){
        this->nome = nome;
        this->telefone  = telefone;
        this->endereco = endereco;
    }

    void encomendar(Encomenda encomenda){
        valorDevido += encomenda.getPreco();
        encomendas.push_back(encomenda);
    }

    bool assertEcomenda(string descricao){
        for(auto e : encomendas){
        if(e.getProduto().getDescricao() == descricao){
           return true;
        }
        }
        throw string("Cliente não tem essa encomenda");

    }

   string pagar(string descricao, float valor){
        for(Encomenda &e : encomendas){
            if(assertEcomenda(descricao) ==  true){
                if(e.getProduto().getDescricao() == descricao){
                if(valor >= e.getPrecoFinal()){
                 e.setvalorDevido(0);
                 e.setStatus("Paga");
                 valorPago += valor;
                 valorDevido -= valor;
                return "Troco: " + to_string(e.getPrecoFinal());
            }else if(valor < e.getPrecoFinal() ){
                    e.setvalorDevido(e.getPrecoFinal() - valor);
                    e.setStatus("Devendo " + to_string(e.getPrecoFinal()));
                    valorPago += valor;
                    valorDevido -= valor;
                    return "Devendo " + to_string(e.getPrecoFinal());
                }
                }
            }
}
   }
    float getValorPago(){
        return valorPago;
    }

   bool cancelar(string descricao){
        int k = 0;
        for(auto e : encomendas){
            if(e.getProduto().getDescricao() == descricao){
                encomendas.erase(encomendas.begin()+ k);
                valorDevido -= e.getPrecoFinal();
                valorPago -= e.getPreco();
                if(valorPago < 0)
                    valorPago = 0;
                return true;
            }

         k++;
    }
        return false;
    }




    vector<Encomenda> getEncomenda(){
        return encomendas;
    }

    string getNome(){
        return nome;
    }

    string toString(){
             stringstream ss;
        ss << "Nome: " << nome << " Telefone: " << telefone->getFoneid() << telefone->getNumero() << " Endereco: " << endereco << " Valor Total :" << valorDevido << endl;
        ss << "Encomendas" << endl;
        for(auto e : encomendas)
              ss << "Data: " << e.getData().toString() << endl
                << "Hora: " << e.getHora()  << endl
                << "Produto: " << e.getProduto().getDescricao() << endl
                << "Descrição: " << e.getDescricao() << endl
                << "Preco: " << e.getPreco() << endl
                << "Quantidade: " << to_string(e.getQtd()) << endl
                << "Status: " << e.getStatus() << endl
                << "---------------------------------------" << endl;
            return ss.str();
    }
};

#endif // CLIENTE_H
