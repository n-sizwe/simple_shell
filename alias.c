#include "shell.h"

/**
 * showCommandHistory - Displays the command history list with line numbers.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int showCommandHistory(info_t *info) {
    printList(info->history);  // Print the command history
    return 0;
}

/**
 * removeAlias - Removes an alias from the alias list.
 * @info: Parameter structure.
 * @aliasString: The alias string to be removed.
 * Return: Always 0 on success, 1 on error
 */
int removeAlias(info_t *info, char *aliasString) {
    char *position, character;
    int result;

    position = _strchr(aliasString, '=');
    if (!position)
        return 1;
    
    character = *position;
    *position = 0;  // Temporarily remove '=' to get alias name
    result = deleteNodeAtIndex(&(info->alias), getNodeIndex(info->alias, findNodeStartingWith(info->alias, aliasString, -1)));
    *position = character;  // Restore '='
    return result;
}

/**
 * addAlias - Adds an alias to the alias list.
 * @info: Parameter structure.
 * @aliasString: The alias string to be added.
 * Return: Always 0 on success, 1 on error
 */
int addAlias(info_t *info, char *aliasString) {
    char *position;

    position = _strchr(aliasString, '=');
    if (!position)
        return 1;

    if (!*++position)  // If alias value is empty, remove the alias
        return removeAlias(info, aliasString);

    removeAlias(info, aliasString);  // Remove existing alias with the same name
    return (addNodeEnd(&(info->alias), aliasString, 0) == NULL);  // Add the new alias
}

/**
 * printCustomAlias - Prints a custom alias string.
 * @node: The alias node.
 * Return: Always 0 on success, 1 on error
 */
int printCustomAlias(list_t *node) {
    char *position = NULL, *alias = NULL;

    if (node) {
        position = _strchr(node->str, '=');
        for (alias = node->str; alias <= position; alias++)
            _putchar(*alias);
        _putchar('\'');
        _puts(position + 1);
        _puts("'\n");
        return 0;
    }
    return 1;
}

/**
 * customAlias - Custom implementation of the alias builtin.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int customAlias(info_t *info) {
    int index = 0;
    char *position = NULL;
    list_t *aliasNode = NULL;

    if (info->argc == 1) {
        aliasNode = info->alias;
        while (aliasNode) {
            printCustomAlias(aliasNode);
            aliasNode = aliasNode->next;
        }
        return 0;
    }

    for (index = 1; info->argv[index]; index++) {
        position = _strchr(info->argv[index], '=');
        if (position) {
            addAlias(info, info->argv[index]);
        } else {
            printCustomAlias(findNodeStartingWith(info->alias, info->argv[index], '='));
        }
    }

    return 0;
}
