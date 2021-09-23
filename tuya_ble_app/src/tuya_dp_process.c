#include "tuya_ble_api.h"

#include "tuya_dp_process.h"


union AXIS_DATA x_axis_mg;
union AXIS_DATA y_axis_mg;
union AXIS_DATA z_axis_mg;

LIS2DW12 lis2dw12;

void dp_init(void)
{
	lis2dw12.x_axis.dp_id = DPID_X_AXIS;
	lis2dw12.x_axis.dp_type = TUYA_DP_TYPE_VALUE;
	lis2dw12.x_axis.dp_data_len = 4;
	lis2dw12.x_axis.dp_data = x_axis_mg.axis_buf;

	lis2dw12.y_axis.dp_id = DPID_Y_AXIS;
	lis2dw12.y_axis.dp_type = TUYA_DP_TYPE_VALUE;
	lis2dw12.y_axis.dp_data_len = 4;
	lis2dw12.y_axis.dp_data = y_axis_mg.axis_buf;

	lis2dw12.z_axis.dp_id = DPID_Z_AXIS;
	lis2dw12.z_axis.dp_type = TUYA_DP_TYPE_VALUE;
	lis2dw12.z_axis.dp_data_len = 4;
	lis2dw12.z_axis.dp_data = z_axis_mg.axis_buf;
}

void dp_update(unsigned char dp_id, unsigned char dp_type, unsigned char *dp_date, unsigned short dp_data_len)
{
	uint16_t i = 0;
	unsigned char dp_data_array[16];

	dp_data_array[0] = dp_id;
	dp_data_array[1] = dp_type;
	dp_data_array[2] = dp_data_len;
	for (i = 0; i < dp_data_array[2]; i++) { //将联合体中数据颠倒
		dp_data_array[i + 3] = *(dp_date + (3-i));
	}
	tuya_ble_dp_data_report(dp_data_array, (dp_data_array[2] + 3));
}

void dp_update_all(void)
{
	dp_update(lis2dw12.x_axis.dp_id,
			lis2dw12.x_axis.dp_type,
			lis2dw12.x_axis.dp_data,
			lis2dw12.x_axis.dp_data_len);

	dp_update(lis2dw12.y_axis.dp_id,
			lis2dw12.y_axis.dp_type,
			lis2dw12.y_axis.dp_data,
			lis2dw12.y_axis.dp_data_len);

	dp_update(lis2dw12.z_axis.dp_id,
			lis2dw12.z_axis.dp_type,
			lis2dw12.z_axis.dp_data,
			lis2dw12.z_axis.dp_data_len);
}
