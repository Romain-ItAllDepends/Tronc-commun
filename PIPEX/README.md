# PIPEX 

Pipex est particulièrement important pour le projet minishell qui se situe sur le prochain cercle.

Les fonctions abordées dans pipex doivent être comprise afin de gagner du temps sur minishell, contrairement à minitalk qui ne constitue qu'une petite partie de minishell.

## Introduction

Pipex est un projet consistant a envoyer quatre parametres comme suit :
    ./pipex file1 cmd1 cmd2 file2
    
Il doit prendre 4 arguments :
- file1 et file2 sont des noms de fichier.
- cmd1 et cmd2 sont des commandes shell avec leurs paramètres.
    
Puis le contenu du premier fichier sera envoyé a la commande numéro une pour traitement qui sera envoyé a la deuxième commande finalement dans le second fichier.

Si il reste une incompréhension veuilliez mettre votre terminal en mode bash.
```
bash
```
Puis exécuter cette commande selon le procédé expliqué précédemment.
```
< file1 cmd1 | cmd2 > file2
```

## Fonctionnement des fonctions nécessaires

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

## Notions importantes à comprendre

- Savoir ce qu'est path dans les variables d'environnements.

- Comment récupérer les variables d'environnement (isoler chacun des paths puis tester à partir de quel path on a le droit d'exécuter les commandes)

- Tester les path absolu.

- Bien comprendre fork et excve.

- Comment faire communiquer les deux process enfant et parents.

> [!IMPORTANT]
> Source : Teddy et Google
>
> Comprehension de fork : https://www.youtube.com/watch?v=cex9XrZCU14&ab_channel=CodeVault
> 
> Source : [fr.subject.pdf](https://github.com/Romain-ItAllDepends/Tronc-commun/blob/main/PIPEX/fr.subject.pdf)
