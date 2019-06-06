#include "mysql_utils.h"
#include "parser_options.h"
#include <string.h>

int main(int argc, char* argv[])
{

  parser_options(argc, argv);

  MYSQL *conn = mysql_init(NULL);
  char query_so[500];
  char query_software[300];

  sprintf(query_so, "INSERT INTO %s (hostname,tipo_equipamento,ip,so,kernel,baixa_imagem,data) "
      "VALUES ('%s','%s','%s','%s','%s','%s','%s') "
      "ON DUPLICATE KEY UPDATE ip=VALUES(ip),so=VALUES(so),kernel=VALUES(kernel),"
      "baixa_imagem=VALUES(baixa_imagem),data=VALUES(data)",
      db_so_table, hostname, tipo_equipamento, endereco_ip, sistema_operacional,
      kernel, baixa_imagem, data_inventario);

  sprintf(query_software, "INSERT INTO %s (hostname,cmthin,fabricante) "
      "VALUES ('%s','%s','%s') "
      "ON DUPLICATE KEY UPDATE cmthin=VALUES(cmthin),fabricante=VALUES(fabricante)",
      db_software_table, hostname, cmthin, fabricante);

  if (mysql_real_connect(conn, db_host, db_user, db_passwd,
        db_database, 0, NULL, 0) == NULL) {
    finish_with_error(conn);
  }

  if (mysql_query(conn, query_so)) {
    finish_with_error(conn);
  }

  if (mysql_query(conn, query_software)) {
    finish_with_error(conn);
  }

  if (conn == NULL) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }


  return 0;
}
