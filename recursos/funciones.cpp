#include "funciones.h"

void crear_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador){
  
  ofstream archivo_salida; // archivo entrenadores
  ofstream archivo_salida_pokemon; // archivo de cada entrenador y sus pokemones
  
  int cant_pokemones;
  int acumulador_poder_poke = 0;

  archivo_salida.open("entrenadores/ENTRENADORES.txt", ios::app); // Abrir el archivo en modo añadir

  if(archivo_salida.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  for (int i = 0; i < cant_entrenador; i++){
    
    acumulador_poder_poke = 0; // El acumulador estara en 0 para cada entrenador
    
    cout << "\nEntrenador #" << (i + 1) << endl;
    cout << "\nDigite el nombre del entrenador: ";
    cin >> lista_entrenador[i].nombre_apellido;
    
    string name_txt = lista_entrenador[i].nombre_apellido + ".txt";
    
    string str = name_txt.c_str();
    string str2 = "pokemones/";

    string archivo = str2 + str;

    archivo_salida_pokemon.open(archivo, ios::out); // Creando el archivo con el nombre del entrenador.
 
    if (archivo_salida_pokemon.fail()){
      cout << "Presentamos fallas tecnicas.";
    }
    
    cout << "Digite el numero de licencia: ";
    cin >> lista_entrenador[i].num_licencia;
    cout << "Digite su edad: ";
    cin >> lista_entrenador[i].edad;
    cout << "Digite su sexo: ";
    cin >> lista_entrenador[i].sexo;
    
    while (lista_entrenador[i].sexo != 'm' && lista_entrenador[i].sexo != 'f'){
      cout << "\nSexo invalido" << endl;
      cout << "\nDigite su sexo: ";
      cin >> lista_entrenador[i].sexo;
    }
    
    cout << "Digite el nombre de su region: ";
    cin >> lista_entrenador[i].region;
    

    cout << "\nHola " << lista_entrenador[i].nombre_apellido << " tus datos fueron registrados con exito";
    cout << " Ahora pasaremos a registrar los pokemones de tu pokedex\n";
    cout << "\nDigite la cantidad de pokemones que tienes en tu pokedex: ";
    cin >> cant_pokemones;

    while (cant_pokemones > 6){
      cout << "\nCantidad de pokemones invalida" << endl;
      cout << "\nDigite la cantidad de pokemones que tienes en tu pokedex: ";
      cin >> cant_pokemones;
    }
    
    for (int i = 0; i < cant_pokemones; i++){

      cout << "\nPokemon #" << (i+1) << endl;
      cout << "\nIngrese el nombre del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.nombre_pokemon;
      cout << "Ingrese el tipo de pokemon: ";
      cin >> lista_entrenador[i].lista_poke.tipo_poke;
      cout << "Ingrese el sexo del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.sexo_poke;

      while (lista_entrenador[i].lista_poke.sexo_poke != 'm' && lista_entrenador[i].lista_poke.sexo_poke != 'f'){
      cout << "\nSexo invalido" << endl;
      cout << "\nIngrese el sexo del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.sexo_poke;
    }
      
      cout << "Ingrese el nivel del pokemon: ";
      cin >> lista_entrenador[i].lista_poke.nivel;
      
      lista_entrenador[i].lista_poke.cantidad_poder = lista_entrenador[i].lista_poke.nivel * 2000;
      
      cout << "\nLa cantidad de poder de su pokemon es de: " << lista_entrenador[i].lista_poke.cantidad_poder;
      acumulador_poder_poke += lista_entrenador[i].lista_poke.cantidad_poder;

      archivo_salida_pokemon << lista_entrenador[i].lista_poke.nombre_pokemon << " " << lista_entrenador[i].lista_poke.tipo_poke << " " << lista_entrenador[i].lista_poke.sexo_poke << " " << lista_entrenador[i].lista_poke.nivel << " " << lista_entrenador[i].lista_poke.cantidad_poder << endl;
      
    }

    archivo_salida_pokemon.close(); // Cerramos archivo


    lista_entrenador[i].nivel_poder = acumulador_poder_poke / cant_pokemones;
    cout << "\nTu nivel de poder es de: " << lista_entrenador[i].nivel_poder << endl;

    archivo_salida << lista_entrenador[i].nombre_apellido << " " << lista_entrenador[i].num_licencia << " " << lista_entrenador[i].edad << " " << lista_entrenador[i].sexo << " " <<  lista_entrenador[i].region << " " << lista_entrenador[i].nivel_poder << endl;

  }

  archivo_salida.close(); // cerramos archivo
  
}

void imprimir_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador){
  
  ifstream archivo_entrenador;

  archivo_entrenador.open("entrenadores/ENTRENADORES.txt");

  if (archivo_entrenador.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  for (int i = 0; i < TAM; i++){
    
    archivo_entrenador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;

    while(archivo_entrenador.good()){
      
      cout << "\n----------Entrenador---------\n";
      cout << "Nombre del entrenador: " << lista_entrenador[i].nombre_apellido;
      cout << "\nNumero de licencia: " << lista_entrenador[i].num_licencia;
      cout << "\nEdad: " << lista_entrenador[i].edad;
      cout << "\nsexo: " << lista_entrenador[i].sexo;
      cout << "\nRegion: " << lista_entrenador[i].region;
      cout << "\nNivel: " << lista_entrenador[i].nivel_poder;
      cout << "\n\n";

      archivo_entrenador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
      
    }
    
  }

  archivo_entrenador.close();
  
}

void imprimir_pokemon(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia){

  ifstream archivo_buscador;
  ifstream archivo_pokemon;

  archivo_buscador.open("entrenadores/ENTRENADORES.txt");

  if (archivo_buscador.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  for (int i = 0; i < TAM; i++){
    
    archivo_buscador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
    
    if (licencia == lista_entrenador[i].num_licencia){

    string name_txt = lista_entrenador[i].nombre_apellido + ".txt";
    string str = name_txt.c_str();
    string str2 = "pokemones/";

    string archivo = str2 + str;
      
      archivo_pokemon.open(archivo);
      
      if (archivo_pokemon.fail()){
        cout << "Presentamos fallas tecnicas.";
      }

      for (int i = 0; i < TAM; i++){
        
        archivo_pokemon >> lista_entrenador[i].lista_poke.nombre_pokemon >> lista_entrenador[i].lista_poke.tipo_poke >> lista_entrenador[i].lista_poke.sexo_poke >> lista_entrenador[i].lista_poke.nivel >> lista_entrenador[i].lista_poke.cantidad_poder;

        while(archivo_pokemon.good()){
          
          cout << "\n----------Pokemon---------\n";
          cout << "Nombre del pokemon: " << lista_entrenador[i].lista_poke.nombre_pokemon << endl;
          cout << "Tipo de pokemon: " << lista_entrenador[i].lista_poke.tipo_poke << endl;
          cout << "Sexo del pokemon: " << lista_entrenador[i].lista_poke.sexo_poke << endl;
          cout << "Nivel del pokemon: " << lista_entrenador[i].lista_poke.nivel << endl;
          lista_entrenador[i].lista_poke.cantidad_poder = lista_entrenador[i].lista_poke.nivel * 2000;
          cout << "La cantidad de poder de el pokemon es de: " << lista_entrenador[i].lista_poke.cantidad_poder;
          cout << "\n";
          
          archivo_pokemon >> lista_entrenador[i].lista_poke.nombre_pokemon >> lista_entrenador[i].lista_poke.tipo_poke >> lista_entrenador[i].lista_poke.sexo_poke >> lista_entrenador[i].lista_poke.nivel >> lista_entrenador[i].lista_poke.cantidad_poder;

        }
        
      }
      archivo_pokemon.close();
    }
  }
  archivo_buscador.close();
}

void encontrar_licencia(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia){
  
  ifstream archivo_buscador;

  archivo_buscador.open("entrenadores/ENTRENADORES.txt");

  if (archivo_buscador.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  for (int i = 0; i < TAM; i++){
    
    archivo_buscador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
    
    if (licencia == lista_entrenador[i].num_licencia){
      
      cout << "\nLicencia encontrada\n";

      cout << "\n----------Entrenador----------\n";
      cout << "Nombre del entrenador: " << lista_entrenador[i].nombre_apellido << endl;
      cout << "Numero de licencia: " << lista_entrenador[i].num_licencia << endl;
      cout << "Edad: " << lista_entrenador[i].edad << endl;
      cout << "Sexo: " << lista_entrenador[i].sexo << endl;
      cout << "Region: " << lista_entrenador[i].region << endl;
      cout << "Nivel de poder: " << lista_entrenador[i].nivel_poder << endl;
      
    }
  }

  archivo_buscador.close();
  
}

void enfrentar(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia, int licencia_2){

  ifstream archivo_buscador;
  ofstream archivo_pelea;

  archivo_pelea.open("batallas_poder/ENFRENTAMIENTOS.txt", ios::app); // Abrir el archivo en modo añadir
  
  if (archivo_pelea.fail()){
    cout << "Presentamos fallas tecnicas.";
  }
  
  archivo_buscador.open("entrenadores/ENTRENADORES.txt");

  if (archivo_buscador.fail()){
    cout << "Presentamos fallas tecnicas.";
  }
  
  string peleador_1;
  float poder_1;
  
  string peleador_2;
  float poder_2; 

  string ganador;
  
for (int i = 0; i < TAM; i++){

  archivo_buscador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
  
    if(licencia == lista_entrenador[i].num_licencia){

      peleador_1 = lista_entrenador[i].nombre_apellido;
      poder_1 = lista_entrenador[i].nivel_poder;
      
    }
  
  }
  
for (int i = 0; i < TAM; i++){

  archivo_buscador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;

    if (licencia_2 == lista_entrenador[i].num_licencia){

      peleador_2 = lista_entrenador[i].nombre_apellido;
      poder_2 = lista_entrenador[i].nivel_poder;
      
    }
    
  }
  
  cout << "\nEnfrentamiento entre " << peleador_1 << " & " << peleador_2 << endl;

  if (poder_1 > poder_2){

    ganador = peleador_1;
    archivo_pelea << "Ganador: " << peleador_1 << " Perdedor: " << peleador_2 << endl;
    
  }
  else {
    
    ganador = peleador_2;
    archivo_pelea << "Ganador: " << peleador_2 << " Perdedor: " << peleador_1 << endl;
    
  }
  
  cout << "\n> Peleando... " << endl;

  delay(5);

  cout << "\n> [ El ganador es " << ganador << " ]"<< endl;

  archivo_pelea.close();
  
  archivo_buscador.close();
  
}

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void fuerte_debil(Entrenador lista_entrenador[TAM], int cant_entrenador){

  ofstream archivo_fuerza;
  ifstream entrenador_fuerza;

  float mayor = 0, menor;
  
  string fuerte, debil;

  entrenador_fuerza.open("entrenadores/ENTRENADORES.txt", ios::in);
  archivo_fuerza.open("batallas_poder/FUERTE_DEBIL.txt");

  for(int i = 0; i < TAM; i++){

    entrenador_fuerza >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
    
    if (lista_entrenador[i].nivel_poder > mayor){
      
      mayor = lista_entrenador[i].nivel_poder;
        
      fuerte = lista_entrenador[i].nombre_apellido;

    }
  }

  menor = mayor;

  for(int i = 0; i < lista_entrenador[i].nivel_poder; i++){

    entrenador_fuerza >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
    
    if (lista_entrenador[i].nivel_poder < menor){
        
      menor = lista_entrenador[i].nivel_poder;
        
      debil = lista_entrenador[i].nombre_apellido;
        
    }
  }

  archivo_fuerza << "Fuerte: " << fuerte << " " << mayor << "\n" << "Debil: " << debil << " " << menor;

  cout << "\n> [ ¡Los entrenadores fueron guardados con exito! ]\n";

  archivo_fuerza.close();
  entrenador_fuerza.close();
  
}

void lista_pokemones(Entrenador lista_entrenador[TAM], int cant_entrenador, string nombre){
  
  ifstream archivo_buscador;
  ifstream archivo_pokemon;

  archivo_buscador.open("entrenadores/ENTRENADORES.txt");

  if (archivo_buscador.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  for (int i = 0; i < TAM; i++){
    
    archivo_buscador >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
    
    if (nombre == lista_entrenador[i].nombre_apellido){

    string name_txt = lista_entrenador[i].nombre_apellido + ".txt";
      
    string str = name_txt.c_str();
    string str2 = "pokemones/";

    string archivo = str2 + str;
      
    archivo_pokemon.open(archivo);
      
      if (archivo_pokemon.fail()){
        cout << "Presentamos fallas tecnicas.";
      }

      for (int i = 0; i < TAM; i++){
        
        archivo_pokemon >> lista_entrenador[i].lista_poke.nombre_pokemon >> lista_entrenador[i].lista_poke.tipo_poke >> lista_entrenador[i].lista_poke.sexo_poke >> lista_entrenador[i].lista_poke.nivel >> lista_entrenador[i].lista_poke.cantidad_poder;

        while(archivo_pokemon.good()){
          
          cout << "\n--------Pokemon--------" << endl;
          cout << "\nNombre del pokemon: " << lista_entrenador[i].lista_poke.nombre_pokemon << endl;
          cout << "Tipo de pokemon: " << lista_entrenador[i].lista_poke.tipo_poke << endl;
          cout << "Sexo del pokemon: " << lista_entrenador[i].lista_poke.sexo_poke << endl;
          cout << "Nivel del pokemon: " << lista_entrenador[i].lista_poke.nivel << endl;
          lista_entrenador[i].lista_poke.cantidad_poder = lista_entrenador[i].lista_poke.nivel * 2000;
          cout << "La cantidad de poder de el pokemon es de: " << lista_entrenador[i].lista_poke.cantidad_poder;
          cout << "\n";
          
          
          archivo_pokemon >> lista_entrenador[i].lista_poke.nombre_pokemon >> lista_entrenador[i].lista_poke.tipo_poke >> lista_entrenador[i].lista_poke.sexo_poke >> lista_entrenador[i].lista_poke.nivel >> lista_entrenador[i].lista_poke.cantidad_poder;

        }
      }
      archivo_pokemon.close();
    }
  }
  archivo_buscador.close();
}

void imprimir_enfrentamiento(){
  
  ifstream archivo_enfrentamiento;
  string texto;

  archivo_enfrentamiento.open("batallas_poder/ENFRENTAMIENTOS.txt");

  if (archivo_enfrentamiento.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  cout << "\n-----------Enfrentamientos-----------\n";
  
  while(!archivo_enfrentamiento.eof()){
    
    getline(archivo_enfrentamiento, texto);
    
    cout << "\n" << texto << "\n";
    
  }

  archivo_enfrentamiento.close();
    
}

void imprimir_fuerte_debil(){
  
  ifstream archivo_fuerte_debil;
  string texto;

  archivo_fuerte_debil.open("batallas_poder/FUERTE_DEBIL.txt");

  if (archivo_fuerte_debil.fail()){
    cout << "Presentamos fallas tecnicas.";
  }

  cout << "\n-----------Fuerte & Debil-----------\n";
  
  while(!archivo_fuerte_debil.eof()){
    
    getline(archivo_fuerte_debil, texto);
    
    cout << "\n" << texto << "\n";
    
  }

  archivo_fuerte_debil.close();
    
}

void editar_entrenador(Entrenador lista_entrenador[TAM], int cant_entrenador, int licencia){

  ifstream archivo_entrenadores;
  ofstream archivo_aux;

  char sexo_aux;
  string region_aux;
  int edad_aux;
  
  archivo_entrenadores.open("entrenadores/ENTRENADORES.txt", ios::in);
  archivo_aux.open("entrenadores/Auxiliar.txt", ios::out);

  for(int i = 0; i < TAM; i++){
    
    archivo_entrenadores >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;

    while(archivo_entrenadores.good()){

    if (lista_entrenador[i].num_licencia == licencia){

      cout << "\n----------Entrenador----------\n";
      cout << "Digite su nueva edad: ";
      cin >> edad_aux;
      cout << "Ingrese su nuevo sexo: ";
      cin >> sexo_aux;
      while (sexo_aux != 'm' && sexo_aux != 'f'){
      cout << "\nSexo invalido" << endl;
      cout << "\nDigite su nuevo sexo: ";
      cin >> sexo_aux;
      }
      cout << "Ingrese su nueva region: ";
      cin >> region_aux;

      archivo_aux << lista_entrenador[i].nombre_apellido << " " << lista_entrenador[i].num_licencia << " " << edad_aux << " " << sexo_aux << " " << region_aux << " " << lista_entrenador[i].nivel_poder << endl;
    }
    else{
      
      archivo_aux << lista_entrenador[i].nombre_apellido << " " << lista_entrenador[i].num_licencia << " " << lista_entrenador[i].edad << " " << lista_entrenador[i].sexo << " " << lista_entrenador[i].region << " " << lista_entrenador[i].nivel_poder << endl;
      }
      
      archivo_entrenadores >> lista_entrenador[i].nombre_apellido >> lista_entrenador[i].num_licencia >> lista_entrenador[i].edad >> lista_entrenador[i].sexo >> lista_entrenador[i].region >> lista_entrenador[i].nivel_poder;
      
    }
    
  }

  archivo_aux.close();
  archivo_entrenadores.close();

  remove("entrenadores/ENTRENADORES.txt");
  rename("entrenadores/Auxiliar.txt", "entrenadores/ENTRENADORES.txt");
  
}
