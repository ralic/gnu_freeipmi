/*****************************************************************************\
 *  $Id: ipmi_monitoring_bitmasks.h,v 1.3 2010-03-19 22:07:58 chu11 Exp $
 *****************************************************************************
 *  Copyright (C) 2007-2013 Lawrence Livermore National Security, LLC.
 *  Copyright (C) 2006-2007 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Albert Chu <chu11@llnl.gov>
 *  UCRL-CODE-222073
 *
 *  This file is part of Ipmimonitoring, an IPMI sensor monitoring
 *  library.  For details, see http://www.llnl.gov/linux/.
 *
 *  Ipmimonitoring is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 3 of the License, or (at your
 *  option) any later version.
 *
 *  Ipmimonitoring is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with Ipmimonitoring.  If not, see <http://www.gnu.org/licenses/>.
\*****************************************************************************/

#ifndef IPMI_MONITORING_BITMASKS_H
#define IPMI_MONITORING_BITMASKS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * IPMI Monitoring Sensor Bitmask Type
 *
 * Possible sensor bitmask types that may be returned for a sensor.
 */
enum ipmi_monitoring_sensor_bitmask_type
  {
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_THRESHOLD                           = 0x00,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_TRANSITION_STATE                    = 0x01,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_STATE                               = 0x02,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PREDICTIVE_FAILURE                  = 0x03,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_LIMIT                               = 0x04,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PERFORMANCE                         = 0x05,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_TRANSITION_SEVERITY                 = 0x06,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_DEVICE_PRESENT                      = 0x07,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_DEVICE_ENABLED                      = 0x08,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_TRANSITION_AVAILABILITY             = 0x09,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_REDUNDANCY                          = 0x0A,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_ACPI_POWER_STATE                    = 0x0B,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PHYSICAL_SECURITY                   = 0x0C,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PLATFORM_SECURITY_VIOLATION_ATTEMPT = 0x0D,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PROCESSOR                           = 0x0E,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_POWER_SUPPLY                        = 0x0F,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_POWER_UNIT                          = 0x10,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_COOLING_DEVICE                      = 0x11,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_OTHER_UNITS_BASED_SENSOR            = 0x12,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_MEMORY                              = 0x13,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_DRIVE_SLOT                          = 0x14,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_POST_MEMORY_RESIZE                  = 0x15,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SYSTEM_FIRMWARE_PROGRESS            = 0x16,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_EVENT_LOGGING_DISABLED              = 0x17,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_WATCHDOG1                           = 0x18,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SYSTEM_EVENT                        = 0x19,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_CRITICAL_INTERRUPT                  = 0x1A,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_BUTTON_SWITCH                       = 0x1B,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_MODULE_BOARD                        = 0x1C,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_MICROCONTROLLER_COPROCESSOR         = 0x1D,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_ADD_IN_CARD                         = 0x1E,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_CHASSIS                             = 0x1F,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_CHIP_SET                            = 0x20,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_OTHER_FRU                           = 0x21,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_CABLE_INTERCONNECT                  = 0x22,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_TERMINATOR                          = 0x23,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SYSTEM_BOOT_INITIATED               = 0x24,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_BOOT_ERROR                          = 0x25,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_OS_BOOT                             = 0x26,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_OS_CRITICAL_STOP                    = 0x27,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SLOT_CONNECTOR                      = 0x28,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SYSTEM_ACPI_POWER_STATE             = 0x29,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_WATCHDOG2                           = 0x2A,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_PLATFORM_ALERT                      = 0x2B,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_ENTITY_PRESENCE                     = 0x2C,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_MONITOR_ASIC_IC                     = 0x2D,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_LAN                                 = 0x2E,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_MANAGEMENT_SUBSYSTEM_HEALTH         = 0x2F,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_BATTERY                             = 0x30,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_SESSION_AUDIT                       = 0x31,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_VERSION_CHANGE                      = 0x32,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_FRU_STATE                           = 0x33,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_OEM                                 = 0xFE,
    IPMI_MONITORING_SENSOR_BITMASK_TYPE_UNKNOWN                             = 0xFF,
  };

/*
 * IPMI Bitmasks
 *
 * The following are the bitmask masks that can be returned.  Use the
 * returned bitmask type to determine which set of bitmasks to use.
 */
