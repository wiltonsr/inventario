#ifndef PARSER_OPTIONS_H
#define PARSER_OPTIONS_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define DB_HOST 1000
#define DB_USER 1001
#define DB_PASSWD 1002
#define DB_DATABASE 1003
#define DB_SO_TABLE 1004
#define DB_SOFTWARE_TABLE 1005
#define HOSTNAME 1006
#define TIPO_EQUIPAMENTO 1007
#define ENDERECO_IP 1008
#define SISTEMA_OPERACIONAL 1009
#define KERNEL 1010
#define BAIXA_IMAGEM 1011
#define DATA_INVENTARIO 1012
#define CMTHIN 1013
#define FABRICANTE 1014

const char* program_name;

void print_usage (FILE* stream, int exit_code);

void parser_options(int argc, char* argv[]);

#endif
