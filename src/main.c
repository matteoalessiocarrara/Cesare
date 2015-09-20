/*
 * Copyright 2015 Matteo Alessio Carrara <sw.matteoac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NLETTERE 26 /*'z'-'a'+1*/
#define mod(a, b) (((a) < 0)? (b)+(a) : (a)%(b))

char g_offset; /*offset per la (de)codifica, preso dalla main*/

void help_(char nome[], char msg[])
{
	fprintf(stderr, "%s\nUso: %s (-c | -d) offset stringa\n", msg, nome);
	exit(EXIT_FAILURE);
}

char modifica_d(char c, char l) /*decodifica un carattere*/
{
	
	return mod(c-l-g_offset, NLETTERE)+l;
}

char modifica_c(char c, char l) /*codifica un carattere*/
{
	return mod(c-l+g_offset, NLETTERE)+l;
}

int main(int argc, char **argv)
{
	#define NOME_SW argv[0]
	#define MOD argv[1] /*(-c | -d)*/
	#define MAIN_OFFSET argv[2] /*offset*/
	#define STR argv[3] /*stringa*/

	#define help(msg) help_(NOME_SW, msg)

	register char (*pmodifica) (char c, char l); /*puntatore a funzione modifica_c o modifica_d*/
	
	/*decodifica o codifica un carattere, se possibile*/
	#define modifica(c)\
		((((c) >= 'a') && ((c) <= 'z'))? pmodifica((c), 'a') : (((c) >= 'A') && ((c) <= 'Z'))? pmodifica((c), 'A') : (c))

	if (argc != 3+1)
		help("Numero di parametri errato");
	if((pmodifica = !strcmp("-c", MOD)? modifica_c : !strcmp("-d", MOD)? modifica_d : NULL) == NULL)
		help("-c o -d non trovato");
	
	g_offset = mod(atoll(MAIN_OFFSET), NLETTERE); /*offset >= di NLETTERE sono equivalenti a offset minori*/

	for(register unsigned long long i = 0; STR[i]; i++)
		printf("%c", modifica(STR[i]));
	
	printf("\n");

	return EXIT_SUCCESS;
}