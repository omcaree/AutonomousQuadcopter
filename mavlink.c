#include <mavlink.h>
#include <common.h>
#include<stdio.h>
mavlink_message_t msg ;
mavlink_message_t msgTemp ;
mavlink_message_t msgOut ;
mavlink_message_t msgOut2 ;
mavlink_status_t status;
mavlink_sys_status_t sysStatus;
mavlink_heartbeat_t heartMsg;

uint8_t getMessageId(int32_t ii,int32_t ll){
    fprintf(stderr,"msg id : %i \t %i \n",msg.msgid,msg.seq);
    return msg.msgid;
}

uint8_t parseMavlink(uint8_t c ){
    uint8_t endPackage= mavlink_parse_char(0,c,&msgTemp,&status);
    if(endPackage){
        msg=msgTemp;
    }
    return endPackage;
}
uint8_t parseHeartBeat(){
mavlink_msg_heartbeat_decode(&msg,&heartMsg);
fprintf(stderr,"HB sys status : %i \t mode %i \n",heartMsg.system_status,heartMsg.base_mode);
return heartMsg.base_mode;
}

uint8_t requestStream(uint8_t* buf,uint8_t id){
    mavlink_msg_request_data_stream_pack(255,0,&msgOut,1,0,id,50,1);
    mavlink_msg_to_send_buffer(buf, &msgOut);
   fprintf(stderr,"streamRequested %i",id);
    return msgOut.len+8;
}

void getRoll(double *roll){
    double roll2 = (double)mavlink_msg_attitude_get_roll(&msg);
     *roll= roll2;      
}
void getPitch(double *pitch){
    double pitch2 =(double)mavlink_msg_attitude_get_pitch(&msg);
    *pitch =  pitch2;
   
}
void getYaw(double *yaw){
    double yaw2 =(double)mavlink_msg_attitude_get_yaw(&msg);
    *yaw =  yaw2;    
}
void parseIMU(double *xxacc, double *yyacc, double *zzacc, double *xxGyro, double *yyGyro, double *zzGyro, double *t){
    uint32_t timestamp = mavlink_msg_raw_imu_get_time_usec(&msg);
 double xacc =(double)mavlink_msg_raw_imu_get_xacc(&msg); ///< X Position
 double yacc=(double)mavlink_msg_raw_imu_get_yacc(&msg); ///< Y Position
 double zacc=(double)mavlink_msg_raw_imu_get_zacc(&msg); ///< Z Position
 double xGyro=(double)mavlink_msg_raw_imu_get_xgyro(&msg); ///< X Speed
 double yGyro=(double)mavlink_msg_raw_imu_get_ygyro(&msg); ///< Y Speed
 double zGyro=(double)mavlink_msg_raw_imu_get_zgyro(&msg);// hmm i wonder what this is
 *xxacc=xacc;
 *yyacc=yacc;
 *zzacc=zacc;
 *xxGyro=xGyro;
 *yyGyro=yGyro;
 *zzGyro=zGyro;
 }

void parseControllerOutput(double *nav_roll,double *nav_pitch,double *alt_error,double *aspd_error, int16_t *nav_bearing,int16_t *target_bearing, uint16_t *wp_dist) {
 double nav_roll_a= (double)mavlink_msg_nav_controller_output_get_nav_roll(&msg); ///< Current desired roll in degrees
 double nav_pitch_a=(double) mavlink_msg_nav_controller_output_get_nav_pitch(&msg); ///< Current desired pitch in degrees
 double alt_error_a= (double)mavlink_msg_nav_controller_output_get_nav_bearing(&msg); ///< Current altitude error in meters
 double aspd_error_a=(double) mavlink_msg_nav_controller_output_get_target_bearing(&msg); ///< Current airspeed error in meters/second
 double xtrack_error_a= (double)mavlink_msg_nav_controller_output_get_wp_dist(&msg); ///< Current crosstrack error on x-y plane in meters
 int16_t nav_bearing_a=(double) mavlink_msg_nav_controller_output_get_alt_error(&msg); ///< Current desired heading in degrees
 int16_t target_bearing_a=(double) mavlink_msg_nav_controller_output_get_aspd_error(&msg); ///< Bearing to current MISSION/target in degrees
 uint16_t wp_dist_a= (double)mavlink_msg_nav_controller_output_get_xtrack_error(&msg); ///< Distance to active MISSION in meters
*nav_roll= nav_roll_a; 
*nav_pitch =nav_pitch_a;
*alt_error =alt_error_a;
*aspd_error =aspd_error_a;
*nav_bearing =nav_bearing_a;
*target_bearing =target_bearing_a;
*wp_dist=wp_dist_a;
}

uint8_t sendArmDisarm(uint8_t* buf, uint8_t armdisarm){
    float ad = (float)armdisarm;
    mavlink_msg_command_long_pack(255,0,&msgOut,1,250,400,0,
            ad,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);    
    mavlink_msg_to_send_buffer(buf, &msgOut);
    return msgOut.len+8;
}

uint8_t sendRPTY(uint8_t* buf,uint16_t R,uint16_t P,uint16_t T,uint16_t Y){
    uint16_t pack;
    uint16_t sendz;    
    pack= mavlink_msg_rc_channels_override_pack(255,0,&msgOut2,1,0,R,P,T,Y,0,0,0,0);  
    sendz= mavlink_msg_to_send_buffer(buf,&msgOut2);
    fprintf(stderr,"RPYT sent \n");
    return (uint8_t)sendz;  
}
void getResult(uint8_t* result){
    uint8_t result2 =mavlink_msg_command_ack_get_result(&msg);
//     uint8_t result ;
//     *result=  result2;
    fprintf(stderr,"ACK Result: %i \n",result2);
}
void getString() {
    uint8_t buf[256];
    mavlink_msg_encapsulated_data_get_data(&msg,buf);
    fprintf(stderr,"%s",buf);
}    
void parseSysStatus(){
mavlink_msg_sys_status_decode(&msg,&sysStatus);
fprintf(stderr,"i% i% i% i% i% i% i% i% i% i% \n",
        sysStatus.onboard_control_sensors_present,
        sysStatus.onboard_control_sensors_enabled,
        sysStatus.onboard_control_sensors_health,
        sysStatus.load, sysStatus.drop_rate_comm,
        sysStatus.errors_comm,sysStatus.errors_count1,
        sysStatus.errors_count2,sysStatus.errors_count3,
        sysStatus.errors_count4);
}
void debugg(){
    fprintf(stderr,"debug");
}