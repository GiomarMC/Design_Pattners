#include <iostream>

// Interfaz de estrategia
class Ataque 
{
    public:
        virtual void realizarAtaque() = 0;
        virtual ~Ataque() {}
};

// Implementaciones concretas de estrategia
class AtaqueEspada : public Ataque 
{
    public:
        void realizarAtaque() override
        {
            std::cout << "Ataque con espada!" << std::endl;
        }
        ~AtaqueEspada() {}
};

class AtaqueArco : public Ataque
{
    public:
        void realizarAtaque() override
        {
            std::cout << "Disparo de flecha con arco!" << std::endl;
        }
        ~AtaqueArco() {}
};

class AtaqueMagia : public Ataque
{
    public:
        void realizarAtaque() override
        {
            std::cout << "Lanzamiento de hechizo magico!" << std::endl;
        }
        ~AtaqueMagia() {}
};

// Clase contexto
class Personaje
{
    private:
        Ataque* estrategiaAtaque;

    public:
        Personaje() : estrategiaAtaque(nullptr) {}

        void setEstrategiaAtaque(Ataque* estrategiaAtaque)
        {
            this->estrategiaAtaque = estrategiaAtaque;
        }

        void atacar()
        {
            estrategiaAtaque->realizarAtaque();
        }

        ~Personaje()
        {
            delete estrategiaAtaque;
        }
};

// Ejemplo de uso
int main()
{
    Personaje personaje;

    // Configurar el personaje con la estrategia de ataque de espada
    personaje.setEstrategiaAtaque(new AtaqueEspada());
    personaje.atacar();  // Salida: Ataque con espada!

    // Cambiar la estrategia de ataque a arco
    personaje.setEstrategiaAtaque(new AtaqueArco());
    personaje.atacar();  // Salida: Disparo de flecha con arco!

    // Cambiar la estrategia de ataque a magia
    personaje.setEstrategiaAtaque(new AtaqueMagia());
    personaje.atacar();  // Salida: Lanzamiento de hechizo mágico!

    return 0;
}