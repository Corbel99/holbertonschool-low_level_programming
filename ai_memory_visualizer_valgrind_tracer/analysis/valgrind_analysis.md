# Rapport d'Analyse Valgrind : `heap_example.c`

## 1. Contexte et Objectif du Programme

Le programme `heap_example.c` est conçu pour illustrer la gestion de la mémoire sur le tas (*heap*) en C à l'aide de la fonction `malloc()`. Il intègre volontairement une erreur de gestion mémoire afin de mettre en évidence la capacité de Valgrind à détecter les fuites de mémoire (*memory leaks*).

---

## 2. Analyse du Rapport Valgrind

Valgrind a identifié une anomalie critique lors de l'exécution du programme.

### Synthèse de l'erreur

| Paramètre | Détail |
| :--- | :--- |
| **Type d'erreur** | Fuite mémoire — *Definitely lost* (définitivement perdue) |
| **Objet concerné** | Allocation dynamique effectuée dans la fonction `person_new()` |
| **Volumétrie** | 6 octets perdus en 1 bloc |
| **Site d'allocation** | `person_new()` (`heap_example.c`, ligne 21) <br> *(Appelée depuis `main()` à la ligne 51)* |

### Explication technique

Le programme alloue de la mémoire sur le tas via `malloc()`, mais ne libère pas l'intégralité des blocs alloués avant de se terminer. Valgrind classe cette fuite comme **"definitely lost"** car, au moment où le programme prend fin, aucun pointeur valide ne pointe plus vers ce bloc mémoire, le rendant totalement inaccessible.

### Cycle de vie de la mémoire

1. **Allocation :** Effectuée sur le tas via `malloc()`.
2. **Durée de validité :** La mémoire reste valide jusqu'à l'exécution d'un `free()`.
3. **État final :** Aucun `free()` correspondant n'ayant été exécuté et le pointeur ayant été perdu, l'allocation demeure réservée jusqu'à la fermeture du programme.

---

## 3. Évaluation de la Revue AI (AI Review)

### Points forts
L'intelligence artificielle a correctement identifié la présence de la fuite mémoire signalée par le rapport Valgrind.

### Axe d'amélioration / Correction apportée
L'analyse de l'AI manque de précision quant au statut spécifique fourni par Valgrind :
* **Précision clé :** L'AI n'a pas distingué une fuite mémoire générique d'un bloc **"definitely lost"**. Un bloc qualifié de *definitely lost* signifie que le programme a totalement perdu l'adresse du pointeur. Il n'est donc plus possible d'y accéder ni de le libérer ultérieurement pendant l'exécution du programme.

---

## 4. Recommandation de Correction du Code

Pour corriger cette erreur, il convient de garantir que toute mémoire allouée dynamiquement soit libérée via `free()` avant la fin de son scope d'utilisation ou la fermeture du programme.

```c
// Exemple de fonction de libération appropriée
void person_free(Person *p) {
    if (p != NULL) {
        // Libérer d'abord les chaînes ou structures internes si nécessaire
        // free(p->name); 
        free(p);
    }
}
