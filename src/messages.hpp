

// InterModules command
#define CMD_TYPE_INTERMODULE "uv"








// Communication Commands
// group broadcast
#define CMD_COMM_GROUP                  "g" 
// individual broadcast
#define CMD_COMM_INDIVIDUAL             "i" 
    

#define ANDRUAV_PROTOCOL_GROUP_ID       "gr"
#define ANDRUAV_PROTOCOL_SENDER         "sd"
#define ANDRUAV_PROTOCOL_COMM_TYPE      "cm"
#define ANDRUAV_PROTOCOL_TARGET_ID      "tg"
#define ANDRUAV_PROTOCOL_MESSAGE_TYPE   "mt"
#define ANDRUAV_PROTOCOL_MESSAGE_CMD    "ms"
#define INTERMODULE_COMMAND_TYPE        "ty"


#define TYPE_AndruavModule_ID                   9100

#define TYPE_AndruavResala_GPS                  1002
#define TYPE_AndruavResala_POWER                1003
#define TYPE_AndruavResala_ID 	                1004
#define TYPE_AndruavResala_RemoteExecute 		1005     
#define TYPE_AndruavResala_Error                1008    
#define TYPE_AndruavResala_FlightControl        1010
#define Type_AndruavResala_HomeLocation         1022
#define TYPE_AndruavResala_Arm                  1030
#define TYPE_AndruavResala_ChangeAltitude       1031
#define TYPE_AndruavResala_Land                 1032
#define TYPE_AndruavResala_GuidedPoint          1033
#define TYPE_AndruavResala_DoYAW                1035
#define TYPE_AndruavResala_NAV_INFO             1036
#define TYPE_AndruavResala_ChangeSpeed          1040
#define TYPE_AndruavResala_SET_HOME_LOCATION    1048

// Error Info Types
#define NOTIFICATION_TYPE_TELEMETRY             33
#define NOTIFICATION_TYPE_PROTOCOL              44
#define NOTIFICATION_TYPE_LO7ETTA7AKOM          77
#define NOTIFICATION_TYPE_GEO_FENCE             88

// Error Numbers
#define ERROR_TYPE_LO7ETTA7AKOM                 5
#define ERROR_3DR                               7
#define ERROR_GPS                               10
#define ERROR_POWER                             11
#define ERROR_GEO_FENCE_ERROR                   100

// 0	MAV_SEVERITY_EMERGENCY	System is unusable. This is a "panic" condition.
#define NOTIFICATION_TYPE_EMERGENCY             0
// 1	MAV_SEVERITY_ALERT	Action should be taken immediately. Indicates error in non-critical systems.
#define NOTIFICATION_TYPE_ALERT                 1
// 2	MAV_SEVERITY_CRITICAL	Action must be taken immediately. Indicates failure in a primary system.
#define NOTIFICATION_TYPE_CRITICAL              2
// 3	MAV_SEVERITY_ERROR	Indicates an error in secondary/redundant systems.
#define NOTIFICATION_TYPE_ERROR                 3
// 4	MAV_SEVERITY_WARNING	Indicates about a possible future error if this is not resolved within a given timeframe. Example would be a low battery warning.
#define NOTIFICATION_TYPE_WARNING               4
// 5	MAV_SEVERITY_NOTICE	An unusual event has occurred, though not an error condition. This should be investigated for the root cause.
#define NOTIFICATION_TYPE_NOTICE                5
// 6	MAV_SEVERITY_INFO	Normal operational messages. Useful for logging. No action is required for these messages.
#define NOTIFICATION_TYPE_INFO                  6
// 7	MAV_SEVERITY_DEBUG	Useful non-operational messages that can assist in debugging. These should not occur during normal operation.
#define NOTIFICATION_TYPE_DEBUG                 7







#define GPS_MODE_AUTO                           0
// .a.k.a mobile... i.e. gps info used bu uavos comm is not from the board
#define GPS_MODE_EXTERNAL                       1
#define GPS_MODE_FCB                            2