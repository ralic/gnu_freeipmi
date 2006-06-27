#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#if STDC_HEADERS
#include <string.h>
#endif /* STDC_HEADERS */
#if HAVE_UNISTD_H
#include <unistd.h>
#endif	/* HAVE_UNISTD_H */
#include <error.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/resource.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else /* !TIME_WITH_SYS_TIME */
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else /* !HAVE_SYS_TIME_H */
#include <time.h>
#endif /* !HAVE_SYS_TIME_H */
#endif /* !TIME_WITH_SYS_TIME */
#include <argp.h>

#include "freeipmi/fiid.h"
#include "freeipmi/ipmi-sel-cmds.h"
#include "freeipmi/ipmi-sel-record-types.h"
#include "freeipmi/ipmi-sensor-event-messages.h"
#include "freeipmi/udm/ipmi-sel-cmds-udm.h"

#include "err-wrappers.h"
#include "fiid-wrappers.h"
#include "freeipmi-portability.h"
#include "ipmi-common.h"
#include "ipmi-sensor-api.h"

#include <freeipmi/freeipmi.h>
#include <freeipmi/udm/udm.h>

#include "ipmi-sel-api.h"
#include "ipmi-sel-wrapper.h"

int 
get_local_sel_info (ipmi_device_t *dev, local_sel_info_t *sel_info)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;
  
  ERR_EINVAL (dev && sel_info);

  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_get_sel_info_rs);

  if (ipmi_cmd_get_sel_info (dev, obj_cmd_rs) != 0)
    {
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "cmd", &val);
      dev->cmd = val;

      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "comp_code", &val);
      dev->comp_code = val;

      ipmi_strerror_cmd_r (obj_cmd_rs, 
                           dev->net_fn,
			   dev->errmsg, 
			   IPMI_ERR_STR_MAX_LEN);
      goto cleanup;
    }
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "sel_version_major", &val);
  sel_info->sel_version_major = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "sel_version_minor", &val);
  sel_info->sel_version_minor = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "entries", &val);
  sel_info->log_entry_count = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "free_space", &val);
  sel_info->free_space = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "most_recent_addition_timestamp", &val);
  sel_info->recent_addition_timestamp = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "most_recent_erase_timestamp", &val);
  sel_info->recent_erase_timestamp = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "get_sel_allocation_info_command_supported", &val);
  sel_info->get_sel_alloc_info_cmd_support = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "reserve_sel_command_supported", &val);
  sel_info->reserve_sel_cmd_support = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "partial_add_sel_entry_command_supported", &val);
  sel_info->partial_add_sel_entry_cmd_support = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "delete_sel_command_supported", &val);
  sel_info->delete_sel_cmd_support = val;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "overflow_flag", &val);
  sel_info->overflow_flag = val;
  
  rv = 0;
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN(obj_cmd_rs);
  return (rv);
}

int 
get_local_sel_record (ipmi_device_t *dev, 
		      uint16_t record_id, 
		      sel_record_t *sel_rec, 
		      uint16_t *next_record_id)
{
  fiid_obj_t obj_cmd_rs;
  uint64_t val;
  int rv = -1;
  int32_t len;
  
  uint8_t record_data[SEL_RECORD_SIZE];
  uint32_t record_data_len = SEL_RECORD_SIZE;
  
  ERR_EINVAL (dev && sel_rec && next_record_id);
  
  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_get_sel_entry_rs);
  
  if (ipmi_cmd_get_sel_entry (dev, 
			      0,
			      record_id, 
			      0,
			      IPMI_SEL_READ_ENTIRE_RECORD_BYTES_TO_READ,
			      obj_cmd_rs) != 0)
    {
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "cmd", &val);
      dev->cmd = val;
      
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "comp_code", &val);
      dev->comp_code = val;
      ipmi_strerror_cmd_r (obj_cmd_rs, 
                           dev->net_fn,
			   dev->errmsg, 
			   IPMI_ERR_STR_MAX_LEN);
      goto cleanup;
    }
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "next_record_id", &val);
  *next_record_id = val;
  
  FIID_OBJ_GET_DATA_LEN_CLEANUP (len,
				 obj_cmd_rs, 
				 "record_data", 
				 record_data,
				 record_data_len);
  record_data_len = len;
  rv = 0;
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN(obj_cmd_rs);
  if (rv == 0)
    {
      return (get_sel_record (record_data, record_data_len, sel_rec));
    }
  else
    {
      return (rv);
    }
}

