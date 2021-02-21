#ifndef WAYPOINT_MANAGER_H_
#define WAYPOINT_MANAGER_H_

#include "mavlink_helper.h"

//class mavlinksdk::CMavlinkCommand;

namespace mavlinksdk
{

#define WAYPOINT_STATE_IDLE                 0
#define WAYPOINT_STATE_READ_REQUEST         1
#define WAYPOINT_STATE_READ_WP              2    
#define WAYPOINT_STATE_WRITING_WP_COUNT     3    
#define WAYPOINT_STATE_WRITING_WP           4    
#define WAYPOINT_STATE_WRITING_ACK          5


/**
 * @brief This class manage waypoints
 * 
 */
class CCallBack_WayPoint
{
    public:

    virtual void onWaypointReached(const int& sequence)        {};
    virtual void onWayPointsLoadingCompleted() {}; 
    virtual void onMissionACK (const int& result, const int& mission_type, const std::string& result_msg) {};
    virtual void onWayPointReceived (const mavlink_mission_item_int_t& mission_item_int) {};
        
};

class CMavlinkWayPointManager
{
    public:
        
        explicit CMavlinkWayPointManager(mavlinksdk::CCallBack_WayPoint& callback_waypoint);
        ~CMavlinkWayPointManager() {};
    
        void parseMessage (const mavlink_message_t& mavlink_message);
    

    public:

            void reloadWayPoints();
            void clearWayPoints();


    protected:
            
            inline void handle_mission_ack   (const mavlink_mission_ack_t& mission_ack);
            inline void handle_mission_count (const mavlink_mission_count_t& mission_count);
            inline void handle_mission_current   (const mavlink_mission_current_t& mission_current);
            inline void handle_mission_item (const mavlink_mission_item_int_t& mission_item_int);
            inline void handle_mission_item_reached (const mavlink_mission_item_reached_t& mission_item_reached);


    // Class Members
    protected:
        mavlinksdk::CCallBack_WayPoint& m_callback_waypoint;

        uint16_t  m_mission_current = 0;
        uint16_t  m_mission_count   = 0;
        uint16_t  m_mission_waiting_for_seq   = 0;

        int m_state = WAYPOINT_STATE_IDLE;
        
      
};

}


#endif