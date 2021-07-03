/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** select
*/

#include "ftp.h"

struct sockaddr_in setup_server(char *port)
{
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(port));

    return (server);
}

void quit_or_handle_cmd(int i, struct uknow *tools, struct info *data)
{
    if (strcmp(tools->buf, "QUIT\r\n") == 0){
        data[i].password = false;
        data[i].username = false;
        write(i, "221 Closing connection.\r\n", 25);
        close(i);
        FD_CLR(i, &tools->master);
    } else
        handle_command(&data[i], tools->buf, tools->path);
}

void bind_and_listen_server(struct sockaddr_in server, struct uknow *tools)
{
    tools->listener = socket(AF_INET , SOCK_STREAM , 0);
    if (bind(tools->listener, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit (84);
    }
    listen(tools->listener, 100);
    FD_SET(tools->listener, &tools->master);
    tools->fdmax = tools->listener;
    tools->c = sizeof(struct sockaddr_in);
}

void read_and_handle_cmd(int i, struct uknow *tools, struct info *data)
{
    if ((read(i, tools->buf, 256)) <= 0) {
        close(i);
        FD_CLR(i, &tools->master);
    } else
        quit_or_handle_cmd(i, tools, data);
    memset(tools->buf, 0, 256);
}

int launch_ftp(char *port, char *path)
{
    struct info data[100];
    struct uknow *tools = malloc(sizeof(tools));
    struct sockaddr_in server = setup_server(port);

    check_path(path, tools);
    bind_and_listen_server(server, tools);

    while (1) {
        tools->read_fds = tools->master;
        handle_select(tools, data);
        for (int i = 0; i <= tools->fdmax; i++) {
            if (FD_ISSET(i, &tools->read_fds)) {
                if (i == tools->listener) {
                    unknown_connection(tools, data, server);
                } else
                    read_and_handle_cmd(i, tools, data);
            }
        }
    }
    return 0;
}