int 
get_local_sel_record_raw (ipmi_device_t *dev, 
			  uint16_t record_id, 
			  uint8_t *record_data, 
			  uint32_t record_data_len, 
			  uint16_t *next_record_id)
{
  fiid_obj_t obj_cmd_rs;
  uint64_t val;
  int rv = -1;
  int32_t len;
  
  ERR_EINVAL (dev && record_data && next_record_id);
  
  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_get_sel_entry_rs);
  if (ipmi_cmd_get_sel_entry (dev, 
			      0,
			      record_id, 
			      0,
			      IPMI_SEL_READ_ENTIRE_RECORD_BYTES_TO_READ,
			      obj_cmd_rs) != 0)
    {
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "cmd", &val);
      dev->cmd = val;
      
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "comp_code", &val);
      dev->comp_code = val;
      ipmi_strerror_cmd_r (obj_cmd_rs, 
                           dev->net_fn,
			   dev->errmsg, 
			   IPMI_ERR_STR_MAX_LEN);
      goto cleanup;
    }
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "next_record_id", &val);
  *next_record_id = val;
  
  FIID_OBJ_GET_DATA_LEN_CLEANUP (len,
				 obj_cmd_rs, 
				 "record_data", 
				 record_data,
				 record_data_len);
  record_data_len = len;
  rv = 0;
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN(obj_cmd_rs);
  return (rv);
}

/* SCM */
/* ex_sel_get_next_entry_raw () */
/* { */
/*   uint8_t record_data[SEL_RECORD_SIZE]; */
/*   SCM scm_sel_record = SCM_EOL; */
  
/*   if (ipmi_sel_get_next_entry (fi_get_ipmi_device (),  */
/* 			       fi_get_seld (),  */
/* 			       record_data, SEL_RECORD_SIZE) == 0) */

/*     { */
/*       int i; */
/*       for (i = SEL_RECORD_SIZE - 1; i >= 0; i--) */
/*         scm_sel_record = gh_cons (gh_ulong2scm (record_data[i]), scm_sel_record); */
/*     } */
/*   return scm_sel_record; */
/* } */

/* SCM */
/* ex_sel_get_first_entry_hex () */
/* { */
/*   uint8_t record_data [SEL_RECORD_SIZE]; */
/*   uint8_t hex_data [SEL_HEX_RECORD_SIZE]; */
  
/*   if (ipmi_sel_get_first_entry (fi_get_ipmi_device (),  */
/* 				fi_get_seld (),  */
/* 				record_data, SEL_RECORD_SIZE) == 0) */
/*     { */
/*       snprintf (hex_data, SEL_HEX_RECORD_SIZE, */
/*                 "RID:[%02X][%02X] RT:[%02X] TS:[%02X][%02X][%02X][%02X] " */
/*                 "GID:[%02X][%02X] ER:[%02X] ST:[%02X] SN:[%02X] EDIR:[%02X] " */
/*                 "ED1: [%02X] ED2: [%02X] ED3: [%02X]\n", */
/*                 record_data[0], record_data[1], record_data[2], record_data[3],  */
/*                 record_data[4], record_data[5], record_data[6], record_data[7],  */
/*                 record_data[8], record_data[9], record_data[10], record_data[11],  */
/*                 record_data[12], record_data[13], record_data[14], record_data[15]); */
/*       return gh_str02scm (hex_data); */
/*     } */
/*   else return SCM_BOOL_F; */
/* } */

/* SCM */
/* ex_sel_get_next_entry_hex () */
/* { */
/*   uint8_t record_data [SEL_RECORD_SIZE]; */
/*   uint8_t hex_data [SEL_HEX_RECORD_SIZE]; */
  
