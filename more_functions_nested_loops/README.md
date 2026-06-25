# 🔁 More Functions, More Nested Loops

> Holberton School – Low Level Programming

## 📖 Description

Ce projet approfondit les notions de **fonctions** et de **boucles imbriquées** en langage C.

L'objectif est de renforcer les bases acquises dans le projet précédent en réalisant des fonctions plus variées et en manipulant davantage les structures de contrôle (`if`, `for`, `while`) sans utiliser la bibliothèque standard.

Toutes les sorties sont réalisées avec la fonction `_putchar()`.

---

## 🎯 Learning Objectives

À la fin de ce projet, je suis capable de :

- Créer et utiliser des fonctions.
- Comprendre la différence entre une déclaration et une définition.
- Utiliser des prototypes dans un fichier d'en-tête (`main.h`).
- Manipuler des boucles `for` et `while`.
- Utiliser des boucles imbriquées.
- Comprendre la portée des variables (scope).
- Vérifier des caractères grâce aux codes ASCII.
- Organiser un projet C avec plusieurs fichiers sources.
- Compiler un projet avec GCC en respectant la norme GNU89.

---

## 🛠️ Technologies

- Language : C
- Compiler : GCC
- Standard : GNU89
- Style : Betty

---

## 📂 Project Structure

```text
more_functions_nested_loops/
├── main.h
├── 0-isupper.c
├── 1-isdigit.c
├── 2-mul.c
├── ...
└── README.md
```

---

## ⚙️ Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o program
```

---

## ▶️ Execution

```bash
./program
```

---

## 📚 Concepts Covered

- Functions
- Function prototypes
- Header files
- Nested loops
- `for` loops
- `while` loops
- `if / else`
- ASCII characters
- Return values
- Variable scope
- `_putchar()`

---

## 📌 Project Requirements

- Ubuntu 20.04 LTS
- GCC (`gnu89`)
- Betty style required
- No global variables
- Maximum 5 functions per file
- No use of the standard library (`printf`, `puts`, etc.)
- Only `_putchar()` is allowed
- All prototypes must be declared in `main.h`

---

## 📋 Compilation Flags

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
```

| Flag | Description |
|------|-------------|
| `-Wall` | Enable common warnings |
| `-Wextra` | Enable additional warnings |
| `-Werror` | Treat warnings as errors |
| `-pedantic` | Enforce ISO C compliance |
| `-std=gnu89` | Use the GNU89 C standard |

---

## 👨‍💻 Author

Thomas

Student at Holberton School
