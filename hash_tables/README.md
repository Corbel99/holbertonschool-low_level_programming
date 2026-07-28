# C - Hash Tables

## 📚 Description

Ce projet a pour objectif de comprendre et d'implémenter une **table de hachage (Hash Table)** en langage C.

Une table de hachage est une structure de données permettant d'associer une **clé** (*key*) à une **valeur** (*value*) et de retrouver cette valeur très rapidement.

Contrairement à une recherche dans une liste chaînée, qui nécessite de parcourir les éléments un à un, une table de hachage calcule directement l'emplacement où la donnée doit être stockée ou recherchée.

Ce projet utilise une méthode de gestion des collisions appelée **Separate Chaining**, où chaque case du tableau pointe vers une liste chaînée.

---

# 🎯 Objectifs pédagogiques

À travers ce projet, j'apprends à :

* Comprendre le principe d'une fonction de hachage.
* Comprendre le rôle d'une table de hachage.
* Associer une clé à une valeur.
* Calculer un indice à partir d'une chaîne de caractères.
* Gérer les collisions grâce aux listes chaînées.
* Manipuler des structures dynamiques en C.
* Renforcer ma maîtrise des pointeurs, du `malloc` et du `free`.

---

# 🧠 Fonctionnement général

Une table de hachage suit toujours le même principe :

```text
          Clé (key)
              │
              ▼
     Fonction de hachage
              │
              ▼
     Calcul d'un indice
              │
              ▼
      Tableau de pointeurs
              │
              ▼
       Liste chaînée
              │
              ▼
            Valeur
```

Exemple :

```text
"Thomas"
     │
     ▼
Hash Function
     │
     ▼
2090756197
     │
     ▼
2090756197 % table_size
     │
     ▼
array[5]
```

---

# ⚙️ Les structures utilisées

Chaque élément de la table est représenté par un nœud.

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

Une table de hachage est composée :

* d'une taille (`size`)
* d'un tableau de pointeurs (`array`)

```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

Chaque case du tableau pointe vers le premier élément d'une liste chaînée.

---

# 🔑 La fonction de hachage

Une fonction de hachage transforme une chaîne de caractères en un nombre entier.

Exemple simplifié :

```text
"Thomas"
      │
      ▼
Fonction de hachage
      │
      ▼
2090756197
```

Ce nombre est ensuite ramené dans les limites du tableau grâce à l'opérateur modulo.

```text
2090756197 % table_size
```

Le résultat correspond à l'indice où sera stockée la donnée.

---

# ⚠️ Les collisions

Deux clés différentes peuvent produire le même indice.

Exemple :

```text
"Thomas"
      │
      ▼
array[5]

"Alice"
      │
      ▼
array[5]
```

On parle alors de **collision**.

Dans ce projet, les collisions sont résolues grâce au **Separate Chaining**.

```text
array[5]
    │
    ▼
+---------+
| Thomas  |
+---------+
     │
     ▼
+---------+
| Alice   |
+---------+
     │
     ▼
