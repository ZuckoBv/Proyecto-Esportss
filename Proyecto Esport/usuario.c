#include "usuario.h"


int main()
{
    char nombreArchivoUsuario[]="usuario.bin";
    return 0;
}

void leerString(char arreglo,int dim)
{
    fgets(arreglo,dimm,stdin);
    arreglo[strcspn(arreglo,"\n")]='\0';
}

void cargarPersona()
{
    Persona a;
    printf("\nIngrese el DNI: ");
    leerString(a.dni,15);
    printf("\nIngrese el Nombre: ");
    leerString(a.nombre,50);
    printf("\nIngrese el Telefono: ");
    leerString(a.telefono,20);
    printf("\nIngrese la Direccion: ");
    leerString(a.direccion,30);
    printf("\nIngrese el Rol: ");
    leerString(a.rol,15);
    return a;
}

void cargarUsaurio()
{
    Usuario u;
    u.persona=cargarPersona();
    printf("\nIngrese un nombre de usuario: ");
    leerString(u.usuario,20);
    printf("\nIngrese una contrasenia: ");
    leerString(u.contrasenia,20);
    return u;
}

void cargarUsuarioArchivo(char nombreArchivo)
{
    char letra='s';
    Usuario a;
    FILE * buffer=fopen(nombreArchivo,"ab");
    if(buffer==NULL)
    {
        printf("\nEl archivo no abrio");
        return -1;
    }
    //trabajo
    while(letra=='s')
    {
        a=cargarUsaurio();
        fwrite(&a,sizeof(Usuario),1,buffer);
        system("pause");
        system ("cls")
        printf("\nDesea seguir cargando usuarios");
        scanf(" %c", &letra);
        system("pause");
        system ("cls")
    }

    //fin
    fclose(buffer);
}

s
