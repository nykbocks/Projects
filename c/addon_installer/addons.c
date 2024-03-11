#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    FILE *file = fopen("add.txt", "r");
    FILE *over = fopen("Dcript.txt", "w");
    FILE *wright = fopen("Dcript.txt", "a");
    char lines[100];
    char final[100];
    char config[200] = "\n@ShutdownOnFailedCommand 1\n@NoPromptForPassword 1\nlogin anonymous\n";
    char works[50] = "workshop_download_item 4000 ";
    char which[20][50];
    int i = 0;
    fprintf(over, config);
    while (fgets(lines, 100, file)){
        i++;
        strrev(lines);
        strcpy(final,lines);
        char *lina = &final[13];
        strrev(lina);
        strcat(lina, "  \n");
        char *line = &lina[55];
        printf("%d",i);
        strcpy(which[i], line);
        fprintf(wright, works);
        fprintf(wright, line);
    }
    fprintf(wright, "quit\n");
    fclose(file);
    fclose(over);
    fclose(wright);
    strcpy(which[0], "");

    // system("C:\\Users\\Computador\\Desktop\\jogos\\steamcmd\\steamcmd.exe +runscript C:\\Users\\Computador\\Desktop\\Dcript.txt");
    for(i=0;i<=10;i++) {
        char copy[1000] = "cp /c/Users/Computador/Desktop/jogos/steamcmd/steamapps/workshop/content/4000/";
        strcat(copy, which[i]);
        strcat(copy, "/c/Users/Computador/Desktop/jogos/Garrys-mod/garrysmod/addons/ -r");
        printf("%s",copy);
        system(copy);
    }
    return 0;
}
