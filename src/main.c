#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "lexer.h"
#include "token.h"

void display_banner(void)
{
    printf("=====================================\n");
    printf("           ShellForge\n");
    printf("    A Unix Style Shell in C\n");
    printf("=====================================\n");
}

void process_command(char *line)
{
    token_list_t tokens;

    lexer(line, &tokens);
    token_print(&tokens);

    /* Parser will be called here */
    /* parser(&tokens); */

    /* Executor will be called here */
    /* execute(...); */
}

int main(void)
{
    char *line;

    display_banner();

    using_history();

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nExiting ShellForge...\n");
            break;
        }

        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        add_history(line);

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        if (strcmp(line, "history") == 0)
        {
            HIST_ENTRY **list = history_list();

            if (list)
            {
                for (int i = 0; list[i] != NULL; i++)
                    printf("%3d  %s\n", i + history_base, list[i]->line);
            }

            free(line);
            continue;
        }

        process_command(line);

        free(line);
    }

    clear_history();

    return 0;
}