/*   if (ipmi_sel_get_next_entry (fi_get_ipmi_device (),  */
/* 			       fi_get_seld (),  */
/* 			       record_data, SEL_RECORD_SIZE) == 0) */
/*     { */
/*       snprintf (hex_data, SEL_HEX_RECORD_SIZE, */
/*                 "RID:[%02X][%02X] RT:[%02X] TS:[%02X][%02X][%02X][%02X] " */
/*                 "GID:[%02X][%02X] ER:[%02X] ST:[%02X] SN:[%02X] EDIR:[%02X] " */
/*                 "ED1: [%02X] ED2: [%02X] ED3: [%02X]\n", */
/*                 record_data[0], record_data[1], record_data[2], record_data[3],  */
/*                 record_data[4], record_data[5], record_data[6], record_data[7],  */
/*                 record_data[8], record_data[9], record_data[10], record_data[11],  */
/*                 record_data[12], record_data[13], record_data[14], record_data[15]); */
/*       return gh_str02scm (hex_data); */
/*     } */
/*   else return SCM_BOOL_F; */
/* } */

/* SCM  */
/* ex_sel_get_info_binary () */
/* { */
/*   local_sel_info_t info; */
  
/*   if (get_sel_info (fi_get_ipmi_device (), &info) == 0) */
/*     { */
/*       SCM tail = SCM_EOL; */
      
/*       tail = gh_cons (info.flags & get_sel_alloc_info_cmd_support ? SCM_BOOL_T : SCM_BOOL_F, tail); */
/*       tail = gh_cons (info.flags & reserve_sel_cmd_support ? SCM_BOOL_T : SCM_BOOL_F, tail); */
/*       tail = gh_cons (info.flags & partial_add_sel_entry_cmd_support ? SCM_BOOL_T : SCM_BOOL_F, tail); */
/*       tail = gh_cons (info.flags & delete_sel_cmd_support ? SCM_BOOL_T : SCM_BOOL_F, tail); */
/*       tail = gh_cons (info.flags & overflow_flag ? SCM_BOOL_T : SCM_BOOL_F, tail); */
      
/*       return gh_cons (gh_ulong2scm (info.version_major), */
/*                       gh_cons (gh_ulong2scm (info.version_minor), */
/*                                gh_cons (gh_ulong2scm (info.entry_count), */
/*                                         gh_cons (gh_ulong2scm (info.last_add_time), */
/*                                                  gh_cons (gh_ulong2scm (info.last_erase_time), */
/*                                                           gh_cons (gh_ulong2scm (info.free_space), */
/*                                                                    tail)))))); */
/*     } */
/*   else return SCM_BOOL_F; */
/* } */

/* SCM  */
/* ex_sel_get_first_entry () */
/* { */
/*   uint8_t record_data[SEL_RECORD_SIZE]; */
/*   sel_record_t sel_rec; */
/*   SCM scm_sel_record = SCM_EOL; */
  
/*   if (ipmi_sel_get_first_entry (fi_get_ipmi_device (),  */
/* 				fi_get_seld (),  */
/* 				record_data, SEL_RECORD_SIZE) != 0) */
/*     return SCM_EOL; */
  
/*   if (get_sel_record (record_data, &sel_rec) != 0) */
/*     return SCM_EOL; */
  
/*   scm_sel_record = gh_list (gh_long2scm (sel_rec.record_id), SCM_UNDEFINED); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.timestamp),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.sensor_info),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_message),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_data2_message),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_data3_message),  */
/* 					SCM_UNDEFINED)); */
  
/*   if (sel_rec.timestamp) free (sel_rec.timestamp); */
/*   if (sel_rec.sensor_info) free (sel_rec.sensor_info); */
/*   if (sel_rec.event_message) free (sel_rec.event_message); */
/*   if (sel_rec.event_data2_message) free (sel_rec.event_data2_message); */
/*   if (sel_rec.event_data3_message) free (sel_rec.event_data3_message); */
  
/*   return scm_sel_record; */
/* } */

/* SCM  */
/* ex_sel_get_next_entry () */
/* { */
/*   uint8_t record_data[SEL_RECORD_SIZE]; */
/*   sel_record_t sel_rec; */
/*   SCM scm_sel_record = SCM_EOL; */
  
/*   if (ipmi_sel_get_next_entry (fi_get_ipmi_device (),  */
/* 			       fi_get_seld (),  */
/* 			       record_data, SEL_RECORD_SIZE) != 0) */
/*     return SCM_EOL; */
  
/*   if (get_sel_record (record_data, &sel_rec) != 0) */
/*     return SCM_EOL; */
  
