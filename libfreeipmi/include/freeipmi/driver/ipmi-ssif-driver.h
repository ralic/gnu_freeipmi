/*
 * Copyright (C) 2003-2015 FreeIPMI Core Team
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef IPMI_SSIF_DRIVER_H
#define IPMI_SSIF_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <freeipmi/fiid/fiid.h>

#define IPMI_DEFAULT_I2C_DEVICE                "/dev/i2c-0"
#define IPMI_DEFAULT_SSIF_IPMB_ADDR            0x42

#define IPMI_SSIF_ERR_SUCCESS              0
#define IPMI_SSIF_ERR_NULL                 1
#define IPMI_SSIF_ERR_INVALID              2
#define IPMI_SSIF_ERR_PARAMETERS           3
#define IPMI_SSIF_ERR_PERMISSION           4
#define IPMI_SSIF_ERR_IO_NOT_INITIALIZED   5
#define IPMI_SSIF_ERR_OVERFLOW             6
#define IPMI_SSIF_ERR_BUSY                 7
#define IPMI_SSIF_ERR_OUT_OF_MEMORY        8
#define IPMI_SSIF_ERR_DEVICE_NOT_FOUND     9
#define IPMI_SSIF_ERR_DRIVER_TIMEOUT      10
#define IPMI_SSIF_ERR_IPMI_ERROR          11
#define IPMI_SSIF_ERR_SYSTEM_ERROR        12
#define IPMI_SSIF_ERR_INTERNAL_ERROR      13
#define IPMI_SSIF_ERR_ERRNUMRANGE         14

#define IPMI_SSIF_FLAGS_DEFAULT       0x00000000
#define IPMI_SSIF_FLAGS_NONBLOCKING   0x00000001

typedef struct ipmi_ssif_ctx *ipmi_ssif_ctx_t;

/* Notes:
 *
 * IPMBAddress - slave address of the BMC on the SMBus (usually 0x42)
 *
 */
ipmi_ssif_ctx_t ipmi_ssif_ctx_create (void);
void ipmi_ssif_ctx_destroy (ipmi_ssif_ctx_t ctx);
int ipmi_ssif_ctx_errnum (ipmi_ssif_ctx_t ctx);
char *ipmi_ssif_ctx_strerror (int errnum);
char *ipmi_ssif_ctx_errormsg (ipmi_ssif_ctx_t ctx);

int ipmi_ssif_ctx_get_driver_device (ipmi_ssif_ctx_t ctx, char **driver_device);
int ipmi_ssif_ctx_get_driver_address (ipmi_ssif_ctx_t ctx, uint8_t *driver_address);
int ipmi_ssif_ctx_get_flags (ipmi_ssif_ctx_t ctx, unsigned int *flags);

int ipmi_ssif_ctx_set_driver_device (ipmi_ssif_ctx_t ctx, const char *driver_device);
int ipmi_ssif_ctx_set_driver_address (ipmi_ssif_ctx_t ctx, uint8_t driver_address);
int ipmi_ssif_ctx_set_flags (ipmi_ssif_ctx_t ctx, unsigned int flags);

int ipmi_ssif_ctx_io_init (ipmi_ssif_ctx_t ctx);

/* returns length written on success, -1 on error */
int ipmi_ssif_write (ipmi_ssif_ctx_t ctx,
                     const void *buf,
                     unsigned int buf_len);

/* returns length read on success, -1 on error */
int ipmi_ssif_read (ipmi_ssif_ctx_t ctx,
                    void *buf,
                    unsigned int buf_len);

int ipmi_ssif_cmd (ipmi_ssif_ctx_t ctx,
                   uint8_t lun,
                   uint8_t net_fn,
                   fiid_obj_t obj_cmd_rq,
                   fiid_obj_t obj_cmd_rs);

#ifdef __cplusplus
}
#endif

#endif /* IPMI_SSIF_DRIVER_H */
