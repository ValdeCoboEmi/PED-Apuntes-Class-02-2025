#include <iostream>
#include <string>
#include <unordered_map>

struct Animal
{
    std::string nombre_cientifico;
    std::string nombre_comun;
    bool genero;
};

Animal SolocitarDatos();
void Imprimir(const std::unordered_map<std::string, Animal> &umap);
bool Buscar(const std::unordered_map<std::string, Animal> &umap, const std::string &clave);
void Eliminar(std::unordered_map<std::string, Animal> &umap, const std::string &clave);

int main()
{

    std::unordered_map<std::string, Animal> umap;
    Animal inf_animal;
    bool continuar = true;
    std::string clave_buscar, clave_eliminar;

    do
    {

        inf_animal = SolocitarDatos();

        /// umap.insert({inf_animal.nombre_cientifico, inf_animal}); //No crea el objeto
        umap.emplace(inf_animal.nombre_cientifico, inf_animal); // Crea el objeto

        // Preguntamos si se desea seguir ingresando más datos
        std::cout << "\nDigite la opcion para continuar ingresando o no: " << std::endl;
        std::cout << "1. Continuar" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Digite la opcion: ";
        std::cin >> continuar;

        std::cin.ignore();

    } while (continuar);

    Imprimir(umap);

    std::cout << "\nIngrese el nombre cientifico del animal a buscar: ";
    std::getline(std::cin, clave_buscar);
    std::cout << (Buscar(umap, clave_buscar) ? "\nnElemento encontrado\n"
                                              : "\nElemento no encontrado\n");

    std::cout << "\nIngrese el nombre cientifico del animal a eliminar: ";
    std::getline(std::cin, clave_eliminar);
    Eliminar(umap, clave_eliminar);

    Imprimir(umap);

    return 0;
}

Animal SolocitarDatos()
{
    Animal a;
    std::cout << "\nIngrese el nombre cientifico del animal: ";
    std::getline(std::cin, a.nombre_cientifico);

    std::cout << "Ingrese el nombre comun del animal: ";
    std::getline(std::cin, a.nombre_comun);

    std::cout << "Digite el genero: " << std::endl;
    std::cout << "1. Macho" << std::endl;
    std::cout << "0. Hembra" << std::endl;
    std::cout << "Digite la opcion: ";
    std::cin >> a.genero;

    return a;
}

void Imprimir(const std::unordered_map<std::string, Animal> &umap)
{

    std::cout << "\n===== CONTENIDO DEL UNORDERED MAP =====\n\n";

    auto hash = umap.hash_function();

    for (auto &&i : umap)
    {
        std::cout << "Hash de la clave " << i.first << " : " << hash(i.first) << std::endl;
        std::cout << "Clave: " << i.first << std::endl;
        std::cout << "Nombre Cientifico: " << i.second.nombre_cientifico << std::endl;
        std::cout << "Nombre Comun: " << i.second.nombre_comun << std::endl;
        std::cout << "Genero: " << (i.second.genero ? "Macho" : "Hembra") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

bool Buscar(const std::unordered_map<std::string, Animal> &umap, const std::string &clave)
{
    auto it = umap.find(clave);

    if (it != umap.end())
    {
        std::cout << "Nombre Cientifico: " << it->second.nombre_cientifico << std::endl;
        std::cout << "Nombre Comun: " << it->second.nombre_comun << std::endl;
        std::cout << "Genero: " << (it->second.genero ? "Macho" : "Hembra") << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Eliminar(std::unordered_map<std::string, Animal> &umap, const std::string &clave)
{
    auto it = umap.find(clave);

    if (it != umap.end())
    {
        umap.erase(it->first);
        std::cout << "Ha sido eliminado exitosamente!\n";
    }
    else
    {
        std::cout << "No se pudo eliminar\n";
        return;
    }
}