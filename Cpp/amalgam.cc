//
// Created by Aidan on 6/20/2018.
//

#include <iostream>

class Main{
public:
    virtual void a() = 0;
    virtual void b() = 0;
    void go(){
        a();
        b();
    }
};

class A : public virtual Main{
public:
    void a(){
        std::cout << "This is A.\n";
    }
};

class B : public virtual Main{
public:
    void b(){
        std::cout << "This is B.\n";
    }
};

class AltA : public virtual Main{
public:
    void a(){
        std::cout << "This is Alternate A.\n";
    }
};

class AltB : public virtual Main{
public:
    void b(){
        std::cout << "This is Alternate B.\n";
    }
};

class Extension : public B{
public:
    void ext(){
        std::cout << "This is an optional extension.\n";
        b();
        go();
    }
};

class Amalgam : public A, public B{};
class AmalgamAltA : public AltA, public B{};
class AmalgamAltB : public A, public AltB{};
class AmalgamExt : public A, public B, public Extension{};

int main(){
    Amalgam a;
    a.go();

    std::cout << '\n';

    AmalgamAltA b;
    b.go();

    std::cout << '\n';

    AmalgamAltB c;
    c.go();

    std::cout << '\n';

    AmalgamExt d;
    d.go();
    d.ext();

    return 0;
}