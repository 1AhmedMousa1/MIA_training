
# My Linux Experience


**Frist i installed virtuial box to boot ubuntu on it then opened the ubuntu os and tried the command line and this is the commands that i tried**

In this file, I will share my experience with using Linux commands

## Basic Commands

| Command | Description | Example |
| ------- | ----------- | ------- |
| `ls` | Lists the contents of a directory | `ls -l` |
| `cd` | Changes the current directory | `cd Documents` |
| `pwd` | Prints the current working directory | `pwd` |
| `mkdir` | Creates a new directory | `mkdir new_directory` |
| `rm` | Removes files or directories | `rm -r old_directory` |
| `man`| you put it before the command to give you its manual | `man man`|

>you can put after `ls -a ` to show you hidden files..etc

## Advanced Commands


| Command | Description | Example |
| ------- | ----------- | ------- |
| `grep` | Searches for text within files | `grep 'example' file.txt` |
| `find` | Searches for files or directories that match certain criteria | `find ~ -type f -mtime 0` |
| `sed` | Performs basic text transformations on input streams (such as files or piped input from other commands) | `sed 's/old/new/g' file.txt` |
| `ssh` | Securely connects to remote servers using SSH (Secure Shell) | `ssh user@192.168.1.100` |
| `scp` | Securely copies files between systems using SSH | `scp file.txt user@192.168.1.100:~` |
| `rsync` | Efficiently transfers and synchronizes files between systems | `rsync -avz local_dir/ user@192.168.1.100:remote_dir` |
