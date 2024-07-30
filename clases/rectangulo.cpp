#include <iostream>
#include <string>
#include <memory>  // Para std::unique_ptr

using namespace std;

class Rectangulo {
    
private:
    float largo, ancho;

public:
    Rectangulo(float largo, float ancho);
    ~Rectangulo();
    void perimetro() const;  // Método const
    void area() const;       // Método const
};

Rectangulo::Rectangulo(float largo, float ancho) : largo(largo), ancho(ancho) {
}

Rectangulo::~Rectangulo() {
    // Destructor vacío
}

void Rectangulo::perimetro() const {
    cout << "El perímetro es: " << 2 * largo + 2 * ancho << endl;
}

void Rectangulo::area() const {
    cout << "El área es: " << ancho * largo << endl;
}

int main() {
    // Uso de std::unique_ptr para gestionar la memoria automáticamente
    unique_ptr<Rectangulo> p = make_unique<Rectangulo>(2, 4);
    p->perimetro();
    p->area();

    // La memoria se libera automáticamente cuando el unique_ptr sale de su alcance
    return 0;
}