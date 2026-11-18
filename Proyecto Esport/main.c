#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "Login.h"
#include "Admin.h"

int main()
{

    int tipoAcceso=login();

    if(tipoAcceso==ACCESO_ADMIN)
    {

        menuAdministrador("administradores.bin");

    }

    else if(tipoAcceso==ACCESO_USUARIO)
    {
        sistemaUsuario();
    }

    return 0;
}
