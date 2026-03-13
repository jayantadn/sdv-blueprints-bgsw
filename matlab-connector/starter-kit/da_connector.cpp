#include "da_connector.h"
#include <stdio.h>

#ifdef _WIN32
// Windows-specific includes and dummy implementation
double da_connector()
{
  fprintf(stderr, "ERROR: da_connector() is not supported on Windows\n");
  return 0.0;
}
#else

#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "kuksa_bridge.h"

// Static buffer to track the last logged message
static char last_message[256] = "";

void log_message(const char *message)
{
  // Skip if this exact message was already logged
  if (strcmp(last_message, message) == 0)
  {
    return;
  }

  // Write directly to /tmp without creating subdirectories
  const char *file_path = "/tmp/mathworks.log";

  // Open file for writing
  FILE *log_file = fopen(file_path, "a");
  if (log_file == NULL)
  {
    fprintf(stderr, "Failed to open log file: %s\n", file_path);
    return;
  }

  // Get current timestamp
  time_t now = time(NULL);
  struct tm *tm_info = localtime(&now);
  char timestamp[64];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

  // Write message with timestamp
  fprintf(log_file, "[%s] %s\n", timestamp, message);

  // Close the file
  fclose(log_file);

  // Save this message as the last logged message
  strncpy(last_message, message, sizeof(last_message) - 1);
  last_message[sizeof(last_message) - 1] = '\0';
}

double da_connector()
{
  const char *mode = kuksa_get_wiper_mode();
  if (mode == NULL)
  {
    return 0;
  }

  log_message(mode);

  // Map wiper mode to return value
  if (strcmp(mode, "OFF") == 0)
  {
    return 0;
  }
  else if (strcmp(mode, "SLOW") == 0)
  {
    return 500;
  }
  else if (strcmp(mode, "MEDIUM") == 0)
  {
    return 750;
  }
  else if (strcmp(mode, "FAST") == 0)
  {
    return 1000;
  }
}

#endif // win
