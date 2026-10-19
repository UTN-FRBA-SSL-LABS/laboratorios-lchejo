#ifndef CONVERSION_H
#define CONVERSION_H

/*
 * Conversion.h — Operaciones de conversion entre tipos
 *
 * Nota de diseño: ToInteger no forma parte de la biblioteca String
 * porque su dominio de entrada es String pero su codominio es Integer,
 * cruzando la frontera entre tipos. Se separa aqui para mantener
 * la cohesion de cada modulo.
 */

/* ToInteger: String -> Integer
 * Pre:  s != NULL, s representa un entero valido en base 10
 *       (digitos con signo '-' opcional al inicio)
 * Post: devuelve el valor entero correspondiente a la cadena */
int ToInteger(const char *s);

/* IsInteger: String -> Boolean
 * Pre:  s != NULL
 * Post: devuelve 1 si s representa un entero decimal valido en base 10
 *       (digitos con signo '-' opcional al inicio, al menos un digito);
 *       devuelve 0 en caso contrario (cadena vacia, solo signo, espacios,
 *       caracteres no digito, signos repetidos, etc.) */
int IsInteger(const char *s);

#endif