+---------+
| Lucas   |
+---------+
```

Chaque nouvelle collision ajoute simplement un nœud dans la liste chaînée.

---

# 🚀 Complexité

| Opération   | Complexité moyenne |
| ----------- | ------------------ |
| Insertion   | O(1)               |
| Recherche   | O(1)               |
| Suppression | O(1)               |

En cas de nombreuses collisions :

| Opération | Pire cas |
| --------- | -------- |
| Recherche | O(n)     |

---

# ✅ Avantages

* Recherche très rapide.
* Insertion efficace.
* Suppression rapide.
* Association simple entre une clé et une valeur.
* Utilisée dans de nombreux langages modernes (Python, Java, C++, etc.).

---

# ❌ Inconvénients

* Dépend fortement de la qualité de la fonction de hachage.
* Les collisions peuvent ralentir les performances.
* Les données ne sont pas stockées dans un ordre particulier.

---

# 📂 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

---

# 📝 Auteur

Projet réalisé dans le cadre de la formation **Holberton School**.
# C - Hash Tables

## 📚 Description

Ce projet a pour objectif de comprendre et d'implémenter une **table de hachage (Hash Table)** en langage C.

Une table de hachage est une structure de données permettant d'associer une **clé** (*key*) à une **valeur** (*value*) et de retrouver cette valeur très rapidement.

Contrairement à une recherche dans une liste chaînée, qui nécessite de parcourir les éléments un à un, une table de hachage calcule directement l'emplacement où la donnée doit être stockée ou recherchée.

Ce projet utilise une méthode de gestion des collisions appelée **Separate Chaining**, où chaque case du tableau pointe vers une liste chaînée.

---

# 🎯 Objectifs pédagogiques

À travers ce projet, j'apprends à :

* Comprendre le principe d'une fonction de hachage.
* Comprendre le rôle d'une table de hachage.
* Associer une clé à une valeur.
* Calculer un indice à partir d'une chaîne de caractères.
* Gérer les collisions grâce aux listes chaînées.
* Manipuler des structures dynamiques en C.
* Renforcer ma maîtrise des pointeurs, du `malloc` et du `free`.

---

# 🧠 Fonctionnement général

Une table de hachage suit toujours le même principe :

```text
          Clé (key)
              │
              ▼
     Fonction de hachage
              │
              ▼
     Calcul d'un indice
              │
              ▼
      Tableau de pointeurs
              │
              ▼
       Liste chaînée
              │
              ▼
            Valeur
```

Exemple :

```text
"Thomas"
     │
     ▼
Hash Function
     │
     ▼
2090756197
     │
     ▼
2090756197 % table_size
     │
     ▼
array[5]
```

---

# ⚙️ Les structures utilisées

Chaque élément de la table est représenté par un nœud.

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

Une table de hachage est composée :

* d'une taille (`size`)
* d'un tableau de pointeurs (`array`)

```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

Chaque case du tableau pointe vers le premier élément d'une liste chaînée.

---

# 🔑 La fonction de hachage

Une fonction de hachage transforme une chaîne de caractères en un nombre entier.

Exemple simplifié :

```text
"Thomas"
      │
      ▼
Fonction de hachage
      │
      ▼
2090756197
```

Ce nombre est ensuite ramené dans les limites du tableau grâce à l'opérateur modulo.

```text
2090756197 % table_size
```

Le résultat correspond à l'indice où sera stockée la donnée.

---

# ⚠️ Les collisions

Deux clés différentes peuvent produire le même indice.

Exemple :

```text
"Thomas"
      │
      ▼
array[5]

"Alice"
      │
      ▼
array[5]
```

On parle alors de **collision**.

Dans ce projet, les collisions sont résolues grâce au **Separate Chaining**.

```text
array[5]
    │
    ▼
+---------+
| Thomas  |
+---------+
     │
     ▼
+---------+
| Alice   |
+---------+
     │
     ▼
+---------+
| Lucas   |
+---------+
```

Chaque nouvelle collision ajoute simplement un nœud dans la liste chaînée.

---

# 🚀 Complexité

| Opération   | Complexité moyenne |
| ----------- | ------------------ |
| Insertion   | O(1)               |
| Recherche   | O(1)               |
| Suppression | O(1)               |

En cas de nombreuses collisions :

| Opération | Pire cas |
| --------- | -------- |
| Recherche | O(n)     |

---

# ✅ Avantages

* Recherche très rapide.
* Insertion efficace.
* Suppression rapide.
* Association simple entre une clé et une valeur.
* Utilisée dans de nombreux langages modernes (Python, Java, C++, etc.).

---

# ❌ Inconvénients

* Dépend fortement de la qualité de la fonction de hachage.
* Les collisions peuvent ralentir les performances.
* Les données ne sont pas stockées dans un ordre particulier.

---

# 📂 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

---

# 📝 Auteur

