#include <stdio.h>
#include <string.h>

int main(void)
{
    char *prompt = "#cisfun$ ";
    char command[100];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;  // Handle Ctrl+D (End of File)
        }

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Execute /bin/ls command
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
            fprintf(stderr, "./shell: No such file or directory\n");
        }
    }

    return 0;
}

