#include "Conversion.h"
#include "String.h"

/*
 * Conversion.c — Implementacion de operaciones de conversion
 *
 * REGLA: no usar atoi, strtol ni ninguna funcion estandar de conversion
 */

/* ── ToInteger — completar siguiendo el README.md ───────────────────────── */

int ToInteger(const char *s) {
    int signo     = 1;
    int resultado = 0;
    if (*s == '-') { signo = -1; s++; }
    for (; *s != '\0'; s++)
        resultado = resultado * 10 + (*s - '0');
    return signo * resultado; 
}

/* ── Operacion libre ─────────────────────────────────────────────────────── */

/*
 * IsInteger — devuelve 1 si s representa un entero decimal valido.
 *
 * Acepta:  "0", "123", "-5", "42"
 * Rechaza: "", "-", "+", " 1", "1 ", "12a", "1.5", "--1"
 *
 * Contrato:
 *   pre:  s != NULL
 *   post: devuelve 1 si s es un entero decimal bien formado, 0 en caso contrario
 */
int IsInteger(const char *s) {
    if (IsEmpty(s)) return 0;        /* cadena vacia: no valido */
    if (*s == '-') s++;              /* signo negativo opcional */
    if (IsEmpty(s)) return 0;        /* solo "-": no valido */
    for (; !IsEmpty(s); s++)
        if (*s < '0' || *s > '9')
            return 0;                /* caracter no digito: no valido */
    return 1;
}
