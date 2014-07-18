#include <mavlink.h>
#include <common.h>
#include<stdio.h>
mavlink_message_t msg ;
mavlink_message_t msgOut ;
mavlink_status_t status;
uint8_t getMessageId(){    
    return msg.msgid;
}

uint8_t parseMavlink(uint8_t c){
    return mavlink_parse_char(0,c,&msg,&status);
}

uint8_t requestAttitude(uint8_t* buf){
    mavlink_msg_request_data_stream_pack(255,0,&msgOut,1,0,10,50,1);
    mavlink_msg_to_send_buffer(buf, &msgOut);
    return msgOut.len;
}

void getRoll(double *roll){
    double roll2 = (double)mavlink_msg_attitude_get_roll(&msg);
     *roll= roll2;      
}
void getPitch(double *pitch){
    double pitch2 =(double)mavlink_msg_attitude_get_pitch(&msg);
    *pitch =  pitch2;
}