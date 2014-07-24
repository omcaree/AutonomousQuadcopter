joy = vrjoystick(1);
set_param('RaspPiPilot/joystickVals/Constant6','Value','1500');
set_param('RaspPiPilot/joystickVals/Constant6','Value','1500');
set_param('RaspPiPilot/joystickVals/Constant6','Value','1000');
set_param('RaspPiPilot/joystickVals/Constant6','Value','1500');
set_param('RaspPiPilot/joystickVals/Constant1','Value','0');
set_param('RaspPiPilot/joystickVals/Constant2','Value','0');
navOn=0;
while(1)
    pitch= axis(joy,2)*500+1500;
    set_param('RaspPiPilot/joystickVals/Constant3','Value',num2str(round(pitch)));
    roll= axis(joy,1)*500+1500;
    set_param('RaspPiPilot/joystickVals/Constant4','Value',num2str(round(roll)));
    throttle= (axis(joy,4)+1)*250+1000;
    set_param('RaspPiPilot/joystickVals/Constant5','Value',num2str(round(throttle)));
    yaw= axis(joy,3)*500+1500;
    set_param('RaspPiPilot/joystickVals/Constant6','Value',num2str(round(yaw)));
    if button(joy,3)
        set_param('RaspPiPilot/joystickVals/Constant1','Value','1');
    else
        set_param('RaspPiPilot/joystickVals/Constant1','Value','0');
    end
    if button(joy,4)
        set_param('RaspPiPilot/joystickVals/Constant2','Value','1');
    else
        set_param('RaspPiPilot/joystickVals/Constant2','Value','0');
    end
    if button(joy,5)
        navOn=~navOn;
        set_param('RaspPiPilot/joystickVals/Constant7','Value',num2str(navOn));
        pause(1);
    end
    if button(joy,8)
        break;
    end
    pause(1/50);
end