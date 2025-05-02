#include <zephyr/init.h>
#include <zephyr/device.h>
#include <nrfx.h>

static int sysoff_init_prekernel(const struct device *dev) {
#ifdef CONFIG_SOC_SERIES_NRF52X
    uint32_t const gpregret = NRF_POWER->GPREGRET;
    if (gpregret == RST_SYSOFF) {
        NRF_POWER->GPREGRET = 0;
        NRF_POWER->SYSTEMOFF = 1;
    }
#endif
    return 0;
}

SYS_INIT(sysoff_init_prekernel, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
    
    