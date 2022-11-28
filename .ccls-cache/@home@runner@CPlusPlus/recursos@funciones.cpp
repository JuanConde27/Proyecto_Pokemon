#include "funciones.h"

void crear_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador){
  
  ifstream archivo_entrada;
  ofstream archivo_salida;
  
  int cant_pokemones;
  int acumulador_poder_poke = 0;
  
  for (int i = 0; i < cant_entrenador; i++){
    
    cout << "\nEntrenador #" << (i + 1) << endl;
    cout << "\nDigite su nombre y apellido: ";
    cin >> lista_entrenador[i].nombre_apellido;
    
    archivo_entrada.open(lista_entrenador[i].nombre_apellido.c_str());

    if(! archivo_entrada.fail()){
      cout << "Ops... Este entrenador ya esta registrado\n";
    }
    
    if (archivo_entrada.fail()){
    archivo_salida.open(lista_entrenador[i].nombre_apellido.c_str());
    
    cout << "Digite el numero de licencia: ";
    cin >> lista_entrenador[i].num_licencia;
    cout << "Digite su edad: ";
    cin >> lista_entrenador[i].edad;
    cout << "Digite su sexo: ";
    cin >> lista_entrenador[i].sexo;
    cout << "Digite el nombre de su region: ";
    cin >> lista_entrenador[i].region;
    cout << "\nHola " << lista_entrenador[i].nombre_apellido << " tus datos fueron registrados con exito";
    cout << " Ahora pasaremos a registrar los pokemones de tu pokedex\n";
    cout << "\nDigite la cantidad de pokemones que tienes en tu pokedex: ";
    cin >> cant_pokemones;

    for (int i = 0; i < cant_pokemones; i++){
      
      cout << "\nPokemon #" << (i+1) << endl;
      cout << "\nIngrese el nombre del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.nombre_pokemon;
      cout << "Ingrese el tipo de pokemon: ";
      cin >> lista_entrenador[i].lista_poke.tipo_poke;
      cout << "Ingrese el sexo del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.sexo_poke;
      cout << "Ingrese el nivel del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.nivel;
      lista_entrenador[i].lista_poke.cantidad_poder = lista_entrenador[i].lista_poke.nivel * 2000;
      cout << "La cantidad de poder de su pokemon es de: " << lista_entrenador[i].lista_poke.cantidad_poder;
      
      acumulador_poder_poke += lista_entrenador[i].lista_poke.cantidad_poder;
      cout << "\n";

      archivo_salida << "\nPokemon " << (i+1) << endl;
      archivo_salida << "Tipo " << lista_entrenador[i].lista_poke.tipo_poke << endl;
      archivo_salida << "Sexo " << lista_entrenador[i].lista_poke.sexo_poke << endl;
      archivo_salida << "Nivel " << lista_entrenador[i].lista_poke.nivel << endl;
      archivo_salida << "Cantidad de poder " << lista_entrenador[i].lista_poke.cantidad_poder << endl;
      
    }
    
    archivo_salida.close();

    lista_entrenador[i].nivel_poder = acumulador_poder_poke / cant_pokemones;

    cout << "\n\nHola " << lista_entrenador[i].nombre_apellido << " tu nivel de poder es de: " << lista_entrenador[i].nivel_poder;


    }
  } 
}

void imprimir_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador){
  
  for (int i = 0; i < cant_entrenador; i++){
    
    cout << "\n----------Entrenador----------\n";
    cout << "Nombre del entrenador: " << lista_entrenador[i].nombre_apellido << endl;
    cout << "Numero de licencia: " << lista_entrenador[i].num_licencia << endl;
    cout << "Edad: " << lista_entrenador[i].edad << endl;
    cout << "Sexo: " << lista_entrenador[i].sexo << endl;
    cout << "Region: " << lista_entrenador[i].region << endl;
    cout << "Nivel de poder: " << lista_entrenador[i].nivel_poder << endl;
    
  }
  
}

void imprimir_pokemon(Entrenador lista_entrenador[TAM], int cant_entrenador){
  
  for (int i = 0; i < cant_entrenador; i++){
    
      cout << "\nPokemon #" << (i+1) << endl;
      cout << "\nNombre del pokemon: " << lista_entrenador[i].lista_poke.nombre_pokemon << endl;
      cout << "Tipo de pokemon: " << lista_entrenador[i].lista_poke.tipo_poke << endl;
      cout << "Sexo del pokemon: " << lista_entrenador[i].lista_poke.sexo_poke << endl;
      cout << "Nivel del pokemon: " << lista_entrenador[i].lista_poke.nivel << endl;
      lista_entrenador[i].lista_poke.cantidad_poder = lista_entrenador[i].lista_poke.nivel * 2000;
      cout << "La cantidad de poder de el pokemon es de: " << lista_entrenador[i].lista_poke.cantidad_poder;
      cout << "\n";
    
  }
}

void encontrar_licencia(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia){

  for (int i = 0; i < cant_entrenador; i++){
    
    if(licencia == lista_entrenador[i].num_licencia){ 
      
      cout << "\n----------Entrenador----------\n";
      cout << "Nombre del entrenador: " << lista_entrenador[i].nombre_apellido << endl;
      cout << "Numero de licencia: " << lista_entrenador[i].num_licencia << endl;
      cout << "Edad: " << lista_entrenador[i].edad << endl;
      cout << "Sexo: " << lista_entrenador[i].sexo << endl;
      cout << "Region: " << lista_entrenador[i].region << endl;
      cout << "Nivel de poder: " << lista_entrenador[i].nivel_poder << endl;
      
    }
  }
}

void editar_licencia(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia){

  for (int i = 0; i < cant_entrenador; i++){
    
    if(licencia == lista_entrenador[i].num_licencia){ 
      
      cout << "\n----------Editar entrenador----------\n";
      cout << "Nuevo nombre del entrenador: ";
      cin >> lista_entrenador[i].nombre_apellido;
      cout << "Nueva edad: ";
      cin >> lista_entrenador[i].edad;
      cout << "Nuevo sexo: ";
      cin >> lista_entrenador[i].sexo;
      cout << "Nueva region: "; 
      cin >> lista_entrenador[i].region;
      
    }
  }
}