#include "gestionvideojuegos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Admin.h"

//carga de videojuegos hardcodeados al archivo

void administarJuegos()
{
 int opcion;
 int dimensionArchi = 0;
 Videojuego *listaHardcodeados = NULL;
 Videojuego *arregloJuegos = NULL;
 // Verificamos si el archivo ya tiene videojuegos
 dimensionArchi = obtenDimArchivoVideojuegos();
 if (dimensionArchi == 0) // Si el archivo esta vacio, cargamos los hardcodeados
 {
  if (cargarHardcodeadosAlArchivo() == -1)
  {
    printf("Error al cargar los videojuegos iniciales.\n");
    return;
  }
  dimensionArchi = obtenDimArchivoVideojuegos();
  }
  // Cargamos los videojuegos del archivo a memoria
  listaHardcodeados = cargarArregloHardcodeados(dimensionArchi);
  if (listaHardcodeados == NULL)
  {
    printf("Error al cargar el arreglo de videojuegos.\n");
    return;
  }
  arregloJuegos = crearArregloJuegos(&dimensionArchi, listaHardcodeados);
  free(listaHardcodeados);
  if (arregloJuegos == NULL)
  {
   printf("Error al reservar memoria.\n");
   return ;
  }
  do
  {
    printf("\n========== MENU DE JUEGOS ==========\n");
    printf("[1] Ver listado de juegos.\n");
    printf("[2] Cargar un nuevo juego.\n");
    printf("[3] Modificar un juego.\n");
    printf("[0] Salir.\n");
    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);
    if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
    {
     printf("\nOpcion invalida. Intente nuevamente.\n");
     opcion = 0;
     continue;
    }
    switch (opcion)
    {
     case 1:
     mostrarJuegos(arregloJuegos, dimensionArchi);
     break;
     case 2:
     arregloJuegos = agregarJuegos(&dimensionArchi,arregloJuegos);
     break;
     case 3:
     modificarJuego(arregloJuegos, dimensionArchi);
     break;
     case 0:
     printf("\nSaliendo del menu de juegos...\n");
     break;
     default:
     printf("\nOpcion incorrecta. Intente nuevamente.\n");
     break;
    }
  } while (opcion != 0);
  free(arregloJuegos);
  return ;
}

