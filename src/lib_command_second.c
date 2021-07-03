/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-alexandre.quenelle
** File description:
** lib_command_bis
*/

#include "ftp.h"

void cmd_pwd(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "257 \" ", 5);
    write(data->client_fd, path, strlen(path));
    write(data->client_fd, "\"\r\n", 3);
}

void cmd_pasv(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "227 Coming soon !\r\n", 19);
}

void cmd_port(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "200 Coming soon !\r\n", 19);
}

void cmd_help(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "214 USER, PASS, CDUP, DELE, PWD, PASV, PORT, \
    HELP, NOOP, RETR, STOR, LIST\r\n", 79);
}

void cmd_noop(struct info *data, char *buffer, char *path)
{
    write(data->client_fd, "200 Command Okay.\r\n", 19);
}