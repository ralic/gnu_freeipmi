/*
   Copyright (C) 2003-2009 FreeIPMI Core Team

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.

 */

#ifndef _IPMI_API_H
#define _IPMI_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <freeipmi/api/ipmi-api.h>
#include <freeipmi/fiid/fiid.h>

/* ERROR CODE NOTES
 *
 * IPMI_ERR_MESSAGE_TIMEOUT

 * message timeout is typical of bridging commands.  The
 * session/connection has not timed out and is fine, but a
 * bridging command could not get its bridged response back in a
 * reasonable timeframe.
 */

enum ipmi_errnum
  {
    IPMI_ERR_SUCCESS = 0,
    IPMI_ERR_CTX_NULL = 1,
    IPMI_ERR_CTX_INVALID = 2,
    IPMI_ERR_PERMISSION = 3,
    IPMI_ERR_USERNAME_INVALID = 4,
    IPMI_ERR_PASSWORD_INVALID = 5,
    IPMI_ERR_K_G_INVALID = 6,
    IPMI_ERR_PRIVILEGE_LEVEL_INSUFFICIENT = 7,
    IPMI_ERR_PRIVILEGE_LEVEL_CANNOT_BE_OBTAINED = 8,
    IPMI_ERR_AUTHENTICATION_TYPE_UNAVAILABLE = 9,
    IPMI_ERR_CIPHER_SUITE_ID_UNAVAILABLE = 10,
    IPMI_ERR_PASSWORD_VERIFICATION_TIMEOUT = 11,
    IPMI_ERR_IPMI_2_0_UNAVAILABLE = 12,
    IPMI_ERR_CONNECTION_TIMEOUT = 13,
    IPMI_ERR_SESSION_TIMEOUT = 14,
    IPMI_ERR_DEVICE_ALREADY_OPEN = 15,
    IPMI_ERR_DEVICE_NOT_OPEN = 16,
    IPMI_ERR_DEVICE_NOT_SUPPORTED = 17,
    IPMI_ERR_DEVICE_NOT_FOUND = 18,
    IPMI_ERR_DRIVER_TIMEOUT = 19,
    IPMI_ERR_MESSAGE_TIMEOUT = 20,
    IPMI_ERR_COMMAND_INVALID_FOR_SELECTED_INTERFACE = 21,
    IPMI_ERR_BAD_COMPLETION_CODE = 22,
    IPMI_ERR_BAD_RMCPPLUS_STATUS_CODE = 23,
    IPMI_ERR_NOT_FOUND = 24,
    IPMI_ERR_BMC_BUSY = 25,
    IPMI_ERR_OUT_OF_MEMORY = 26,
    IPMI_ERR_HOSTNAME_INVALID = 27,
    IPMI_ERR_PARAMETERS = 28,
    IPMI_ERR_DRIVER_PATH_REQUIRED = 29,
    IPMI_ERR_IPMI_ERROR = 30,
    IPMI_ERR_SYSTEM_ERROR = 31,
    IPMI_ERR_INTERNAL_ERROR = 32,
    IPMI_ERR_ERRNUMRANGE = 33,
  };
typedef enum ipmi_errnum ipmi_errnum_type_t;

enum ipmi_driver_type
{
  IPMI_DEVICE_UNKNOWN = 0,
  IPMI_DEVICE_LAN = 1,
  IPMI_DEVICE_LAN_2_0 = 2,
  IPMI_DEVICE_KCS = 3,
  IPMI_DEVICE_SMIC = 4,
  IPMI_DEVICE_BT = 5,
  IPMI_DEVICE_SSIF = 6,
  IPMI_DEVICE_OPENIPMI = 7,
  IPMI_DEVICE_SUNBMC = 8,
};
typedef enum ipmi_driver_type ipmi_driver_type_t;

#define IPMI_WORKAROUND_FLAGS_DEFAULT                     0x00000000
#define IPMI_WORKAROUND_FLAGS_ACCEPT_SESSION_ID_ZERO      0x00000001 /* IPMI 1.5  only */
#define IPMI_WORKAROUND_FLAGS_FORCE_PERMSG_AUTHENTICATION 0x00000002 /* IPMI 1.5  only */
#define IPMI_WORKAROUND_FLAGS_CHECK_UNEXPECTED_AUTHCODE   0x00000004 /* IPMI 1.5  only */
#define IPMI_WORKAROUND_FLAGS_BIG_ENDIAN_SEQUENCE_NUMBER  0x00000008 /* IPMI 1.5  only */
#define IPMI_WORKAROUND_FLAGS_AUTHENTICATION_CAPABILITIES 0x00000010 /* IPMI 1.5 and 2.0 */
#define IPMI_WORKAROUND_FLAGS_INTEL_2_0_SESSION           0x01000000 /* IPMI 2.0  only */
#define IPMI_WORKAROUND_FLAGS_SUPERMICRO_2_0_SESSION      0x02000000 /* IPMI 2.0  only */
#define IPMI_WORKAROUND_FLAGS_SUN_2_0_SESSION             0x04000000 /* IPMI 2.0  only */
#define IPMI_WORKAROUND_FLAGS_OPEN_SESSION_PRIVILEGE      0x08000000 /* IPMI 2.0  only */

