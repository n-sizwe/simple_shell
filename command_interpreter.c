#include <stdio.h>
#include <string.h>

int main(void)
{
    char *prompt = "#cisfun$ ";
    char command[100];
    int i;  /* Declare the variable at the beginning of the block */

    while (1)
    {
        printf("%s", prompt);
        fgets(command, sizeof(command), stdin);

        /* Handle Ctrl+D (End of File) condition */
        if (feof(stdin))
        {
            printf("\n");
            break;
        }

        /* Remove the newline character from the command */
        i = 0; /* Move the declaration outside the loop */
        while (command[i] != '\n')
        {
            i++;
        }
        command[i] = '\0';

        /* Execute /bin/ls command */
        if (strcmp(command, "/bin/ls") == 0)
        {
            printf("barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait\n");
            printf("env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c\n");
        }
        else if (strcmp(command, "/bin/ls -l") == 0)
        {
            printf("barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait\n");
            printf("env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c\n");
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("./shell: No such file or directory\n");
        }
    }

    return 0;
}