Projet réalisé dans le cadre de la formation **Holberton School**.
# C - Hash Tables

## 📚 Description

Ce projet a pour objectif de comprendre et d'implémenter une **table de hachage (Hash Table)** en langage C.

Une table de hachage est une structure de données permettant d'associer une **clé** (*key*) à une **valeur** (*value*) et de retrouver cette valeur très rapidement.

Contrairement à une recherche dans une liste chaînée, qui nécessite de parcourir les éléments un à un, une table de hachage calcule directement l'emplacement où la donnée doit être stockée ou recherchée.

Ce projet utilise une méthode de gestion des collisions appelée **Separate Chaining**, où chaque case du tableau pointe vers une liste chaînée.

---

# 🎯 Objectifs pédagogiques

À travers ce projet, j'apprends à :

* Comprendre le principe d'une fonction de hachage.
* Comprendre le rôle d'une table de hachage.
* Associer une clé à une valeur.
* Calculer un indice à partir d'une chaîne de caractères.
* Gérer les collisions grâce aux listes chaînées.
* Manipuler des structures dynamiques en C.
* Renforcer ma maîtrise des pointeurs, du `malloc` et du `free`.

---

# 🧠 Fonctionnement général

Une table de hachage suit toujours le même principe :

```text
          Clé (key)
              │
              ▼
     Fonction de hachage
              │
              ▼
     Calcul d'un indice
              │
              ▼
      Tableau de pointeurs
              │
              ▼
       Liste chaînée
              │
              ▼
            Valeur
```

Exemple :

```text
"Thomas"
     │
     ▼
Hash Function
     │
     ▼
2090756197
     │
     ▼
2090756197 % table_size
     │
     ▼
array[5]
```

---

# ⚙️ Les structures utilisées

Chaque élément de la table est représenté par un nœud.

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

Une table de hachage est composée :

* d'une taille (`size`)
* d'un tableau de pointeurs (`array`)

```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

Chaque case du tableau pointe vers le premier élément d'une liste chaînée.

---

# 🔑 La fonction de hachage

Une fonction de hachage transforme une chaîne de caractères en un nombre entier.

Exemple simplifié :

```text
"Thomas"
      │
      ▼
Fonction de hachage
      │
      ▼
2090756197
```

Ce nombre est ensuite ramené dans les limites du tableau grâce à l'opérateur modulo.

```text
2090756197 % table_size
```

Le résultat correspond à l'indice où sera stockée la donnée.

---

# ⚠️ Les collisions

Deux clés différentes peuvent produire le même indice.

Exemple :

```text
"Thomas"
      │
      ▼
array[5]

"Alice"
      │
      ▼
array[5]
```

On parle alors de **collision**.

Dans ce projet, les collisions sont résolues grâce au **Separate Chaining**.

```text
array[5]
    │
    ▼
+---------+
| Thomas  |
+---------+
     │
     ▼
+---------+
| Alice   |
+---------+
     │
     ▼
