//carga de videojuegos hardcodeados al archivo

int cargarHardcodeadosAlArchivo(char nombreArchivoJuegos[])
{
     Videojuego listadoJuegosHardcodeado[] = {
        {"1", "LoL", "MOBA", "PC", 1},
        {"2", "Dota 2", "MOBA", "PC", 1},
        {"3", "Honor of Kings", "MOBA", "PC", 1},
        {"4", "Counter Strike 2", "Shooter", "PC", 1},
        {"5", "Valorant", "Shooter", "PC", 1},
        {"6", "Rainbow Six Siege", "Shooter", "PC", 1},
        {"7", "Overwatch 2", "Shooter", "PC", 1},
        {"8", "Apex Legends", "Battle Royale", "PC", 1},
        {"9", "PUBG Battlegrounds", "Battle Royale", "PC", 1},
        {"10", "Fortnite", "Battle Royale", "PC", 1},
        {"11", "Starcraft II", "RTS", "PC", 1},
        {"12", "TFT", "RTS", "PC", 1},
        {"13", "Hearthstone", "RTS", "PC", 1},
        {"14", "EA Sports FC", "Sports", "Consola", 1},
        {"15", "Rocket League", "Sports", "PC/Consola", 1},
        {"16", "Simracing", "Sports", "PC", 1},
        {"17", "Street Fighter 6", "Fighting", "PC/Consola", 1},
        {"18", "Tekken 8", "Fighting", "PC/Consola", 1},
        {"19", "Super Smash Bros Ultimate", "Fighting", "PC/Consola", 1},
        {"20", "Super Smash Bros Melee", "Fighting", "PC/Consola", 1},
        {"21", "PUBG Mobile", "Battle Royale", "Movil", 1},
        {"22", "Mobile Legends", "MOBA", "Movil", 1},
        {"23", "Clash Royale", "RTS", "Movil", 1} //formateado con ia para que no se vea horrible pero dejamela pasar
        };
    int i = 0;
    int cantidadJuegosHC = sizeof(listadoJuegosHardcodeado) / sizeof(listadoJuegosHardcodeado[0]); //obtiene la cantidad total de videojuegos

    FILE *archivoJuegos = fopen(nombreArchivoJuegos, "ab"); //AB para que no sobreescriba los contenidos del archivo
    fseek(archivoJuegos, 0, SEEK_SET); //esto es para que SIEMPRE empieze desde el principio del archivo
    if (archivoJuegos == NULL)
    {
        return -1;
    }

    for (i = 0; i < cantidadJuegosHC; i++)
    {
        if (fwrite(&listadoJuegosHardcodeado[i], sizeof(Videojuego), 1, archivoJuegos) != 1) //donde se escribe en el archivo
        {
            fclose(archivoJuegos); //tambien sirve como verificacion, si el archivo no contiene nada, se cierra y retorna -1
            return -1;
        }
    }

    fclose(archivoJuegos);
    return cantidadJuegosHC;
}


Videojuego *cargarArregloHardcodeados(char nombreArchivoJuegos[], int cantidadHardcodeados)
{
    Videojuego temp_array; //arreglo temporal
    int i = 0;

    FILE *archivoJuegos = fopen(nombreArchivoJuegos, "rb");
    Videojuego *listaHardcodeados = calloc((size_t) cantidadHardcodeados, sizeof (Videojuego));
    if (listaHardcodeados == NULL)
    {
     printf("Error al reservar memoria.\n");
     return NULL;
    }
    if (archivoJuegos == NULL)
    {
        return NULL;
    }

    while (fread(&temp_array, sizeof(Videojuego), 1, archivoJuegos) == 1) //"mientras el archivo no este vacio,
    {
        listaHardcodeados[i] = temp_array; //pasa lo que haya de temparray a listaHardcodeados"
        i++;
    }

    fclose(archivoJuegos);

    return listaHardcodeados;
}


int obtenDimArchivoVideojuegos(char nombreArchivoJuegos[])
{
  int i = 0;
  FILE * archivo = fopen(nombreArchivoJuegos, "rb");
  if (archivo == NULL)
  {
    return 0;
  }
 fseek(archivo, 1, SEEK_END); //se posiciona al final
 i = ftell(archivo); //obtiene la cantidad total de bytes del archivo
 int dimensionArchi = i/sizeof(Videojuego); //lo divide por el tamanio de 1 videojuego
 return dimensionArchi;
}

Videojuego *crearArregloJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego listaHardcodeados[])
{
 int i = 0;
 if (dimensionArchi == NULL || *dimensionArchi <= 0) //verifica que la dimension no tenga ningun valor imposible o apunte a null
 {
  return NULL;
 }
 FILE *archivo = fopen(nombreArchivoJuegos, "rb");
 if (archivo == NULL)
 {
  return NULL;
 }
 Videojuego *arregloJuegos = calloc((size_t)*dimensionArchi,sizeof(Videojuego)); //reservo espacio suficiente para todo lo que ya hay en archi
 //ej. lo ya hardcodeado
 if (arregloJuegos == NULL)
 {
   fclose(archivo);
   return NULL;
 }
 for (i; i<dimensionArchi; i++) //comprobamos que no se exceda de la dim.
 {
   arregloJuegos[i] = listaHardcodeados[i]; //"pasa lo que haya de listaHardcodeados a arregloJuegos" (todavia no escribimos en archi)
 }
 fclose(archivo);
 return arregloJuegos;
}

Videojuego *agregarJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego arregloJuegos[])
{
 int i = 0;
 int nuevaDim;
 if (dimensionArchi == NULL || *dimensionArchi <= 0) //verifica que la dimension no tenga ningun valor imposible o apunte a null
 {
  return NULL;
 }
 FILE *archivo = fopen(nombreArchivoJuegos, "ab");
 if (archivo == NULL)
 {
  return NULL;
 }

 if (arregloJuegos == NULL)
 {
   fclose(archivo);
   return NULL;
 }
 printf("Porfavor ingrese la cantidad de nuevos juegos a cargar.");
 scanf("%i", &nuevaDim);
 Videojuego *nuevoArregloJuegos = redimensionarArreglo(arregloJuegos, nuevaDim);
 for (i; i>dimensionArchi; i++) //cargamos todo los hardcodeados, sabemos cuanto son dado a la dim. original
 {
   nuevoArregloJuegos[i] = arregloJuegos[i]; //"pasa lo que haya de listaHardcodeados a el nuevo arregloJuegos"
 }
 for (i; i>nuevaDim; i++) //cargamos todo los hardcodeados, sabemos cuanto son dado a la dim. original
 {
   agregarJuego(nombreArchivoJuegos, nuevaDim);
 }
 fclose(archivo);
 return arregloJuegos;
}

Videojuego *redimensionarArreglo(Videojuego *arregloJuegos, int nuevaDimension)
{
  if (nuevaDimension <= 0)
  {
    return NULL;
  }
  Videojuego *aux = realloc(arregloJuegos, (size_t)nuevaDimension * sizeof(Videojuego));
  if (aux == NULL)
  {
    return arregloJuegos;
  }
  return aux;
}

Videojuego agregarJuego(char nombreArchivoJuegos[], int nuevaDim)
{
  int i = 0;
  FILE *archivo = fopen(nombreArchivoJuegos, "ab");
  for (i; i>nuevaDim; i++)
  {
    fseek(archivo, 0, SEEK_END);
  }
  fclose(archivo);
}
