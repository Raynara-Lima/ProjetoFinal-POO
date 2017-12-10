#ifndef SISTEMA_H
#define SISTEMA_H
#include <sstream>
#include "cliente.h"
#include "materiais.h"
#include "repository.h"
class Sistema
{
    float lucro = 0;
    float despesas;
    float ganho = 0;
    vector<Encomenda> agenda;
    Repository<Cliente> *r_cli;
    Repository<Material> *r_mat;
public:
    Sistema( Repository<Cliente> *r_cli, Repository<Material> *r_mat){
        this->r_cli = r_cli;
        this->r_mat = r_mat;
    }

    vector<Encomenda> getAgenda(){
        for(auto cli: r_cli->values()){
            for(Encomenda e: cli.getEncomenda()){
                agenda.push_back(e);
            }
        }
        return agenda;
    }

    string toStringAgenda(){
        stringstream ss;
        for(auto a : getAgenda())
            ss << a.toString()  << endl;
        return ss.str();

    }

       float getGanho(){
           for(auto cli: r_cli->values()){
               ganho += cli.getValorPago();

           }
           return ganho;
       }



       float getLucro(){
           lucro = getGanho() - getDespesas();
           return lucro;
       }

       string toStringCli(){
        string ss;
        for(auto cli : r_cli->values()){
           ss += cli.toString() + "\n";
        }
        return ss;
    }

    string toStringMat(){
        string ss;
        for(auto &mat : r_mat->values()){
            ss += mat.toString();
        }
        return ss;
    }

    string pagarMaterial(string id, float valor){
        auto m = r_mat->get(id);

            if(m->getValorDevido() == 0)
                return "Já está paga";

            if(m->getValorDevido() > valor){
                    m->setvalorDevido((m->getValorDevido() - valor));
                    m->setStatus("Devendo " + to_string(m->getPreco() - valor));
                     despesas += valor;
                    return m->getStatus();

                }else if(m->getValorDevido() <= valor ){
                    m->setvalorDevido(0);
                    m->setStatus("Paga");
                    despesas += valor;
                    return m->getStatus();
                }


        }

    float getDespesas(){
         return despesas;
    }
    vector <Encomenda> searchDia(string dia){
        vector<Encomenda> agenda;
        for(auto e: getAgenda()){
            if(e.getData().getDia() == dia){
                agenda.push_back(e);
            }
        }
        return agenda;
    }
    vector <Encomenda> searchMes(string mes){
        vector<Encomenda> agenda;
        for(auto e: getAgenda()){
            if(e.getData().getMes() == mes){
                agenda.push_back(e);
            }
        }
        return agenda;
    }
    vector <Encomenda> searchAno(string ano){
        vector<Encomenda> agenda;
        for(auto e: getAgenda()){
            if(e.getData().getAno() == ano){
                agenda.push_back(e);
            }
        }
        return agenda;
    }

    string toStringserach(vector<Encomenda> e){
        stringstream ss;
        for(Encomenda a : e){
            ss << a.toString() << endl;
        }
        return ss.str();
    }
};

#endif // SISTEMA_H
