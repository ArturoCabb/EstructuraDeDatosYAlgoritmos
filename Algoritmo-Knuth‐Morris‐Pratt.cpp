/*
    La idea básica es:
    • Se van comparando los caracteres a partir de la posición i del texto con los
    del patrón.
    • Cuando uno no coincide, en el substring del patrón que se tiene antes de la
    no coincidencia, buscamos el máximo prefijo que al mismo tiempo sea
    sufijo de dicho substring.
    • Si no existe, no nos tenemos que regresar ni un carácter en el texto, sólo
    nos regresamos en el patrón a su posición inicial.
    • Si existe un prefijo que es sufijo, y la longitud de este prefijo es k,
    continuamos a partir de la posición i del texto, pero no tenemos que
    regresar a la posición 1 del patrón, sino a la posición 1+k.
    • Este proceso se hace tan hacia atrás como sea necesario, pudiendo llegar a
    iniciar el patrón en su posición 1

    La complejidad en el tiempo es de O(m + n) donde m es del patron y n es lonjitud de texto
*/
#include <iostream>
#include <vector>
#include <string>


