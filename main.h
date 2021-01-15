#ifndef MAIN_H
#define MAIN_H


#define IMU_PARSE_STATE_SYNC1_ID      0xAA
#define IMU_PARSE_STATE_SYNC2_ID      0x55

typedef union
{
  unsigned char payload[1024];
}ParseUnion;

typedef struct {
    volatile unsigned char state;
    volatile unsigned int count;
    volatile unsigned int id;
    volatile unsigned int length;
    volatile uint32_t check;
    volatile unsigned char id_temp;
    volatile unsigned char length_temp;
    volatile unsigned char check_temp1;
    volatile unsigned char check_temp2;
    volatile unsigned char check_temp3;
    volatile unsigned char check_temp4;

} ParseStruct;




typedef enum {
    IMU_PARSE_STATE_WAIT_SYNC1=0,
    IMU_PARSE_STATE_WAIT_SYNC2,
    IMU_PARSE_STATE_WAIT_ID1,
    IMU_PARSE_STATE_WAIT_ID,
    IMU_PARSE_STATE_WAIT_LENGTH1,
    IMU_PARSE_STATE_WAIT_LENGTH2,
    IMU_PARSE_STATE_PAYLOAD,
    IMU_PARSE_STATE_CHECK1,
    IMU_PARSE_STATE_CHECK2,
    IMU_PARSE_STATE_CHECK3,
    IMU_PARSE_STATE_CHECK4
} imu_parse_state_t;




struct  AG_DATA
{
uint32_t time_ms;
float wheel_angle;//deg
float roll;//deg
float pitch;//deg
float yaw;//deg
int32_t pos[3];//lat*1e7 deg,lng*1e7 deg,alt mm
float vel[3];//ned,m/s
uint16_t wheel_base;//mm
int16_t rtk_leverarm_x;//RTK主天线杆臂向量X--mm
int16_t rtk_leverarm_y;//RTK主天线杆臂向量Y--mm
int16_t rtk_leverarm_z;//RTK主天线杆臂向量Z--mm
uint32_t itow;
uint8_t heading_fix;
uint8_t rtk_fix;
uint8_t antenna_type;
uint8_t wheelangle_valid;
}__attribute__((packed));


#endif
