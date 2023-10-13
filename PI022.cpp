#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Tarefa
{
public:
    Tarefa(const std::string &descricao, bool concluida = false)
        : descricao(descricao), concluida(concluida) {}

    const std::string &getDescricao() const
    {
        return descricao;
    }

    bool estaConcluida() const
    {
        return concluida;
    }

    void marcarComoConcluida()
    {
        concluida = true;
    }

private:
    std::string descricao;
    bool concluida;
};

class GerenciadorTarefas
{
public:
    void adicionarTarefa(const std::string &descricao)
    {
        Tarefa tarefa(descricao);
        tarefas.push_back(tarefa);
    }

    void marcarTarefaComoConcluida(std::vector<Tarefa>::size_type indice)
    {
        if (indice < tarefas.size())
        {
            tarefas[indice].marcarComoConcluida();
        }
        else
        {
            std::cout << "Índice inválido." << std::endl;
        }
    }

    void listarTarefasPendentes() const
    {
        for (std::vector<Tarefa>::size_type i = 0; i < tarefas.size(); ++i)
        {
            if (!tarefas[i].estaConcluida())
            {
                std::cout << "[" << i << "] " << tarefas[i].getDescricao() << std::endl;
            }
        }
    }

    void salvarTarefas(const std::string &nomeArquivo) const
    {
        std::ofstream arquivo(nomeArquivo);
        if (arquivo.is_open())
        {
            for (const Tarefa &tarefa : tarefas)
            {
                arquivo << tarefa.getDescricao() << "," << tarefa.estaConcluida() << std::endl;
            }
            arquivo.close();
        }
    }

    void carregarTarefas(const std::string &nomeArquivo)
    {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open())
        {
            tarefas.clear();
            std::string linha;
            while (std::getline(arquivo, linha))
            {
                size_t pos = linha.find(",");
                if (pos != std::string::npos && pos + 1 < linha.length())
                {
                    std::string descricao = linha.substr(0, pos);
                    bool concluida = (linha[pos + 1] == '1');
                    Tarefa tarefa(descricao, concluida);
                    tarefas.push_back(tarefa);
                }
            }
            arquivo.close();
        }
    }

private:
    std::vector<Tarefa> tarefas;
};

int main()
{
    GerenciadorTarefas gerenciador;

    
    gerenciador.carregarTarefas("tarefas.txt");

    int opcao;
    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Adicionar tarefa" << std::endl;
        std::cout << "2. Marcar tarefa como concluída" << std::endl;
        std::cout << "3. Listar tarefas pendentes" << std::endl;
        std::cout << "4. Salvar tarefas" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            std::string descricao;
            std::cout << "Digite a descrição da tarefa: ";
            std::cin.ignore();
            std::getline(std::cin, descricao);
            gerenciador.adicionarTarefa(descricao);
        }
        break;
        case 2:
        {
            std::vector<Tarefa>::size_type indice;
            std::cout << "Digite o índice da tarefa para marcar como concluída: ";
            std::cin >> indice;
            gerenciador.marcarTarefaComoConcluida(indice);
        }
        break;
        case 3:
            std::cout << "Tarefas pendentes:" << std::endl;
            gerenciador.listarTarefasPendentes();
            break;
        case 4:
            gerenciador.salvarTarefas("tarefas.txt");
            std::cout << "Tarefas salvas no arquivo 'tarefas.txt'." << std::endl;
            break;
        case 5:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != 5);

    return 0;
}
