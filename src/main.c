/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** main
*/

#include "ftp.h"

int main(int argc, char ** argv, char **envp)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0){
        printf("USAGE: ./myftp port path\n\
            \tport is the port number on which the server socket listens\n\
            \tpath is the path to the home directory for the Anonymous user\n");
        return (0);
    } else if (argc == 3){
        return (launch_ftp(argv[1], argv[2]));
    } else {
        return (84);
    }
}