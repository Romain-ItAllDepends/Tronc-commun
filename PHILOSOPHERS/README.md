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

- pthread_create(&(thread_name), priorite, fonction a execute, argument d'entree de la fonction precedente);

