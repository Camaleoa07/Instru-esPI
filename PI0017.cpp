#include <iostream>
#include <cmath>

class Ponto
{
private:
    double x;
    double y;

public:
    Ponto() : x(0.0), y(0.0) {}

    Ponto(double x, double y) : x(x), y(y) {}

    void setCoordenadas(double novoX, double novoY)
    {
        x = novoX;
        y = novoY;
    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    double calcularDistancia() const
    {
        return sqrt(x * x + y * y);
    }
};

int main()
{

    Ponto p1(3, 4);
    double distancia1 = p1.calcularDistancia();
    std::cout << "A distância do ponto (3, 4) até a origem é aproximadamente " << distancia1 << "." << std::endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    double distancia2 = p2.calcularDistancia();
    std::cout << "A distância do ponto (1, 1) até a origem é aproximadamente " << distancia2 << "." << std::endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calcularDistancia();
    double distancia_p4 = p4.calcularDistancia();
    std::cout << "A distância do ponto (0, 3) até a origem é " << distancia_p3 << " e do ponto (4, 0) até a origem é " << distancia_p4 << "." << std::endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for (int i = 0; i < 3; ++i)
    {
        double distancia = pontos[i].calcularDistancia();
        std::cout << "Distância do ponto " << i + 1 << " até a origem: " << distancia << std::endl;
    }

    Ponto p5;
    std::cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << std::endl;
    p5.setCoordenadas(8, -3);
    std::cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << std::endl;

    return 0;
}