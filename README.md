# Rl
Readline library using termcaps

## Features
> Arrow Key  (Left / Right)
  Del Key
  Ctrl Arrow (Left / Right)
  Ctrl A/E   (Jump end begin)
  Alt Del    (Word jump del)
  Suppr Key
    
    [toto42sh@epitech.eu]$> Allo|
    /* Alt Del */
    [toto42sh@epitech.eu]$> |
    
    [toto42sh@epitech.eu]$> Hey |Hey Hey Hey Hey.
    /* Ctrl Right */
    [toto42sh@epitech.eu]$> Hey Hey |Hey Hey Hey.
    /* Ctrl Right */
    [toto42sh@epitech.eu]$> Hey Hey Hey |Hey Hey.
    /* Etc */
    
## Example
If you want to test do:

    make example

else if you want to use it as a lib:

    make
   
And link rl.h then use it link that:

    char *cmd = NULL;
    
    while (cmd == NULL) {
        cmd = rl("[YourPrompt]> ");
        printf("%s\n", cmd);
        free(cmd);
        cmd = NULL;
    }
