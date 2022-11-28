#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

static void art() {

  cout << "\n\n";
  
  cout << " /$$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$$ /$$      /$$  /$$$$$$  /$$   /$$   " << endl;
  cout << "| $$__  $$ /$$__  $$| $$  /$$/| $$_____/| $$$    /$$$ /$$__  $$| $$$ | $$   " << endl;
  cout << "| $$  \\ $$| $$  \\ $$| $$ /$$/ | $$      | $$$$  /$$$$| $$  \\ $$| $$$$| $$" << endl;
  cout << "| $$$$$$$/| $$  | $$| $$$$$/  | $$$$$   | $$ $$/$$ $$| $$  | $$| $$ $$ $$   " << endl;
  cout << "| $$____/ | $$  | $$| $$  $$  | $$__/   | $$  $$$| $$| $$  | $$| $$  $$$$   " << endl;
  cout << "| $$      | $$  | $$| $$\\  $$ | $$      | $$\\  $ | $$| $$  | $$| $$\\  $$$" << endl;
  cout << "| $$      |  $$$$$$/| $$ \\  $$| $$$$$$$$| $$ \\/  | $$|  $$$$$$/| $$ \\  $$" << endl;
  cout << "|__/       \\______/ |__/  \\__/|________/|__/     |__/ \______/ |__/  \\__/" << endl;
  cout << "\n";
  cout << "                          BIENVENIDO A LA POKEDEX                           " << endl;
  cout << "\n";
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "|                                                                         |" << endl;
  cout << "|                   [1] -> Crear Entrenadores                             |" << endl;
  cout << "|                   [2] -> Imprimir lista de entrenadores                 |" << endl;
  cout << "|                   [3] -> Buscar entrenador                              |" << endl;
  cout << "|                   [4] -> Entrenador mas fuerte y mas debil              |" << endl;
  cout << "|                   [5] -> Enfrentamiento entre entrenadores              |" << endl;
  cout << "|                   [6] -> Cargar archivos en pantalla                    |" << endl;
  cout << "|                   [7] -> Salir                                          |" << endl;
  cout << "|                                                                         |" << endl;
  cout << "---------------------------------------------------------------------------" << endl;

  cout << "\n";
  
}

struct pokemon {

  string nombre_pokemon;
  char tipo_poke[100];
  char sexo_poke;
  float nivel;
  float cantidad_poder;

};

struct Entrenador {

  string nombre_apellido;
  int num_licencia;
  int edad;
  char sexo;
  char region[100];
  pokemon lista_poke;
  float nivel_poder;

};

int const TAM = 100;

void crear_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador);

void imprimir_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador);

void encontrar_licencia(Entrenador lista_entrenador[TAM], int cant_entrenador,int licencia);

void imprimir_pokemon(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia);

void enfrentar(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia, int licencia_2);

void fuerte_debil(Entrenador lista_entrenador[TAM], int cant_entrenador);

void lista_pokemones(Entrenador lista_entrenador[TAM], int cant_entrenador, string nombre);

void imprimir_enfrentamiento();

void delay(int secs); 

void imprimir_fuerte_debil();

void editar_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia);