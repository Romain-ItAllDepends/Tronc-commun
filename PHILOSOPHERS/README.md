# Philisophers

## Commandes

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

