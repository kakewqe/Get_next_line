# 📄 get_next_line

## 🇬🇧 English

The goal of this project is to read a line from a file descriptor, one line at a time.

---

## Description

**get_next_line** is a function that returns a line read from a file descriptor.

This project helps you better understand:

* static variables
* file descriptors
* memory management
* buffering and reading from files

---

## Function Prototype

char *get_next_line(int fd);

---

## How it works

* Reads from a file descriptor (fd)
* Returns one line at a time, including the newline (\n) if present
* Keeps the remaining content for the next call using a static variable
* Returns NULL when:

  * there is nothing left to read
  * an error occurs

---

## Compilation

make

---

## Usage

gcc main.c get_next_line.c get_next_line_utils.c

---

## Example

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int fd = open("file.txt", O_RDONLY);
char *line;

```
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
return (0);
```

}

---

## Skills Developed

* C programming
* static variables
* file I/O
* memory management
* buffer handling
* algorithm optimization

---

# 📄 get_next_line

## 🇫🇷 Français

Le but de ce projet est de lire une ligne depuis un descripteur de fichier, une ligne à la fois.

---

## Description

**get_next_line** est une fonction qui retourne une ligne lue depuis un file descriptor.

Ce projet permet de mieux comprendre :

* les variables statiques
* les file descriptors
* la gestion mémoire
* la lecture avec buffer

---

## Prototype de la fonction

char *get_next_line(int fd);

---

## Fonctionnement

* Lit depuis un file descriptor (fd)
* Retourne une ligne à la fois, incluant \n si présent
* Garde le reste du buffer pour les appels suivants avec une variable statique
* Retourne NULL si :

  * il n’y a plus rien à lire
  * une erreur survient

---

## Compilation

make

---

## Utilisation

gcc main.c get_next_line.c get_next_line_utils.c

---

## Exemple

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int fd = open("file.txt", O_RDONLY);
char *line;

```
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
return (0);
```

}

---

## Compétences travaillées

* langage C
* variables statiques
* gestion des fichiers
* gestion mémoire
* manipulation de buffers
* optimisation
