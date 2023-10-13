#include <iostream>
#include <vector>
#include <algorithm>

class ItemSet
{
private:
    std::vector<std::string> items;

public:
    ItemSet() {}

    void inserir(const std::string &s)
    {
        if (std::find(items.begin(), items.end(), s) == items.end())
        {
            items.push_back(s);
        }
    }

    void excluir(const std::string &s)
    {
        items.erase(std::remove(items.begin(), items.end(), s), items.end());
    }

    ItemSet operator+(const ItemSet &other) const
    {
        ItemSet result = *this;
        for (const std::string &item : other.items)
        {
            result.inserir(item);
        }
        return result;
    }

    ItemSet operator*(const ItemSet &other) const
    {
        ItemSet result;
        for (const std::string &item : items)
        {
            if (other.contem(item))
            {
                result.inserir(item);
            }
        }
        return result;
    }

    ItemSet operator-(const ItemSet &other) const
    {
        ItemSet result = *this;
        for (const std::string &item : other.items)
        {
            result.excluir(item);
        }
        return result;
    }

    bool operator==(const ItemSet &other) const
    {
        return items == other.items;
    }

    bool contem(const std::string &s) const
    {
        return std::find(items.begin(), items.end(), s) != items.end();
    }

    void mostrar() const
    {
        for (const std::string &item : items)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    ItemSet conjuntoA;
    ItemSet conjuntoB;
    ItemSet conjuntoC;

    conjuntoA.inserir("Maçã");
    conjuntoA.inserir("Banana");
    conjuntoA.inserir("Pera");

    conjuntoB.inserir("Banana");
    conjuntoB.inserir("Laranja");

    conjuntoC.inserir("Maçã");
    conjuntoC.inserir("Laranja");

    std::cout << "Conjunto A: ";
    conjuntoA.mostrar();

    std::cout << "Conjunto B: ";
    conjuntoB.mostrar();

    std::cout << "Conjunto C: ";
    conjuntoC.mostrar();

    ItemSet uniao = conjuntoA + conjuntoB;
    std::cout << "União (A + B): ";
    uniao.mostrar();

    ItemSet interseccao = conjuntoA * conjuntoB;
    std::cout << "Intersecção (A * B): ";
    interseccao.mostrar();

    ItemSet diferenca = conjuntoA - conjuntoB;
    std::cout << "Diferença (A - B): ";
    diferenca.mostrar();

    if (conjuntoA == conjuntoB)
    {
        std::cout << "Conjunto A é igual ao Conjunto B." << std::endl;
    }
    else
    {
        std::cout << "Conjunto A não é igual ao Conjunto B." << std::endl;
    }

    return 0;
}
