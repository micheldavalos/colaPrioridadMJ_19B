#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class Barco
{
    string id;
    double velocidad;
    double combustible;
    double armadura;

public:
    Barco(string i, double v, double c, double a)
    {
        id = i;
        velocidad = v;
        combustible = c;
        armadura = a;
    }

    double getVelocidad()
    {
        return velocidad;
    }

    friend ostream& operator<<(ostream &out,Barco &b)
    {
        out << setw(3) << b.id <<
               setw(4) << b.velocidad <<
               setw(4) << b.combustible <<
               setw(4) << b.armadura;
        return out;
    }

    struct Comparador
    {
        bool operator()(Barco *b1, Barco *b2)
        {
            return b1->getVelocidad() > b2->getVelocidad();
        }
    };
};

class Civilizacion
{
    priority_queue<Barco*,
                    vector<Barco*>,
                    Barco::Comparador> pq;

public:
    Civilizacion()
    {
        pq.push(new Barco("1", 10, 100, 0));
        pq.push(new Barco("2", 5, 100, 0));
        pq.push(new Barco("3", 20, 100, 0));
    }

    void mostrar()
    {
        priority_queue<Barco*,
                vector<Barco*>,
                Barco::Comparador> copia(pq);

        while (!copia.empty()) {
            Barco *b = copia.top();
            cout << *b << endl;
            copia.pop();
        }
    }
};

int main()
{
//    queue<int> cola;

//    for (int i = 0; i < 10; i++) {
//        cola.push(i);
//    }

//    cout << "frente: " << cola.front() << endl;
//    cout << "ultimo: " << cola.back() << endl;

//    while (!cola.empty()) {
//        int i = cola.front();
//        cout << i << " ";
//        cola.pop();
//    }

//    cout << endl;

//    priority_queue<int, vector<int>, greater<int> > pq;

//    pq.push(10);
//    pq.push(2);
//    pq.push(15);
//    pq.push(0);

//    while (!pq.empty()) {
//        cout << pq.top() << " ";
//        pq.pop();
//    }

//    cout << endl;

//    priority_queue<string,
//            vector<string>,
//            greater<string> > pq;

//    pq.push("Michel");
//    pq.push("Davalos");
//    pq.push("Boites");

//    while (!pq.empty()) {
//        cout << pq.top() << " ";
//        pq.pop();
//    }

//    cout << endl;
//    auto comparador = [](Barco *b1, Barco *b2)
//    {
//        return b1->getVelocidad() < b2->getVelocidad();
//    };
//    priority_queue<Barco*,
//            vector<Barco*>,
//            decltype (comparador)> pq(comparador);

//    pq.push(new Barco("1", 10, 100, 0));
//    pq.push(new Barco("2", 5, 100, 0));
//    pq.push(new Barco("3", 20, 100, 0));

//    while (!pq.empty()) {
//        cout << *pq.top() << endl;
//        pq.pop();
//    }

    Civilizacion c;
    c.mostrar();


    return 0;
}
