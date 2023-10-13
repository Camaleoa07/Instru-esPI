#include <iostream>
#include <string>
#include <unordered_map>

class Produto
{
private:
    std::string nome;
    double preco;
    int codigo;

public:
    Produto() : nome(""), preco(0.0), codigo(0) {}

    Produto(const std::string &nome, double preco, int codigo)
        : nome(nome), preco(preco), codigo(codigo) {}

    std::string getNome() const
    {
        return nome;
    }

    double getPreco() const
    {
        return preco;
    }

    int getCodigo() const
    {
        return codigo;
    }
};

class Estoque
{
private:
    std::unordered_map<int, int> quantidades;
    std::unordered_map<int, Produto> produtos;

public:
    void adicionarProduto(const Produto &produto, int quantidade)
    {
        quantidades[produto.getCodigo()] += quantidade;
        produtos[produto.getCodigo()] = produto;
    }

    const Produto &getProdutoPorCodigo(int codigo) const
    {
        return produtos.at(codigo);
    }

    int getQuantidadeProduto(const Produto &produto) const
    {
        return quantidades.at(produto.getCodigo());
    }

    void removerProduto(const Produto &produto, int quantidade)
    {
        quantidades[produto.getCodigo()] -= quantidade;
        if (quantidades[produto.getCodigo()] < 0)
        {
            quantidades[produto.getCodigo()] = 0;
        }
    }
};

class CarrinhoDeCompras
{
private:
    std::unordered_map<int, int> itens;

public:
    void adicionarProduto(const Produto &produto, int quantidade)
    {
        itens[produto.getCodigo()] += quantidade;
    }

    void removerProduto(const Produto &produto, int quantidade)
    {
        itens[produto.getCodigo()] -= quantidade;
        if (itens[produto.getCodigo()] < 0)
        {
            itens[produto.getCodigo()] = 0;
        }
    }

    double calcularValorTotal(const Estoque &estoque) const
    {
        double total = 0.0;
        for (const auto &item : itens)
        {
            int codigo = item.first;
            int quantidade = item.second;
            const Produto &produto = estoque.getProdutoPorCodigo(codigo);
            total += quantidade * produto.getPreco();
        }
        return total;
    }

    void exibirCarrinho(const Estoque &estoque) const
    {
        std::cout << "Carrinho de Compras:" << std::endl;
        for (const auto &item : itens)
        {
            int codigo = item.first;
            int quantidade = item.second;
            const Produto &produto = estoque.getProdutoPorCodigo(codigo);
            std::cout << "- " << produto.getNome() << " (" << produto.getPreco() << ") x " << quantidade << std::endl;
        }
    }

    void esvaziarCarrinho()
    {
        itens.clear();
    }
};

int main()
{
    Produto p1("Maçã", 2.5, 1);
    Produto p2("Arroz", 10.0, 2);
    Produto p3("Leite", 4.0, 3);
    Produto p4("Chocolate", 3.0, 4);

    Estoque estoque;
    estoque.adicionarProduto(p1, 50);
    estoque.adicionarProduto(p2, 100);
    estoque.adicionarProduto(p3, 200);
    estoque.adicionarProduto(p4, 5);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);

    double valorTotal = carrinho.calcularValorTotal(estoque);
    std::cout << "Valor total da compra: " << valorTotal << std::endl;

    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal(estoque);
    std::cout << "Valor total após remoção: " << valorTotal << std::endl;

    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal(estoque);
    std::cout << "Valor total após esvaziar o carrinho: " << valorTotal << std::endl;

    carrinho.adicionarProduto(p4, 10);
    std::cout << "Quantidade de chocolates no carrinho: " << estoque.getQuantidadeProduto(p4) << std::endl;

    carrinho.adicionarProduto(p1, 2);
    carrinho.adicionarProduto(p2, 3);
    carrinho.adicionarProduto(p3, 1);
    carrinho.adicionarProduto(p4, 2);

    carrinho.exibirCarrinho(estoque);

    return 0;
}
