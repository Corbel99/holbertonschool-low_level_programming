# 🐞 Intro to Debugging

> Holberton School – Low Level Programming

## 📖 Description

Ce projet a pour objectif d'apprendre les bases du **debugging** (débogage) en langage C.

Contrairement aux projets précédents où l'objectif était principalement d'écrire du code, celui-ci met l'accent sur la compréhension de l'exécution d'un programme afin de détecter et corriger des erreurs de logique.

À l'aide de **Python Tutor**, chaque programme est exécuté étape par étape pour observer :

- l'évolution des variables ;
- le comportement des boucles ;
- les appels de fonctions ;
- les valeurs retournées ;
- le chemin suivi dans les structures conditionnelles.

Le but est de comprendre **pourquoi** un programme produit un mauvais résultat avant de le corriger.

---

## 🎯 Learning Objectives

À la fin de ce projet, je suis capable de :

- Comprendre ce qu'est le debugging.
- Suivre l'exécution d'un programme ligne par ligne.
- Utiliser Python Tutor pour visualiser un programme C.
- Identifier les erreurs de logique.
- Corriger des erreurs de boucles (`for`, `while`).
- Vérifier les valeurs des variables au cours de l'exécution.
- Comprendre les appels de fonctions et les valeurs de retour.
- Produire un programme compilant sans erreur avec GCC.

---

## 🛠️ Technologies

- Language : C
- Compiler : GCC
- Standard : GNU89
- Debugger : Python Tutor

---

## 📂 Project Structure

```text
intro_debugging/
├── sum_to_n.c
├── ...
└── README.md
```

---

## ⚙️ Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 file.c -o program
```

---

## ▶️ Execution

```bash
./program
```

---

## 📚 Concepts Covered

- Variables
- Functions
- Return values
- `for` loops
- `while` loops
- Nested loops
- Conditional statements (`if`, `else`)
- Logic errors
- Step-by-step execution
- Debugging methodology

---

## 🔍 Debugging Workflow

Pour chaque exercice :

1. Lire le code.
2. Comprendre l'objectif de la fonction.
3. Exécuter le programme dans Python Tutor.
4. Observer les variables.
5. Identifier l'erreur logique.
6. Corriger le code.
7. Recompiler.
8. Vérifier le résultat.

---

## 📌 Requirements

Le projet respecte les contraintes suivantes :

- Pas de pointeurs
- Pas de tableaux
- Pas de structures
- Pas d'allocation dynamique
- Pas d'entrées/sorties de fichiers

Compilation obligatoire avec :

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
```

---

## 👨‍💻 Author

Thomas

Student at Holberton School