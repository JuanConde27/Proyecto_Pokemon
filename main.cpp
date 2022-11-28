#include "recursos/funciones.h"

int main() {

int x = 0;
int cant_entrenador;
  
do{

  art();
  
  cout << "> [ Menu ] Digite la opcion que desea escoger" << endl;
  cout << "\n> ";
  cin >> x;
  
  switch(x){
    
    case 1:
    {

      cout << "\n> Digite la cantidad de entrenadores que desea crear" << endl;
      cout << "> ";
      cin >> cant_entrenador;
  
      Entrenador lista_entrenador[TAM];

      crear_entrenador(lista_entrenador, cant_entrenador);

      break;
      
    }
    case 2:
    {
    
      cout << "\n --Lista de los entrenadores registrados-- \n";

       Entrenador lista_entrenador[TAM];

      imprimir_entrenador(lista_entrenador, cant_entrenador);
      
      break;
      
    }
    case 3:
    {
      
      int licencia;
      
      cout << "\n> Ingrese el numero de la licencia para buscar al entrenador ";
      cout << "> ";
      cin >> licencia;
      
      Entrenador lista_entrenador[TAM];
      
      encontrar_licencia(lista_entrenador, cant_entrenador, licencia);

      int str;
      
      cout << "\n1 -> Modificar los datos del entrenador" << endl;
      cout << "\n2 -> Imprimir lista de pokemones" << endl;
      cout << "\n";
      cout << "> ";
      cin >> str;

      if (str == 1){
        
      editar_entrenador(lista_entrenador,cant_entrenador,licencia);
        
      }
      else if (str == 2){
        
      imprimir_pokemon(lista_entrenador, cant_entrenador, licencia);
        
      }
      
      break;
      
    }
    case 4:
    {
      
      Entrenador lista_entrenador[TAM];
      
      fuerte_debil(lista_entrenador, cant_entrenador);

      break;
      
    }
    case 5:
    {
      
      int licencia; int licencia_2;
      
      cout << "\n> Ingrese los 2 numeros de la licencia de los entrenadores para enfrentar\n";
      cout << "\n> Ingrese licencia 1: ";
      cin >> licencia;
      cout << "\n> Ingrese licencia 2: ";
      cin >> licencia_2;

      Entrenador lista_entrenador[TAM];

      enfrentar(lista_entrenador, cant_entrenador, licencia, licencia_2);

      break;
      
    }
    case 6:
    {

      char opc;

      cout << "\n[A] Cargar enfrenador mas fuerte y mas debil\n[B] Resultado enfrentamientos\n[C] Lista de pokemones atrapados\n\n> ";
      cin >> opc;

      switch(tolower(opc)){
        
        case 'a':{

          imprimir_fuerte_debil();
          
        break;
        }
        case 'b':{

          imprimir_enfrentamiento();

        break;  
        }
        
        case 'c':{
          
        string nombre;
          
        cout << "\n> Digite el nombre del entrenador: ";
        cin >> nombre;
          
        Entrenador lista_entrenador[TAM];
          
        lista_pokemones(lista_entrenador,cant_entrenador, nombre);
          
        break;
        }
      }
    }
  }
  
  } while(x != 7);
  cout << "\n";
  return 0;
}