enum ipmi_monitoring_sensor_bitmask_threshold
  {
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_LOWER_NON_CRITICAL_THRESHOLD    = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_LOWER_CRITICAL_THRESHOLD        = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_LOWER_NON_RECOVERABLE_THRESHOLD = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_UPPER_NON_CRITICAL_THRESHOLD    = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_UPPER_CRITICAL_THRESHOLD        = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_THRESHOLD_AT_OR_BELOW_UPPER_NON_RECOVERABLE_THRESHOLD = 0x0020,
  };

enum ipmi_monitoring_sensor_bitmask_transition
  {
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_IDLE   = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_ACTIVE = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_BUSY   = 0x0004,
  };

enum ipmi_monitoring_sensor_bitmask_state
  {
    IPMI_MONITORING_SENSOR_BITMASK_STATE_DEASSERTED = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_STATE_ASSERTED   = 0x0002,
  };
  
enum ipmi_monitoring_sensor_bitmask_predictive_failure
  {
    IPMI_MONITORING_SENSOR_BITMASK_PREDICTIVE_FAILURE_DEASSERTED = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PREDICTIVE_FAILURE_ASSERTED   = 0x0002,
  };
  
enum ipmi_monitoring_sensor_bitmask_limit
  {
    IPMI_MONITORING_SENSOR_BITMASK_LIMIT_NOT_EXCEEDED = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_LIMIT_EXCEEDED     = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_performance
  {
    IPMI_MONITORING_SENSOR_BITMASK_PERFORMANCE_MET  = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PERFORMANCE_LAGS = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_transition_severity
  {
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_OK                               = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_NON_CRITICAL_FROM_OK             = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_CRITICAL_FROM_LESS_SEVERE        = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_NON_RECOVERABLE_FROM_LESS_SEVERE = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_NON_CRITICAL_FROM_MORE_SEVERE    = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_CRITICAL_FROM_NON_RECOVERABLE    = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_NON_RECOVERABLE                  = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_MONITOR                             = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_INFORMATIONAL                       = 0x0100,
  };

enum ipmi_monitoring_sensor_bitmask_device_present
  {
    IPMI_MONITORING_SENSOR_BITMASK_DEVICE_REMOVED_DEVICE_ABSENT   = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_DEVICE_INSERTED_DEVICE_PRESENT = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_device_enabled
  {
    IPMI_MONITORING_SENSOR_BITMASK_DEVICE_DISABLED = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_DEVICE_ENABLED  = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_transition_availability
  {
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_RUNNING    = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_IN_TEST    = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_POWER_OFF  = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_ON_LINE    = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_OFF_LINE   = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_OFF_DUTY   = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_DEGRADED   = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_TO_POWER_SAVE = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_TRANSITION_INSTALL_ERROR = 0x0100,
  };

enum ipmi_monitoring_sensor_bitmask_redundancy
  {
    IPMI_MONITORING_SENSOR_BITMASK_FULLY_REDUNDANT                                                = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_REDUNDANCY_LOST                                                = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_REDUNDANCY_DEGRADED                                            = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_NON_REDUNDANT_SUFFICIENT_RESOURCES_FROM_REDUNDANT              = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_NON_REDUNDANT_SUFFICIENT_RESOURCES_FROM_INSUFFICIENT_RESOURCES = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_NON_REDUNDANT_INSUFFICIENT_RESOURCES                           = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_REDUNDANCY_DEGRADED_FROM_FULLY_REDUNDANT                       = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_REDUNDANCY_DEGRADED_FROM_NON_REDUNDANT                         = 0x0080,
  };

enum ipmi_monitoring_sensor_bitmask_acpi_power_state
  {
    IPMI_MONITORING_SENSOR_BITMASK_D0_POWER_STATE = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_D1_POWER_STATE = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_D2_POWER_STATE = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_D3_POWER_STATE = 0x0008,
  };

enum ipmi_monitoring_sensor_bitmask_physical_security
  {
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_GENERAL_CHASSIS_INTRUSION = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_DRIVE_BAY_INTRUSION       = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_IO_CARD_INTRUSION         = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_PROCESSOR_AREA_INTRUSION  = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_LAN_LEASH_LOST            = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_UNAUTHORIZED_DOCK_UNDOCK  = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_PHYSICAL_SECURITY_FAN_AREA_INTRUSION        = 0x0040,
  };

enum ipmi_monitoring_sensor_bitmask_platform_security_violation_attempt
  {
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_SECURE_MODE_VIOLATION_ATTEMPT                      = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_PRE_BOOT_PASSWORD_VIOLATION_USER_PASSWORD          = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_PRE_BOOT_PASSWORD_VIOLATION_ATTEMPT_SETUP_PASSWORD = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_PRE_BOOT_PASSWORD_VIOLATION_NETWORK_BOOT_PASSWORD  = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_OTHER_PRE_BOOT_PASSWORD_VIOLATION                  = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_SECURITY_VIOLATION_ATTEMPT_OUT_OF_BAND_ACCESS_PASSWORD_VIOLATION              = 0x0020,
  };
  
enum ipmi_monitoring_sensor_bitmask_processor
  {
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_IERR                                          = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_THERMAL_TRIP                                  = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_FRB1_BIST_FAILURE                             = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_FRB2_HANG_IN_POST_FAILURE                     = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_FRB3_PROCESSOR_STARTUP_INITIALIZATION_FAILURE = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_CONFIGURATION_ERROR                           = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_SMBIOS_UNCORRECTABLE_CPU_COMPLEX_ERROR        = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_PROCESSOR_PRESENCE_DETECTED                   = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_PROCESSOR_DISABLED                            = 0x0100,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_TERMINATOR_PRESENCE_DETECTED                  = 0x0200,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_PROCESSOR_AUTOMATICALLY_THROTTLED             = 0x0400,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_MACHINE_CHECK_EXCEPTION                       = 0x0800,
    IPMI_MONITORING_SENSOR_BITMASK_PROCESSOR_CORRECTABLE_MACHINE_CHECK_ERROR               = 0x1000,
  };

enum ipmi_monitoring_sensor_bitmask_power_supply
  {
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_PRESENCE_DETECTED                           = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_POWER_SUPPLY_FAILURE_DETECTED               = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_PREDICTIVE_FAILURE                          = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_POWER_SUPPLY_INPUT_LOST_AC_DC               = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_POWER_SUPPLY_INPUT_LOST_OR_OUT_OF_RANGE     = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_POWER_SUPPLY_INPUT_OUT_OF_RANGE_BUT_PRESENT = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_SUPPLY_CONFIGURATION_ERROR                         = 0x0040,
  };

enum ipmi_monitoring_sensor_bitmask_power_unit
  {
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_POWER_OFF_POWER_DOWN        = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_POWER_CYCLE                 = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_240VA_POWER_DOWN            = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_INTERLOCK_POWER_DOWN        = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_AC_LOST                     = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_SOFT_POWER_CONTROL_FAILURE  = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_POWER_UNIT_FAILURE_DETECTED = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_POWER_UNIT_PREDICTIVE_FAILURE          = 0x0080,
  };

enum ipmi_monitoring_sensor_bitmask_memory
  {
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_CORRECTABLE_MEMORY_ERROR                       = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_UNCORRECTABLE_MEMORY_ERROR                     = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_PARITY                                         = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_MEMORY_SCRUB_FAILED                            = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_MEMORY_DEVICE_DISABLED                         = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_CORRECTABLE_MEMORY_ERROR_LOGGING_LIMIT_REACHED = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_PRESENCE_DETECTED                              = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_CONFIGURATION_ERROR                            = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_SPARE                                          = 0x0100,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_MEMORY_AUTOMATICALLY_THROTTLED                 = 0x0200,
    IPMI_MONITORING_SENSOR_BITMASK_MEMORY_CRITICAL_OVERTEMPERATURE                       = 0x0400,
  };

enum ipmi_monitoring_sensor_bitmask_drive_slot
  {
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_DRIVE_PRESENCE                             = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_DRIVE_FAULT                                = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_PREDICTIVE_FAILURE                         = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_HOT_SPARE                                  = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_CONSISTENCY_CHECK_PARITY_CHECK_IN_PROGRESS = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_IN_CRITICAL_ARRAY                          = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_IN_FAILED_ARRAY                            = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_REBUILD_REMAP_IN_PROGRESS                  = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_DRIVE_SLOT_REBUILD_REMAP_ABORTED                      = 0x0100,
  };

enum ipmi_monitoring_sensor_bitmask_system_firmware_progress
  {
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_FIRMWARE_PROGRESS_SYSTEM_FIRMWARE_ERROR    = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_FIRMWARE_PROGRESS_SYSTEM_FIRMWARE_HANG     = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_FIRMWARE_PROGRESS_SYSTEM_FIRMWARE_PROGRESS = 0x0004,
  };

enum ipmi_monitoring_sensor_bitmask_event_logging_disabled
  {
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_CORRECTABLE_MEMORY_ERROR_LOGGING_DISABLED        = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_EVENT_TYPE_LOGGING_DISABLED                      = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_LOG_AREA_RESET_CLEARED                           = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_ALL_EVENT_LOGGING_DISABLED                       = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_SEL_FULL                                         = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_SEL_ALMOST_FULL                                  = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_EVENT_LOGGING_DISABLED_CORRECTABLE_MACHINE_CHECK_ERROR_LOGGING_DISABLED = 0x0040,
  };

enum ipmi_monitoring_sensor_bitmask_watchdog1
  {
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_BIOS_WATCHDOG_RESET                       = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_RESET                         = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_SHUT_DOWN                     = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_POWER_DOWN                    = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_POWER_CYCLE                   = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_NMI_DIAGNOSTIC_INTERRUPT      = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_EXPIRED_STATUS_ONLY           = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG1_OS_WATCHDOG_PRE_TIMEOUT_INTERRUPT_NON_NMI = 0x0080,
  };

enum ipmi_monitoring_sensor_bitmask_system_event
  {
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_SYSTEM_RECONFIGURED                  = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_OEM_SYSTEM_BOOT_EVENT                = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_UNDETERMINED_SYSTEM_HARDWARE_FAILURE = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_ENTRY_ADDED_TO_AUXILIARY_LOG         = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_PEF_ACTION                           = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_EVENT_TIMESTAMP_CLOCK_SYNC                 = 0x0020,
  };

enum ipmi_monitoring_sensor_bitmask_critical_interrupt
  {
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_FRONT_PANEL_NMI_DIAGNOSTIC_INTERRUPT = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_BUS_TIMEOUT                          = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_IO_CHANNEL_CHECK_NMI                 = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_SOFTWARE_NMI                         = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_PCI_PERR                             = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_PCI_SERR                             = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_EISA_FAIL_SAFE_TIMEOUT               = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_BUS_CORRECTABLE_ERROR                = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_BUS_UNCORRECTABLE_ERROR              = 0x0100,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_FATAL_NMI                            = 0x0200,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_BUS_FATAL_ERROR                      = 0x0400,
    IPMI_MONITORING_SENSOR_BITMASK_CRITICAL_INTERRUPT_BUS_DEGRADED                         = 0x0800,
  };

enum ipmi_monitoring_sensor_bitmask_button_switch
  {
    IPMI_MONITORING_SENSOR_BITMASK_BUTTON_SWITCH_POWER_BUTTON_PRESSED       = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_BUTTON_SWITCH_SLEEP_BUTTON_PRESSED       = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_BUTTON_SWITCH_RESET_BUTTON_PRESSED       = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_BUTTON_SWITCH_FRU_LATCH_OPEN             = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_BUTTON_SWITCH_FRU_SERVICE_REQUEST_BUTTON = 0x0010,
  };

enum ipmi_monitoring_sensor_bitmask_chip_set
  {
    IPMI_MONITORING_SENSOR_BITMASK_CHIP_SET_SOFT_POWER_CONTROL_FAILURE = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_CHIP_SET_THERMAL_TRIP               = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_cable_interconnect
  {
    IPMI_MONITORING_SENSOR_BITMASK_CABLE_INTERCONNECT_IS_CONNECTED        = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_CABLE_INTERCONNECT_CONFIGURATION_ERROR = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_system_boot_initiated
  {
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_INITIATED_BY_POWER_UP                     = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_INITIATED_BY_HARD_RESET                   = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_INITIATED_BY_WARM_RESET                   = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_USER_REQUESTED_PXE_BOOT                   = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_AUTOMATIC_BOOT_TO_DIAGNOSTIC              = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_OS_RUN_TIME_SOFTWARE_INITIATED_HARD_RESET = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_OS_RUN_TIME_SOFTWARE_INITIATED_WARM_RESET = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_BOOT_INITIATED_SYSTEM_RESTART                            = 0x0080,
  };

enum ipmi_monitoring_sensor_bitmask_boot_error
  {
    IPMI_MONITORING_SENSOR_BITMASK_BOOT_ERROR_NO_BOOTABLE_MEDIA                                 = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_BOOT_ERROR_NON_BOOTABLE_DISKETTE_LEFT_IN_DRIVE               = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_BOOT_ERROR_PXE_SERVER_NOT_FOUND                              = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_BOOT_ERROR_INVALID_BOOT_SECTOR                               = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_BOOT_ERROR_TIMEOUT_WAITING_FOR_USER_SELECTION_OF_BOOT_SOURCE = 0x0010,
  };

enum ipmi_monitoring_sensor_bitmask_os_boot
  {
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_A_BOOT_COMPLETED                         = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_C_BOOT_COMPLETED                         = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_PXE_BOOT_COMPLETED                       = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_DIAGNOSTIC_BOOT_COMPLETED                = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_CD_ROM_BOOT_COMPLETED                    = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_ROM_BOOT_COMPLETED                       = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_OS_BOOT_BOOT_COMPLETED_BOOT_DEVICE_NOT_SPECIFIED = 0x0040,
  };

enum ipmi_monitoring_sensor_bitmask_os_critical_stop
  {
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_CRITICAL_STOP_DURING_OS_LOAD   = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_RUN_TIME_CRITICAL_STOP         = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_OS_GRACEFUL_STOP               = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_OS_GRACEFUL_SHUTDOWN           = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_SOFT_SHUTDOWN_INITIATED_BY_PEF = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_OS_CRITICAL_STOP_AGENT_NOT_RESPONDING           = 0x0020,
  };

enum ipmi_monitoring_sensor_bitmask_slot_connector
  {
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_FAULT_STATUS_ASSERTED                        = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_IDENTIFY_STATUS_ASSERTED                     = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_CONNECTOR_DEVICE_INSTALLED_ATTACHED     = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_CONNECTOR_READY_FOR_DEVICE_INSTALLATION = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_CONNECTOR_READY_FOR_DEVICE_REMOVAL      = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_POWER_IS_OFF                            = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_CONNECTOR_DEVICE_REMOVAL_REQUEST        = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_INTERLOCK_ASSERTED                           = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_IS_DISABLED                             = 0x0100,
    IPMI_MONITORING_SENSOR_BITMASK_SLOT_CONNECTOR_SLOT_HOLDS_SPARE_DEVICE                      = 0x0200,
  };

enum ipmi_monitoring_sensor_bitmask_system_acpi_power_state
  {
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S0_G0                             = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S1                                = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S2                                = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S3                                = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S4                                = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S5_G2                             = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S4_S5_SOFT_OFF                    = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_G3_MECHANICAL_OFF                 = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_SLEEPING_IN_AN_S1_S2_OR_S3_STATES = 0x0100,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_G1_SLEEPING                       = 0x0200,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_S5_ENTERED_BY_OVERRIDE            = 0x0400,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_LEGACY_ON_STATE                   = 0x0800,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_LEGACY_OFF_STATE                  = 0x1000,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_UNSPECIFIED                       = 0x2000,
    IPMI_MONITORING_SENSOR_BITMASK_SYSTEM_ACPI_POWER_STATE_UNKNOWN                           = 0x4000,
  };

enum ipmi_monitoring_sensor_bitmask_watchdog2
  {
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_TIMER_EXPIRED   = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_HARD_RESET      = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_POWER_DOWN      = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_POWER_CYCLE     = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_RESERVED1       = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_RESERVED2       = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_RESERVED3       = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_RESERVED4       = 0x0080,
    IPMI_MONITORING_SENSOR_BITMASK_WATCHDOG2_TIMER_INTERRUPT = 0x0100,
  };

enum ipmi_monitoring_sensor_bitmask_platform_alert
  {
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_ALERT_PLATFORM_GENERATED_PAGE       = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_ALERT_PLATFORM_GENERATED_LAN_ALERT  = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_ALERT_PLATFORM_EVENT_TRAP_GENERATED = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_PLATFORM_ALERT_PLATFORM_GENERATED_SNMP_TRAP  = 0x0008,
  };

enum ipmi_monitoring_sensor_bitmask_entity_presence
  {
    IPMI_MONITORING_SENSOR_BITMASK_ENTITY_PRESENCE_ENTITY_PRESENT  = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_ENTITY_PRESENCE_ENTITY_ABSENT   = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_ENTITY_PRESENCE_ENTITY_DISABLED = 0x0004,
  };

enum ipmi_monitoring_sensor_bitmask_lan
  {
    IPMI_MONITORING_SENSOR_BITMASK_LAN_HEARTBEAT_LOST = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_LAN_HEARTBEAT      = 0x0002,
  };

enum ipmi_monitoring_sensor_bitmask_management_subsystem_health
  {
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_SENSOR_ACCESS_DEGRADED_OR_UNAVAILABLE     = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_CONTROLLER_ACCESS_DEGRADED_OR_UNAVAILABLE = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_MANAGEMENT_CONTROLLER_OFF_LINE            = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_MANAGEMENT_CONTROLLER_UNAVAILABLE         = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_SENSOR_FAILURE                            = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_MANAGEMENT_SUBSYSTEM_HEALTH_FRU_FAILURE                               = 0x0020,
  };

enum ipmi_monitoring_sensor_bitmask_battery
  {
    IPMI_MONITORING_SENSOR_BITMASK_BATTERY_BATTERY_LOW               = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_BATTERY_BATTERY_FAILED            = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_BATTERY_BATTERY_PRESENCE_DETECTED = 0x0004,
  };

enum ipmi_monitoring_sensor_bitmask_session_audit
  {
    IPMI_MONITORING_SENSOR_BITMASK_SESSION_AUDIT_SESSION_ACTIVATED            = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_SESSION_AUDIT_SESSION_DEACTIVATED          = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_SESSION_AUDIT_INVALID_USERNAME_OR_PASSWORD = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_SESSION_AUDIT_INVALID_PASSWORD_DISABLE     = 0x0008,
  };
  
enum ipmi_monitoring_sensor_bitmask_version_change
  {
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_HARDWARE_CHANGE_DETECTED_WITH_ASSOCIATED_ENTITY                        = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_FIRMWARE_OR_SOFTWARE_CHANGE_DETECTED_WITH_ASSOCIATED_ENTITY            = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_HARDWARE_INCOMPATABILITY_DETECTED_WITH_ASSOCIATED_ENTITY               = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_FIRMWARE_OR_SOFTWARE_INCOMPATABILITY_DETECTED_WITH_ASSOCIATED_ENTITY   = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_ENTITY_IS_OF_AN_INVALID_OR_UNSUPPORTED_HARDWARE_VERSION                = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_ENTITY_CONTAINS_AN_INVALID_OR_UNSUPPORTED_FIRMWARE_OR_SOFTWARE_VERSION = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_HARDWARE_CHANGE_DETECTED_WITH_ASSOCIATED_ENTITY_WAS_SUCCESSFUL         = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_VERSION_CHANGE_SOFTWARE_OR_FW_CHANGE_DETECTED_WITH_ASSOCIATED_ENTITY_WAS_SUCCESSFUL   = 0x0080,
  };
  
enum ipmi_monitoring_sensor_bitmask_fru_state
  {
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_NOT_INSTALLED            = 0x0001,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_INACTIVE                 = 0x0002,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_ACTIVATION_REQUESTED     = 0x0004,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_ACTIVATION_IN_PROGRESS   = 0x0008,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_ACTIVE                   = 0x0010,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_DEACTIVATION_REQUESTED   = 0x0020,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_DEACTIVATION_IN_PROGRESS = 0x0040,
    IPMI_MONITORING_SENSOR_BITMASK_FRU_STATE_FRU_COMMUNICATION_LOST       = 0x0080,
  };

#ifdef __cplusplus
}
#endif

#endif /* IPMI_MONITORING_BITMASKS_H */
