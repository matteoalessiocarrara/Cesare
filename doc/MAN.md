### Nome

Cesare - software per codificare/decodifcare una stringa ASCII usando il cifrario di Cesare

### Sintassi

cesare (-c | -d) offset stringa

### Descrizione

Cesare prende in input una stringa ASCII-7bit e sposta i caratteri a-z A-Z di "offset" posizioni, quindi stampa la nuova stringa. Le opzioni sono:

* -c	Codifica la stringa (+offset)
* -d 	Decodifica la stringa (-offset)

### Limiti

* I caratteri utilizzabili sono solo quelli ASCII 7 bit
* L'offset massimo è 2^(sizeof(long long)*8-1)-1. Comumque, offset maggiori o uguali a NLETTERE (26) non hanno senso e verranno convertiti automaticamente.
* La lunghezza massima della stringa è 2^(sizeof(unsigned long long)*8)-1 caratteri.
 
