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