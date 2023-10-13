#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Evento
{
public:
    Evento(const string &nome, double preco) : nome(nome), preco(preco) {}

    string getNome() const
    {
        return nome;
    }

    double getPreco() const
    {
        return preco;
    }

private:
    string nome;
    double preco;
};

class Roteiro
{
public:
    Roteiro(const string &descricao) : descricao(descricao) {}

    string getDescricao() const
    {
        return descricao;
    }

private:
    string descricao;
};

class Deslocamento
{
public:
    Deslocamento(const string &meioTransporte, double custo) : meioTransporte(meioTransporte), custo(custo) {}

    string getMeioTransporte() const
    {
        return meioTransporte;
    }

    double getCusto() const
    {
        return custo;
    }

private:
    string meioTransporte;
    double custo;
};

class Pernoite
{
public:
    Pernoite(const string &cidade, double custo) : cidade(cidade), custo(custo) {}

    string getCidade() const
    {
        return cidade;
    }

    double getCusto() const
    {
        return custo;
    }

private:
    string cidade;
    double custo;
};

class Pacote
{
public:
    Pacote(const string &nome) : nome(nome) {}

    void adicionarEvento(const Evento &evento)
    {
        eventos.push_back(evento);
    }

    void adicionarRoteiro(const Roteiro &roteiro)
    {
        roteiros.push_back(roteiro);
    }

    void adicionarDeslocamento(const Deslocamento &deslocamento)
    {
        deslocamentos.push_back(deslocamento);
    }

    void adicionarPernoite(const Pernoite &pernoite)
    {
        pernoites.push_back(pernoite);
    }

    const vector<Evento> &getEventos() const
    {
        return eventos;
    }

    const vector<Roteiro> &getRoteiros() const
    {
        return roteiros;
    }

    const vector<Deslocamento> &getDeslocamentos() const
    {
        return deslocamentos;
    }

    const vector<Pernoite> &getPernoites() const
    {
        return pernoites;
    }

    string getNome() const
    {
        return nome;
    }

private:
    string nome;
    vector<Evento> eventos;
    vector<Roteiro> roteiros;
    vector<Deslocamento> deslocamentos;
    vector<Pernoite> pernoites;
};

class Cliente
{
public:
    Cliente(const string &nome) : nome(nome) {}

    void adicionarDependente(const string &dependente)
    {
        dependentes.push_back(dependente);
    }

    const vector<std::string> &getDependentes() const
    {
        return dependentes;
    }

    string getNome() const
    {
        return nome;
    }

private:
    string nome;
    vector<std::string> dependentes;
};

class GerenciadorPacotes
{
public:
    void criarPacote(const string &nome)
    {
        pacotes.push_back(Pacote(nome));
    }

    void adicionarEventoAoPacote(size_t indicePacote, const Evento &evento)
    {
        if (indicePacote < pacotes.size())
        {
            pacotes[indicePacote].adicionarEvento(evento);
        }
    }

    void adicionarRoteiroAoPacote(size_t indicePacote, const Roteiro &roteiro)
    {
        if (indicePacote < pacotes.size())
        {
            pacotes[indicePacote].adicionarRoteiro(roteiro);
        }
    }

    void adicionarDeslocamentoAoPacote(size_t indicePacote, const Deslocamento &deslocamento)
    {
        if (indicePacote < pacotes.size())
        {
            pacotes[indicePacote].adicionarDeslocamento(deslocamento);
        }
    }

    void adicionarPernoiteAoPacote(size_t indicePacote, const Pernoite &pernoite)
    {
        if (indicePacote < pacotes.size())
        {
            pacotes[indicePacote].adicionarPernoite(pernoite);
        }
    }

    void criarCliente(const std::string &nome)
    {
        clientes.push_back(Cliente(nome));
    }

    void adicionarDependenteAoCliente(size_t indiceCliente, const std::string &dependente)
    {
        if (indiceCliente < clientes.size())
        {
            clientes[indiceCliente].adicionarDependente(dependente);
        }
    }

    void venderPacoteParaCliente(size_t indicePacote, size_t indiceCliente)
    {
        if (indicePacote < pacotes.size() && indiceCliente < clientes.size())
        {
        }
    }

    void listarClientes()
    {
        cout << "Clientes:\n";
        for (const Cliente &cliente : clientes)
        {
            cout << "Nome: " << cliente.getNome() << endl;
            cout << "Dependentes: ";
            for (const string &dependente : cliente.getDependentes())
            {
                cout << dependente << ", ";
            }
            cout << std::endl;
        }
    }

    void listarPacotes()
    {
        cout << "Pacotes:\n";
        for (const Pacote &pacote : pacotes)
        {
            cout << "Nome do Pacote: " << pacote.getNome() << endl;
            cout << "Eventos no Pacote: ";
            for (const Evento &evento : pacote.getEventos())
            {
                cout << evento.getNome() << ", ";
            }
            cout << endl;

            cout << "Roteiros no Pacote: ";
            for (const Roteiro &roteiro : pacote.getRoteiros())
            {
                cout << roteiro.getDescricao() << ", ";
            }
            cout << endl;

            cout << "Deslocamentos no Pacote: ";
            for (const Deslocamento &deslocamento : pacote.getDeslocamentos())
            {

                cout << deslocamento.getMeioTransporte() << ", ";
            }
            cout << endl;

            cout << "Pernoites no Pacote: ";
            for (const Pernoite &pernoite : pacote.getPernoites())
            {
                cout << pernoite.getCidade() << ", ";
            }
            cout << endl;
        }
    }

private:
    vector<Pacote> pacotes;
    vector<Cliente> clientes;
};

int main()
{
    GerenciadorPacotes gerenciador;

    Evento evento1("Evento A", 100.0);
    Evento evento2("Evento B", 75.0);

    Roteiro roteiro1("Roteiro 1");
    Roteiro roteiro2("Roteiro 2");

    Deslocamento deslocamento1("Avião", 200.0);
    Deslocamento deslocamento2("Trem", 50.0);

    Pernoite pernoite1("Cidade A", 80.0);
    Pernoite pernoite2("Cidade B", 90.0);
    gerenciador.criarPacote("Pacote 1");
    gerenciador.adicionarEventoAoPacote(0, evento1);
    gerenciador.adicionarRoteiroAoPacote(0, roteiro1);
    gerenciador.adicionarDeslocamentoAoPacote(0, deslocamento1);
    gerenciador.adicionarPernoiteAoPacote(0, pernoite1);

    gerenciador.criarPacote("Pacote 2");
    gerenciador.adicionarEventoAoPacote(1, evento1);
    gerenciador.adicionarEventoAoPacote(1, evento2);
    gerenciador.adicionarRoteiroAoPacote(1, roteiro2);
    gerenciador.adicionarDeslocamentoAoPacote(1, deslocamento2);
    gerenciador.adicionarPernoiteAoPacote(1, pernoite2);
    gerenciador.criarCliente("Cliente 1");
    gerenciador.adicionarDependenteAoCliente(0, "Dependente 1");
    gerenciador.adicionarDependenteAoCliente(0, "Dependente 2");

    gerenciador.criarCliente("Cliente 2");
    gerenciador.adicionarDependenteAoCliente(1, "Dependente 3");

    gerenciador.listarClientes();
    gerenciador.listarPacotes();

    return 0;
}