/*   scm_sel_record = gh_list (gh_long2scm (sel_rec.record_id), SCM_UNDEFINED); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.timestamp),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.sensor_info),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_message),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_data2_message),  */
/* 					SCM_UNDEFINED)); */
/*   scm_sel_record = gh_append2 (scm_sel_record,  */
/* 			       gh_list (gh_str02scm (sel_rec.event_data3_message),  */
/* 					SCM_UNDEFINED)); */
  
/*   if (sel_rec.timestamp) free (sel_rec.timestamp); */
/*   if (sel_rec.sensor_info) free (sel_rec.sensor_info); */
/*   if (sel_rec.event_message) free (sel_rec.event_message); */
/*   if (sel_rec.event_data2_message) free (sel_rec.event_data2_message); */
/*   if (sel_rec.event_data3_message) free (sel_rec.event_data3_message); */
  
/*   return scm_sel_record; */
/* } */

/* SCM  */
/* ex_sel_delete_entry (SCM scm_record_id) */
/* { */
/*   uint16_t record_id; */
/*   fiid_obj_t obj_cmd_rs; */
/*   uint16_t reservation_id; */
/*   uint64_t val; */
  
/*   record_id = gh_scm2long (scm_record_id); */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_reserve_sel_rs); */
/*   if (ipmi_cmd_reserve_sel2 (fi_get_ipmi_device (),  */
/* 			     obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_reserve_sel2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   fiid_obj_get (obj_cmd_rs,  */
/* 		tmpl_reserve_sel_rs,  */
/* 		"reservation_id",  */
/* 		&val); */
/*   reservation_id = val; */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_delete_sel_entry_rs); */
/*   if (ipmi_cmd_delete_sel_entry2 (fi_get_ipmi_device (),  */
/* 				  reservation_id,  */
/* 				  record_id,  */
/* 				  obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_delete_sel_entry2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   return SCM_BOOL_T; */
/* } */

/* SCM  */
/* ex_sel_clear () */
/* { */
/*   fiid_obj_t obj_cmd_rs; */
/*   uint16_t reservation_id; */
/*   uint64_t val; */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_reserve_sel_rs); */
/*   if (ipmi_cmd_reserve_sel2 (fi_get_ipmi_device (),  */
/* 			     obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_reserve_sel2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   fiid_obj_get (obj_cmd_rs,  */
/* 		tmpl_reserve_sel_rs,  */
/* 		"reservation_id",  */
/* 		&val); */
/*   reservation_id = val; */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_clear_sel_rs); */
/*   if (ipmi_cmd_clear_sel2 (fi_get_ipmi_device (),  */
/* 			   reservation_id,  */
/* 			   IPMI_SEL_INITIATE_ERASE,  */
/* 			   obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_clear_sel2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   return SCM_BOOL_T; */
/* } */

/* SCM  */
/* ex_sel_get_clear_status () */
/* { */
/*   fiid_obj_t obj_cmd_rs; */
/*   uint16_t reservation_id; */
/*   uint64_t val; */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_reserve_sel_rs); */
/*   if (ipmi_cmd_reserve_sel2 (fi_get_ipmi_device (),  */
/* 			     obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_reserve_sel2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   fiid_obj_get (obj_cmd_rs,  */
/* 		tmpl_reserve_sel_rs,  */
/* 		"reservation_id",  */
/* 		&val); */
/*   reservation_id = val; */
  
/*   fiid_obj_alloca (obj_cmd_rs, tmpl_clear_sel_rs); */
/*   if (ipmi_cmd_clear_sel2 (fi_get_ipmi_device (),  */
/* 			   reservation_id,  */
/* 			   IPMI_SEL_GET_ERASURE_STATUS,  */
/* 			   obj_cmd_rs) != 0) */
/*     { */
/*       ipmi_error (obj_cmd_rs, "ipmi_cmd_clear_sel2()"); */
/*       return SCM_BOOL_F; */
/*     } */
  
/*   fiid_obj_get (obj_cmd_rs,  */
/* 		tmpl_clear_sel_rs,  */
/* 		"erasure_progress",  */
/* 		&val); */
/*   return (gh_long2scm (val)); */
/* } */

