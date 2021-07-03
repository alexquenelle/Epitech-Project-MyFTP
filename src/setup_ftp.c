/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-alexandre.quenelle
** File description:
** setup_ftp
*/

#include "ftp.h"

void check_path(char *path, struct uknow *tools)
{
    if (access(path, R_OK) == -1)
        exit(84);

    tools->path = path;
    return;
}

void handle_select(struct uknow *tools, struct info *data)
{
    if (select(tools->fdmax+1, &tools->read_fds, NULL, NULL, NULL) == -1) {
        perror("select");
        exit (84);
    }
}

void unknown_connection(struct uknow *tools, struct info *data,
struct sockaddr_in server)
{
    tools->newfd = accept(tools->listener,
    (struct sockaddr *)&server, (socklen_t *)&tools->c);
    if (tools->newfd == -1) {
        perror("accept");
    } else {
        FD_SET(tools->newfd, &tools->master);
        if (tools->newfd > tools->fdmax)
            tools->fdmax = tools->newfd;
        data[tools->newfd].client_fd = tools->newfd;
        write(tools->newfd, "220 Welcome !\r\n", 15);
    }
}