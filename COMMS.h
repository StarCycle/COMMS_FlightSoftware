/*
 * COMMS.h
 *
 *  Created on: 23 Jul 2019
 *      Author: stefanosperett
 */

#ifndef EPS_H_
#define EPS_H_

#include <driverlib.h>
#include <LDPCDecoder.h>
#include "msp.h"
#include "DelfiPQcore.h"
#include "PQ9Bus.h"
#include "PQ9Frame.h"
#include "DWire.h"
#include "DSPI.h"
#include "DSerial.h"
#include "CommandHandler.h"
#include "Task.h"
#include "PeriodicTask.h"
#include "TaskManager.h"
#include "HousekeepingService.h"
#include "COMMSTelemetryContainer.h"
#include "PingService.h"
#include "COMMSTelemetryContainer.h"
#include "TestService.h"
#include "ResetService.h"
#include "SoftwareUpdateService.h"
#include "SX1276.h"
#include "RadioService.h"
#include "COMMRadio.h"


#define FCLOCK 48000000

#define COMMS_ADDRESS     4

// callback functions
void acquireTelemetry(COMMSTelemetryContainer *tc);
void periodicTask();

#endif /* COMMS_H_ */
