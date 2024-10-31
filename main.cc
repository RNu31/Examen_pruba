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
  std::vector<Miembro> Miembros;
};

void RegistrarMiembro(std::queue<Club>& clubes);
void ListarMiembros(const std::queue<Club>& clubes);

bool idExistente(const std::vector<Club>& clubes, const std::string& id){
    for (const Club& club : clubes) {
        for (const Miembro& miembro : club.Miembros) {
            if (miembro.id == id) {
                return true;
            }
        }
    }
    return false;
}

int main() {

}

void RegistrarMiembro(std::vector<Club>& clubes, int n){
    if (clubes.empty()){
        std::cout << "No hay clubes disponibles para registar nuevos miembros.\n";
        return;
    }
    MostrarClubes(clubes);
    std::cout << "\nSeleccione el numero del club";
    std::cin >> n;
    if (n < 1 || n > clubes.size()){
        std::cout << "Numero de club invalido.\n";
        return;
    }
    Miembro nuevoMiembro;
    std::cout << "Ingrese el nombre del nuevo miembro: ";
    std::getline(std::cin, nuevoMiembro.nombre);
    std::cout << "Ingrese el apellido del nuevo miembro: ";
    std::getline(std::cin, nuevoMiembro.apellido);
    std::cout << "Ingrese la edad del nuevo miembro: ";
    std::cin >> nuevoMiembro.edad;
    std::cin.ignore();

    do{
        std::cout  << "Ingrese el id del nuevo miembro: ";
        std::getline(std::cin, nuevoMiembro.id);
        if (idExistente(clubes, nuevoMiembro.id)){
            std::cout << "El id ya existe, por favor ingrese otro\n";
        } 
    }while (idExistente(clubes, nuevoMiembro.id));
    clubes[n - 1].Miembros.push_back(nuevoMiembro);
    std::cout << "Miembro registrado exitosamente!\n";
}

void ListarMiembros(const std::vector<Club>& clubes, int n){
    if (clubes.empty())
    {
        std::cout  << "No hay ningun club registrado.\n";
        return;
    }
    MostrarClubes(clubes);
    std::cout << "\nSeleccion el numero del club: ";
    std::cin >> n;
    if (n < 1 || n > clubes.size()){
        std::cout << "Numero de club invalido.\n";
        return;
    }
    const Club& club = clubes[n - 1];
    if (club.Miembros.empty()) {
        std::cout << "No hay miembros registrados en este club.\n";
        return;
    }
    std::cout << "\nMiembros del club " << club.nombre << ":\n";
    for (const auto& miembro : club.Miembros) {
        std::cout << miembro.nombre << " " << miembro.apellido << " " <<
        miembro.edad << " " << miembro.id << "\n";
    }
}