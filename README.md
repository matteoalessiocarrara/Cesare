# Cesare #

Software per codificare/decodifcare una stringa ASCII usando il cifrario di Cesare

## Sintassi ##

cesare (-c | -d) offset stringa

## Funzionamento ##

Cesare prende in input una stringa ASCII-7bit e "sposta" i caratteri a-z A-Z di "offset" posizioni, quindi stampa la nuova stringa. Le opzioni sono:

* -c	Codifica la stringa (+offset)
* -d 	Decodifica la stringa (-offset)

## Limiti ##

* I caratteri utilizzabili sono solo quelli ASCII 7 bit ("char")
* L'offset massimo è LONG_LONG_MAX (limits.h), il tipo restituito da atoll(). Comumque, offset maggiori o uguali a NLETTERE (26) non hanno senso e verranno convertiti automaticamente
* La lunghezza massima della stringa è ULONG_LONG_MAX

## Altre informazioni ##

> This is the Unix philosophy: Write programs that do one thing and do it well. Write programs to work together. Write programs to handle text streams, because that is a universal interface.  

Aggiornamenti: [GitHub] (https://github.com/matteoalessiocarrara)  
Email: sw.matteoac@gmail.com
 
