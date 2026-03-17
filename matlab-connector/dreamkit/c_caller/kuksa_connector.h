#ifndef KUKSA_CONNECTOR_H
#define KUKSA_CONNECTOR_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Read functions - Get values from KUKSA via UDS
double kuksa_get_pothole_left();
double kuksa_get_pothole_center();
double kuksa_get_pothole_right();
double kuksa_get_steering_angle();

// Write function - Set hazard signal to KUKSA via UDS
void kuksa_set_hazard_signal(bool value);

#ifdef __cplusplus
}
#endif

#endif // KUKSA_CONNECTOR_H
