#ifndef __TUYA_DP_PROCESS_H__
#define __TUYA_DP_PROCESS_H__

union AXIS_DATA
{
	unsigned char axis_buf[4];
	long axis_mg;
};

/* tuya data point type */
#define TUYA_DP_TYPE_BOOL		1
#define TUYA_DP_TYPE_VALUE		2
#define TUYA_DP_TYPE_STRING		3
#define TUYA_DP_TYPE_ENUM		4
#define TUYA_DP_TYPE_BITMAP		5

#define DPID_X_AXIS	101
#define DPID_Y_AXIS	102
#define DPID_Z_AXIS	103

typedef struct {
	unsigned char dp_id;
	unsigned char dp_type;
	unsigned char dp_data_len;
	unsigned char *dp_data;
}DataPoint;

typedef struct {
	DataPoint x_axis;
	DataPoint y_axis;
	DataPoint z_axis;
}LIS2DW12;

extern LIS2DW12 lis2dw12;

void dp_init(void);
void dp_update(unsigned char dp_id, unsigned char dp_type, unsigned char *dp_date, unsigned short dp_data_len);
void dp_update_all(void);

#endif /* __TUYA_DP_PROCESS_H__ */
