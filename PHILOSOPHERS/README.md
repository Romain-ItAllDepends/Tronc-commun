# Philisophers

## Commandes

Un thread est l'unité de base à laquelle un système d'exploitation alloue du temps processeur. Chaque thread a une priorité de planification et maintient un ensemble de structures utilisé par le système pour enregistrer le contexte du thread quand l'exécution du thread est en pause.

Les threads permettent de faire du multi-tache comme l'utilisation de processus parent et enfant mais bien moins exigeant au niveau de la memoire.
Un thread ne copie pas le programme du parent mais execute seulement la fonction qui lui est donnee.
Les threads sont generalement utiliser pour effectuer de petite tache.
Un processus parent peut avoir plusieurs thread.

Lors de la creation d'un thread il est nescessaire de l'initialiser de la facon suivante :

```
int  main(void)
{
  pthread_t  thread1;

  return (0);
}
```

Il est egalement important d'utiliser la commande suivante lors de la compilation pour que le programme puisse s'executer.

Version classique :
```
gcc -lpthread thread.c -o thread
```
Version 42 :
```
gcc -Wall -Werror -Wextra -lpthread thread.c -o thread
```

- pthread_create(&(thread_name), priorite, fonction a execute, argument d'entree de la fonction precedente);
Lors de l'execution du programme si la fonction en parametre de pthread_create est assez lourde le programme se terminera avant de l'avoir terminer.
  
- pthread_join(thread_name, NULL);
Permet d'attendre que le thread termine sa fonction avant de passer a la suite.

-Qu'est-ce qu'un mutex et a quoi sa sert ?

Un mutex permet le blocage d'un thread, lorsque le mutex est cree il est par defaut deverouiller.

![image](https://github.com/Romain-ItAllDepends/Tronc-commun/assets/140979120/53734010-bc1f-4d09-862f-5da1dd34a545)


- Initialisation d'un thread mutex :
```
pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
```
L'utilisation de mutex se fait avec les deux commandes suivantes :
```
pthread_mutex_lock(&mutex);

/**
* Programme ..
**/

pthread_mutex_unlock(&mutex);
```

Les deux commandes verouilleront et deverouilleront les threads qui ont se mutex en commun.

Exemple :

```
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

void  *print1(void)
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

void  *print2(void)
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

  pthread_create(&t1, NULL, print1, NULL);
  pthread_create(&t2, NULL, print2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return (0);
}
```


> [!IMPORTANT]
> Source : Google
> 
> Source : https://www.youtube.com/watch?v=9JAblZeSwOI
> 
> Source : https://www.youtube.com/watch?v=o_GbRujGCnM
