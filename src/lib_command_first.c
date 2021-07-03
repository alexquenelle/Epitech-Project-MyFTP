/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-alexandre.quenelle
** File description:
** lib_command
*/

#include "ftp.h"

void set_pswd(struct info *data, char *buffer, char *path)
{
    if (!data->username){
        write(data->client_fd, "332 Need account for login.\r\n", 29);
        return;
    }

    data->argument_pass = get_argument(buffer, 4);
    data->password = true;
    if (data->argument_user != NULL
        && strcmp(data->argument_user, "Anonymous") == 0
        && data->argument_pass != NULL && strlen(data->argument_pass) == 0)
        write(data->client_fd, "230 User logged in, proceed\r\n", 29);
    else {
        data->password = false;
        data->username = false;
        write(data->client_fd, "530 Incorrect Login\r\n", 21);
    }
}

void set_user(struct info *data, char *buffer, char *path)
{
    data->username = true;
    data->argument_user = get_argument(buffer, 4);

    write(data->client_fd, "331 User name okay, need password.\r\n", 36);
}

void cmd_cdup(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "200 Coming soon !\r\n", 19);
}

void cmd_cwd(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "250 Coming soon !\r\n", 19);
}

void cmd_dele(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "250 Coming soon !\r\n", 19);
}