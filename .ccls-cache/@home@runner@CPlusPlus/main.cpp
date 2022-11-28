#include "recursos/funciones.h"

int main() {

int x = 0;
int cant_entrenador;
  
do{
  
  art();

  cout << "> Digite la opcion que desea escoger" << endl;
  cout << "> ";
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

      editar_licencia(lista_entrenador, cant_entrenador, licencia);
        
      }
      else if (str == 2){
        
      imprimir_pokemon(lista_entrenador, cant_entrenador);
        
      }
      
    break;
    
    }
  
    }while(x != 7);
  
    cout << "\n";
    system("PAUSE");
    return 0;
}
