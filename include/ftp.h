/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-alexandre.quenelle
** File description:
** test
*/

#ifndef TEST_H_
#define TEST_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>

struct info
{
    bool username;
    bool password;
    int client_fd;
    char *handle_command;
    char *argument_user;
    char *argument_pass;
} typedef info;

struct uknow
{
    fd_set master;
    fd_set read_fds;
    int newfd;
    char buf[256];
    int listener;
    int i;
    struct sockaddr_in server;
    int fdmax;
    int c;
    char *path;
} typedef uknow;

int launch_ftp(char *port, char *path);
void *connection_handler(void *socket_desc);
void handle_command(struct info *data, char *buffer, char *path);
void command_manager(struct info *data);
int search_command(char *cmd[], char *handle_cmd, struct info *data);
char *get_argument(char *buffer, int size);
void set_pswd(struct info *data, char *buffer, char *path);
void set_user(struct info *data, char *buffer, char *path);
void cmd_cdup(struct info *data, char *buffer, char *path);
void cmd_cwd(struct info *data, char *buffer, char *path);
void cmd_dele(struct info *data, char *buffer, char *path);
void cmd_pwd(struct info *data, char *buffer, char *path);
void cmd_pasv(struct info *data, char *buffer, char *path);
void cmd_port(struct info *data, char *buffer, char *path);
void cmd_help(struct info *data, char *buffer, char *path);
void cmd_noop(struct info *data, char *buffer, char *path);
void cmd_retr(struct info *data, char *buffer, char *path);
void cmd_stor(struct info *data, char *buffer, char *path);
void cmd_list(struct info *data, char *buffer, char *path);
struct sockaddr_in setup_server(char *port);
void quit_or_handle_cmd(int i, struct uknow *tools, struct info *data);
void bind_and_listen_server(struct sockaddr_in server, struct uknow *tools);
void read_and_handle_cmd(int i, struct uknow *tools, struct info *data);
void check_path(char *path, struct uknow *tools);
void unknown_connection(struct uknow *tools, struct info *data,
struct sockaddr_in server);
void handle_select(struct uknow *tools, struct info *data);

#endif /* !TEST_H_ */