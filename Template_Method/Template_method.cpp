#include <iostream>

// Clase abstracta que define el template method
class AbstractClass
{
    public:
        AbstractClass() {}
        virtual ~AbstractClass() {}

        void TemplateMethod()
        {
            // Paso 1
            Step1();

            // Paso 2 (abstracto, implementado por las subclases)
            Step2();

            // Paso 3
            Step3();
        }

        // Paso 1 (común a todas las subclases)
        void Step1()
        {
            std::cout << "Realizando el paso 1." << std::endl;
        }

        // Paso 3 (común a todas las subclases)
        void Step3()
        {
            std::cout << "Realizando el paso 3." << std::endl;
        }

        // Paso 2 (abstracto, implementado por las subclases)
        virtual void Step2() = 0;
};

// Subclase que implementa el paso 2 específico
class ConcreteClassA : public AbstractClass
{
    public:
        ConcreteClassA() {}
        ~ConcreteClassA() {}

        void Step2() override
        {
            std::cout << "Realizando el paso 2 especifico para ConcreteClassA." << std::endl;
        }
};

// Otra subclase que implementa el paso 2 específico
class ConcreteClassB : public AbstractClass {
public:
    ConcreteClassB() {}
    ~ConcreteClassB() {}

    void Step2() override
    {
        std::cout << "Realizando el paso 2 especifico para ConcreteClassB." << std::endl;
    }
};

int main()
{
    // Utilizando ConcreteClassA
    AbstractClass* objectA = new ConcreteClassA();
    objectA->TemplateMethod();

    std::cout << std::endl;

    // Utilizando ConcreteClassB
    AbstractClass* objectB = new ConcreteClassB();
    objectB->TemplateMethod();

    delete objectA;
    delete objectB;

    return 0;
}