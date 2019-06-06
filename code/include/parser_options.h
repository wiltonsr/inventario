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

extern const char* program_name;
extern const char* db_host;
extern const char* db_user;
extern const char* db_passwd;
extern const char* db_database;
extern const char* db_so_table;
extern const char* db_software_table;
extern const char* hostname;
extern const char* tipo_equipamento;
extern const char* endereco_ip;
extern const char* sistema_operacional;
extern const char* kernel;
extern const char* baixa_imagem;
extern const char* data_inventario;
extern const char* cmthin;
extern const char* fabricante;

void print_usage (FILE* stream, int exit_code, char* program_name);

void parser_options(int argc, char* argv[]);

#endif
