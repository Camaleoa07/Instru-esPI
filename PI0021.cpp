#include <iostream>
#include <string>
#include <vector>

class Livro
{
public:
    Livro(const std::string &titulo, const std::string &autor, int numCopias)
        : titulo(titulo), autor(autor), numCopiasDisponiveis(numCopias) {}

    const std::string &getTitulo() const { return titulo; }
    const std::string &getAutor() const { return autor; }
    int getNumCopiasDisponiveis() const { return numCopiasDisponiveis; }

    bool emprestarLivro()
    {
        if (numCopiasDisponiveis > 0)
        {
            numCopiasDisponiveis--;
            return true;
        }
        return false;
    }

    void devolverLivro()
    {
        numCopiasDisponiveis++;
    }

private:
    std::string titulo;
    std::string autor;
    int numCopiasDisponiveis;
};

class Usuario
{
public:
    Usuario(const std::string &nome) : nome(nome) {}

    const std::string &getNome() const { return nome; }

    void emprestarLivro(Livro &livro)
    {
        if (livro.emprestarLivro())
        {
            livrosEmprestados.push_back(&livro);
        }
    }

    void listarLivrosEmprestados() const
    {
        if (livrosEmprestados.empty())
        {
            std::cout << nome << " não tem livros emprestados." << std::endl;
        }
        else
        {
            std::cout << nome << " tem os seguintes livros emprestados:" << std::endl;
            for (const Livro *livro : livrosEmprestados)
            {
                std::cout << "Título: " << livro->getTitulo() << ", Autor: " << livro->getAutor() << std::endl;
            }
        }
    }

private:
    std::string nome;
    std::vector<Livro *> livrosEmprestados;
};

class Biblioteca
{
public:
    static void adicionarLivro(Livro &livro)
    {
        livros.push_back(&livro);
    }

    static Livro *buscarLivro(const std::string &titulo)
    {
        for (Livro *livro : livros)
        {
            if (livro->getTitulo() == titulo)
            {
                return livro;
            }
        }
        return nullptr;
    }

private:
    static std::vector<Livro *> livros;
};

std::vector<Livro *> Biblioteca::livros;

int main()
{
    Livro livro1("Livro A", "Autor 1", 5);
    Livro livro2("Livro B", "Autor 2", 3);

    Biblioteca::adicionarLivro(livro1);
    Biblioteca::adicionarLivro(livro2);

    Usuario usuario1("Usuário 1");
    Usuario usuario2("Usuário 2");

    usuario1.emprestarLivro(livro1);
    usuario1.emprestarLivro(livro2);
    usuario2.emprestarLivro(livro1);

    usuario1.listarLivrosEmprestados();
    usuario2.listarLivrosEmprestados();

    return 0;
}