+---------+
| Lucas   |
+---------+
```

Chaque nouvelle collision ajoute simplement un nœud dans la liste chaînée.

---

# 🚀 Complexité

| Opération   | Complexité moyenne |
| ----------- | ------------------ |
| Insertion   | O(1)               |
| Recherche   | O(1)               |
| Suppression | O(1)               |

En cas de nombreuses collisions :

| Opération | Pire cas |
| --------- | -------- |
| Recherche | O(n)     |

---

# ✅ Avantages

* Recherche très rapide.
* Insertion efficace.
* Suppression rapide.
* Association simple entre une clé et une valeur.
* Utilisée dans de nombreux langages modernes (Python, Java, C++, etc.).

---

# ❌ Inconvénients

* Dépend fortement de la qualité de la fonction de hachage.
* Les collisions peuvent ralentir les performances.
* Les données ne sont pas stockées dans un ordre particulier.

---

# 📂 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

---

# 📝 Auteur

Projet réalisé dans le cadre de la formation **Holberton School**.
# C - Hash Tables

## 📚 Description

Ce projet a pour objectif de comprendre et d'implémenter une **table de hachage (Hash Table)** en langage C.

Une table de hachage est une structure de données permettant d'associer une **clé** (*key*) à une **valeur** (*value*) et de retrouver cette valeur très rapidement.

Contrairement à une recherche dans une liste chaînée, qui nécessite de parcourir les éléments un à un, une table de hachage calcule directement l'emplacement où la donnée doit être stockée ou recherchée.

Ce projet utilise une méthode de gestion des collisions appelée **Separate Chaining**, où chaque case du tableau pointe vers une liste chaînée.

---

# 🎯 Objectifs pédagogiques

À travers ce projet, j'apprends à :

* Comprendre le principe d'une fonction de hachage.
* Comprendre le rôle d'une table de hachage.
* Associer une clé à une valeur.
* Calculer un indice à partir d'une chaîne de caractères.
* Gérer les collisions grâce aux listes chaînées.
* Manipuler des structures dynamiques en C.
* Renforcer ma maîtrise des pointeurs, du `malloc` et du `free`.

---

# 🧠 Fonctionnement général

Une table de hachage suit toujours le même principe :

```text
          Clé (key)
              │
              ▼
     Fonction de hachage
              │
              ▼
     Calcul d'un indice
              │
              ▼
      Tableau de pointeurs
              │
              ▼
       Liste chaînée
              │
              ▼
            Valeur
```

Exemple :

```text
"Thomas"
     │
     ▼
Hash Function
     │
     ▼
2090756197
     │
     ▼
2090756197 % table_size
     │
     ▼
array[5]
```

---

# ⚙️ Les structures utilisées

Chaque élément de la table est représenté par un nœud.

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

Une table de hachage est composée :

* d'une taille (`size`)
* d'un tableau de pointeurs (`array`)

```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

Chaque case du tableau pointe vers le premier élément d'une liste chaînée.

---

# 🔑 La fonction de hachage

Une fonction de hachage transforme une chaîne de caractères en un nombre entier.

Exemple simplifié :

```text
"Thomas"
      │
      ▼
Fonction de hachage
      │
      ▼
2090756197
```

Ce nombre est ensuite ramené dans les limites du tableau grâce à l'opérateur modulo.

```text
2090756197 % table_size
```

Le résultat correspond à l'indice où sera stockée la donnée.

---

# ⚠️ Les collisions

Deux clés différentes peuvent produire le même indice.

Exemple :

```text
"Thomas"
      │
      ▼
array[5]

"Alice"
      │
      ▼
array[5]
```

On parle alors de **collision**.

Dans ce projet, les collisions sont résolues grâce au **Separate Chaining**.

```text
array[5]
    │
    ▼
+---------+
| Thomas  |
+---------+
     │
     ▼
+---------+
| Alice   |
+---------+
     │
     ▼
+---------+
| Lucas   |
+---------+
```

Chaque nouvelle collision ajoute simplement un nœud dans la liste chaînée.

---

# 🚀 Complexité

| Opération   | Complexité moyenne |
| ----------- | ------------------ |
| Insertion   | O(1)               |
| Recherche   | O(1)               |
| Suppression | O(1)               |

En cas de nombreuses collisions :

| Opération | Pire cas |
| --------- | -------- |
| Recherche | O(n)     |

---

# ✅ Avantages

* Recherche très rapide.
* Insertion efficace.
* Suppression rapide.
* Association simple entre une clé et une valeur.
* Utilisée dans de nombreux langages modernes (Python, Java, C++, etc.).

---

# ❌ Inconvénients

* Dépend fortement de la qualité de la fonction de hachage.
* Les collisions peuvent ralentir les performances.
* Les données ne sont pas stockées dans un ordre particulier.

---

# 📂 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

---

# 📝 Auteur

Projet réalisé dans le cadre de la formation **Holberton School**.
