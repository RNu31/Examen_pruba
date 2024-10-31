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
void RegistrarMiembro(std::queue<Club>& clubes);
void ListarMiembros(const std::queue<Club>& clubes);
void CrearClubes(std::queue<Club>& Clubes);
void MostrarClubes(std::queue<Club>& Clubes);
void EliminarClubes(std::queue<Club>& Clubes);
void Menu();

int main() {
  std::queue<Club> Clubes;
  int respuesta;
  do
  {
    Menu();
    std::cin>>respuesta;
    std::cout << "=================================================\n";
    switch (respuesta)
    {
    case 1:
      system ("cls");
      CrearClubes(Clubes);
      system ("pause");
      break;
    
    case 2:
      system ("cls");
      MostrarClubes(Clubes);
      system ("pause");
      break;
    
    case 3:
      system ("cls");
      EliminarClubes(Clubes);
      system ("pause");
      break;
    
    case 4:
      std::cout<<"gracias hasta la proxima";
      break;
    
    default:
      break;
    }
  } while (respuesta != 4);
  

}

void CrearClubes(std::queue<Club>& Clubes){
  Club nuevo_club;
  std::cout<<"ingrese el nombre del club"<<std::endl;
  std::cin>>nuevo_club.nombre;std::cout<<"\n";
  std::cout<<"ingrese el fecha del club"<<std::endl;
  std::cin>>nuevo_club.fecha;std::cout<<"\n";
  Clubes.push(nuevo_club);
}
void MostrarClubes(std::queue<Club>& Clubes){
  if (Clubes.empty()){
    std::cout<<"No hay clubes de momento." << std::endl;
    return;
  }
  std::queue<Club> temp = Clubes;//igualo a temp a clubes para hacer una copia de la cola 
  std::cout << "Clubes en activo"<<std::endl;
  while (!temp.empty()) {
  std::cout <<"==========================\n";
  std::cout << temp.front().nombre <<"\n";
  std::cout << temp.front().fecha <<"\n";
  std::cout <<"==========================";
  temp.pop();//elimino la cola temporal
  }
}

void EliminarClubes(std::queue<Club>& Clubes){
if(!Clubes.empty()){
  Clubes.pop();
  std::cout<<"Clubes eliminados";
}
std::cout<<"no hay Clubes para eliminar";
}

void Menu(){
  std::cout << "=================================================\n";
  std::cout << "\nBienvenido al programa de gestion de Clubes:\n";
  std::cout << "\nMenu:\n";
  std::cout << "1. Agregar Club\n";
  std::cout << "2. Mostrar Clubes\n";
  std::cout << "3. Eliminar Clubes\n";
  std::cout << "4. Salir\n";
  std::cout << "Seleccione una opcion: ";
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