/* NONBLOCKING - for inband only
 *
 * DEBUG_DUMP - for all interfaces

 * NO_VALID_CHECK - do not check if IPMI response packets are valid
 * (i.e. all required fields set).  Useful to workaround non-compliant
 * motherboards.
 */

#define IPMI_FLAGS_DEFAULT        0x00000000
#define IPMI_FLAGS_NONBLOCKING    0x00000001
#define IPMI_FLAGS_DEBUG_DUMP     0x00000010
#define IPMI_FLAGS_NO_VALID_CHECK 0x00000100

typedef struct ipmi_ctx *ipmi_ctx_t;

ipmi_ctx_t ipmi_ctx_create (void);

int ipmi_ctx_errnum (ipmi_ctx_t ctx);

char *ipmi_ctx_strerror (int errnum);

char *ipmi_ctx_errormsg (ipmi_ctx_t ctx);

int ipmi_ctx_get_flags (ipmi_ctx_t ctx, unsigned int *flags);

/* for changing flags mid-operation for corner cases */
int ipmi_ctx_set_flags (ipmi_ctx_t ctx, unsigned int flags);

int ipmi_ctx_open_outofband (ipmi_ctx_t ctx,
                             const char *hostname,
                             const char *username,
                             const char *password,
                             uint8_t authentication_type,
                             uint8_t privilege_level,
                             unsigned int session_timeout,
                             unsigned int retransmission_timeout,
                             unsigned int workaround_flags,
                             unsigned int flags);

int ipmi_ctx_open_outofband_2_0 (ipmi_ctx_t ctx,
                                 const char *hostname,
                                 const char *username,
                                 const char *password,
                                 const unsigned char *k_g,
                                 unsigned int k_g_len,
                                 uint8_t privilege_level,
                                 uint8_t cipher_suite_id,
                                 unsigned int session_timeout,
                                 unsigned int retransmission_timeout,
                                 unsigned int workaround_flags,
                                 unsigned int flags);

int ipmi_ctx_open_inband (ipmi_ctx_t ctx,
                          ipmi_driver_type_t driver_type,
                          int disable_auto_probe,
                          uint16_t driver_address,
                          uint8_t register_spacing,
                          const char *driver_device,
                          unsigned int workaround_flags,
                          unsigned int flags);

/* like ipmi_ctx_open_inband, but finds probes/discovers an inband device */
/* returns 1 on driver found, 0 on not found, -1 on error */
/* if specified, driver type returned in 'driver_type' */
int ipmi_ctx_find_inband (ipmi_ctx_t ctx,
                          ipmi_driver_type_t *driver_type,
                          int disable_auto_probe,
                          uint16_t driver_address,
                          uint8_t register_spacing,
                          const char *driver_device,
                          unsigned int workaround_flags,
                          unsigned int flags);

int ipmi_cmd (ipmi_ctx_t ctx,
              uint8_t lun,
              uint8_t net_fn,
              fiid_obj_t obj_cmd_rq,
              fiid_obj_t obj_cmd_rs);

int ipmi_cmd_ipmb (ipmi_ctx_t ctx,
                   uint8_t rs_addr,
                   uint8_t lun,
                   uint8_t net_fn,
                   fiid_obj_t obj_cmd_rq,
                   fiid_obj_t obj_cmd_rs);

/* for request/response, byte #1 = cmd */
/* for response, byte #2 (typically) = completion code */
/* returns length written into buf_fs on success, -1 on error */
int ipmi_cmd_raw (ipmi_ctx_t ctx,
                  uint8_t lun,
                  uint8_t net_fn,
                  const void *buf_rq,
                  unsigned int buf_rq_len,
                  void *buf_rs,
                  unsigned int buf_rs_len);

int ipmi_ctx_close (ipmi_ctx_t ctx);

void ipmi_ctx_destroy (ipmi_ctx_t ctx);

#ifdef __cplusplus
}
#endif

#endif /* _IPMI_API_H */
