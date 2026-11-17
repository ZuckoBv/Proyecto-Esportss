#include "Torneo.h"
#include "Usuario.h"
#include "gestionvideojuegos.h"

void sistemaTorneo()
{
    int opcion;

    do
    {

        printf("\n========================================");
        printf("\n          SISTEMA DE TORNEOS");
        printf("\n========================================");
        printf("\n");
        printf("\n  [1]  Cargar nuevo torneo ");
        printf("\n  [2]  Mostrar todos los torneos ");
        printf("\n");
        printf("\n  [0]  Salir");
        printf("\n");
        printf("\n========================================");
        printf("\n  Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cargarTorneoArchivo (ARCHIVOTORNEO);
            break;

        case 2:
            mostrarTorneosArchivo (ARCHIVOTORNEO);
            break;

        case 0:

            break;

        default:
            printf ("\n Opcion invalida");
        }
    }
    while(opcion!=0);

}

Torneo crearTorneo(const char nombreArchivoTorneo [])
{
    Torneo torneo;
    int valido = 0;
    while (getchar() != '\n');

    while (valido == 0)
    {
        printf ("Ingrese el ID del torneo: \n");                   //Bucle para no repetir ID
        leerString (torneo.idTorneo, 10);
        valido = validarIdTorneo (nombreArchivoTorneo, torneo.idTorneo);
    }

    printf ("Ingrese el nombre del torneo: \n");
    leerString (torneo.nombre, 50);

    mostrarVideojuegosDisponibles (ARCHIVOVIDEOJUEGO);
    printf ("Escriba el ID del videojuego a agregar: \n");
    //FUNCION PARA GUARDAR TODOS LOS DATOS DEL JUEGO AL TORNEO

    printf ("Ingrese la fecha: \n");
    printf ("  Dia: ");
    scanf ("%d", &torneo.fechaInicio.dia);
    printf ("  Mes:  ");
    scanf ("%d", &torneo.fechaInicio.mes);
    printf ("  Anio:  ");
    scanf ("%d",&torneo.fechaInicio.anio);

    printf ("\nIngrese la capacidad maxima: \n");
    scanf ("%d", &torneo.capacidadMaxima);
    printf ("Ingrese cantidad de cupos disponibles: \n");
    scanf ("%d", &torneo.cuposDisponibles);
    printf ("Ingrese el premio: \n");
    scanf ("%f", &torneo.premioTotal);
    while (getchar() != '\n');
    printf ("Estado del torneo: (Abierto, En Curso, Finalizado)\n");
    leerString (torneo.estado, 15);

    return torneo;
}

void cargarTorneoArchivo (const char nombreArchivoTorneo [])
{
    char letra = 's';
    Torneo torneo;

    while(letra == 's' || letra == 'S')
    {
        torneo = crearTorneo(nombreArchivoTorneo);              //Creo torneo y valido ID

        FILE* archivo = fopen (nombreArchivoTorneo, "ab");
        if(archivo==NULL)
        {
            printf("\nEl archivo no abrio");                   //Abro archivo, guardo y cierro
            return;
        }
        fwrite(&torneo, sizeof(Torneo), 1, archivo);
        fclose(archivo);

        printf("\nDesea agregar mas torneos s/n? ");
        scanf(" %c", &letra);
    }
}

void mostrarTorneo (Torneo torneo)
{
    printf("\n========================================");
    printf ("\n ID: %s", torneo.idTorneo);
    printf ("\n Nombre: %s", torneo.nombre);
    printf ("\n Videojuego: %s (ID: %s)", torneo.juego.nombre, torneo.juego.idJuego);
    printf ("\n Fecha: %d|%d|%d ", torneo.fechaInicio.dia, torneo.fechaInicio.mes, torneo.fechaInicio.anio);
    printf ("\n Capacidad maxima del torneo: %d", torneo.capacidadMaxima);
    printf ("\n Cupos disponibles: %d", torneo.cuposDisponibles);
    printf ("\n Premio: $%.2f", torneo.premioTotal);
    printf ("\n Estado: %s", torneo.estado);
    printf("\n========================================");
}

void mostrarTorneosArchivo (const char nombreArchivoTorneo [])
{
    Torneo torneo;

    FILE* archivo = fopen (nombreArchivoTorneo, "rb");

    if (archivo == NULL)
    {
        printf ("Error al intentar abrir el archivo\n");
        return;
    }

    while (fread (&torneo, sizeof (Torneo), 1, archivo) == 1)
    {
        mostrarTorneo (torneo);
    }

    fclose (archivo);
}

int validarIdTorneo (const char nombreArchivoTorneo [], char idNuevoTorneo [] )
{
    Torneo torneo;

    FILE* archivo = fopen (nombreArchivoTorneo, "rb");

    if (archivo == NULL)
    {
        printf ("Error al intentar abrir el archivo\n");
        return 1;
    }

    while (fread (&torneo, sizeof (Torneo), 1, archivo) == 1)
    {
        if (strcmp (torneo.idTorneo, idNuevoTorneo) == 0)                 // Comparar con todos los ID
        {
            printf ("Ya existe ese ID \n");
            fclose (archivo);
            return 0;
        }
    }

    fclose (archivo);
    return 1;
}
