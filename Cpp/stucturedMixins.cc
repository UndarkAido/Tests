//
// Created by Aidan on 6/20/2018.
//

#include <iostream>

struct requireA{
    virtual void a() = 0;
};

struct requireB{
    virtual void b() = 0;
};

class MainClass : virtual requireA, virtual requireB{
public:
    void go(){
        a();
        b();
    }
};

template <typename BASE>
class provideA : public BASE, virtual requireA{
public:
    void a(){
        std::cout << "A is here.\n";
    }
};

template <typename BASE>
class provideB : public BASE, virtual requireB{
public:
    void b(){
        std::cout << "B is here.\n";
    }
};

template <typename BASE>
class provideAAlt : public BASE, virtual requireA{
public:
    void a(){
        std::cout << "A Alt is here.\n";
    }
};

template <typename BASE>
class provideBAlt : public BASE, virtual requireB{
public:
    void b(){
        std::cout << "B Alt is here.\n";
    }
};

struct requireC{
    virtual void c() = 0;
};

template <typename BASE>
class provideC : public BASE, virtual requireC{
public:
    void c(){
        std::cout << "C is here, if you want it.\n";
    }
};

template <typename BASE>
class provideD : public BASE, virtual requireA, virtual requireC{
public:
    void d(){
        std::cout << "D is here, if you want it.\nDo you have A and C?\n";
        a();
        c();
    }
};

typedef provideA<provideB<MainClass> > MyMain;
typedef provideA<provideBAlt<MainClass> > MyMain2;
typedef provideAAlt<provideB<MainClass> > MyMain3;
typedef provideC<provideA<provideB<MainClass> > > MyMainEx;
typedef provideD<provideC<provideA<provideB<MainClass> > > > MyMainExPlus;

int main(){
    MyMain one;
    one.go();
    one.b();
    one.a();

    std::cout << "\n\n";

    MyMain2 two;
    two.go();
    two.b();
    two.a();

    std::cout << "\n\n";

    MyMain3 three;
    three.go();
    three.b();
    three.a();

    std::cout << "\n\n";

    MyMainEx four;
    four.go();
    four.c();

    std::cout << "\n\n";

    MyMainExPlus five;
    five.go();
    five.d();

    std::cout << "\n\n";


    return 0;
}