#include "da_connector.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("Starting DA Connector...\n");

  char buffer[1024];
  int result = uds_listen(buffer, sizeof(buffer));

  if (result > 0)
  {
    printf("Received message: %s\n", buffer);
  }
  else if (result == 0)
  {
    printf("No data received\n");
  }
  else
  {
    printf("Failed to listen to socket\n");
  }

  return 0;
}
