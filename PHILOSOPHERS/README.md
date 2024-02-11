# Philisophers

## Introduction

### Qu'est-ce qu'un thread ?

Un thread est l'unité de base à laquelle un système d'exploitation alloue du temps processeur. Chaque thread a une priorité de planification et maintient un ensemble de structures utilisé par le système pour enregistrer le contexte du thread quand l'exécution du thread est en pause.

Les threads permettent de faire du multi-tache comme l'utilisation de processus parent et enfant, mais bien moins exigeant au niveau de la mémoire.
Un thread ne copie pas le programme du parent, mais exécute seulement la fonction qui lui est donnée.
Les threads sont généralement utilisés pour effectuer de petite tache.
Un processus parent peut avoir plusieurs threads.

## Commandes

### Initialisation d'un thread

Lors de la création d'un thread, il est nécessaire de l'initialiser de la façon suivante :

```
int  main(void)
{
  pthread_t  thread1;

  return (0);
}
```

### Compilation lors de l'utilisation de thread

Il est également important d'utiliser la commande suivante lors de la compilation pour que le programme puisse s'exécuter.

Version classique :
```
gcc -lpthread thread.c -o thread
```
Version 42 :
```
gcc -Wall -Werror -Wextra -lpthread thread.c -o thread
```

### Création de thread

- pthread_create(&(thread_name), priorite, fonction, arg);
Lors de l'exécution du programme si la fonction en paramètre de pthread_create est assez lourde le programme se terminera avant de l'avoir terminé.

### Attendre la fin de l'exécution d'un thread

- pthread_join(thread_name, NULL);
Permet d'attendre que le thread termine sa fonction avant de passer a la suite.

### Libérer un thread

- pthread_detach(thread_name);
Permet de libérer les ressources du thread, mais empêche de synchroniser plusieurs threads a l'aide de pthread_join.

### Détruire un mutex

- pthread_mutex_destroy(&mutex);
Permet de détruire le mutex et donc libère les ressources occupe par se mutex.
Les mutex sont expliquer ci-dessous.

### Qu'est-ce qu'un mutex et a quoi ça sert ?

Un mutex permet le blocage d'un thread, lorsque le mutex est créé il est par défaut déverrouiller.

![image](https://github.com/Romain-ItAllDepends/Tronc-commun/assets/140979120/53734010-bc1f-4d09-862f-5da1dd34a545)


### Initialisation d'un mutex et utilisation
```
int  main(void)
{
  pthread_mutex_t  mutex;

  pthread_mutex_init(&mutex, NULL);
  return(0);
}
```
L'utilisation de mutex se fait avec les deux commandes suivantes :
```
pthread_mutex_lock(&mutex);

/**
* Programme ..
**/

pthread_mutex_unlock(&mutex);
```

Les deux commandes verrouilleront et déverrouilleront les threads qui ont se mutex en commun.

Exemple :

```
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

void  *print1(void *mutex)
{
  int    i;
  char  str[] = "Hello 42";

  i = 0;
  pthread_mutex_lock(&mutex);
  while (i < 8)
  {
    fprintf(stderr, "%c", str[i]);
    i++;
  }
  write(1, "\n", 1);
  pthread_mutex_unlock(&mutex);
}

void  *print2(void *mutex)
{
  int    i;
  char  str[] = "Bye 42";

  i = 0;
  pthread_mutex_lock(&mutex);
  while (i < 6)
  {
    fprintf(stderr, "%c", str[i]);
    i++;
  }
  write(1, "\n", 1);
  pthread_mutex_unlock(&mutex);
}

int  main(void)
{
  pthread_t  t1;
  pthread_t  t2;
  pthread_mutex_t  mutex;

  pthread_mutex_init(&mutex, NULL);
  pthread_create(&t1, NULL, print1, &mutex);
  pthread_create(&t2, NULL, print2, &mutex);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_mutex_destroy(&mutex);

  return (0);
}
```

Le résultat retourné sera :
```
Hello 42
Bye 42
```
Alors que sans mutex le résultat serait plus semblable a celui-ci :
```
HeBlyloe  442
2

```
Le résultat sans mutex dépend de l'horloge du processeur comme expliquer dans l'introduction.

### Mettre en attente le programme

- usleep(nb_en_ms);
Met en attente le programme/thread/processus selon le temps en milliseconde renseigner en paramètre de usleep.

### Obtenir l'heure

- int gettimeofday(struct timeval *tv, struct timezone *tz);

La structure suivante va être nécessaire pour le projet Philosophers.

```
struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};
```
### Vérification des data race

- valgrind --tool=drd --read-var-info=yes programme parametres
Les data race ne sont pas autoriser sur le projet Philosophers.
Une data race est une situation où deux threads accèdent à un emplacement mémoire "en même temps" et qu'un des deux au moins le fait en écriture. 

# Idée de comment faire le projet

Il faut plusieurs structures et comprendre les listes chaînées.
Tout d'abord, il faudra créer un tableau de thread qui varie selon le nombre de philosophes.
Autant de fourchettes que de philosophe.
Récupérer l'heure actuelle en ms.
Créer plusieurs mutex afin de ne pas verrouiller tous les threads quand un philosophe mange, car si les philosophes sont quatre, ils peuvent au moins manger deux par deux.
À chaque fois qu'un philosophe mange, on obtient le temps lorsqu'il commence à manger puis à le comparer à l'heure actuelle en faisant une simple différence, on peut savoir s'il a fini de manger ou non.

> [!IMPORTANT]
> Source : Google
> 
> Source : https://www.youtube.com/watch?v=9JAblZeSwOI
> 
> Source : https://www.youtube.com/watch?v=o_GbRujGCnM
>
> Source : https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/
