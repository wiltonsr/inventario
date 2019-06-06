#include "mysql_utils.h"
#include "parser_options.h"

int main(int argc, char* argv[])
{

  parser_options(argc, argv);

  MYSQL *conn = mysql_init(NULL);
  /* const char* query_so = NULL; */
  /* const char* query_software = NULL; */

  /* if (con == NULL) */
  /* { */
  /*   fprintf(stderr, "%s\n", mysql_error(con)); */
  /*   exit(1); */
  /* } */
  /*  */
  /* if (mysql_real_connect(con, db_host, db_user, db_passwd, */
  /*       db_database, 0, NULL, 0) == NULL) */
  /* { */
  /*   finish_with_error(con); */
  /* } */

  printf("Perimeter: %s\n",db_host);

  return 0;
}
