#include <iostream>
#include <stdint.h>

typedef enum
{
    MOSI_PIN_0 = 11,
    MOSI_PIN_1 = 12,
    MOSI_PIN_2 = 13
} SPI_Mosi;

typedef enum
{
    MISO_PIN_0 = 21,
    MISO_PIN_1 = 22,
    MISO_PIN_2 = 23
} SPI_Miso;

typedef enum
{
    CS_PIN_0 = 31,
    CS_PIN_1 = 32,
    CS_PIN_2 = 33,
    CS_Default
} SPI_Cs;

typedef enum
{
    CLK_PIN_0 = 41,
    CLK_PIN_1 = 42,
    CLK_PIN_2 = 43
} SPI_Clk;

class MCU_PINS
{

public:
};

class Com : public MCU_PINS
{
public:
    virtual void sent() = 0;
    virtual void receive() = 0;
};

typedef enum
{
    SPI_0,
    SPI_1,
    SPI_2
} SPI_Type;

class SPI_Com : public Com
{

public:
    SPI_Com(SPI_Type SPI)
    {
        switch (SPI)
        {
        case SPI_0:
            this->mosi = MOSI_PIN_0;
            this->miso = MISO_PIN_0;
            this->clk = CLK_PIN_0;
            this->cs = CS_PIN_0;
            break;
        case SPI_1:
            this->mosi = MOSI_PIN_1;
            this->miso = MISO_PIN_1;
            this->clk = CLK_PIN_1;
            this->cs = CS_PIN_1;
            break;
        case SPI_2:
            this->mosi = MOSI_PIN_2;
            this->miso = MISO_PIN_2;
            this->clk = CLK_PIN_2;
            this->cs = CS_PIN_2;
            break;
        default:
            //error handling
            break;
        }
    }

    SPI_Com(SPI_Cs Cs, SPI_Miso Miso, SPI_Mosi Mosi, SPI_Clk Clk)
    {
        this->mosi = Mosi;
        this->miso = Miso;
        this->clk = Clk;
        this->cs = Cs;
    }

    void sent()
    {
    }

    void receive()
    {
    }

    void SystemMonitor()
    {
        std::cout << this->cs << std::endl;
    }

    ~SPI_Com()
    {
    }

private:
    SPI_Mosi mosi;
    SPI_Miso miso;
    SPI_Cs cs;
    SPI_Clk clk;
};
#define semaphore int
class GPS
{

public:
    SPI_Com *SPI;
    semaphore semaphoreGps;
    GPS(SPI_Com &SPI)
    {
        this->SPI = &SPI;
        this->SPI->SystemMonitor();
    }

    void GetGPS_Speed()
    {
        if(semaphoreGps == 1){ //xsemaphoreTake

        }
        this->SPI->SystemMonitor();
    }
};

int main()
{

    SPI_Com SPI0(SPI_0);
    SPI_Com SPI0_1(CS_PIN_0, MISO_PIN_1, MOSI_PIN_2, CLK_PIN_0);

    GPS GPS1(SPI0);
    GPS1.GetGPS_Speed();
    GPS GPS2(SPI0_1);
    GPS2.GetGPS_Speed();

    return 0;
}