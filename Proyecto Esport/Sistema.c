#include <stdio.h>
#include <stdlib.h>
#include "modelos.h"
#include "Login.h"
#include "Admin.h"

void iniciarSistema()
{
    int estado = ACCESO_FALLIDO;

    while (estado != SALIR_SISTEMA)
    {
        estado = login();

        if (estado == ACCESO_ADMIN)
        {
            submenuAdministradores("administradores.bin");

        }
    }

    return;
}
