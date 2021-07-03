/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-alexandre.quenelle
** File description:
** handle_command
*/

#include "ftp.h"

int search_command(char *cmd[], char *handle_cmd, struct info *data)
{
    int return_value = -1;

    for (int i = 0; i < 13; i++){
        if (strcmp(handle_cmd, cmd[i]) == 0)
            return_value = i;
    }
    printf("func pointer => %d\n", return_value);
    if (return_value >= 2){
        if (!data->password || !data->username)
            return (-1);
    }
    return (return_value);
}

char *get_argument(char *buffer, int size)
{
    int len = 0;
    int inc = 0;
    for (len; buffer[len] != ' '; len++);
    char *new = malloc(sizeof(char) * ((strlen(buffer) - len) + 1));
    len++;

    if (strlen(buffer) == size){
        new = "";
    } else{
        for (len; buffer[len]; len++){
            if (buffer[len] >= 'A' && buffer[len] <= 'Z'
            || buffer[len] >= 'a' && buffer[len] <= 'z'){
                new[inc] = buffer[len];
                inc++;
            } else
                break;
        }
    }
    return (new);
}

char *get_command(char *buffer)
{
    char *new = malloc(sizeof(char) * 4);

    for (int inc = 0; buffer[inc]; inc++){
        if (buffer[inc] >= 'A' && buffer[inc] <= 'Z')
            new[inc] = buffer[inc];
        else
            break;
    }
    return (new);
}

void handle_command(struct info *data, char *buffer, char *path )
{
    data->handle_command = get_command(buffer);
    char *cmd[] = {"USER", "PASS", "CDUP", "CWD", "DELE", "PWD", "PASV",
                    "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};
    int to_point = search_command(cmd, data->handle_command, data);

    if (to_point == -1 && !data->username && !data->password ||
        to_point == -1 && !data->username && data->password ||
        to_point == -1 && !data->password && data->username){
        write(data->client_fd, "530 You need to login first\r\n", 29);
        return;
    } else if (to_point == -1){
        write(data->client_fd, "500 Unknow Command\r\n", 20);
        return;
    }
    void (*fun_ptr_arr[])(struct info *, char*, char*) = {set_user, set_pswd,
    cmd_cdup, cmd_cwd, cmd_dele, cmd_pwd, cmd_pasv, cmd_port, cmd_help,
    cmd_noop, cmd_retr, cmd_stor, cmd_list};

    (*fun_ptr_arr[to_point])(data, buffer, path);
}