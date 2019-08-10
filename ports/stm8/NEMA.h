#ifndef __NEMA_H
#define __NEMA_H

#endif
typedef enum Nema_Output_Format
{
    NEMA_OUTPUT_FORMAT_RMC_ONLY//$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29
}Nema_Output_Format_T;


 //    $GPRMC,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,<12>*hh<CR><LF> 
    //<1> UTC时间，hhmmss（时分秒）格式 
    //<2> 定位状态，A=有效定位，V=无效定位 
    //<3> 纬度ddmm.mmmm（度分）格式（前面的0也将被传输） 
    //<4> 纬度半球N（北半球）或S（南半球） 
    //<5> 经度dddmm.mmmm（度分）格式（前面的0也将被传输） 
    //<6> 经度半球E（东经）或W（西经） 
    //<7> 地面速率（000.0~999.9节，前面的0也将被传输） 
    //<8> 地面航向（000.0~359.9度，以真北为参考基准，前面的0也将被传输） 
    //<9> UTC日期，ddmmyy（日月年）格式 
    //<10> 磁偏角（000.0~180.0度，前面的0也将被传输） 
    //<11> 磁偏角方向，E（东）或W（西） 
    //<12> 模式指示（仅NMEA0183 3.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效）
typedef  struct data{
        char utc_time[10+1];
        char status;
        char latitude_value[9+1];
        char latitude;
        char longtitude_value[10+1];
        char longtitude;
        char speed[4+1];
        float azimuth_angle[6+1];
        char utc_date[6+1];              
}Gps_Info_T;



void NEMA_SET_OUTPUT(Nema_Output_Format_T format);

char NEMA_RMC_Dispatch(const char *rmc_data_buf, const Gps_Info_T *rmc_info);