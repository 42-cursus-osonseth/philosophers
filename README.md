# 🧠 Philosophers

Implémentation du classique problème des philosophes en C, avec `pthreads` et `mutex` pour la gestion de la concurrence.

---

## 📚 Objectif

Simuler le comportement de philosophes assis autour d’une table qui alternent entre **penser**, **manger** et **dormir**, tout en partageant des fourchettes.  
L’objectif est de gérer les accès concurrents de manière sûre.

---

## ⚙️ Fonctionnement

- Chaque philosophe est représenté par un **thread** (`pthread`).
- Les fourchettes sont modélisées par des **mutex** (`pthread_mutex_t`) pour garantir l’exclusion mutuelle.
- Pour **manger**, un philosophe doit acquérir les **deux mutex adjacents** (les fourchettes gauche et droite).
- Les accès concurrentiels aux ressources critiques (fourchettes, affichage, statut de vie, etc.) sont **protégés par mutex**.
- Un **monitoring** vérifie régulièrement si un philosophe dépasse `time_to_die` sans manger, ce qui provoque l’arrêt de la simulation.
- L’ordre de prise des fourchettes est conçu pour **éviter les interblocages** (deadlocks) 
- L’option `[nombre_de_menusnumber_of_times_each_philosopher_must_eat]` permet de stopper proprement la simulation une fois que chaque        philosophe a mangé un nombre minimum de fois.

---

## 🧪 Exécution

```bash
./philo [nb_philosophes] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optionnel)]
