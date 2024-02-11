# Philisophers

## Commandes

Les threads permettent de faire du multi-tache comme l'utilisation de processus parent et enfant mais bien moins exigeant au niveau de la memoire.
Un thread ne copie pas le programme du parent mais execute seulement la fonction qui lui est donnee.
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
