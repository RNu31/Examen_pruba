#include<iostream>
#include<string>
#include<queue>

struct Miembro
{
  std::string nombre;
  std::string apellido;
  int edad;
  std::string id;
};

struct Club
{
  std::string nombre;
  std::string fecha;
  std::queue<Miembro> Miembros;
};


int main() {

}