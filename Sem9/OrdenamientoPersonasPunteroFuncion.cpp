#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string apellido;
    long long dni;
    
    Persona(string nombre, string apellido, long long dni)
    : nombre(nombre), apellido(apellido), dni(dni) {}
};

template <class T>
void ordenar(vector<T>& v, bool(*comp)(T, T)) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = 0; j < v.size() - i - 1; ++j) {
            if (comp(v[j], v[j + 1])) {
                T t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }
}

bool compPersonaApeAsc(Persona a, Persona b) {
    return a.apellido > b.apellido;
}
bool compPersonaApeDesc(Persona a, Persona b) {
    return a.apellido < b.apellido;
}

ostream& operator <<(ostream& os, vector<Persona> v) {
    os << "[ ";
    for (int i = 0; i < v.size(); ++i) {
        cout << "{ apellido: '" << v[i].apellido << "' },\n";
    }
    os << "]\n";
    return os;
}

int main() {
    vector<Persona> ps;
    ps.push_back(Persona("Jose", "Lopez", 123123123));
    ps.push_back(Persona("Rosa", "Rosales", 123123123));
    ps.push_back(Persona("Manuel", "Palacios", 123123123));
    ps.push_back(Persona("Maria", "Miranda", 123123123));
    ps.push_back(Persona("Abel", "Zavala", 123123123));
    
    ordenar<Persona>(ps, compPersonaApeAsc);
    cout << ps;
    
    ordenar<Persona>(ps, compPersonaApeDesc);
    cout << ps;
    
    return 0;
}
