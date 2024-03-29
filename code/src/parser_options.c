#include "parser_options.h"

const char* db_host = NULL;
const char* db_user = NULL;
const char* db_passwd = NULL;
const char* db_database = NULL;
const char* db_so_table = NULL;
const char* db_software_table = NULL;
const char* hostname = NULL;
const char* tipo_equipamento = NULL;
const char* endereco_ip = NULL;
const char* sistema_operacional = NULL;
const char* kernel = NULL;
const char* baixa_imagem = NULL;
const char* data_inventario = NULL;
const char* cmthin = NULL;
const char* fabricante = NULL;
const char* scthin = NULL;
const char* apl = NULL;

void print_usage (FILE* stream, int exit_code, char* program_name)
{
  fprintf (stream, "Como utilizar:  %s opcoes\n", program_name);
  fprintf (stream,
      " -h  --help                 Exibe esta mensagem.\n"
      "     --db-host              Endereco IP do Banco de Dados.\n"
      "                            [%s]\n"
      "     --db-user              Usuario do Banco de Dados.\n"
      "                            [%s]\n"
      "     --db-passwd            Senha do Banco de Dados.\n"
      "                            [%s]\n"
      "     --db-database          Nome do Banco de Dados.\n"
      "                            [%s]\n"
      "     --db-so-table          Nome da Tabela de Informacoes do SO.\n"
      "                            [%s]\n"
      "     --db-software-table    Nome da Tabela de Informacoes de Softwares.\n"
      "                            [%s]\n"
      "     --hostname             Nome do equipamento.\n"
      "                            [%s]\n"
      "     --tipo-equipamento     Tipo do equipamento.\n"
      "                            [%s]\n"
      "     --endereco-ip          Endereco IP do equipamento.\n"
      "                            [%s]\n"
      "     --sistema-operacional  Sistema Operacional do equipamento.\n"
      "                            [%s]\n"
      "     --kernel               Kernel do equipamento.\n"
      "                            [%s]\n"
      "     --baixa-imagem         Data de Baixa da Imagem.\n"
      "                            [%s]\n"
      "     --data-inventario      Data do Inventario.\n"
      "                            [%s]\n"
      "     --cmthin               Versao do pacote cmthin.\n"
      "                            [%s]\n"
      "     --fabricante           Fabricante do equipamento.\n"
      "                            [%s]\n"
      "     --scthin               Versao do pacote scthin.\n"
      "                            [%s]\n"
      "     --apl                  Versao do APL.\n"
      "                            [%s]\n",
      db_host, db_user, db_passwd, db_database, db_so_table, db_software_table,
      hostname, tipo_equipamento, endereco_ip, sistema_operacional, kernel,
      baixa_imagem, data_inventario, cmthin, fabricante, scthin, apl);
  exit (exit_code);
}

void parser_options(int argc, char* argv[])
{
  int next_option;

  const char* const short_options = "h";
  const struct option long_options[] = {
    { "help",                0, NULL, 'h'                 },
    { "db-host",             1, NULL, DB_HOST             },
    { "db-user",             1, NULL, DB_USER             },
    { "db-passwd",           1, NULL, DB_PASSWD           },
    { "db-database",         1, NULL, DB_DATABASE         },
    { "db-so-table",         1, NULL, DB_SO_TABLE         },
    { "db-software-table",   1, NULL, DB_SOFTWARE_TABLE   },
    { "hostname",            1, NULL, HOSTNAME            },
    { "tipo-equipamento",    1, NULL, TIPO_EQUIPAMENTO    },
    { "endereco-ip",         1, NULL, ENDERECO_IP         },
    { "sistema-operacional", 1, NULL, SISTEMA_OPERACIONAL },
    { "kernel",              1, NULL, KERNEL              },
    { "baixa-imagem",        1, NULL, BAIXA_IMAGEM        },
    { "data-inventario",     1, NULL, DATA_INVENTARIO     },
    { "cmthin",              1, NULL, CMTHIN              },
    { "fabricante",          1, NULL, FABRICANTE          },
    { "scthin",              1, NULL, SCTHIN              },
    { "apl",                 1, NULL, APL                 },
    { NULL,                  1, NULL, 0                   }
  };

  const char* program_name = argv[0];

  do {
    next_option = getopt_long (argc, argv, short_options,
        long_options, NULL);
    switch (next_option)
    {
      case 'h':
        print_usage (stdout, 0, (char *)program_name);

      case DB_HOST:
        db_host = optarg;
        break;

      case DB_PASSWD:
        db_passwd = optarg;
        break;

      case DB_USER:
        db_user = optarg;
        break;

      case DB_DATABASE:
        db_database = optarg;
        break;

      case DB_SO_TABLE:
        db_so_table = optarg;
        break;

      case DB_SOFTWARE_TABLE:
        db_software_table = optarg;
        break;

      case HOSTNAME:
        hostname = optarg;
        break;

      case TIPO_EQUIPAMENTO:
        tipo_equipamento = optarg;
        break;

      case ENDERECO_IP:
        endereco_ip = optarg;
        break;

      case SISTEMA_OPERACIONAL:
        sistema_operacional = optarg;
        break;

      case KERNEL:
        kernel = optarg;
        break;

      case BAIXA_IMAGEM:
        baixa_imagem = optarg;
        break;

      case DATA_INVENTARIO:
        data_inventario = optarg;
        break;

      case CMTHIN:
        cmthin = optarg;
        break;

      case FABRICANTE:
        fabricante = optarg;
        break;

      case SCTHIN:
        scthin = optarg;
        break;

      case APL:
        apl = optarg;
        break;

      case '?':
        print_usage (stderr, 1, (char *)program_name);

      case -1:
        break;

      default:
        print_usage (stdout, 0, (char *)program_name);
    }
  }
  while (next_option != -1);
}
