#include <iostream>

class Character;

// Visitante de habilidades
class AbilityVisitor 
{
    public:
        virtual void visit(Character& character) = 0;
};

// Clase base de personajes del juego
class Character
{
    public:
        virtual void accept(AbilityVisitor& visitor) = 0;
};

// Implementación de un personaje del juego (por ejemplo, un mago)
class Wizard : public Character
{
    public:
        void accept(AbilityVisitor& visitor) override 
        {
            visitor.visit(*this);
        }
};

// Implementación de un personaje del juego (por ejemplo, un guerrero)
class Warrior : public Character
{
    public:
        void accept(AbilityVisitor& visitor) override
        {
            visitor.visit(*this);
        }
};

// Implementación del visitante de habilidades para magos
class WizardAbilityVisitor : public AbilityVisitor
{
    public:
        void visit(Character& character) override
        {
            std::cout << "Activando habilidad de mago" << std::endl;
            // Lógica específica para habilidades de magos
            // ...
        }
};

// Implementación del visitante de habilidades para guerreros
class WarriorAbilityVisitor : public AbilityVisitor
{
    public:
        void visit(Character& character) override
        {
            std::cout << "Activando habilidad de guerrero" << std::endl;
            // Lógica específica para habilidades de guerreros
            // ...
        }
};

// Uso del patrón Visitor en el contexto de habilidades
void activateAbility(Character& character, AbilityVisitor& visitor)
{
    character.accept(visitor);
}

int main()
{
    Wizard wizard;
    Warrior warrior;

    WizardAbilityVisitor wizardVisitor;
    WarriorAbilityVisitor warriorVisitor;

    activateAbility(wizard, wizardVisitor);    // Salida: Activando habilidad de mago
    activateAbility(warrior, warriorVisitor);  // Salida: Activando habilidad de guerrero

    return 0;
}