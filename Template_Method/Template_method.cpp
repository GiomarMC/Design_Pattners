
#include <iostream>

// Clase abstracta que define el template method
class Battle
{
public:
    Battle() {} //Constructor

    virtual ~Battle() {} //Destructor

    virtual void pelea() final //La implementación en las subclases no modificará el TEMPLATE METHOD
    {
        prepararse();
        ataque();
        endBattle();
    }

    // Paso 1: Preparación (común a todas las batallas)
    void prepararse()
    {
        std::cout << "Preparando la batalla." << std::endl;
    }

    // Paso 3: Fin de la batalla (común a todas las batallas)
    void endBattle()
    {
        std::cout << "La batalla ha terminado." << std::endl;
    }

    // Paso 2: Ataque (abstracto, implementado por las subclases)
    virtual void ataque() = 0;
};

// Subclase que implementa el paso 2 específico para una batalla de espadas
class BatallaEspada : public Battle
{
public:
    BatallaEspada() {} //Constructor
    virtual ~BatallaEspada() {} //Destructor

    void ataque() override //Es necesario realizar la implementación
    {
        std::cout << "Atacando con una espada." << std::endl;
    }
};

// Otra subclase que implementa el paso 2 específico para una batalla de arcos
class BatallaArco : public Battle
{
public:
    BatallaArco() {} //Constructor
    virtual ~BatallaArco() {} //Destructor
    void ataque() override //Es necesario realizar la implementación
    {
        std::cout << "Atacando con un arco." << std::endl;
    }
};

int main()
{
    // Batalla con espadas
    Battle* a = new BatallaEspada();
    a->pelea();

    std::cout << std::endl;

    // Batalla con arcos
    Battle* b = new BatallaArco();
    b->pelea();

    delete a;
    delete b;

    return 0;
}