#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

class Usuario;

class Tweet
{
public:
    Tweet(Usuario *autor, const std::string &conteudo)
    {
        this->autor = autor;
        this->conteudo = conteudo;
        this->data_criacao = std::time(0);
    }

    Usuario *getAutor()
    {
        return autor;
    }

    std::string getConteudo()
    {
        return conteudo;
    }

    time_t getDataCriacao()
    {
        return data_criacao;
    }

private:
    Usuario *autor;
    std::string conteudo;
    time_t data_criacao;
};

class Usuario
{
public:
    Usuario(const std::string &nome_usuario, const std::string &nome)
    {
        this->nome_usuario = nome_usuario;
        this->nome = nome;
    }

    void postarTweet(const std::string &conteudo)
    {
        Tweet *tweet = new Tweet(this, conteudo);
        tweets.push_back(tweet);
    }

    void seguir(Usuario *usuario)
    {
        seguindo.push_back(usuario);
        usuario->seguidores.push_back(this);
    }

    std::vector<Tweet *> receberFeed()
    {

        std::vector<Tweet *> feed = tweets;
        for (Usuario *u : seguindo)
        {
            for (Tweet *tweet : u->tweets)
            {
                feed.push_back(tweet);
            }
        }

        std::sort(feed.begin(), feed.end(), [](Tweet *a, Tweet *b)
                  { return a->getDataCriacao() > b->getDataCriacao(); });

        return feed;
    }

    std::string getNomeUsuario()
    {
        return nome_usuario;
    }

private:
    std::string nome_usuario;
    std::string nome;
    std::vector<Tweet *> tweets;
    std::vector<Usuario *> seguidores;
    std::vector<Usuario *> seguindo;
};

class RedeSocial
{
public:
    void registrarUsuario(const std::string &nome_usuario, const std::string &nome)
    {
        Usuario *novoUsuario = new Usuario(nome_usuario, nome);
        usuarios.push_back(novoUsuario);
    }

    Usuario *buscarUsuario(const std::string &nome_usuario)
    {
        for (Usuario *usuario : usuarios)
        {
            if (usuario->getNomeUsuario() == nome_usuario)
            {
                return usuario;
            }
        }
        return nullptr;
    }

    std::vector<Usuario *> listarUsuarios()
    {
        return usuarios;
    }

    std::vector<Tweet *> listarTweets()
    {
        std::vector<Tweet *> todosTweets;
        for (Usuario *usuario : usuarios)
        {
            for (Tweet *tweet : usuario->receberFeed())
            {
                todosTweets.push_back(tweet);
            }
        }
        return todosTweets;
    }

private:
    std::vector<Usuario *> usuarios;
};

int main()
{
    RedeSocial redeSocial;

    redeSocial.registrarUsuario("usuario1", "Nome1");
    redeSocial.registrarUsuario("usuario2", "Nome2");

    Usuario *usuario1 = redeSocial.buscarUsuario("usuario1");
    Usuario *usuario2 = redeSocial.buscarUsuario("usuario2");

    usuario1->postarTweet("Primeiro tweet do usuário 1.");
    usuario2->postarTweet("Tweet do usuário 2.");

    usuario1->seguir(usuario2);

    std::vector<Tweet *> feedUsuario1 = usuario1->receberFeed();
    for (Tweet *tweet : feedUsuario1)
    {
        std::cout << tweet->getAutor()->getNomeUsuario() << ": " << tweet->getConteudo() << std::endl;
    }

    return 0;
}
