#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hello.pio.h"

int main() {
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &hello_program);
    uint sm = pio_claim_unused_sm(pio, true);
    hello_program_init(pio, sm, offset, 6);

    uint32_t inc[512];
    for(int i = 0; i < 512; i++) {
        inc[i] = i;
    }

    int chan = dma_claim_unused_channel(true);
    dma_channel_config c = dma_channel_get_default_config(chan);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
    channel_config_set_read_increment(&c, true);
    channel_config_set_write_increment(&c, false);
    dma_channel_configure(
        chan,
        &c,
        &(pio->txf[sm]),
        inc,
        512,
        true
    );

    dma_channel_wait_for_finish_blocking(chan);
}
