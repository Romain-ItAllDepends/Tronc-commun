### Algorithme push swap

[^1]: Trier.
[^2]: Trouver le midpoint en divisant par deux la length et prendre la liste triée est récupérer le nombre à cet index dans midpoint.
[^3]: Maintenant, on divise par deux la length et on cherche tous les nombres inférieurs au midpoint jusqu'à pas. [length / 2]
[^4]: Si c'est inférieur au midpoint pb (Push le premier, nombre de la pile a sur la pile b donc au-dessus.), si c'est supérieur ou égale au midpoint ra (Décale d’une position vers le haut tous les éléments de la pile a. Le premier élément devient le dernier.)
Si l'élément qui remplace celui qui était supérieur au midpoint y est inférieur alors pb sinon ra.

[^5]: On récupère un nouveau midpoint avec la nouvelle liste et on recommence.
[^6]: Chaque chunk est délimiter par les midpoint, si notre premier midpoint est 7 alors tous les éléments inférieurs a 7 son du (premier ou dernier) chunk de la liste b. Si le second est 10 alors tout se qui est inférieur a 10 et supérieur à 6 sont dans le second chunk.
[^7]: Vue qu'il ne reste que deux éléments dans la liste a, il suffit de les trier.
(ra si le premier élément est plus grand que le second.)

[^8]: Si un chunk ne comporte qu'un élément pa (On envoie le premier element de la pile b sur la pile a) sinon on trie par ordre décroissant (de sorte a se que le premier element de la liste sois le plus grand) en se basant sur le midpoint de se chunk (Si le chunk comporte les nombres 7,8,9 alors le midpoint est 8 (on l'obtient de la même façon que la pile a, mais en se basant que sur les nombres d'un chunk)) le premier chunk (le chunk du dessus) avec sb (switch les deux premiers éléments) puis pa.
[^9]: Si c'est le dernier chunk on peut utiliser directement rb (y a une histoire d'utiliser rrb pour une raison inconnue)
[^10]: Si la liste est déjà trier (ordre décroissant) dans le chunk peu importe le nombre d'éléments pa.

> ![IMPORTANT]
> Source : https://www.youtube.com/watch?v=7KW59UO55TQ&ab_channel=JOHNPARK
