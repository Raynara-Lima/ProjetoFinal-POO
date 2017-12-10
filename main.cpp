#include <iostream>
#include "controller.h"
#include "sistema.h"

using namespace std;
using namespace poo;



class DeliciasDaBranca: public Controller{
    Repository<Cliente> r_cli;
    Repository<Material> r_mat;
    Repository<Produto> r_pro;

public:
    DeliciasDaBranca():
    r_cli("Cliente"), r_mat("Material")
    {
    }

    string process(string line){
        //Sistema s;
        auto ui = poo::split(line);
        auto cmd = ui[0];
        Sistema sistema = Sistema(&r_cli, &r_mat);
        if(cmd == "help"){
            stringstream ss;
            ss << "addCli _nome _idTel _numTel _endereco" << endl
               << "addMat _descricao _preco _qtd" << endl
               << "addPro _descricao _preco" << endl
               << "rmPro _descricao" << endl
               << "encomendar _dia _mes _ano _hora _descricao _qtd //encomendar bolos e salgados" << endl
              // << "encomendarOutros _dia _mes _ano _hora _descricao _preco _qtd  //encomendar outras coisas que não sejam bolos e salgados" << endl
               << "cancelarEncomenda _nomeCliente _descricao" << endl
               << "pagarEncomenda _nomeCliente _descricao" << endl
               << "clientes" <<endl
               << "verCliente _nomeCliente" << endl
               << "agenda" << endl
               << "materiais" << endl
               << "verMat" << endl
               << "produtos" << endl
               << "verPro _descricao" << endl
               << "pagarMat _nomeMaterial _descricao" << endl
               << "agendaDia _dia" << endl
               << "agendaMes _mes" << endl

               << "agendaAno _ano" << endl
               << "lucro" << endl
               << "despesas" << endl
               << "ganho" << endl
               << "fim" << endl;

        return ss.str();
        }
        else if(cmd == "addCli"){//_user
            Fone *telefone = new Fone(ui[2], ui[3]);
            if(telefone->validate()){
                r_cli.add(ui[1], Cliente(ui[1], telefone, poo::join(slice(ui, 4), " ")));
                return "Cliente adicionado";
            }else
                return "Telefone inválido";
        }
        else if(cmd == "addMat"){
            r_mat.add(ui[1], Material(ui[1], poo::Int(ui[2]), poo::Float(ui[3])));
            return "Material adicionado";;
        }else if(cmd == "addPro"){
            r_pro.add(ui[1], Produto(ui[1], Float(ui[2])));
            return "Adicionado";
        }
        else if(cmd == "encomendar"){
            Data *data = new Data(ui[2], ui[3], ui[4]);
            if(data->validar()){
                Produto *produto =  r_pro.get(ui[6]);
                r_cli.get(ui[1])->encomendar(Encomenda(data, ui[5], produto, ui[7], ui[1], Int(ui[8])));
                return "Encomenda realizada";
            }else
                return "Data inválida";
        }/*else if(cmd == "encomendarOutros"){
            Data *data = new Data(ui[2], ui[3], ui[4]);
            if(data->validar()){
                Produto *produto =  new Produto(ui[6], Float(ui[7]));
                r_cli.get(ui[1])->encomendar(Encomenda(data ,ui[5], produto, ui[8], ui[1], Int(ui[9])));
                return "Encomenda realizada";
            }else
                return "Data inváida";
        }*/
        else if(cmd == "cancelarEncomenda"){

             if(r_cli.get(ui[1])->cancelar(ui[2]))
                 return "Encomenda cancelada";
             else
                 return "Cliente" + ui[1] + "não tem essa encomenda";
        }else if(cmd == "clientes"){
            return sistema.toStringCli();
        }else if(cmd == "materiais"){
            return sistema.toStringMat();
        }else if(cmd == "verMat"){
            return r_mat.get(ui[1])->toString();
        }
        else if(cmd == "verCliente"){
            return r_cli.get(ui[1])->toString();
        }
         else if(cmd == "agendaDia"){
            return sistema.toStringserach( sistema.searchDia(ui[1]));
        }
        else if(cmd == "agendaMes"){
           return sistema.toStringserach( sistema.searchMes(ui[1]));
       }
        else if(cmd == "agendaAno"){
           return sistema.toStringserach( sistema.searchAno(ui[1]));
       }
        else if(cmd == "produtos"){
            stringstream ss;
            for(auto p : r_pro.values())
                ss << p.toString();
            return ss.str();
        }else if(cmd == "rmPro"){
            r_pro.rm(ui[1]);
            return "Removido";
        }else if(cmd == "verPro"){
           return r_pro.get(ui[1])->toString();
        }
        else if(cmd == "agenda"){
            return sistema.toStringAgenda();
        }else if(cmd == "pagarEncomenda"){
            r_cli.get(ui[1])->assertEcomenda(ui[2]);
            return r_cli.get(ui[1])->pagar(ui[2], poo::Float(ui[3]));
        }else if(cmd == "pagarMat"){
            return sistema.pagarMaterial(ui[1], Float(ui[2]));
        }else if(cmd == "lucro"){
            return to_string(sistema.getLucro());
        }else if(cmd == "despesas"){
            return to_string(sistema.getDespesas());
        }else if(cmd == "ganho"){
            return to_string(sistema.getGanho());
        }
        else if(cmd == "fim")
            return "";
        else
            return string("") + "comando invalido " + "[" + cmd + "]";
        return "done";

    }

};

int main()
{
    DeliciasDaBranca d;
    d.commandLine();
    return 0;
}

