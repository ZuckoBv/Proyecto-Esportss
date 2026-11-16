#include "Torneo.h"
#include "Usuario.h"

void sistemaTorneo()
{
    int opcion;

    const char ARCHIVOTORNEO[]= "Torneo.bin";

    do {

        printf("\n========================================");
        printf("\n          SISTEMA DE TORNEOS");
        printf("\n========================================");
        printf("\n");
        printf("\n  [1]  Cargar nuevo torneo ");
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

            break;

        case 0:

            break;

        default:
            printf ("\n Opcion invalida");
        }
    }  while(opcion!=0);

}



Torneo crearTorneo()
{
    Torneo torneo;

    printf ("Ingrese el ID del torneo: \n");
    while (getchar() != '\n');
    leerString (torneo.idTorneo, 10);

    //FUNCION POR SI YA EXISTE EL ID

    printf ("Ingrese el nombre del torneo: \n");
    leerString (torneo.nombre, 50);

    //FUNCION DE MOSTRAR VIDEOJUEGOS

    printf ("Escriba el ID del videojuego a agregar: \n");
    //FUNCION PARA GUARDAR TODOS LOS DATOS DEL JUEGO AL TORNEO

    printf ("Ingrese la fecha: ");
    scanf ("%d", &torneo.fechaInicio.dia);
    printf ("| ");
    scanf ("%d", &torneo.fechaInicio.mes);
    printf ("| ");
    scanf ("%d",&torneo.fechaInicio.anio);
    printf ("\n");
    printf ("Ingrese la capacidad maxima: ");
    scanf ("%d", &torneo.capacidadMaxima);
    printf ("Ingrese cantidad de cupos disponibles: \n");
    scanf ("%d", &torneo.cuposDisponibles);
    printf ("Ingrese el premio: \n");
    scanf ("%f", &torneo.premioTotal);
    printf ("Estado del torneo: (Abierto, En Curso, Finalizado)\n");
    leerString (torneo.estado, 15);

    return torneo;
}

void cargarTorneoArchivo (const char nombreArchivo [])
{
    char letra = 's';
    Torneo torneo;

    FILE* archivo = fopen (nombreArchivo , "ab");

    if(archivo==NULL)
    {
        printf("\nEl archivo no abrio");
        return;
    }

    while(letra == 's' || letra == 'S')

    {
        torneo = crearTorneo();
        fwrite(&torneo, sizeof(Torneo), 1, archivo);
        printf("\nDesea agregar mas torneos s/n? ");
        scanf(" %c", &letra);

//        system("pause");
//        system ("cls");
    }
    fclose(archivo);
}
