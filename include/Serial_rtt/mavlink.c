#include <mavlink.h>
#include <common.h>
#include<stdio.h>
mavlink_message_t msg ;
mavlink_message_t msgOut ;
mavlink_message_t msgOut2 ;
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
uint8_t sendArmDisarm(uint8_t* buf,uint8_t armdisarm){
    float ad = (float)armdisarm;
    mavlink_msg_command_long_pack(255,0,&msgOut,1,0,400,0,
            ad,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
    mavlink_msg_to_send_buffer(buf, &msgOut);
    return msgOut.len+8;
}

uint8_t sendRPYT(uint8_t* buf,uint16_t R,uint16_t P,uint16_t Y,uint16_t T){
    uint16_t pack;
    uint16_t sendz;    
    pack= mavlink_msg_rc_channels_override_pack(255,0,&msgOut2,1,0,R,P,T,Y,0,0,0,0);  
    sendz= mavlink_msg_to_send_buffer(buf,&msgOut2);
    fprintf(stderr,"after buffer %i\t %i\t %f\n",pack,sendz,msgOut2.len);
    return (uint8_t)sendz;  
}

