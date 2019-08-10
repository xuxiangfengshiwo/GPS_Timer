#ifndef __NEMA_H
#define __NEMA_H

#endif
typedef enum Nema_Output_Format
{
    NEMA_OUTPUT_FORMAT_RMC_ONLY//$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29
}Nema_Output_Format_T;


 //    $GPRMC,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,<12>*hh<CR><LF> 
    //<1> UTCʱ�䣬hhmmss��ʱ���룩��ʽ 
    //<2> ��λ״̬��A=��Ч��λ��V=��Ч��λ 
    //<3> γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩 
    //<4> γ�Ȱ���N�������򣩻�S���ϰ��� 
    //<5> ����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩 
    //<6> ���Ȱ���E����������W�������� 
    //<7> �������ʣ�000.0~999.9�ڣ�ǰ���0Ҳ�������䣩 
    //<8> ���溽��000.0~359.9�ȣ����汱Ϊ�ο���׼��ǰ���0Ҳ�������䣩 
    //<9> UTC���ڣ�ddmmyy�������꣩��ʽ 
    //<10> ��ƫ�ǣ�000.0~180.0�ȣ�ǰ���0Ҳ�������䣩 
    //<11> ��ƫ�Ƿ���E��������W������ 
    //<12> ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч��
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