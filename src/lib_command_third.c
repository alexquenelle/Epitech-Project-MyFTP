/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-alexandre.quenelle
** File description:
** lib_command_third
*/

#include "ftp.h"

void cmd_retr(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "150 Coming soon !\r\n", 19);
}

void cmd_stor(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "150 Coming soon !\r\n", 19);
}

void cmd_list(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "404 Coming soon !\r\n", 19);
}