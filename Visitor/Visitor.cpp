#include <iostream>
using namespace std;

// Forward declaration de las clases visitables
class ElementA;
class ElementB;

// Interfaz del visitante
class Visitor
{
    public:
        virtual ~Visitor() {}
        virtual void visit(ElementA* element) = 0;
        virtual void visit(ElementB* element) = 0;
};

// Clase base para los elementos visitables
class Element
{
    public:
        virtual ~Element() {}
        virtual void accept(Visitor* visitor) = 0;
};

// Implementación de los elementos visitables
class ElementA : public Element
{
    public:
        ElementA() {}
        ~ElementA() {}
        
        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }
        
        void operationA()
        {
            std::cout << "Operacion A en ElementA\n";
        }
};

class ElementB : public Element
{
    public:
        ElementB() {}
        ~ElementB() {}
        
        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }
        
        void operationB()
        {
            std::cout << "Operacion B en ElementB\n";
        }
};

// Implementación concreta del visitante
class ConcreteVisitor : public Visitor
{
    public:
        ConcreteVisitor() {}
        ~ConcreteVisitor() {}
        
        void visit(ElementA* element) override
        {
            std::cout << "ConcreteVisitor visitando ElementA\n";
            element->operationA();
        }
        
        void visit(ElementB* element) override
        {
            std::cout << "ConcreteVisitor visitando ElementB\n";
            element->operationB();
        }
};
// Uso del patrón Visitor

int main()
{
	ElementA elementA;
	ElementB elementB;
	ConcreteVisitor visitor;
	
	elementA.accept(&visitor);
	elementB.accept(&visitor);
	
	return 0;
}