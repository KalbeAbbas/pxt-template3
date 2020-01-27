#include "xChip.h"

using namespace pxt;

// function prototypes
static bool wireWriteByte(uint8_t val);
static bool wireWriteDataByte(uint8_t reg, uint8_t val);
static bool wireWriteDataBlock(uint8_t reg, uint8_t *val, int len);
static bool wireReadDataByte(uint8_t reg, uint8_t &val);
static int wireReadDataBlock(uint8_t reg, uint8_t *val, int len);
static void delay(uint16_t time);


myClass::myClass()
{
}

int myClass::begin(int var)
{
    return var;
}

uint8_t myClass::readDeviceID(uint8_t deviceIDReg)
{
    uint8_t id;
    wireReadDataByte(deviceIDReg, id);
    return id;
}

int myClass::delay(uint32_t time_ms)
{
    sleep_ms(time_ms);
}

static bool wireWriteByte(uint8_t val)
{
auto sda = LOOKUP_PIN(SDA);
auto scl = LOOKUP_PIN(SCL);
codal::I2C *i2c = pxt::getI2C(sda, scl);
    int error;
    error = i2c->write((uint16_t)ADDR, (uint8_t *)&val, 1);
    if (error != 0)
    {
        return false;
    }
    return true;
}

static bool wireWriteDataByte(uint8_t reg, uint8_t val)
{
    auto sda = LOOKUP_PIN(SDA);
auto scl = LOOKUP_PIN(SCL);
codal::I2C *i2c = pxt::getI2C(sda, scl);
    int error;
    uint8_t buf[2];
    buf[0] = (uint8_t)reg;
    buf[1] = (uint8_t)val;
    error = i2c->write((uint16_t)ADDR, (uint8_t *)&buf, 2);
    if (error != 0)
    {
        return false;
    }
    return true;
}

static bool wireWriteDataBlock(uint8_t reg, uint8_t *val, int len)
{
    return true;
}

static bool wireReadDataByte(uint8_t reg, uint8_t &val)
{
    auto sda = LOOKUP_PIN(SDA);
auto scl = LOOKUP_PIN(SCL);
codal::I2C *i2c = pxt::getI2C(sda, scl);
    int error;
    error = i2c->write((uint16_t)ADDR, (uint8_t *)&reg, 1, true);
    if (error != 0)
    {
        return false;
    }
    error = i2c->read((uint16_t)ADDR, (uint8_t *)&val, 1);
    if (error != 0)
    {
        return false;
    }
    return true;
}

static int wireReadDataBlock(uint8_t reg, uint8_t *val, int len)
{
    auto sda = LOOKUP_PIN(SDA);
auto scl = LOOKUP_PIN(SCL);
codal::I2C *i2c = pxt::getI2C(sda, scl);
    unsigned char i = 0;
    int error;
    error = i2c->write((uint16_t)ADDR, (uint8_t *)&reg, 1, true);
    if (error != 0)
    {
        return false;
    }
    error = i2c->read((uint16_t)ADDR, (uint8_t *)val, len);
    if (error != 0)
    {
        return false;
    }
    return len;
}

static void delay(uint16_t time)
{
    sleep_ms(time);
    //uBit.sleep(time);
}

namespace xChip
{
static myClass *ptr = new myClass;

//%
int begin(int var)
{
    return ptr->begin(var);
}

//%
uint8_t readDeviceID(uint8_t deviceIDReg)
{
    return ptr->readDeviceID(deviceIDReg);
}
    
//%
int delay(uint16_t time_ms)
{
    sleep_ms(time_ms);
}
} // namespace xChip
 
