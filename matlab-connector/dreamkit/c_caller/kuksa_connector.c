#include "kuksa_connector.h"
#include <stdio.h>

#ifdef _WIN32
// Windows stub implementations
double kuksa_get_pothole_left() {
    fprintf(stderr, "ERROR: KUKSA connector not supported on Windows\n");
    return 0.0;
}

double kuksa_get_pothole_center() {
    fprintf(stderr, "ERROR: KUKSA connector not supported on Windows\n");
    return 0.0;
}

double kuksa_get_pothole_right() {
    fprintf(stderr, "ERROR: KUKSA connector not supported on Windows\n");
    return 0.0;
}

double kuksa_get_steering_angle() {
    fprintf(stderr, "ERROR: KUKSA connector not supported on Windows\n");
    return 0.0;
}

void kuksa_set_hazard_signal(bool value) {
    fprintf(stderr, "ERROR: KUKSA connector not supported on Windows\n");
}

#else

#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

// Helper function to read from UDS socket
static int uds_read(const char *socket_path, char *buffer, size_t buffer_size) {
    int sock_fd;
    struct sockaddr_un addr;
    ssize_t bytes_received;

    sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        fprintf(stderr, "Failed to create socket for %s\n", socket_path);
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Failed to connect to socket: %s\n", socket_path);
        close(sock_fd);
        return -1;
    }

    bytes_received = recv(sock_fd, buffer, buffer_size - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        if (bytes_received > 0 && buffer[bytes_received - 1] == '\n') {
            buffer[bytes_received - 1] = '\0';
        }
    } else {
        close(sock_fd);
        return -1;
    }

    close(sock_fd);
    return bytes_received;
}

// Helper function to write to UDS socket
static int uds_write(const char *socket_path, const char *message) {
    int sock_fd;
    struct sockaddr_un addr;
    ssize_t bytes_sent;

    sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        fprintf(stderr, "Failed to create socket for %s\n", socket_path);
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Failed to connect to socket: %s\n", socket_path);
        close(sock_fd);
        return -1;
    }

    bytes_sent = send(sock_fd, message, strlen(message), 0);
    close(sock_fd);
    
    return (bytes_sent > 0) ? 0 : -1;
}

// Read pothole detection from left lane (zones 1, 4, 7)
double kuksa_get_pothole_left() {
    char buffer[1024];
    const char *socket_path = "/tmp/kuksa_pothole_left.sock";
    
    if (uds_read(socket_path, buffer, sizeof(buffer)) > 0) {
        // Parse boolean or numeric value
        if (strcmp(buffer, "true") == 0 || strcmp(buffer, "1") == 0) {
            return 1.0;
        }
    }
    return 0.0;
}

// Read pothole detection from center lane (zones 2, 5, 8)
double kuksa_get_pothole_center() {
    char buffer[1024];
    const char *socket_path = "/tmp/kuksa_pothole_center.sock";
    
    if (uds_read(socket_path, buffer, sizeof(buffer)) > 0) {
        if (strcmp(buffer, "true") == 0 || strcmp(buffer, "1") == 0) {
            return 1.0;
        }
    }
    return 0.0;
}

// Read pothole detection from right lane (zones 3, 6, 9)
double kuksa_get_pothole_right() {
    char buffer[1024];
    const char *socket_path = "/tmp/kuksa_pothole_right.sock";
    
    if (uds_read(socket_path, buffer, sizeof(buffer)) > 0) {
        if (strcmp(buffer, "true") == 0 || strcmp(buffer, "1") == 0) {
            return 1.0;
        }
    }
    return 0.0;
}

// Read steering wheel angle
double kuksa_get_steering_angle() {
    char buffer[1024];
    const char *socket_path = "/tmp/kuksa_steering_angle.sock";
    
    if (uds_read(socket_path, buffer, sizeof(buffer)) > 0) {
        return atof(buffer);
    }
    return 0.0;
}

// Write hazard signal status
void kuksa_set_hazard_signal(bool value) {
    const char *socket_path = "/tmp/kuksa_hazard_signal.sock";
    char message[64];
    
    // Convert to boolean string
    snprintf(message, sizeof(message), "%s", value ? "true" : "false");
    
    uds_write(socket_path, message);
}

#endif // _WIN32
