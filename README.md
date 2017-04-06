# ft_ls project of school 42

Pour tout connaitre du filesystem, de la façon dont sont rangés les fichiers et répertoires, codage d'une des commandes les plus utilisées : ls avec les options [-alrRtfF].

## Installing
```
make
```

## Running
```
./ft_ls [-alrRtfF][file ...]
```

## Options

-a      Include directory entries whose names begin with a dot (.).
-f      Output is not sorted.  This option turns on the -a option.
-l      List in long format.
-r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first.
-R      Recursively list subdirectories encountered.
-F      Display a slash ("/") immediately after each pathname that is a directory, an asterisk ("*") after each that is
        executable, an at sign (`@') after each symbolic link, an equals sign (`=') after each socket, a percent sign (`%')
        after each whiteout, and a vertical bar (`|') after each that is a FIFO.
