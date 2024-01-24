# PIPEX 

## Introduction :

Pipex est un projet consistant a envoyer quatre parametres comme suit :
    ./pipex file1 cmd1 cmd2 file2



### access :

Permet de verifier  l'existence d'un fichier
Permet de tester les permissions d'acces a un fichier.

signature : 

int access(const char path, int mode);

path ->chemin du fichier.
mode -> F_OK : Vérifie simplement l'existence du fichier.
               R_OK : Vérifie les permissions de lecture.
               X_OK : Vérifie les permissions d'exécution.

return (0) -> si ok

return (-1)-> si ko 

### dup :

Permet de dupliquer un descripteur de fichier existant.

signature : 
int dup(int oldfd);

oldfd -> fichier existant.

### dup2: 

Permet de dupliquer un descripteur de fichier existant
et de specifier explicitement le numero de descripteur de fichier que vous souhaitez utiliser 
pour le nouveau descripteur dupliquer. 

signature : 

int dup2(int oldfd, int newfd);

### execve:

Execute un programme dans le contexte du processus appelant.

signature : 

int execve(const charpathname, char const argv[], charconst envp[]);

pathname-> chemin du fichier executable du programme que vous souhaitez executer. 

argv-> Un tableau de chaines de caracteres representant les variables d'environnement representant les arguments du programme. Le dernier 

element de ce tableau doit etre NULL. 

envp-> Un tableau de chaines de caracteres representatant les variables d'environnement. Le dernier element de ce tableau doit etre NULL. 

```
int main()
{
char pathname;
charconst arguments[] = {"/bin/ls", "-l", NULL};
char *const envp[] = {NULL};
pathname = "/bin/ls";
if (execve(pathname, arguments, envp) == -1)
{
printf("Error lors de l'executation du programme");
return (1);
}
return (0);
}
```

valeur de return - 1 en cas d'erreur.

### exit : 

Permet de terminer l'execution d'un programme , peu importe la fonction dans laquelle elle est appeler.

signature :
exit(int status) 

### fork : 

La fonction fork est utilisée pour créer un nouveau processus appelé le processus fils, qui est une copie exacte du processus parent.

> [!IMPORTANT]
> Source : Teddy et Google

