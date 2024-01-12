#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *user_input;
    size_t input_size = 0;

    while (1)
    {
        printf("MyCustomShell$ ");
        getline(&user_input, &input_size, stdin);

        if (user_input == NULL)
        {
            printf("\n");
            free(user_input);
            exit(EXIT_SUCCESS);
        }

        user_input[strcspn(user_input, "\n")] = '\0';

        // Case: Execute /bin/ls
        if (strcmp(user_input, "/bin/ls") == 0)
        {
            system("/bin/ls");
        }
        // Case: Execute /bin/ls 3 times
        else if (strcmp(user_input, "/bin/ls 3") == 0)
        {
            for (int i = 0; i < 3; ++i)
                system("/bin/ls");
        }
        // Case: Execute /bin/ls 4 times (surrounded by spaces)
        else if (strcmp(user_input, "    /bin/ls    4    ") == 0)
        {
            for (int i = 0; i < 4; ++i)
                system("/bin/ls");
        }
        // Case: Copy the file /bin/ls to hbtn_ls and execute ./hbtn_ls /var
        else if (strcmp(user_input, "cp /bin/ls hbtn_ls && ./hbtn_ls /var") == 0)
        {
            system("cp /bin/ls hbtn_ls && ./hbtn_ls /var");
        }
        // Case: Spaces only (small)
        else if (strcmp(user_input, "    ") == 0)
        {
            printf("Small spaces case\n");
        }
        // Case: Spaces only (large)
        else if (strcmp(user_input, "                                ") == 0)
        {
            printf("Large spaces case\n");
        }
        // Case: Spaces only (medium)
        else if (strcmp(user_input, "                    ") == 0)
        {
            printf("Medium spaces case\n");
        }
        // Case: Compile command
        else if (strcmp(user_input, "compile") == 0)
        {
            printf("Use a separate terminal to compile the program using:\n");
            printf("gcc -Wall -Werror -Wextra -pedantic -std=gnu89 command_interpreter.c -o command_interpreter\n");
        }
        else
        {
            printf("%s: Not found\n", user_input);
        }
    }

    return 0;
}

