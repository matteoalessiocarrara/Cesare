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
#define mod(a, b) (((a)<0)?(b)+(a):(a)%(b))

char offset; /*preso dalla main*/

void Help_(char nome[], char msg[])
{
	printf("%s\nUso: %s (-c | -d) offset stringa\n", msg, nome);
	exit(EXIT_FAILURE);
}

char Modifica_D(char c, char l) /*decodifica*/
{
	
	return mod(c-l-offset, NLETTERE)+l;
}

char Modifica_C(char c, char l) /*codifica*/
{
	return mod(c-l+offset, NLETTERE)+l;
}

int main(int argc, char **argv)
{
	#define NOME_SW argv[0]
	#define MOD argv[1] 
	#define MAIN_OFFSET argv[2]
	#define STR argv[3]
	#define Help(msg) Help_(NOME_SW, msg)

	register char (*Modifica) (char c, char l);

	if (argc != 3+1) Help("Numero di parametri errato");
	offset=mod(atoll(MAIN_OFFSET), NLETTERE); /*offset>= di NLETTERE sono equivalenti a offset minori*/
	if((Modifica=(!strcmp("-c", MOD))?Modifica_C:(!strcmp("-d", MOD))?Modifica_D:NULL)==NULL) Help("-c o -d non trovato");
	for(register unsigned long long i=0; STR[i]!='\0'; i++) printf("%c", ((STR[i]>='a')&&(STR[i]<='z'))?Modifica(STR[i], 'a'):((STR[i]>='A')&&(STR[i]<='Z'))?Modifica(STR[i], 'A'):STR[i]);
	printf("\n");
	return EXIT_SUCCESS;
}