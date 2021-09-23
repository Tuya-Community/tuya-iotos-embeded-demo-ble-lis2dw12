#include "drivers.h"
#include "app_config.h"
#include "drivers/8258/i2c.h"

#include "tuya_ble_log.h"
#include "tuya_dp_process.h"
#include "tuya_app_lis2dw12.h"

#define I2C_CLK_SPEED 200000

unsigned char lis2dw12_init(void)
{
    i2c_gpio_set(I2C_GPIO_GROUP_C0C1);
    i2c_master_init(LIS2DW12_I2C_ADD_H, (unsigned char)(CLOCK_SYS_CLOCK_HZ / (4 * I2C_CLK_SPEED)));

    /* who am i */
    if (LIS2DW12_ID != i2c_read_byte(LIS2DW12_WHO_AM_I, 1)) {
        /* error */
        return 0;
    }

    i2c_write_byte(LIS2DW12_CTRL1, 1, 0x63);//0x63 : ODR:200HZ, low power mode4,
    i2c_write_byte(LIS2DW12_CTRL2, 1, 0x84);//1000 0100
    i2c_write_byte(LIS2DW12_CTRL6, 1, 0x04);//0000 0100 +-2g,
    //i2c_write_byte(LIS2DW12_STATUS_DUP, 1, 0x41);

    return 1;
}

short get_lis2dw12_x_value(void)
{
	unsigned char x_axis_low;
	unsigned char x_axis_high;

    i2c_master_init(LIS2DW12_I2C_ADD_H, (unsigned char)(CLOCK_SYS_CLOCK_HZ / (4 * I2C_CLK_SPEED)));

	x_axis_low = i2c_read_byte(LIS2DW12_OUT_X_L, 1);
	x_axis_high = i2c_read_byte(LIS2DW12_OUT_X_H, 1);

	return ((x_axis_high<<8)|x_axis_low);
}

short get_lis2dw12_y_value(void)
{
	unsigned char y_axis_low;
	unsigned char y_axis_high;

    i2c_master_init(LIS2DW12_I2C_ADD_H, (unsigned char)(CLOCK_SYS_CLOCK_HZ / (4 * I2C_CLK_SPEED)));

	y_axis_low = i2c_read_byte(LIS2DW12_OUT_Y_L, 1);
	y_axis_high = i2c_read_byte(LIS2DW12_OUT_Y_H, 1);

	return ((y_axis_high<<8)|y_axis_low);
}

short get_lis2dw12_z_value(void)
{
	unsigned char z_axis_low;
	unsigned char z_axis_high;

    i2c_master_init(LIS2DW12_I2C_ADD_H, (unsigned char)(CLOCK_SYS_CLOCK_HZ / (4 * I2C_CLK_SPEED)));

	z_axis_low = i2c_read_byte(LIS2DW12_OUT_Z_L, 1);
	z_axis_high = i2c_read_byte(LIS2DW12_OUT_Z_H, 1);

	return ((z_axis_high<<8)|z_axis_low);
}

long get_lis2dw12_x_mg(void)
{
	long x_mg;
	x_mg = get_lis2dw12_x_value() / 4 * 244; //除以1000为真实值

	return x_mg;
}

long get_lis2dw12_y_mg(void)
{
	long y_mg;
	y_mg = get_lis2dw12_y_value() / 4 * 244; //除以1000为真实值

	return y_mg;
}

long get_lis2dw12_z_mg(void)
{
	long z_mg;
	z_mg = get_lis2dw12_z_value() / 4 * 244; //除以1000为真实值

	return z_mg;
}

unsigned char lis2dw12_status(LIS2DW12_STATUS status)
{
	unsigned char ret = 0;

	i2c_master_init(LIS2DW12_I2C_ADD_H, (unsigned char)(CLOCK_SYS_CLOCK_HZ / (4 * I2C_CLK_SPEED)));

	ret = (i2c_read_byte(STATUS, 1) & status);

	return ret;
}