int cargarHardcodeadosAlArchivo()
{
    Videojuego listadoJuegosHardcodeado[] =
    {
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
        {"23", "Clash Royale", "RTS", "Movil", 1}
    };

    int i = 0;
    int cantidadJuegosHC = sizeof(listadoJuegosHardcodeado) / sizeof(listadoJuegosHardcodeado[0]); //obtiene la cantidad total de videojuegos

    FILE *archivoJuegos = fopen("Juegos.bin", "ab"); //AB para que no sobreescriba los contenidos del archivo
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


Videojuego *cargarArregloHardcodeados(int cantidadHardcodeados)
{
    FILE *archivo = fopen("Juegos.bin", "rb");
    if (archivo == NULL || cantidadHardcodeados <= 0) //verificacion
    {
        if (archivo != NULL)
        {
            fclose(archivo);
        }
        return NULL;
    }
    Videojuego *listaHardcodeados = calloc((size_t)cantidadHardcodeados, sizeof(Videojuego)); // reserva de mem. dinamica
    if (listaHardcodeados == NULL) //verificacion
    {
        fclose(archivo);
        return NULL;
    }
    if (fread(listaHardcodeados, sizeof(Videojuego), cantidadHardcodeados, archivo) != cantidadHardcodeados) //mas verificaciones + guarda contenido en listaHardcodeados
    {
        free(listaHardcodeados);
        fclose(archivo);
        return NULL;
    }
    fclose(archivo);
    return listaHardcodeados;
}



int obtenDimArchivoVideojuegos()
{
    FILE *archivo = fopen("Juegos.bin", "rb");
    int dimension;
    if (archivo == NULL)
    {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    dimension = ftell(archivo) / sizeof(Videojuego);
    fclose(archivo);
    return dimension;
}

Videojuego *crearArregloJuegos(int* dimensionArchi, Videojuego listaHardcodeados[])
{
    Videojuego *arregloJuegos;
    if (dimensionArchi == NULL || *dimensionArchi <= 0 || listaHardcodeados == NULL) //verif.
    {
        return NULL;
    }
    arregloJuegos = calloc((size_t)*dimensionArchi, sizeof(Videojuego)); //reserva dinam. de mem.
    if (arregloJuegos == NULL)
    {
        return NULL;
    }
    memcpy(arregloJuegos, listaHardcodeados, (size_t)*dimensionArchi * sizeof(Videojuego)); //copia en arregloJuegos lo que hay en listahardcodeados
    //
    return arregloJuegos;
}

Videojuego *agregarJuegos(int* dimensionArchi, Videojuego arregloJuegos[])
{
    int cantidadNuevos;
    int i;
    FILE *archivo;
    if (dimensionArchi == NULL)
    {
        return arregloJuegos;
    }
    printf("\n¿Cuantos videojuegos desea agregar?: ");
    scanf("%d", &cantidadNuevos);
    getchar();
    if (cantidadNuevos <= 0)
    {
        printf("\nCantidad invalida.\n");
        return arregloJuegos;
    }
    Videojuego *nuevoArregloJuegos = redimensionarArregloJuegos(arregloJuegos, *dimensionArchi + cantidadNuevos);
    if (nuevoArregloJuegos == arregloJuegos && nuevoArregloJuegos == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return arregloJuegos;
    }
    archivo = fopen("Juegos.bin", "ab");
    if (archivo == NULL)
    {
        printf("\nError al abrir el archivo.\n");
        return nuevoArregloJuegos;
    }
    for (i = 0; i < cantidadNuevos; i++)
    {
        nuevoArregloJuegos[*dimensionArchi] = agregarJuego(i + 1);
        if (fwrite(&nuevoArregloJuegos[*dimensionArchi], sizeof(Videojuego), 1, archivo) != 1)
        {
            printf("\nError al guardar el videojuego.\n");
            break;
        }
        (*dimensionArchi)++;
        printf("\nVideojuego guardado correctamente.\n");
    }
    fclose(archivo);
    return nuevoArregloJuegos;
}

Videojuego *redimensionarArregloJuegos(Videojuego *arregloJuegos, int nuevaDimension)
{
    Videojuego *aux;
    if (nuevaDimension <= 0)
    {
        return NULL;
    }
    aux = realloc(arregloJuegos, (size_t)nuevaDimension * sizeof(Videojuego));
    if (aux == NULL)
    {
        return arregloJuegos;
    }
    return aux;
}

Videojuego agregarJuego(int nuevaDim)
{
    Videojuego nuevoJuego;
    printf("\n========== NUEVO VIDEOJUEGO %d ==========\n", nuevaDim);
    printf("Ingrese el ID: ");
    scanf(" %9[^\n]", nuevoJuego.idJuego);
    getchar();
    printf("Ingrese el nombre: ");
    scanf(" %49[^\n]", nuevoJuego.nombre);
    getchar();
    printf("Ingrese el genero: ");
    scanf(" %29[^\n]", nuevoJuego.genero);
    getchar();
    printf("Ingrese la plataforma: ");
    scanf(" %19[^\n]", nuevoJuego.plataforma);
    getchar();
    nuevoJuego.activo = 1;
    return nuevoJuego;
}


void mostrarUnJuego(Videojuego juego)
{
    printf("\nID: %s", juego.idJuego);
    printf("\nNombre: %s", juego.nombre);
    printf("\nGenero: %s", juego.genero);
    printf("\nPlataforma: %s", juego.plataforma);
    printf("\nEstado: %s\n", juego.activo ? "Activo" : "Inactivo");
}

void mostrarJuegos(Videojuego arregloJuegos[], int dimension)
{
    int i;
    if (arregloJuegos == NULL || dimension <= 0)
    {
        printf("\nNo hay videojuegos cargados.\n");
        return;
    }
    printf("\n========== LISTADO DE VIDEOJUEGOS ==========\n");

    for (i = 0; i < dimension; i++)
    {
        mostrarUnJuego(arregloJuegos[i]);
        printf("--------------------------------------------\n");
    }
}

void modificarJuego(Videojuego arregloJuegos[], int dimension)
{
    char idBuscado[10];
    int i;
    int encontrado = 0;
    FILE *archivo;
    if (arregloJuegos == NULL || dimension <= 0)
    {
        printf("\nNo hay videojuegos para modificar.\n");
        return;
    }
    printf("\nIngrese el ID del videojuego que desea modificar: ");
    scanf(" %9[^\n]", idBuscado);
    getchar();
    for (i = 0; i < dimension; i++)
    {
        if (strcmp(arregloJuegos[i].idJuego, idBuscado) == 0)
        {
            encontrado = 1;
            printf("\nVideojuego encontrado:\n");
            mostrarUnJuego(arregloJuegos[i]);
            printf("\nIngrese el nuevo nombre: ");
            scanf(" %49[^\n]", arregloJuegos[i].nombre);
            getchar();
            printf("Ingrese el nuevo genero: ");
            scanf(" %29[^\n]", arregloJuegos[i].genero);
            getchar();
            printf("Ingrese la nueva plataforma: ");
            scanf(" %19[^\n]", arregloJuegos[i].plataforma);
            getchar();
            printf("Ingrese el estado (1 = Activo / 0 = Inactivo): ");
            scanf("%d", &arregloJuegos[i].activo);
            getchar();
            archivo = fopen("Juegos.bin", "wb");
            if (archivo == NULL)
            {
                printf("\nError al abrir el archivo.\n");
                return;
            }
            if (fwrite(arregloJuegos, sizeof(Videojuego), dimension, archivo) != dimension)
            {
                printf("\nError al guardar los cambios.\n");
            }
            else
            {
                printf("\nVideojuego modificado correctamente.\n");
            }
            fclose(archivo);
            break;
        }
    }
    if (!encontrado)
    {
        printf("\nNo se encontro ningun videojuego con ese ID.\n");
    }
}

void mostrarVideojuegosArchivo(char nombreArchivo[])
{
    FILE *arch = fopen(nombreArchivo, "rb");
    Videojuego aux;
    if (arch == NULL)
    {
        printf("No se pudo abrir el archivo de videojuegos.\n");
        return;
    }
    printf("\n=== LISTADO DE VIDEOJUEGOS ===\n");
    while (fread(&aux, sizeof(Videojuego), 1, arch) > 0)
    {
        printf("ID: %s | Nombre: %s | Genero: %s | Plataforma: %s | Estado: %s\n", aux.idJuego,
               aux.nombre,
               aux.genero,
               aux.plataforma,
               (aux.activo == 1) ? "Activo" : "Inactivo");
    }
    printf("==============================\n\n");
    fclose(arch);
}

void modificarJuegoo(Videojuego arregloJuegos[], int dimension)
{
  char idBuscado[10];
  int i;
  int encontrado = 0;
  FILE *archivo;
  if (arregloJuegos == NULL || dimension <= 0)
  {
    printf("\nNo hay videojuegos para modificar.\n");
    return;
  }
  printf("\nIngrese el ID del videojuego que desea modificar: ");
  scanf(" %9[^\n]", idBuscado);
  getchar();
  for (i = 0; i < dimension; i++)
  {
    if (strcmp(arregloJuegos[i].idJuego, idBuscado) == 0)
    {
     encontrado = 1;
     printf("\nVideojuego encontrado:\n");
     mostrarUnJuego(arregloJuegos[i]);
     printf("\nIngrese el nuevo nombre: ");
     scanf(" %49[^\n]", arregloJuegos[i].nombre);
     getchar();
     printf("Ingrese el nuevo genero: ");
     scanf(" %29[^\n]", arregloJuegos[i].genero);
     getchar();
     printf("Ingrese la nueva plataforma: ");
     scanf(" %19[^\n]", arregloJuegos[i].plataforma);
     getchar();
     printf("Ingrese el estado (1 = Activo / 0 = Inactivo): ");
     scanf("%d", &arregloJuegos[i].activo);
     getchar();
     archivo = fopen("Juegos.bin", "wb");
     if (archivo == NULL)
     {
      printf("\nError al abrir el archivo.\n");
      return;
     }
     if (fwrite(arregloJuegos, sizeof(Videojuego), dimension, archivo) != dimension)
     {
      printf("\nError al guardar los cambios.\n");
     }
     else
     {
      printf("\nVideojuego modificado correctamente.\n");
     }
      fclose(archivo);
      break;
    }
  }
  if (!encontrado)
  {
   printf("\nNo se encontro ningun videojuego con ese ID.\n");
  }
}
