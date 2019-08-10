
#include <stdio.h>
#include <string.h>
#include "NEMA.h"

void NEMA_SET_OUTPUT(Nema_Output_Format_T format)
{
    char *cmd = "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29";
    if(format == NEMA_OUTPUT_FORMAT_RMC_ONLY){
        printf("%s",cmd);
    }
}

char NEMA_RMC_Dispatch(const char *rmc_data_buf, const Gps_Info_T *rmc_info)
{
    //strstr for RMC data frame
    char * temp_buf = NULL;
    int count = 0;
    
    temp_buf = strstr(rmc_data_buf,"$GPRMC");
    temp_buf[sizeof(Gps_Info_T)]='\0';
    //sscanf for exact data
    if(temp_buf!= NULL){

    count = sscanf(temp_buf,"$GPRMC,%[^,],%c,%[^,],%c,%[^,],%c,%[^,],%[^,],%[^,]",\
                                                 rmc_info->utc_time,\
                                                 &rmc_info->status,\
                                                 rmc_info->latitude_value,\
                                                 &rmc_info->latitude,\
                                                 rmc_info->longtitude_value,\
                                                 &rmc_info->longtitude,\
                                                 rmc_info->speed,\
                                                 rmc_info->azimuth_angle,\
                                                 rmc_info->utc_date);\


        if(count ==9){
      return 0;
     }
    }
    return -1;
}