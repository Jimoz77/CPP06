#ifndef BASE_HPP
#define BASE_HPP

class Base
{
    public:
        virtual ~Base(); // Le destructeur virtuel obligatoire !
};

// Héritage PUBLIC, et classes totalement vides !
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Les trois fonctions demandées par le sujet
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
